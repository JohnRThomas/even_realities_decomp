/*
 * Function: FUN_01011988
 * Entry:    01011988
 * Prototype: undefined __stdcall FUN_01011988(uint param_1, int param_2, uint param_3)
 */


void FUN_01011988(uint param_1,int param_2,uint param_3)

{
  undefined2 uVar1;
  byte *pbVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  uVar4 = FUN_0100ddd0(*(uint *)(param_2 + 0x14));
  uVar1 = *(undefined2 *)(param_2 + 0x1e);
  *(undefined2 *)(param_1 + 0x9e) = *(undefined2 *)(param_2 + 0x1c);
  *(short *)(param_1 + 0x9c) = (short)uVar4;
  *(undefined2 *)(param_1 + 0xa0) = uVar1;
  *(undefined1 *)(param_1 + 0xa2) = *(undefined1 *)(param_2 + 0x2d8);
  if (((*(char *)(param_1 + 0x1a) == '\0') || (*(char *)(param_1 + 0x60) != '\x01')) ||
     ((*(byte *)(param_1 + 0x66) & 0xc0) != 0x40)) {
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x94) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x61);
    *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(param_1 + 0x65);
  }
  pbVar2 = DAT_21000f20;
  *(byte *)(param_1 + 0x89) = (byte)(((uint)*DAT_21000f20 << 0x19) >> 0x1f);
  if (param_3 == 0xff) {
    *(undefined4 *)(param_1 + 0x8a) = *(undefined4 *)(pbVar2 + 3);
    uVar1 = *(undefined2 *)(pbVar2 + 7);
    *(undefined4 *)(param_1 + 0x96) = 0;
    *(undefined2 *)(param_1 + 0x8e) = uVar1;
    *(undefined2 *)(param_1 + 0x9a) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x96) = *(undefined4 *)(pbVar2 + 3);
  *(undefined2 *)(param_1 + 0x9a) = *(undefined2 *)(pbVar2 + 7);
  iVar5 = FUN_0100d298(param_3,(undefined1 *)(param_1 + 0x89),(undefined4 *)(param_1 + 0x8a));
  if (iVar5 != 0) {
    *(byte *)(param_1 + 0x89) = *(byte *)(param_1 + 0x89) | 2;
    return;
  }
  FUN_01009500(0x2d,0xc4d,extraout_r2,extraout_r3);
  uVar4 = param_1 >> 0x1c;
  puVar6 = (undefined4 *)FUN_0100d268((uint)*(byte *)(uVar4 + 0x1b));
  if (((*(char *)(uVar4 + 0x1a) != '\0') && (puVar6 != (undefined4 *)0x0)) &&
     (cVar3 = FUN_0100c404((uint)*(byte *)(uVar4 + 0x1b)), cVar3 == '\0')) {
    *(undefined1 *)(uVar4 + 0x60) = 1;
    FUN_0100b314(puVar6,(undefined1 *)(uVar4 + 0x61),0);
    FUN_0100d3e4((undefined4 *)(uVar4 + 0x61),(uint)*(byte *)(uVar4 + 0x1b));
  }
  if ((((int)((uint)*(ushort *)(uVar4 + 2) << 0x1d) < 0) &&
      (puVar6 = (undefined4 *)FUN_0100d280((uint)*(byte *)(uVar4 + 0x1b)),
      puVar6 != (undefined4 *)0x0)) &&
     (cVar3 = FUN_0100c3ec((uint)*(byte *)(uVar4 + 0x1b)), cVar3 == '\0')) {
    *(undefined1 *)(uVar4 + 0x6e) = 1;
    FUN_0100b314(puVar6,(undefined1 *)(uVar4 + 0x6f),0);
    FUN_0100e828((int)DAT_21000f20,(undefined4 *)(uVar4 + 0x6f));
    FUN_0100e854(DAT_21000f20,'\x01');
    return;
  }
  return;
}


