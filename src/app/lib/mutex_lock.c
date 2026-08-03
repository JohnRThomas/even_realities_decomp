/*
 * Function: mutex_lock
 * Entry:    0007c988
 * Prototype: int __stdcall mutex_lock(int * param_1)
 */


/* exclude_from_export */

int mutex_lock(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return -0x7001;
  }
  if (param_1[1] != 0xa95c5f2c) {
    if ((param_1[1] & 0x3a000000U) != 0) {
      do {
        do {
          ExclusiveAccess(param_1);
          iVar2 = *param_1;
          bVar1 = (bool)hasExclusiveAccess(param_1);
        } while (!bVar1);
        *param_1 = 1;
      } while (iVar2 == 1);
      DataMemoryBarrier(0x1f);
      return 0;
    }
    return -0x7017;
  }
  return -0x7016;
}


