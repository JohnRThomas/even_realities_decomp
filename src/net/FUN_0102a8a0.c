/*
 * Function: FUN_0102a8a0
 * Entry:    0102a8a0
 * Prototype: undefined4 __stdcall FUN_0102a8a0(undefined4 * param_1, uint param_2)
 */


undefined4 FUN_0102a8a0(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  bVar1 = FUN_010222b4();
  do {
    if ((uint)bVar1 <= (uint)bVar4) {
      if (8 < param_2) {
        return 0xffffffea;
      }
      if (param_1 == (undefined4 *)0x0) {
        param_2 = 0;
      }
      if (((uint)param_1 & 3) == 0) {
        DAT_210016e8 = (undefined1)param_2;
        uVar2 = 0;
        DAT_210016e4 = param_1;
        if (param_1 != (undefined4 *)0x0) {
          FUN_01026284(param_1,0,param_2 * 0x30);
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xfffffff2;
      }
      return uVar2;
    }
    iVar3 = FUN_010222c0((uint)bVar4);
    bVar4 = bVar4 + 1;
  } while (*(char *)(iVar3 + 0x26) == '\0');
  return 0xffffffff;
}


