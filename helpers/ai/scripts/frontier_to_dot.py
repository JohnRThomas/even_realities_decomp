#!/usr/bin/env python3
"""Emit sdk_frontier.json as one Graphviz DOT file per weakly-connected component.

Each file is a standalone `digraph` so it can be rendered directly:
  dot -Tsvg call_tree_components/01_xxx.dot -o 01_xxx.svg

Files are written to call_tree_components/ and numbered by component size (desc).
"""
import json
import os
import re
import sys

IN = "/media/files/ncs/sdk_frontier.json"
OUT_DIR = "/media/files/ncs/call_tree_components"


def classify(name):
    if name.startswith("$_FUN_"):
        return "staged"
    if name.startswith("FUN_"):
        return "frontier"
    if name.startswith("$_") or name.startswith("#_$_"):
        return "sdk"
    return "named"


STYLE = {
    "frontier": 'fillcolor="#ef4444", fontcolor="white"',
    "sdk":      'fillcolor="#3b82f6", fontcolor="white"',
    "named":    'fillcolor="#10b981", fontcolor="white"',
    "staged":   'fillcolor="#f59e0b", fontcolor="black"',
}


_SAFE_ID = re.compile(r"[^A-Za-z0-9_]")


def node_id(name):
    """DOT-safe identifier."""
    return "n_" + _SAFE_ID.sub("_", name)


def dot_escape(s):
    return s.replace("\\", "\\\\").replace('"', '\\"')


def weakly_connected_components(nodes, edges):
    """Return list of sets; each set is one weakly-connected component."""
    adj = {n: set() for n in nodes}
    for s, d in edges:
        adj[s].add(d)
        adj[d].add(s)
    seen = set()
    comps = []
    for start in nodes:
        if start in seen:
            continue
        stack = [start]
        comp = set()
        while stack:
            n = stack.pop()
            if n in seen:
                continue
            seen.add(n)
            comp.add(n)
            stack.extend(adj[n] - seen)
        comps.append(comp)
    return comps


def pick_component_name(comp, by_name):
    """Pick a readable slug for a component: prefer a non-FUN_ name with highest degree."""
    named = [n for n in comp if not (n.startswith("FUN_") or n.startswith("$_FUN_"))]
    if named:
        # Prefer plain names (like `main`, `imu_fusion_thread`) over prefixed SDK names
        plain = [n for n in named if not (n.startswith("$_") or n.startswith("#_$_"))]
        pool = plain or named
        pool.sort(key=lambda n: -len(n))
        pick = pool[0]
    else:
        pick = sorted(comp)[0]
    slug = re.sub(r"[^A-Za-z0-9_]+", "_", pick).strip("_")
    return slug[:60] or "component"


def write_component(path, comp, edges_in_comp, by_name, in_deg, out_deg):
    with open(path, "w") as f:
        f.write(f"// Component: {len(comp)} nodes, {len(edges_in_comp)} edges\n")
        f.write("digraph call_tree {\n")
        f.write('  graph [bgcolor="#18181b", rankdir=TB, overlap=false, splines=true, pad=0.4, nodesep=0.3, ranksep=2.0];\n')
        f.write('  node  [shape=box, style="filled,rounded", fontname="Menlo", fontsize=10, penwidth=0, margin="0.08,0.04"];\n')
        f.write('  edge  [color="#52525b", arrowsize=0.5, penwidth=0.6];\n\n')

        by_cls = {"frontier": [], "sdk": [], "named": [], "staged": []}
        for n in sorted(comp):
            by_cls[classify(n)].append(n)

        for cls, names in by_cls.items():
            if not names:
                continue
            f.write(f"  // {cls}: {len(names)} nodes\n")
            for n in names:
                entry = by_name.get(n)
                tooltip = n
                if entry:
                    tooltip += f"\\n0x{entry['address']}"
                tooltip += f"\\ncallers: {in_deg[n]} · callees: {out_deg[n]}"
                label = dot_escape(n)
                deg = in_deg[n] + out_deg[n]
                width = min(0.5 + deg * 0.02, 2.0)
                f.write(
                    f'  {node_id(n)} [label="{label}", '
                    f'tooltip="{dot_escape(tooltip)}", '
                    f'{STYLE[cls]}, width={width:.2f}];\n'
                )
            f.write("\n")

        f.write("  // edges\n")
        for s, d in sorted(edges_in_comp):
            f.write(f"  {node_id(s)} -> {node_id(d)};\n")
        f.write("}\n")


def main():
    with open(IN) as f:
        frontier = json.load(f)

    by_name = {e["name"]: e for e in frontier}
    all_nodes = set()
    edges = set()
    for e in frontier:
        src = e["name"]
        all_nodes.add(src)
        for c in e.get("all_callers", []):
            all_nodes.add(c)
            edges.add((c, src))
        for c in e.get("all_callees", []):
            all_nodes.add(c)
            edges.add((src, c))

    in_deg = {n: 0 for n in all_nodes}
    out_deg = {n: 0 for n in all_nodes}
    for s, d in edges:
        out_deg[s] += 1
        in_deg[d] += 1

    comps = weakly_connected_components(all_nodes, edges)
    comps.sort(key=lambda c: -len(c))

    os.makedirs(OUT_DIR, exist_ok=True)
    # Clear stale files from prior runs
    for old in os.listdir(OUT_DIR):
        if old.endswith(".dot"):
            os.remove(os.path.join(OUT_DIR, old))

    pad = max(2, len(str(len(comps))))
    sizes = []
    for i, comp in enumerate(comps, start=1):
        slug = pick_component_name(comp, by_name)
        fname = f"{i:0{pad}d}_{slug}.dot"
        path = os.path.join(OUT_DIR, fname)
        comp_edges = {(s, d) for (s, d) in edges if s in comp and d in comp}
        write_component(path, comp, comp_edges, by_name, in_deg, out_deg)
        sizes.append((fname, len(comp), len(comp_edges)))

    # Index file
    with open(os.path.join(OUT_DIR, "INDEX.txt"), "w") as f:
        f.write(f"{len(comps)} components · {len(all_nodes)} total nodes · {len(edges)} total edges\n\n")
        f.write(f"{'file':60s}  {'nodes':>6s}  {'edges':>6s}\n")
        for fname, ns, es in sizes:
            f.write(f"{fname:60s}  {ns:>6d}  {es:>6d}\n")

    print(f"wrote {len(comps)} components to {OUT_DIR}/", file=sys.stderr)
    print(f"  largest: {sizes[0][1]} nodes · smallest: {sizes[-1][1]} nodes", file=sys.stderr)


if __name__ == "__main__":
    main()
