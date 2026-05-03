/*
 * Function: FUN_0102e1d8
 * Entry:    0102e1d8
 * Prototype: undefined __stdcall FUN_0102e1d8(int param_1, byte * param_2, undefined4 param_3)
 */


void FUN_0102e1d8(int param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + 0xb0);
  pbVar3 = (byte *)(iVar5 + -0x15c);
  while( true ) {
    iVar1 = FUN_0102aa44(param_2,pbVar3);
    if (iVar1 == 0) {
      uVar2 = FUN_01035c7c((char *)(pbVar3 + -0x40),param_1,(char *)param_2,0xffffffff,param_3,
                           *(int *)(iVar5 + 0x10),&LAB_0103a94e_1);
      if (uVar2 != 0) {
        return;
      }
      *(undefined1 *)(iVar4 * 0x70 + iVar5 + -0x138) = 1;
      if (*(code **)(iVar5 + 0xc) != (code *)0x0) {
        (**(code **)(iVar5 + 0xc))(pbVar3 + -0x40);
      }
    }
    pbVar3 = pbVar3 + 0x70;
    if (iVar4 != 0) break;
    iVar4 = 1;
  }
  return;
}


