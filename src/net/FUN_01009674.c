/*
 * Function: FUN_01009674
 * Entry:    01009674
 * Prototype: int __stdcall FUN_01009674(int param_1, int param_2, ushort * param_3)
 */


int FUN_01009674(int param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  int iVar9;
  
  if (param_1 != 0) {
LAB_010096ca:
    return -0x2d;
  }
  if (DAT_21000a5c != '\0') {
    return -1;
  }
  bVar2 = DAT_21000a32;
  bVar3 = DAT_21000a33;
  bVar4 = DAT_21000a39;
  bVar5 = DAT_21000a3e;
  bVar6 = DAT_21000a3f;
  cVar7 = DAT_21000a44;
  bVar8 = DAT_21000a46;
  if (param_2 == 0) goto LAB_010096b4;
  if (param_3 == (ushort *)0x0) {
    return -0x16;
  }
  switch(param_2) {
  case 1:
    DAT_21000a30 = (undefined1)*param_3;
    break;
  case 2:
    DAT_21000a31 = (undefined1)*param_3;
    break;
  case 3:
    if ((char)param_3[1] == '\0') {
      return -0x16;
    }
    if (*(char *)((int)param_3 + 3) == '\0') {
      return -0x16;
    }
    if ((byte)*param_3 < 0x1b) {
      return -0x16;
    }
    if (*(byte *)((int)param_3 + 1) < 0x1b) {
      return -0x16;
    }
    DAT_21000a35 = *(undefined4 *)param_3;
    break;
  case 4:
    bVar2 = (byte)*param_3;
    if ((byte)*param_3 < DAT_21000a33) {
      return -0x16;
    }
    break;
  case 5:
    bVar4 = (byte)*param_3;
    if ((DAT_21000a4f != '\0') && (bVar4 < 2)) {
      return -0x16;
    }
    break;
  case 6:
    DAT_21000a3a = *param_3;
    break;
  case 7:
    if (0xff < *param_3) {
      return -0x16;
    }
    DAT_21000a3c = (undefined1)*param_3;
    break;
  case 8:
    bVar3 = (byte)*param_3;
    bVar1 = bVar3;
    goto joined_r0x01009710;
  case 9:
    DAT_21000a34 = (undefined1)*param_3;
    break;
  case 10:
    if (DAT_21000a4e == '\0') {
      if ((byte)*param_3 < 2) {
        return -0x16;
      }
    }
    else if ((byte)*param_3 == 0) {
      return -0x16;
    }
    DAT_21000a3d = (undefined1)*param_3;
    break;
  case 0xb:
    bVar5 = (byte)*param_3;
    if (8 < (byte)*param_3) {
      return -0x16;
    }
    break;
  case 0xc:
    bVar6 = (byte)*param_3;
    bVar1 = (byte)*param_3;
joined_r0x01009710:
    if (DAT_21000a32 < bVar1) {
      return -0x16;
    }
    break;
  case 0xd:
    if ((char)*param_3 == '\0') {
      return -0x16;
    }
    if (0xf8 < (byte)(*(char *)((int)param_3 + 1) - 1U)) {
      return -0x16;
    }
    DAT_21000a40 = *param_3;
    DAT_21000a42 = (undefined1)param_3[1];
    break;
  case 0xe:
    DAT_21000a43 = (undefined1)*param_3;
    FUN_010203bc(DAT_21000a43);
    bVar2 = DAT_21000a32;
    bVar3 = DAT_21000a33;
    bVar4 = DAT_21000a39;
    bVar5 = DAT_21000a3e;
    bVar6 = DAT_21000a3f;
    cVar7 = DAT_21000a44;
    bVar8 = DAT_21000a46;
    break;
  case 0xf:
    cVar7 = (char)*param_3;
    if ((char)*param_3 == '\0') {
      return -0x16;
    }
    break;
  case 0x10:
    DAT_21000a45 = (undefined1)*param_3;
    break;
  case 0x11:
    bVar8 = (byte)*param_3;
    if (0xe < (byte)*param_3) {
      return -0x16;
    }
    break;
  case 0x12:
    DAT_21000a47 = (undefined1)*param_3;
    break;
  case 0x13:
    DAT_21000a48 = (undefined1)*param_3;
    break;
  case 0x14:
    DAT_21000a49 = (undefined1)*param_3;
    break;
  case 0x15:
    DAT_21000a4a = (undefined1)*param_3;
    break;
  case 0x16:
    DAT_21000a4b = *param_3;
    break;
  default:
    goto LAB_010096ca;
  }
LAB_010096b4:
  DAT_21000a46 = bVar8;
  DAT_21000a44 = cVar7;
  DAT_21000a3f = bVar6;
  DAT_21000a3e = bVar5;
  DAT_21000a39 = bVar4;
  DAT_21000a33 = bVar3;
  DAT_21000a32 = bVar2;
  iVar9 = FUN_01009258(0,1);
  if (iVar9 < 0x10000) {
    DAT_21000a5d = 1;
  }
  else {
    iVar9 = -0xc;
  }
  return iVar9;
}


