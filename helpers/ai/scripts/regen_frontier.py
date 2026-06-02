#!/usr/bin/env python3
"""Regenerate sdk_frontier.json from current Ghidra state.

Frontier rules (inferred from the existing file):
- Candidate: name starts with `FUN_` and address < 0x8b154
- Keep if at least one neighbor (caller or callee) has a non-`FUN_` / non-`$_FUN_` name
- named_* = neighbor name not starting with `FUN_` or `$_FUN_`
- sdk_neighbors = subset of named_* whose name starts with `$_` or `#_$_` (excludes plain names like `main`)
- app_neighbors = [] (never populated in the existing file)
"""
import json
import sys
import urllib.parse
import urllib.request
from collections import OrderedDict

BASE = "http://127.0.0.1:8089"
APP_BASE = 0x8b154


def get(path, **params):
    q = urllib.parse.urlencode(params)
    url = f"{BASE}/{path}?{q}" if q else f"{BASE}/{path}"
    with urllib.request.urlopen(url, timeout=30) as r:
        return r.read().decode()


def get_json(path, **params):
    return json.loads(get(path, **params))


def is_named(name):
    return not (name.startswith("FUN_") or name.startswith("$_FUN_"))


def is_sdk(name):
    return name.startswith("$_") or name.startswith("#_$_")


def dedupe_preserve(seq):
    seen = set()
    out = []
    for x in seq:
        if x not in seen:
            seen.add(x)
            out.append(x)
    return out


def list_all_functions():
    batch = 1000
    offset = 0
    out = []
    while True:
        data = get_json("list_functions_enhanced", query="", limit=batch, offset=offset)
        fns = data.get("functions", [])
        if not fns:
            break
        out.extend(fns)
        if len(fns) < batch:
            break
        offset += batch
    return out


def analyze(name):
    return get_json("analyze_function_complete", name=name)


def build_entry(fn):
    name = fn["name"]
    addr = fn["address"]
    info = analyze(name)
    callers = info.get("callers") or []
    callees = info.get("callees") or []
    strings = info.get("strings") or []

    all_callers = dedupe_preserve(callers)
    all_callees = dedupe_preserve(callees)

    named_callers = [c for c in all_callers if is_named(c)]
    named_callees = [c for c in all_callees if is_named(c)]

    sdk_neighbors = dedupe_preserve([c for c in named_callers + named_callees if is_sdk(c)])
    named_count = len(named_callers) + len(named_callees)

    entry = OrderedDict()
    entry["address"] = addr
    entry["name"] = name
    entry["named_callers"] = named_callers
    entry["named_callees"] = named_callees
    entry["named_count"] = named_count
    entry["all_callers"] = all_callers
    entry["all_callees"] = all_callees
    entry["strings"] = strings
    entry["sdk_neighbors"] = sdk_neighbors
    entry["app_neighbors"] = []
    entry["sdk_count"] = len(sdk_neighbors)
    entry["app_count"] = 0
    return entry


def main():
    print("listing functions...", file=sys.stderr)
    fns = list_all_functions()
    print(f"got {len(fns)} functions", file=sys.stderr)

    candidates = [
        fn for fn in fns
        if fn["name"].startswith("FUN_")
        and not fn.get("isThunk")
        and not fn.get("isExternal")
        and int(fn["address"], 16) < APP_BASE
    ]
    print(f"{len(candidates)} frontier candidates (FUN_* below 0x{APP_BASE:x})", file=sys.stderr)

    entries = []
    for i, fn in enumerate(candidates):
        try:
            e = build_entry(fn)
        except Exception as ex:
            print(f"[{i}/{len(candidates)}] {fn['name']}: FAIL {ex}", file=sys.stderr)
            continue
        if e["named_count"] >= 1:
            entries.append(e)
        if (i + 1) % 25 == 0:
            print(f"[{i+1}/{len(candidates)}] kept {len(entries)}", file=sys.stderr)

    entries.sort(key=lambda e: int(e["address"], 16))

    with open("/media/files/ncs/sdk_frontier.json", "w") as f:
        json.dump(entries, f, indent=2)
    print(f"wrote {len(entries)} entries to sdk_frontier.json", file=sys.stderr)


if __name__ == "__main__":
    main()
