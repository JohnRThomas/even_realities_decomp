//@category EvenG1Helpers
//@menupath Tools.Decompiler Export.Dump All Decompiled C (per function)
// Dumps all functions' decompiled C to files under a chosen directory.
// Works in GUI, and with analyzeHeadless via: -postScript DumpDecompiled.java outDir=/path

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.util.task.TaskMonitor;
import java.nio.file.*;
import java.io.IOException;
import java.util.*;
import java.nio.charset.StandardCharsets;

public class DumpDecompiled extends GhidraScript {
    @Override
    public void run() throws Exception {
        if (currentProgram == null) {
            printerr("Open a program first.");
            return;
        }

        // Allow headless arg: outDir=/some/path
        Path outDir = null;
        for (String arg : getScriptArgs()) {
            if (arg.startsWith("outDir=")) {
                outDir = Paths.get(arg.substring("outDir=".length())).toAbsolutePath();
            }
        }
        if (outDir == null) {
            outDir = askDirectory("Choose output directory", "Select").toPath();
        }
        Files.createDirectories(outDir);

        DecompileOptions opts = new DecompileOptions();
        DecompInterface ifc = new DecompInterface();
        ifc.setOptions(opts);
        if (!ifc.openProgram(currentProgram)) {
            printerr("Failed to open decompiler for program.");
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        FunctionIterator it = fm.getFunctions(true);
        TaskMonitor mon = getMonitor();

        List<String> index = new ArrayList<>();
        int count = 0, ok = 0, fail = 0;
        int timeoutSec = 60;

        while (it.hasNext() && !mon.isCancelled()) {
            Function f = it.next();
            String name = f.getName();
            String comment = f.getComment();

            // Skip explicitly excluded functions.
            if (comment != null && comment.startsWith("exclude_from_export")) {
                continue;
            }

            // Thunk will export as a duplicate function, so just ignore it.
            if (f.isThunk()){
                continue;
            }

            count++;
            mon.setMessage("Decompiling: " + name + " @ " + f.getEntryPoint());
            DecompileResults res = ifc.decompileFunction(f, timeoutSec, mon);

            if (name.startsWith("?_")) {
                name = name.substring(2);
            }

            if (name.startsWith("$_?_")) {
                name = name.substring(4);
            }

            String fileSafeName = sanitize(f.getName()) + ".c";
            Path outFile = outDir.resolve(fileSafeName);

            try {
                StringBuilder sb = new StringBuilder();
                sb.append("/*\n")
                  .append(" * Function: ").append(f.getName()).append("\n")
                  .append(" * Entry:    ").append(f.getEntryPoint()).append("\n")
                  .append(" * Prototype: ").append(f.getPrototypeString(false, true)).append("\n")
                  .append(" */\n\n");

                if (res != null && res.getDecompiledFunction() != null) {
                    sb.append(res.getDecompiledFunction().getC()).append("\n");
                    ok++;
                } else {
                    sb.append("/* <no decompilation available> */\n");
                    fail++;
                }

                Files.write(outFile, sb.toString().getBytes(StandardCharsets.UTF_8));
                index.add(f.getEntryPoint() + "\t" + f.getName() + "\t" + outFile.getFileName().toString());
            } catch (IOException e) {
                printerr("Write failed for " + f.getName() + ": " + e.getMessage());
                fail++;
            }
        }

        Files.write(outDir.resolve("index.txt"),
                index, StandardCharsets.UTF_8);

        println("Done. Decompiled " + ok + " / " + count + " functions; failures: " + fail);
        println("Output dir: " + outDir.toString());
    }

    private static String sanitize(String s) {
        return s.replaceAll("[^A-Za-z0-9_\\-\\.]", "_");
    }
}
