/*
 * Function: FUN_0101434c
 * Entry:    0101434c
 * Prototype: undefined4 __stdcall FUN_0101434c(int param_1, int param_2, uint param_3)
 */


undefined4 FUN_0101434c(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  
  if (*(char *)(param_1 + 0x120) != '\0') {
    return 0xc;
  }
  uVar5 = FUN_01023634(0x1013485,param_1);
  if (uVar5 == 0x20) {
    return 0xc;
  }
  FUN_01026284((undefined4 *)(param_1 + 0x100),0,0x50);
  *(char *)(param_1 + 0x100) = (char)uVar5;
  *(int *)(param_1 + 0x104) = param_2;
  *(undefined1 *)(param_1 + 0x120) = 1;
  if (param_2 != 0) {
    iVar6 = FUN_0100fe6c();
    *(byte *)(param_2 + 0x30c) = ((byte)iVar6 & 7) + 1;
  }
  iVar6 = FUN_01013414(param_1);
  *(undefined1 *)(param_1 + 0x128) = 0;
  *(undefined2 *)(param_1 + 0x132) = 0x102;
  *(short *)(param_1 + 0x130) = (short)iVar6;
  sVar4 = FUN_01024ed8();
  uVar5 = FUN_010236a8();
  uVar1 = *(ushort *)(param_1 + 0x130);
  if (uVar1 < uVar5) {
    uVar1 = (ushort)uVar5;
  }
  uVar8 = (uint)(ushort)(sVar4 + 0xe7 + uVar1);
  uVar5 = FUN_01012ec0(param_1);
  if (uVar5 == 0) {
    uVar10 = FUN_01012ab4(param_1,0);
    *(int *)(param_1 + 300) = (int)uVar10 + 0x152;
    iVar6 = 0;
    if ((DAT_21000f66 != 0) && (iVar6 = 0, *(short *)(param_1 + 0x22) != 0)) {
      uVar5 = FUN_0100fe6c();
      iVar6 = uVar5 - (uVar5 / DAT_21000f66) * (uint)DAT_21000f66;
    }
    lVar9 = thunk_FUN_01025834();
    lVar9 = lVar9 + (ulonglong)(uVar8 + iVar6);
    *(longlong *)(param_1 + 0x138) = lVar9;
    if (param_3 != 0) {
      *(ulonglong *)(param_1 + 0x140) = lVar9 + (ulonglong)param_3;
      goto LAB_01014432;
    }
  }
  else {
    sVar4 = thunk_FUN_01024ecc();
    iVar6 = FUN_01024e78(param_3,(uint)(ushort)(sVar4 + 0x668));
    *(uint *)(param_1 + 300) = iVar6 + param_3;
    lVar9 = thunk_FUN_01025834();
    lVar9 = lVar9 + (ulonglong)uVar8;
    *(undefined2 *)(param_1 + 0x22) = 0;
    *(int *)(param_1 + 0x138) = (int)lVar9;
    *(undefined1 *)(param_1 + 0x108) = 1;
    *(int *)(param_1 + 0x13c) = (int)((ulonglong)lVar9 >> 0x20);
    bVar2 = FUN_01012ef0(param_1);
    if (bVar2) {
      uVar10 = FUN_01012ab4(param_1,1);
      *(uint *)(param_1 + 0x10c) = (param_3 - 0x54e) - (int)uVar10;
    }
    else {
      iVar6 = FUN_01013398(1);
      *(uint *)(param_1 + 0x10c) = (param_3 - 0x152) - iVar6;
    }
  }
  *(undefined4 *)(param_1 + 0x140) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x144) = 0x7fffffff;
LAB_01014432:
  uVar5 = FUN_010239c8((uint)*(byte *)(param_1 + 0x100),(byte *)(param_1 + 0x128));
  if (uVar5 != 0) {
    *(undefined2 *)(param_1 + 0x122) = 0;
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x13c);
    FUN_01013160(param_1,0);
    return 0;
  }
  iVar6 = FUN_01009500(0x30,0x1ec,extraout_r2,extraout_r3);
  if (*(char *)(iVar6 + 0x120) == '\0') {
    return 0;
  }
  *(undefined1 *)(iVar6 + 0x148) = 1;
  FUN_01013160(iVar6,1);
  if (*(char *)(iVar6 + 0x120) == '\0') {
    return 0;
  }
  FUN_01023fb0((uint)*(byte *)(iVar6 + 0x100));
  FUN_0102491c((uint)*(byte *)(iVar6 + 0x100),extraout_r1,extraout_r2_00,extraout_r3_00);
  cVar3 = FUN_010236bc((uint)*(byte *)(iVar6 + 0x100));
  if (cVar3 != '\0') {
    *(undefined1 *)(iVar6 + 0x120) = 0;
    return 0;
  }
  uVar7 = FUN_01009500(0x30,0x20a,extraout_r2_01,extraout_r3_01);
  DAT_21000f5c = (char)uVar7;
  return uVar7;
}


