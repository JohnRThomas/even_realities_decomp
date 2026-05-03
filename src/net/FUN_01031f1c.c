/*
 * Function: FUN_01031f1c
 * Entry:    01031f1c
 * Prototype: undefined __stdcall FUN_01031f1c(int param_1)
 */


void FUN_01031f1c(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 == -1) {
    param_1 = 0x7fffff;
  }
  else if (param_1 < 2) {
    param_1 = 1;
  }
  else if (0x7ffffe < param_1) {
    param_1 = 0x7fffff;
  }
  uVar2 = FUN_01031b68();
  uVar1 = (int)uVar2 - DAT_21002b80;
  if (0x7fffff < uVar1) {
    param_1 = 0;
  }
  uVar1 = param_1 + uVar1;
  if (0x7ffffe < uVar1) {
    uVar1 = 0x7fffff;
  }
  FUN_01031bac(0,&LAB_01031a48_1,uVar1 + DAT_21002b80,
               DAT_21002b84 + (uint)CARRY4(uVar1,DAT_21002b80),&LAB_01031a48_1,0,'\0');
  return;
}


