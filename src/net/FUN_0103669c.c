/*
 * Function: FUN_0103669c
 * Entry:    0103669c
 * Prototype: uint __stdcall FUN_0103669c(uint param_1, int param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, int param_8, undefined1 param_9)
 */


uint FUN_0103669c(uint param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,undefined1 param_9)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int extraout_r1;
  int extraout_r2;
  int extraout_r2_00;
  int iVar5;
  undefined4 uVar6;
  int extraout_r3;
  uint unaff_r5;
  uint uVar7;
  int unaff_r6;
  int unaff_r7;
  int iVar8;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  int iStack_24;
  undefined1 uStack_20;
  
  if (param_8 == 0xf) {
    if (param_4 == 0x1036915) {
LAB_010366b4:
      *(uint *)(param_1 + 0x58) = param_1 + 0x58;
      *(uint *)(param_1 + 0x5c) = param_1 + 0x58;
      *(undefined1 *)(param_1 + 0xc) = param_9;
      uVar7 = param_3 + 7U & 0xfffffff8;
      iVar8 = uVar7 + 0x40 + param_2;
      *(undefined1 *)(param_1 + 0xd) = 4;
      *(char *)(param_1 + 0xe) = (char)param_8;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined1 *)(param_1 + 0xf) = 0;
      iVar2 = FUN_0102f56c(param_1,iVar8);
      *(int *)(param_1 + 0x78) = param_2 + 0x40;
      *(uint *)(param_1 + 0x7c) = uVar7;
      uVar7 = iVar2 + 7U & 0xfffffff8;
      *(uint *)(param_1 + 0x80) = uVar7;
      uVar7 = iVar8 - uVar7;
      FUN_0102f4a0(param_1,param_2,uVar7,param_4,param_5,param_6,param_7);
      *(undefined4 *)(param_1 + 0x54) = 0;
      iVar2 = DAT_21004b30;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined1 *)(param_1 + 0x70) = 0;
      uVar6 = 0;
      if (iVar2 != 0) {
        uVar6 = *(undefined4 *)(iVar2 + 0x84);
      }
      *(undefined4 *)(param_1 + 0x84) = uVar6;
      return uVar7;
    }
  }
  else if (param_8 + 0x10U < 0x1f) goto LAB_010366b4;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/thread.c",0x21a,param_8
              );
  puVar3 = (undefined4 *)FUN_0103a370();
  iVar2 = 0;
  *(undefined4 **)(unaff_r7 + 0xc) = puVar3;
  *(undefined4 *)(unaff_r7 + 0x10) = 0;
  if (((uint)puVar3 & 0x10000000) == 0) {
    iVar8 = (int)puVar3 << 4;
    uVar7 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar7 = getCurrentExceptionNumber();
      uVar7 = uVar7 & 0x1f;
    }
    puVar4 = puVar3;
    iVar5 = extraout_r2;
    if (uVar7 != 0) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/thread.c",0x28c,
                   iVar8);
      puVar4 = (undefined4 *)FUN_0103a370();
      iVar2 = extraout_r1;
      iVar5 = extraout_r2_00;
      iVar8 = extraout_r3;
    }
    FUN_0103669c((uint)puVar4,iVar2,iVar5,iVar8,in_stack_ffffffd0,in_stack_ffffffd4,
                 in_stack_ffffffd8,iStack_24,uStack_20);
    if (unaff_r6 == -1 && unaff_r5 == 0xffffffff) {
      return (uint)puVar3;
    }
    param_1 = (uint)puVar3;
    if (unaff_r6 != 0 || unaff_r5 != 0) {
      FUN_0103874c(puVar3 + 6,&LAB_0103ba88_1,unaff_r5,unaff_r6);
      return (uint)puVar3;
    }
  }
  FUN_0103795c((undefined4 *)param_1);
  return (uint)(undefined4 *)param_1;
}


