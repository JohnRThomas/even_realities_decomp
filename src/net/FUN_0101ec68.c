/*
 * Function: FUN_0101ec68
 * Entry:    0101ec68
 * Prototype: undefined __stdcall FUN_0101ec68(int param_1, undefined1 * param_2, undefined4 param_3)
 */


void FUN_0101ec68(int param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined8 uVar8;
  undefined2 uStack_24;
  ushort local_22;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  
  uVar8 = CONCAT44(param_3,param_1);
  uVar7 = *(ushort *)(param_1 + 0x58);
  if ((ushort)DAT_21001208 <= *(ushort *)(param_1 + 0x58)) {
    uVar7 = (ushort)DAT_21001208;
  }
  uVar6 = *(ushort *)(param_1 + 0x56);
  if ((ushort)DAT_21001208 <= *(ushort *)(param_1 + 0x56)) {
    uVar6 = (ushort)DAT_21001208;
  }
  uVar5 = DAT_21001208._2_2_;
  if (uVar6 == 0x1b) goto LAB_0101ecec;
  do {
    if (uVar5 == 0x148) {
      return;
    }
    if (0x847 < uVar5) {
      uVar5 = 0x848;
    }
    FUN_01028afc((undefined2 *)uVar8,(int)((ulonglong)uVar8 >> 0x20),&uStack_24);
    if (local_1e <= uVar7) {
      uVar7 = local_1e;
    }
    *(ushort *)(param_2 + 6) = uVar7;
    uVar3 = local_1c;
    if (uVar5 <= local_1c) {
      uVar3 = uVar5;
    }
    *(ushort *)(param_2 + 8) = uVar3;
    if (local_22 <= uVar6) {
      uVar6 = local_22;
    }
    *(ushort *)(param_2 + 2) = uVar6;
    if (local_20 <= uVar5) {
      uVar5 = local_20;
    }
    *(ushort *)(param_2 + 4) = uVar5;
    *param_2 = 0xff;
    uVar4 = *(ushort *)(param_2 + 6) - 0x1b & 0xffff;
    uVar2 = extraout_r2;
    if (uVar4 < 0xe1) {
      uVar4 = *(ushort *)(param_2 + 2) - 0x1b & 0xffff;
      if (uVar4 < 0xe1) {
        uVar2 = 0x948;
        uVar4 = *(ushort *)(param_2 + 8) - 0x148 & 0xffff;
        if (uVar4 < 0x949) {
          uVar4 = *(ushort *)(param_2 + 4) - 0x148 & 0xffff;
          if (uVar4 < 0x949) {
            return;
          }
          uVar1 = 0x5b6;
        }
        else {
          uVar1 = 0x5b4;
        }
      }
      else {
        uVar1 = 0x5b2;
      }
    }
    else {
      uVar1 = 0x5b0;
    }
    uVar8 = FUN_01009500(0x39,uVar1,uVar2,uVar4);
LAB_0101ecec:
  } while (uVar7 != 0x1b);
  return;
}


