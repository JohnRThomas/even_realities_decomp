/*
 * Function: FUN_0100e040
 * Entry:    0100e040
 * Prototype: undefined __stdcall FUN_0100e040(int param_1, byte * param_2)
 */


void FUN_0100e040(int param_1,byte *param_2)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if ((byte *)(param_1 + 1) != param_2) {
    *(undefined4 *)(param_1 + 1) = *(undefined4 *)param_2;
    *(byte *)(param_1 + 5) = param_2[4];
  }
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0x1f;
  pbVar3 = (byte *)(param_1 + 1);
  do {
    pbVar2 = pbVar3 + 1;
    iVar1 = FUN_0100fee8((uint)*pbVar3);
    pbVar3[5] = (byte)iVar1;
    *(byte *)(param_1 + 0xb) = (byte)iVar1 + *(char *)(param_1 + 0xb);
    pbVar3 = pbVar2;
  } while (pbVar2 != (byte *)(param_1 + 6));
  return;
}


