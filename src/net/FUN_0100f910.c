/*
 * Function: FUN_0100f910
 * Entry:    0100f910
 * Prototype: undefined __stdcall FUN_0100f910(int param_1, int param_2, byte * param_3, int param_4)
 */


void FUN_0100f910(int param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar5 = *(ushort *)(param_2 + 4);
  uVar4 = *(ushort *)(param_2 + 8);
  if ((*(byte *)(param_1 + 0x6e) & 0xc) == 0) {
    if (param_4 == 0) {
      bVar1 = *(byte *)(param_1 + 0x6f);
    }
    else {
      if (((*param_3 & 0xc) != 0) && (uVar5 < 0xa90)) {
        uVar5 = 0xa90;
      }
      if ((*(byte *)(param_1 + 0x6f) & 0xc) != 0) goto LAB_0100f94a;
      bVar1 = param_3[1];
    }
joined_r0x0100f994:
    if ((bVar1 & 0xc) == 0) goto LAB_0100f954;
  }
  else {
    if (uVar5 < 0xa90) {
      uVar5 = 0xa90;
    }
    if ((*(byte *)(param_1 + 0x6f) & 0xc) == 0) {
      if (param_4 == 0) goto LAB_0100f954;
      bVar1 = param_3[1];
      goto joined_r0x0100f994;
    }
  }
LAB_0100f94a:
  if (uVar4 < 0xa90) {
    uVar4 = 0xa90;
  }
LAB_0100f954:
  uVar2 = *(undefined2 *)(param_2 + 6);
  uVar3 = *(undefined2 *)(param_2 + 2);
  *(ushort *)(param_1 + 0x4e) = uVar5;
  *(undefined2 *)(param_1 + 0x4c) = uVar3;
  *(undefined2 *)(param_1 + 0x50) = uVar2;
  *(ushort *)(param_1 + 0x52) = uVar4;
  return;
}


