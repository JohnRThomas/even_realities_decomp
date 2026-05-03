/*
 * Function: FUN_0101096c
 * Entry:    0101096c
 * Prototype: undefined __stdcall FUN_0101096c(char * param_1)
 */


void FUN_0101096c(char *param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar7;
  undefined8 uVar8;
  
  if (*param_1 == '\0') {
    uVar2 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,
                         (uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),0);
    uVar5 = extraout_r2;
    uVar7 = extraout_r3;
    if (uVar2 != 0) {
      *(undefined1 *)(*(int *)(param_1 + 4) + 0x104) = 0;
      return;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 4);
    iVar6 = *(uint *)(iVar4 + 0xb4) << 0x1f;
    if (iVar6 < 0) {
      cVar1 = *(char *)(iVar4 + 0x104) + -1;
      *(char *)(iVar4 + 0x104) = cVar1;
      if (-1 < cVar1) {
        *(uint *)(iVar4 + 0xb4) = *(uint *)(iVar4 + 0xb4) & 0xfffffffe;
        return;
      }
      FUN_01009500(0x1c,0xb9,iVar4,(int)cVar1);
      iVar4 = extraout_r2_00;
      iVar6 = extraout_r3_00;
    }
    FUN_01009500(0x1c,0xb7,iVar4,iVar6);
    uVar5 = extraout_r2_01;
    uVar7 = extraout_r3_01;
  }
  uVar8 = FUN_01009500(0x1c,0xb2,uVar5,uVar7);
  puVar3 = (undefined1 *)((ulonglong)uVar8 >> 0x20);
  *puVar3 = 0xe;
  *(undefined2 *)(puVar3 + 2) = *(undefined2 *)((int)uVar8 + -0x1c5);
  return;
}


