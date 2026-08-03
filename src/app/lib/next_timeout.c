/*
 * Function: next_timeout
 * Entry:    00077e24
 * Prototype: int32_t __stdcall next_timeout(void)
 */


/* exclude_from_export */

int32_t next_timeout(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = DAT_20002d1c;
  if ((undefined4 **)DAT_20002d1c == &DAT_20002d1c) {
    elapsed();
  }
  else {
    uVar2 = elapsed();
    if (puVar1 != (undefined4 *)0x0) {
      uVar4 = puVar1[4] - uVar2;
      iVar3 = (puVar1[5] - ((int)uVar2 >> 0x1f)) - (uint)((uint)puVar1[4] < uVar2);
      if (iVar3 < (int)(uint)(uVar4 < 0x80000000)) {
        if (-1 < iVar3) {
          return uVar4;
        }
        return 0;
      }
    }
  }
  return 0x7fffffff;
}


