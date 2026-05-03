/*
 * Function: FUN_0100b7f4
 * Entry:    0100b7f4
 * Prototype: undefined4 __stdcall FUN_0100b7f4(int param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0100b7f4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint extraout_r2;
  uint extraout_r2_00;
  int extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar6;
  
  bVar1 = DAT_21000c8c;
  iVar3 = DAT_21000c70;
  uVar5 = (uint)DAT_21000c8c;
  uVar6 = (uint)DAT_21000c8c;
  if (uVar5 != 1) goto LAB_0100b902;
  if (*(char *)(DAT_21000c70 + 0xb8) != '\0') {
    DAT_21000c7a = DAT_21000c7a | 4;
    *(undefined1 *)(DAT_21000c70 + 0xb8) = 0;
    (*DAT_21000c7c)(4);
    if ((char)DAT_21000c6c != '\0') {
      *(byte *)(iVar3 + 0xba) = bVar1;
    }
  }
  if ((*DAT_21000cc4 & 3) == 3) {
    if (*(char *)(iVar3 + 0xbe) == '\0') {
      DAT_21000c7a = DAT_21000c7a | 2;
      (*DAT_21000c7c)(2);
      if ((*DAT_21000cc4 & 3) != 3) goto LAB_0100b83e;
    }
    *(undefined1 *)(iVar3 + 0xbe) = 3;
  }
  else {
LAB_0100b83e:
    if (DAT_21000cc4[1] == 0) {
      *(undefined1 *)(iVar3 + 0xbe) = 1;
    }
    else {
      *(undefined1 *)(iVar3 + 0xbe) = 2;
    }
  }
  if (*(char *)(iVar3 + 0xcb) != '\0') {
    DAT_21000ce8 = (char)DAT_21000c6c != '\0';
    DAT_21000ce0 = *(undefined4 *)(iVar3 + 0x128);
    DAT_21000ce4 = *(undefined4 *)(iVar3 + 300);
    switch(*(undefined1 *)(DAT_21000c70 + 0x6f)) {
    case 1:
      uVar6 = 0;
      break;
    case 2:
      break;
    default:
      FUN_01009500(6,0x3c5,(uint)DAT_21000cc2,DAT_21000ce4);
      uVar5 = extraout_r2;
      param_4 = extraout_r3;
LAB_0100b902:
      FUN_01009500(0x27,0x46e,uVar5,param_4);
      DAT_21000050 = &PTR_FUN_0100b710_1_0100c21c;
      if (DAT_21000c8c == 0) {
        DAT_21000c60 = DAT_21000c8c;
        uVar4 = FUN_0100eddc(&DAT_21000c90,1);
        DAT_21000d00 = extraout_r2_00 >> 0x13;
        DAT_21000ccc = 0;
        return uVar4;
      }
      FUN_01009500(0x27,0xde,&PTR_FUN_0100b710_1_0100c21c,(uint)DAT_21000c8c);
      *(int *)extraout_r2_01 = extraout_r2_01;
      *(undefined4 *)(extraout_r2_01 + 4) = extraout_r3_00;
      *(undefined4 **)(extraout_r2_01 + 8) = &DAT_21000c48;
      if (DAT_21000c8c == 0) {
        DAT_21000c60 = DAT_21000c8c;
        return 0;
      }
      return 0xc;
    case 4:
      uVar6 = 3;
      break;
    case 8:
      uVar6 = 2;
    }
    FUN_010205d0(1,0x21000cd0,(uint)DAT_21000cc2,uVar6,0);
  }
  if ((((param_2 == 1) && (param_1 == 0)) && (iVar3 = (*DAT_21000d08)(0), iVar3 != 0)) &&
     ((DAT_21000c85 == '\0' && (bVar2 = FUN_0100b6ac(0), !bVar2)))) {
    uVar4 = FUN_0100b73c(0);
    return uVar4;
  }
  uVar4 = FUN_0100b434();
  return uVar4;
}


