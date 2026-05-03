/*
 * Function: FUN_01010784
 * Entry:    01010784
 * Prototype: undefined4 __stdcall FUN_01010784(char * param_1, int param_2)
 */


undefined4 FUN_01010784(char *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*param_1 == '\0') {
    iVar3 = *(int *)(param_1 + 4);
    uVar1 = FUN_0100dbc0(iVar3 + 0xa8,0,(uint)*(byte *)(iVar3 + 0xc6),0);
    if (uVar1 != 0) {
      uVar1 = *(uint *)(param_2 + 4);
      uVar2 = *(uint *)(param_2 + 8);
      *(undefined2 *)(iVar3 + 0x102) = 0;
      *(uint *)(iVar3 + 0x116) = uVar1 & 0xf704492f;
      *(undefined1 *)(iVar3 + 0x104) = 1;
      *(undefined1 *)(iVar3 + 0xc6) = 4;
      *(byte *)(iVar3 + 0x119) = *(byte *)(iVar3 + 0x119) | 8;
      *(uint *)(iVar3 + 0x11a) = uVar2 & 0x1807;
      return 0;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 4);
    if ((*(uint *)(iVar3 + 0xb4) & 1) == 0) {
      uVar2 = *(uint *)(param_2 + 4);
      uVar1 = *(uint *)(param_2 + 8);
      *(uint *)(iVar3 + 0xb4) = *(uint *)(iVar3 + 0xb4) | 1;
      *(undefined2 *)(iVar3 + 0x102) = 0;
      *(char *)(iVar3 + 0x104) = *(char *)(iVar3 + 0x104) + '\x01';
      *(uint *)(iVar3 + 0x116) = uVar2 & 0xf704492f;
      *(byte *)(iVar3 + 0x119) = *(byte *)(iVar3 + 0x119) | 8;
      *(uint *)(iVar3 + 0x11a) = uVar1 & 0x1807;
      return 0;
    }
  }
  return 1;
}


