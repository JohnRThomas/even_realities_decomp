/*
 * Function: FUN_010103bc
 * Entry:    010103bc
 * Prototype: undefined4 __stdcall FUN_010103bc(int param_1, int param_2)
 */


undefined4 FUN_010103bc(int param_1,int param_2)

{
  bool bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  int iVar9;
  
  uVar6 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       0);
  if (uVar6 == 0) {
    return 1;
  }
  bVar1 = FUN_0100efe0(param_2);
  if (!bVar1) {
    uVar7 = FUN_0101006c(param_1,param_2);
    return uVar7;
  }
  iVar9 = *(int *)(param_1 + 4);
  uVar2 = FUN_0100efd8(param_2);
  uVar3 = FUN_0100efd0(param_2);
  uVar4 = FUN_0100efdc(param_2);
  uVar5 = FUN_0100efd4(param_2);
  FUN_0100f998(iVar9 + 0x30,uVar2,uVar3,uVar4,uVar5);
  puVar8 = *(undefined2 **)(param_1 + 4);
  if (*(char *)((int)puVar8 + 0xc5) == '\x1e') {
    *(undefined1 *)(puVar8 + 0x32) = 1;
  }
  else if (((*(char *)(puVar8 + 0x32) != '\x01') && (*(char *)((int)puVar8 + 0x163) == '\0')) &&
          (*(char *)(puVar8 + 0xb1) == '\0')) {
    *(undefined1 *)(puVar8 + 99) = 0x1f;
    FUN_0100fad0(*puVar8,(int)(puVar8 + 0x18),(undefined4 *)(puVar8 + 0xf1));
    puVar8 = *(undefined2 **)(param_1 + 4);
    goto LAB_0101043a;
  }
  *(undefined1 *)(puVar8 + 99) = 0x20;
LAB_0101043a:
  puVar8[0x81] = 0;
  *(undefined1 *)(puVar8 + 0x82) = 1;
  return 0;
}


