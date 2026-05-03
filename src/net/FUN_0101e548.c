/*
 * Function: FUN_0101e548
 * Entry:    0101e548
 * Prototype: ulonglong __stdcall FUN_0101e548(uint param_1, int param_2)
 */


ulonglong FUN_0101e548(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(int *)(param_1 + 0x1c) = param_2;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x18) = DAT_2100113c;
    if (DAT_2100113c == 0) {
      DAT_2100113c = param_1;
      *(undefined4 *)(param_1 + 0xc) = 0;
      return (ulonglong)param_1;
    }
    *(uint *)(DAT_2100113c + 0x1c) = param_1;
    param_2 = *(int *)(param_1 + 0x1c);
    DAT_2100113c = param_1;
LAB_0101e55a:
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (param_2 == 0) goto LAB_0101e572;
  }
  else {
    iVar2 = *(int *)(param_2 + 0x18);
    *(uint *)(param_2 + 0x18) = param_1;
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 != 0) {
      *(uint *)(iVar2 + 0x1c) = param_1;
      param_2 = *(int *)(param_1 + 0x1c);
      goto LAB_0101e55a;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  uVar3 = *(uint *)(param_2 + 0xc);
  if (uVar3 != 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if (uVar3 < uVar1) {
      FUN_01009500(0x37,0x2c,uVar1,uVar3);
      return (ulonglong)DAT_2100113c;
    }
    *(uint *)(param_1 + 0xc) = uVar3 - uVar1;
  }
  *(undefined4 *)(param_2 + 0xc) = 0;
LAB_0101e572:
  return CONCAT44(param_2,param_1);
}


