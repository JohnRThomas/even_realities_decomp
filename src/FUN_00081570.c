/*
 * Function: FUN_00081570
 * Entry:    00081570
 * Prototype: uint __stdcall FUN_00081570(undefined * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_00081570(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  k_thread *thread;
  int extraout_r0;
  uint uVar1;
  int extraout_r1;
  int iVar2;
  int extraout_r2;
  
  (*(code *)param_1)(param_2,param_3,param_4,param_4,param_4);
  thread = (k_thread *)k_current_get();
  z_thread_abort(thread);
  iVar2 = extraout_r0 + extraout_r1 * 8;
  if (*(uint *)(extraout_r0 + 8) < 0x8000) {
    uVar1 = (uint)*(ushort *)(iVar2 + extraout_r2 * 2);
  }
  else {
    uVar1 = *(uint *)(iVar2 + extraout_r2 * 4);
  }
  return uVar1;
}


