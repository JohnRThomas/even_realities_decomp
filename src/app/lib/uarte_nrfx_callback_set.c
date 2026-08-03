/*
 * Function: uarte_nrfx_callback_set
 * Entry:    000880d4
 * Prototype: undefined4 __stdcall uarte_nrfx_callback_set(int param_1, undefined4 param_2, undefined4 param_3)
 */


/* exclude_from_export */

undefined4 uarte_nrfx_callback_set(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  puVar1 = *(undefined4 **)(iVar2 + 0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    *(undefined4 *)(*(int *)(iVar2 + 0xc) + 4) = param_3;
    return 0;
  }
  return 0xffffff7a;
}


