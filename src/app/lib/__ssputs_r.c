/*
 * Function: __ssputs_r
 * Entry:    0008aee6
 * Prototype: undefined4 __stdcall __ssputs_r(undefined4 * param_1, int * param_2, void * param_3, uint param_4)
 */


/* exclude_from_export_ai */

undefined4 __ssputs_r(undefined4 *param_1,int *param_2,void *param_3,uint param_4)

{
  void *d;
  uint uVar1;
  uint uVar2;
  size_t n;
  
  if ((uint)param_2[2] <= param_4) {
    uVar2 = param_2[2];
    if (((int)(short)param_2[3] & 0x480U) != 0) {
      n = *param_2 - param_2[4];
      uVar1 = param_4 + 1 + n;
      uVar2 = (param_2[5] * 3) / 2;
      if (uVar2 < uVar1) {
        uVar2 = uVar1;
      }
      if ((int)(short)param_2[3] << 0x15 < 0) {
        d = _malloc_r((size_t)param_1,uVar2);
        if (d == (void *)0x0) {
LAB_0008af88:
          *param_1 = 0xc;
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
          return 0xffffffff;
        }
        memcpy(d,(void *)param_2[4],n);
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
      }
      else {
        d = _realloc_r(param_1,(void *)param_2[4],uVar2);
        if (d == (void *)0x0) {
          _free_r(param_1,param_2[4]);
          goto LAB_0008af88;
        }
      }
      param_2[4] = (int)d;
      param_2[5] = uVar2;
      *param_2 = (int)d + n;
      param_2[2] = uVar2 - n;
      uVar2 = param_4;
    }
    if (uVar2 <= param_4) goto LAB_0008af58;
  }
  uVar2 = param_4;
LAB_0008af58:
  memmove((void *)*param_2,param_3,uVar2);
  param_2[2] = param_2[2] - uVar2;
  *param_2 = *param_2 + uVar2;
  return 0;
}


