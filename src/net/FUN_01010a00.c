/*
 * Function: FUN_01010a00
 * Entry:    01010a00
 * Prototype: undefined4 __stdcall FUN_01010a00(char * param_1)
 */


undefined4 FUN_01010a00(char *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (*param_1 == '\0') {
    uVar1 = FUN_0100dbc0(iVar2 + 0xa8,0,(uint)*(byte *)(iVar2 + 0xc6),0);
    if (uVar1 != 0) {
      *(undefined2 *)(iVar2 + 0x102) = 0;
      *(undefined1 *)(iVar2 + 0x104) = 1;
      *(undefined1 *)(iVar2 + 0xc6) = 2;
      return 0;
    }
  }
  else if ((*(uint *)(iVar2 + 0xb4) & 4) == 0) {
    FUN_0100ff98((int)param_1);
    *(uint *)(iVar2 + 0xb4) = *(uint *)(iVar2 + 0xb4) | 4;
    return 0;
  }
  return 1;
}


