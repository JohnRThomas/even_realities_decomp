/*
 * Function: FUN_010111ec
 * Entry:    010111ec
 * Prototype: undefined8 __stdcall FUN_010111ec(uint param_1, undefined * param_2, uint param_3, int param_4, ushort param_5)
 */


undefined8 FUN_010111ec(uint param_1,undefined *param_2,uint param_3,int param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined *puVar9;
  
  uVar7 = param_1;
  if (0xd8 < param_1) {
    uVar7 = 0xd9;
  }
  uVar7 = uVar7 + 0x30 & 0xffff;
  if (0xfe < uVar7) {
    uVar7 = 0xff;
  }
  if ((param_5 & 3) == 0) {
    puVar5 = param_2 + 0x14a;
    if (param_4 == 0) {
      if (param_3 == 8) {
        puVar8 = puVar5 + (uVar7 + 5 & 0xffff) * 0x40 + 400;
        if (0xd9 < param_1) {
          param_2 = &DAT_000043da;
          uVar2 = param_1 - 0xd9 & 0xffff;
          uVar7 = ((uint)((ulonglong)uVar2 * 0x10953f391 >> 0x21) << 0x11) >> 0x18;
          puVar8 = puVar8 + uVar7 * 0x43da;
          uVar7 = uVar2 + uVar7 * -0xf7 & 0xffff;
          if (uVar7 == 0) goto LAB_01011264;
          iVar3 = 400;
          iVar4 = 0x40;
          iVar1 = (uVar7 + 8 & 0xffff) + 5;
          goto LAB_0101154c;
        }
        goto LAB_01011264;
      }
      if (param_3 == 4) {
        param_2 = &UNK_0000017e;
        iVar3 = 0x10;
LAB_01011434:
        puVar8 = puVar5 + (int)(param_2 + (uVar7 + 5 & 0xffff) * iVar3);
        if (param_1 < 0xda) goto LAB_01011264;
        uVar7 = param_1 - 0xd9 & 0xffff;
        param_2 = (undefined *)(((uint)((ulonglong)uVar7 * 0x10953f391 >> 0x21) << 0x11) >> 0x18);
        if (param_3 == 4) {
          puVar8 = puVar8 + (int)param_2 * 0x1308;
          uVar7 = uVar7 + (int)param_2 * -0xf7 & 0xffff;
          if (uVar7 == 0) goto LAB_01011264;
          iVar3 = 0x17e;
          iVar4 = 0x10;
          iVar1 = (uVar7 + 8 & 0xffff) + 5;
          goto LAB_0101154c;
        }
        if (param_3 == 2) {
          puVar8 = puVar8 + (int)param_2 * 0x572;
          uVar7 = uVar7 + (int)param_2 * -0xf7 & 0xffff;
          if (uVar7 != 0) {
            iVar3 = 0x18;
            iVar4 = 4;
            iVar1 = (uVar7 + 8 & 0xffff) + 5;
            goto LAB_0101154c;
          }
          goto LAB_01011264;
        }
      }
      else {
        if (param_3 == 2) {
          param_2 = &UsageFault;
          iVar3 = 4;
          goto LAB_01011434;
        }
        puVar8 = puVar5 + (uVar7 + 5 & 0xffff) * 8 + 0x28;
        if (param_1 < 0xda) goto LAB_01011264;
        uVar7 = param_1 - 0xd9 & 0xffff;
        param_2 = (undefined *)(((uint)((ulonglong)uVar7 * 0x10953f391 >> 0x21) << 0x11) >> 0x18);
      }
      puVar8 = puVar8 + (int)param_2 * 0x992;
      uVar7 = uVar7 + (int)param_2 * -0xf7 & 0xffff;
      if (uVar7 != 0) {
        iVar3 = 0x28;
        iVar4 = 8;
        iVar1 = (uVar7 + 8 & 0xffff) + 5;
LAB_0101154c:
        return CONCAT44(param_2,puVar8 + iVar1 * iVar4 + iVar3 + 0x14a);
      }
      goto LAB_01011264;
    }
    if (param_3 != 8) {
      if (param_3 == 4) {
        puVar9 = &DAT_000011be;
LAB_01011496:
        puVar8 = puVar5 + (int)puVar9;
        if (param_1 < 0xda) goto LAB_01011264;
        uVar2 = (param_1 - 0xd9 & 0xffff) + 0xf6;
        uVar7 = uVar2 * -0x7b560637;
        goto joined_r0x010114ba;
      }
      if (param_3 == 2) {
        puVar9 = (undefined *)0x428;
        goto LAB_01011496;
      }
      puVar8 = param_2 + 0x992;
      if (param_1 < 0xda) goto LAB_01011264;
LAB_010112a6:
      uVar2 = (param_1 - 0xd9 & 0xffff) + 0xf6;
      uVar7 = uVar2 * -0x7b560637;
      uVar2 = uVar2 / 0xf7;
LAB_010112b8:
      puVar5 = (undefined *)0x992;
      goto LAB_010112bc;
    }
    puVar8 = param_2 + 0x43da;
joined_r0x010114da:
    if (0xd9 < param_1) {
      puVar5 = &DAT_000043da;
      uVar7 = (ushort)((short)param_1 - 0xd9) + 0xf6;
      uVar2 = uVar7 / 0xf7;
LAB_010112bc:
      return CONCAT44(uVar7,puVar8 + (int)puVar5 * uVar2);
    }
    goto LAB_01011264;
  }
  if ((int)((uint)param_5 << 0x1e) < 0) {
    if (param_3 == 8) {
      puVar5 = &DAT_000012d0;
    }
    else if (param_3 == 4) {
      puVar5 = (undefined *)0x5ce;
    }
    else if (param_3 == 2) {
      puVar5 = (undefined *)0x12c;
    }
    else {
      puVar5 = (undefined *)0x250;
    }
LAB_01011234:
    param_2 = param_2 + (int)(puVar5 + 0x14a);
    if ((param_3 & 0xc) != 0) goto LAB_0101123e;
LAB_01011356:
    if (param_3 == 8) {
      iVar3 = 0xb50;
    }
    else if (param_3 == 4) {
      iVar3 = 0x3ee;
    }
    else if (param_3 == 2) {
      iVar3 = 0xb4;
    }
    else {
      iVar3 = 0x160;
    }
    param_2 = param_2 + 0x9c;
    puVar6 = param_2 + iVar3;
    puVar8 = puVar6 + 0x98;
  }
  else {
    if (param_4 != 0) {
      if (param_3 == 8) {
        puVar5 = &DAT_00004290;
      }
      else if (param_3 == 4) {
        puVar5 = &DAT_000011be;
      }
      else {
        puVar5 = (undefined *)0x848;
        if (param_3 == 2) {
          puVar5 = (undefined *)0x428;
        }
      }
      goto LAB_01011234;
    }
    if (param_3 == 8) {
      iVar3 = 400;
      iVar1 = 0x40;
      uVar7 = uVar7 + 5 & 0xffff;
    }
    else if (param_3 == 4) {
      iVar3 = 0x17e;
      iVar1 = 0x10;
      uVar7 = uVar7 + 5 & 0xffff;
    }
    else if (param_3 == 2) {
      iVar3 = 0x18;
      iVar1 = 4;
      uVar7 = uVar7 + 5 & 0xffff;
    }
    else {
      iVar3 = 0x28;
      iVar1 = 8;
      uVar7 = uVar7 + 5 & 0xffff;
    }
    param_2 = param_2 + uVar7 * iVar1 + iVar3 + 0x14a;
    if ((param_3 & 0xc) == 0) goto LAB_01011356;
LAB_0101123e:
    puVar6 = param_2 + 0xc14;
    puVar8 = param_2 + 0xcac;
  }
  if ((int)((uint)param_5 << 0x1f) < 0) {
    if (param_3 == 8) {
      param_2 = &UNK_00000650;
    }
    else if (param_3 == 4) {
      param_2 = &UNK_000002ae;
    }
    else if (param_3 == 2) {
      param_2 = &DAT_00000064;
    }
    else {
      param_2 = &UNK_000000c0;
    }
    puVar8 = puVar8 + (int)param_2;
    goto LAB_01011264;
  }
  if (param_4 != 0) {
    if (param_3 != 8) {
      if (param_3 == 4) {
        param_2 = &DAT_000011be;
      }
      else {
        if (param_3 != 2) {
          puVar8 = puVar6 + 0x8e0;
          if (param_1 < 0xda) {
            return CONCAT44(param_2,puVar8);
          }
          goto LAB_010112a6;
        }
        param_2 = &DAT_00000428;
      }
      puVar8 = puVar8 + (int)param_2;
      if (param_1 < 0xda) goto LAB_01011264;
      uVar7 = (param_1 - 0xd9 & 0xffff) + 0xf6;
      uVar2 = uVar7;
joined_r0x010114ba:
      uVar2 = uVar2 / 0xf7;
      if (param_3 == 4) {
        puVar5 = &DAT_00001308;
        goto LAB_010112bc;
      }
      if (param_3 == 2) {
        puVar5 = (undefined *)0x572;
        goto LAB_010112bc;
      }
      goto LAB_010112b8;
    }
    puVar8 = puVar6 + 0x4328;
    goto joined_r0x010114da;
  }
  uVar7 = param_1;
  if (0xf0 < param_1) {
    uVar7 = 0xf1;
  }
  if (param_3 == 8) {
    puVar8 = puVar8 + (uVar7 + 0x13 & 0xffff) * 0x40 + 400;
    if (0xd9 < param_1) {
      param_2 = &DAT_000043da;
      uVar2 = param_1 - 0xd9 & 0xffff;
      uVar7 = ((uint)((ulonglong)uVar2 * 0x10953f391 >> 0x21) << 0x11) >> 0x18;
      puVar8 = puVar8 + uVar7 * 0x43da;
      uVar7 = uVar2 + uVar7 * -0xf7 & 0xffff;
      if (uVar7 == 0) goto LAB_01011264;
      iVar3 = 400;
      iVar1 = 0x40;
      iVar4 = (uVar7 + 8 & 0xffff) + 5;
      goto LAB_0101140c;
    }
    goto LAB_01011264;
  }
  if (param_3 == 4) {
    iVar3 = 0x17e;
    param_2 = &MemManage;
LAB_010115d0:
    puVar8 = puVar8 + (uVar7 + 0x13 & 0xffff) * (int)param_2 + iVar3;
    if (param_1 < 0xda) goto LAB_01011264;
    uVar2 = param_1 - 0xd9 & 0xffff;
    uVar7 = ((uint)((ulonglong)uVar2 * 0x10953f391 >> 0x21) << 0x11) >> 0x18;
    if (param_3 == 4) {
      param_2 = &DAT_00001308;
      puVar8 = puVar8 + uVar7 * 0x1308;
      uVar7 = uVar2 + uVar7 * -0xf7 & 0xffff;
      if (uVar7 == 0) goto LAB_01011264;
      iVar3 = 0x17e;
      iVar1 = 0x10;
      iVar4 = (uVar7 + 8 & 0xffff) + 5;
      goto LAB_0101140c;
    }
    if (param_3 == 2) {
      param_2 = &UNK_00000572;
      puVar8 = puVar8 + uVar7 * 0x572;
      uVar7 = uVar2 + uVar7 * -0xf7 & 0xffff;
      if (uVar7 != 0) {
        iVar3 = 0x18;
        iVar1 = 4;
        iVar4 = (uVar7 + 8 & 0xffff) + 5;
        goto LAB_0101140c;
      }
      goto LAB_01011264;
    }
  }
  else {
    if (param_3 == 2) {
      iVar3 = 0x18;
      param_2 = &Reset;
      goto LAB_010115d0;
    }
    puVar8 = puVar8 + (uVar7 + 0x13 & 0xffff) * 8 + 0x28;
    if (param_1 < 0xda) goto LAB_01011264;
    uVar2 = param_1 - 0xd9 & 0xffff;
    uVar7 = ((uint)((ulonglong)uVar2 * 0x10953f391 >> 0x21) << 0x11) >> 0x18;
  }
  param_2 = &UNK_00000992;
  puVar8 = puVar8 + uVar7 * 0x992;
  uVar7 = uVar2 + uVar7 * -0xf7 & 0xffff;
  if (uVar7 != 0) {
    iVar3 = 0x28;
    iVar1 = 8;
    iVar4 = (uVar7 + 8 & 0xffff) + 5;
LAB_0101140c:
    return CONCAT44(iVar1,puVar8 + iVar4 * iVar1 + iVar3 + 0x14a);
  }
LAB_01011264:
  return CONCAT44(param_2,puVar8);
}


