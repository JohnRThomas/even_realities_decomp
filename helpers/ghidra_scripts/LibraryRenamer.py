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
count = 0
for func in funcs:
    if func.getName().startswith("$_?_"):
        continue
        # oldName = func.getName()
        # newName = oldName[2:]
        # comment = ""
        # print("{} -> {}".format(oldName, newName))
        # count += 1
        # func.setName(newName, SourceType.USER_DEFINED)
        # func.setComment(comment)
    elif func.getName().startswith("%_"):
        oldName = func.getName()
        newName = oldName[2:]
        print("{} -> {}".format(oldName, newName))
        count += 1
        func.setName(newName, SourceType.USER_DEFINED)
    elif func.getName().startswith("$_"):
        oldName = func.getName()
        newName = oldName[2:]
        comment = "exclude_from_export"
        print("{} -> {}".format(oldName, newName))
        count += 1
        # func.setName(newName, SourceType.USER_DEFINED)
        # func.setComment(comment)
    elif func.getName().startswith("#_$_"):
        oldName = func.getName()
        newName = oldName[4:]
        comment = "exclude_from_export_ai"
        print("{} -> {}".format(oldName, newName))
        count += 1
        # func.setName(newName, SourceType.USER_DEFINED)
        # func.setComment(comment)
    elif func.getName().startswith("nano-newlib"):
        oldName = func.getName()
        newName = oldName[12:]
        func.setName(newName, SourceType.USER_DEFINED)
        print("{} -> {}".format(oldName, newName))


print("Renamed {} functions".format(count))
