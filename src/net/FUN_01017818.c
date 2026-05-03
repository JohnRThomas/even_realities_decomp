/*
 * Function: FUN_01017818
 * Entry:    01017818
 * Prototype: undefined * __stdcall FUN_01017818(undefined4 param_1, byte * param_2)
 */


undefined * FUN_01017818(undefined4 param_1,byte *param_2)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = FUN_010200d8();
  if (((((int)(uVar1 << 0x1d) < 0) || ((param_2[2] & 0xe0) != 0x40)) &&
      ((uVar1 = FUN_010200d8(), (int)(uVar1 << 0x1e) < 0 || ((param_2[2] & 0xe0) != 0x20)))) &&
     ((*param_2 & 0x3f) < 0x25)) {
    uVar1 = FUN_01020aa8();
    if ((char)*param_2 < '\0') {
      iVar4 = 300;
    }
    else {
      iVar4 = 0x1e;
    }
    uVar3 = iVar4 * ((uint)param_2[1] | (param_2[2] & 0x1f) << 8);
    if ((0x10d < uVar3 - uVar1) && (uVar1 <= uVar3)) {
      DAT_2100104a = *(undefined2 *)param_2;
      DAT_2100104c = param_2[2];
      puVar2 = FUN_0101b95c(param_1);
      return puVar2;
    }
  }
  return (undefined *)0x0;
}


