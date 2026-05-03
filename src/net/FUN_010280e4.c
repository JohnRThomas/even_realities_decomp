/*
 * Function: FUN_010280e4
 * Entry:    010280e4
 * Prototype: undefined4 * __stdcall FUN_010280e4(int * param_1, int param_2)
 */


undefined4 * FUN_010280e4(int *param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *local_c;
  
  if (param_2 == *param_1) {
    iVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    puVar2 = FUN_01028094(param_1);
    if (iVar3 == 0) {
      enableIRQinterrupts();
    }
  }
  else {
    local_c = (int *)*param_1;
    if (local_c != (int *)0x0) {
      for (; *local_c != 0; local_c = (int *)*local_c) {
        if (param_2 == *local_c) {
          iVar3 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            iVar3 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          puVar2 = FUN_010280bc(local_c);
          if (iVar3 != 0) {
            return puVar2;
          }
          enableIRQinterrupts();
          return puVar2;
        }
      }
    }
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}


