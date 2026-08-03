/*
 * Function: _fflush_r
 * Entry:    00079d78
 * Prototype: undefined4 __stdcall _fflush_r(int * param_1, int * param_2)
 */


/* exclude_from_export_ai */

undefined4 _fflush_r(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2[4] != 0) {
    if ((param_1 != (int *)0x0) && (param_1[6] == 0)) {
      __sinit(param_1);
    }
    if (param_2 == (int *)&DAT_0009c2ac) {
      param_2 = (int *)param_1[1];
    }
    else if (param_2 == (int *)&DAT_0009c28c) {
      param_2 = (int *)param_1[2];
    }
    else if (param_2 == (int *)&DAT_0009c26c) {
      param_2 = (int *)param_1[3];
    }
    if ((short)param_2[3] != 0) {
      if ((-1 < param_2[0x19] << 0x1f) && (-1 < (int)(short)param_2[3] << 0x16)) {
        __retarget_lock_acquire_recursive(param_2[0x16]);
      }
      uVar1 = __sflush_r(param_1,param_2);
      if (param_2[0x19] << 0x1f < 0) {
        return uVar1;
      }
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x16) < 0) {
        return uVar1;
      }
      __retarget_lock_release_recursive(param_2[0x16]);
      return uVar1;
    }
  }
  return 0;
}


