/*
 * Function: FUN_0101aa18
 * Entry:    0101aa18
 * Prototype: undefined4 __stdcall FUN_0101aa18(void)
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0101aa18(void)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  
  lVar7 = src/*FUN_01025834();
  uVar2 = (uint)lVar7;
  if (DAT_210010a0 == '\x04') {
    if ((uint)(DAT_210010b8 - DAT_210010f0) < (uint)(DAT_210010a4 * 10)) {
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 1;
  }
  puVar1 = (undefined *)FUN_010245ec(uVar5);
  if ((undefined *)0x75 < puVar1) {
    if (puVar1 == (undefined *)0xffffffff) {
      puVar4 = (undefined *)(DAT_210010dc - DAT_210010d8);
      if (&UNK_00001387 < (undefined *)(DAT_210010dc - DAT_210010d8)) {
        puVar4 = &DAT_00001388;
      }
    }
    else {
      if (DAT_210010dc <= (uint)(DAT_210010d8 + (int)puVar1)) {
        puVar1 = (undefined *)(DAT_210010dc - DAT_210010d8);
      }
      puVar3 = (undefined *)((DAT_210010d0 + 0x45) - uVar2);
      iVar6 = ((DAT_210010d4 + (uint)(0xffffffba < DAT_210010d0)) - (int)((ulonglong)lVar7 >> 0x20))
              - (uint)(DAT_210010d0 + 0x45 < uVar2);
      if (iVar6 < (int)(uint)(puVar3 == (undefined *)0x0)) {
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = &DAT_00001388;
        if ((int)(-(uint)(puVar1 < puVar3) - iVar6) < 0 ==
            (SBORROW4(0,iVar6) != SBORROW4(-iVar6,(uint)(puVar1 < puVar3)))) {
          if (puVar3 < &UNK_00001389) {
            puVar4 = puVar3;
          }
        }
        else if (puVar1 < &UNK_00001389) {
          puVar4 = puVar1;
        }
      }
    }
    lVar7 = src/*FUN_01025834();
    if (((undefined *)((0xbf - uVar2) + (int)lVar7) <= puVar4) &&
       (uVar2 = FUN_010246a8((int)puVar4,uVar5,extraout_r2), uVar2 == 0)) {
      DAT_210010e0 = DAT_210010e0 + (int)puVar4;
      DAT_210010d8 = DAT_210010d8 + (int)puVar4;
      FUN_01024538(DAT_210010e0,extraout_r1,extraout_r2_00,DAT_210010d8);
      return 1;
    }
  }
  return 0;
}


