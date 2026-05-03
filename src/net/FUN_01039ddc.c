/*
 * Function: FUN_01039ddc
 * Entry:    01039ddc
 * Prototype: undefined __stdcall FUN_01039ddc(int param_1)
 */


void FUN_01039ddc(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_01008a3c(param_1 * 0x8000 + 999,param_1 >> 0x11,1000,0);
  FUN_01038424((uint)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  return;
}


