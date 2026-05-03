/*
 * Function: FUN_01010bc4
 * Entry:    01010bc4
 * Prototype: undefined __stdcall FUN_01010bc4(byte * param_1)
 */


void FUN_01010bc4(byte *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar8 = *(int *)(param_1 + 4);
    iVar7 = iVar8 + 0xa8;
    iVar9 = iVar8 + 0x160;
    if ((int)((uint)*(byte *)(iVar8 + 0x107) << 0x1e) < 0) {
      uVar3 = FUN_0100dbc0(iVar7,0,(uint)*(byte *)(iVar8 + 0xc6),0);
      if (uVar3 != 0) {
        *(byte *)(iVar8 + 0x104) = bVar1;
        *(undefined1 *)(iVar8 + 0x172) = 0;
        return;
      }
      goto LAB_01010c28;
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 4);
    iVar9 = iVar7 + 0x160;
    if ((int)((uint)*(byte *)(iVar7 + 0x107) << 0x1e) < 0) {
      uVar3 = *(uint *)(iVar7 + 0xb4);
      if (-1 < (int)(uVar3 << 0x1e)) {
LAB_01010c28:
        *(undefined1 *)(iVar9 + 0x12) = 0;
        return;
      }
      cVar2 = *(char *)(iVar7 + 0x104) + -1;
      *(char *)(iVar7 + 0x104) = cVar2;
      if (-1 < cVar2) {
        *(uint *)(iVar7 + 0xb4) = uVar3 & 0xfffffffd;
        goto LAB_01010c28;
      }
      FUN_01009500(0x40,0x81,(int)cVar2,uVar3);
      uVar5 = extraout_r2_00;
      uVar6 = extraout_r3_00;
      goto LAB_01010c56;
    }
    iVar7 = iVar7 + 0xa8;
  }
  uVar3 = FUN_0100dbc0(iVar7,0,(uint)*(byte *)(iVar7 + 0x1d),(uint)bVar1);
  uVar5 = extraout_r2;
  uVar6 = extraout_r3;
  if (uVar3 != 0) {
    *(undefined1 *)(iVar7 + 0x1d) = 1;
    *(undefined1 *)(iVar7 + 0x58) = 1;
    *(undefined2 *)(iVar7 + 0x54) = 0;
    return;
  }
LAB_01010c56:
  uVar10 = FUN_01009500(0x40,0x6f,uVar5,uVar6);
  puVar4 = (undefined1 *)((ulonglong)uVar10 >> 0x20);
  do {
    *puVar4 = 0x2e;
    *(undefined4 *)(puVar4 + 3) = *(undefined4 *)((int)uVar10 + 9);
  } while( true );
}


