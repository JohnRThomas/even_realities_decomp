#@runtime Jython
#@author
#@category EvenG1Helpers
#@keybinding
#@menupath
#@toolbar

from datetime import datetime
from datetime import date
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.address import Address
from ghidra.program.model.listing import Function
from ghidra.util.exception import DuplicateNameException

fm = currentProgram.getFunctionManager()
funcs = fm.getFunctions(True) # True means 'forward'
total = 0
labeled = 0
zephyr = 0
ai = 0
for func in funcs:
    total += 1
    if not func.getName().startswith("FUN_"):
        labeled += 1
    
    comment = func.getComment()

    if comment is not None and comment.startswith("exclude_from_export"):
        zephyr += 1

    if comment is not None and comment == "exclude_from_export_ai":
        ai += 1


    # if func.getName().startswith("$_") or func.getName().startswith("#_$_"):
    #     zephyr += 1
    # if func.getName().startswith("#_"):
    #     ai += 1


percentage =  100 * labeled / total
zpercentage =  100 * zephyr / total
aipercentage = 100 * ai / total

print("{}: Total Functions: {}, Labeled Functions: {}, Percentage: {}%, Zephyr Functions: {}, ZPercentage: {}%, AI Functions: {}, AIPercentage: {}%".format(
      datetime.now(), total, labeled, percentage, zephyr, zpercentage, ai , aipercentage))
