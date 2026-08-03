/*
 * Function: i2c_write_byte
 * Entry:    0007f922
 * Prototype: undefined4 __stdcall i2c_write_byte(byte * param_1, int * param_2)
 */


/* exclude_from_export_ai */

undefined4 i2c_write_byte(byte *param_1,int *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  byte extraout_r1;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if (((param_1 == (byte *)0x0) || (param_2 == (int *)0x0)) || ((byte *)*param_2 == (byte *)0x0)) {
    uVar2 = 7;
  }
  else if ((uint)param_2[1] < 7) {
    uVar2 = 1;
    param_2[1] = 7;
  }
  else {
    *(byte *)*param_2 = *param_1;
    *(byte *)(*param_2 + 1) = param_1[1];
    uVar3 = __i2c_read_byte((int)param_1);
    if (uVar3 < 0x100) {
      *(char *)(*param_2 + 2) = (char)uVar3;
      iVar5 = 3;
    }
    else {
      *(char *)(*param_2 + 2) = (char)(uVar3 >> 0x18);
      *(char *)(*param_2 + 3) = (char)(uVar3 >> 0x10);
      *(char *)(*param_2 + 4) = (char)(uVar3 >> 8);
      *(char *)(*param_2 + 5) = (char)uVar3;
      iVar5 = 6;
    }
    uVar2 = 0;
    iVar4 = (uint)*param_1 << 0x1c;
    bVar6 = iVar4 < 0;
    bVar1 = extraout_r1;
    if (bVar6) {
      bVar1 = param_1[2];
      iVar4 = *param_2;
    }
    if (bVar6) {
      *(byte *)(iVar4 + iVar5) = bVar1;
      iVar5 = iVar5 + 1;
    }
    param_2[1] = iVar5;
  }
  return uVar2;
}


