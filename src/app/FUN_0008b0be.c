/*
 * Function: FUN_0008b0be
 * Entry:    0008b0be
 * Prototype: undefined4 __stdcall FUN_0008b0be(undefined4 * param_1, undefined4 * param_2)
 */


undefined4 FUN_0008b0be(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  size_t n;
  
  if ((undefined4 *)param_2[0xd] == param_2 + 0x11) {
    pvVar1 = ____calloc((size_t)param_1,0x400);
    if (pvVar1 != (void *)0x0) {
      param_2[0xd] = pvVar1;
      param_2[0xe] = 0x400;
      *(undefined1 *)((int)pvVar1 + 0x3ff) = *(undefined1 *)((int)param_2 + 0x46);
      *(undefined1 *)((int)pvVar1 + 0x3fe) = *(undefined1 *)((int)param_2 + 0x45);
      *(undefined1 *)((int)pvVar1 + 0x3fd) = *(undefined1 *)(param_2 + 0x11);
      *param_2 = (undefined1 *)((int)pvVar1 + 0x3fd);
      return 0;
    }
  }
  else {
    n = param_2[0xe];
    pvVar1 = _realloc_r(param_1,(undefined4 *)param_2[0xd],n << 1);
    if (pvVar1 != (void *)0x0) {
      memcpy((void *)((int)pvVar1 + n),pvVar1,n);
      *param_2 = (void *)((int)pvVar1 + n);
      param_2[0xd] = pvVar1;
      param_2[0xe] = n << 1;
      return 0;
    }
  }
  return 0xffffffff;
}


