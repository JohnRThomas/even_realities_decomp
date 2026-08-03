/*
 * Function: __sinit
 * Entry:    00079e74
 * Prototype: undefined __stdcall __sinit(undefined4 * param_1)
 */


/* exclude_from_export */

void __sinit(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  __sinit_lock_release();
  if (param_1[6] == 0) {
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[10] = 0x79e39;
    if (param_1 == (undefined4 *)&_GLOBAL_REENT) {
      DAT_20002d5c = 1;
    }
    puVar1 = __sfp(param_1);
    param_1[1] = puVar1;
    puVar1 = __sfp(param_1);
    param_1[2] = puVar1;
    puVar1 = __sfp(param_1);
    param_1[3] = puVar1;
    std((FILE *)param_1[1],4,0);
    std((FILE *)param_1[2],9,1);
    std((FILE *)param_1[3],0x12,2);
    param_1[6] = 1;
  }
  __sinit_lock_release();
  return;
}


