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
app = 0
labeled_app = 0
for func in funcs:
    total += 1

    comment = func.getComment()

    if comment is not None and comment.startswith("exclude_from_export"):
        zephyr += 1
    elif comment is not None and comment == "exclude_from_export_ai":
        ai += 1
    else:
        if not func.getName().startswith("FUN_"):
            labeled_app += 1
        app += 1

    if not func.getName().startswith("FUN_") or comment is not None:
        labeled += 1

    # if func.getName().startswith("$_") or func.getName().startswith("#_$_"):
    #     zephyr += 1
    # if func.getName().startswith("#_"):
    #     ai += 1


totalPercentage =  100 * labeled / total
zpercentage =  100 * zephyr / total
aipercentage = 100 * ai / total
appPercentage = 100 * labeled_app / app

print("| *{}* | {}% | {}% | {} | {} | {} | {} | {} |".format(date.today(), totalPercentage, appPercentage, total, labeled, zephyr, app, labeled_app))

print("{}: Total Functions: {}, Labeled Functions: {}, Percentage: {}%, Zephyr Functions: {}, ZPercentage: {}%, AI Functions: {}, AIPercentage: {}% {}% {} {}".format(
      datetime.today(), total, labeled, totalPercentage, zephyr, zpercentage, ai , aipercentage, appPercentage, app, labeled_app))
