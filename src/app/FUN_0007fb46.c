/*
 * Function: FUN_0007fb46
 * Entry:    0007fb46
 * Prototype: undefined4 __stdcall FUN_0007fb46(undefined4 * param_1, byte * param_2)
 */


undefined4 FUN_0007fb46(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (byte *)0x0)) {
    uVar4 = 7;
  }
  else {
    bVar1 = *param_2;
    *param_2 = bVar1 & 0x7f | 0x40;
    param_2[0x18] = 0;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    param_2[0x1b] = 0;
    pbVar2 = (byte *)*param_1;
    if ((byte *)*param_1 == (byte *)0x0) {
      *param_2 = bVar1 & 0x7f | 0xc0;
      *param_1 = param_2;
    }
    else {
      do {
        pbVar5 = pbVar2;
        pbVar2 = *(byte **)(pbVar5 + 0x18);
      } while (*(byte **)(pbVar5 + 0x18) != (byte *)0x0);
      *(byte **)(pbVar5 + 0x18) = param_2;
      *pbVar5 = *pbVar5 & 0xbf;
    }
    iVar3 = __read_block(param_2);
    uVar4 = 0;
    param_1[1] = param_1[1] + iVar3;
    param_1[2] = param_1[2] + 1;
  }
  return uVar4;
}


