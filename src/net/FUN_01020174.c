/*
 * Function: FUN_01020174
 * Entry:    01020174
 * Prototype: undefined __stdcall FUN_01020174(int param_1)
 */


void FUN_01020174(int param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint extraout_r1;
  undefined4 *puVar5;
  undefined4 in_r2;
  int iVar6;
  
  puVar2 = *(undefined2 **)(param_1 + 4);
  puVar2[0xff] = *puVar2;
  puVar3 = (undefined4 *)((int)puVar2 + 0x1f5);
  puVar2[0x100] = puVar2[0x33];
  if (*(byte *)((int)puVar2 + 0x1fd) != 0) {
    FUN_0100f3b8(puVar3,0x1029e75,in_r2,(uint)*(byte *)((int)puVar2 + 0x1fd));
    uVar4 = extraout_r1;
    while( true ) {
      puVar3 = (undefined4 *)(uVar4 >> 0x1b);
      uVar4 = 0;
      if (*(char *)(puVar3 + 2) == '\0') break;
      *(undefined1 *)(puVar3 + 2) = 3;
    }
    puVar3[1] = 0;
    *(undefined1 *)(puVar3 + 2) = 3;
    iVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *puVar3 = &DAT_21000ed0;
    uVar4 = 0;
    if ((DAT_21000ed0 == 0) ||
       (uVar4 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar5 = &DAT_21000ed0, uVar4 != 1)) {
      puVar5 = DAT_21000ecc;
    }
    *puVar5 = puVar3;
    if (iVar6 == 0) {
      enableIRQinterrupts();
    }
    DAT_21000ecc = puVar3;
    FUN_0102603c((uint)DAT_21000ec8,uVar4,puVar5,0x21000ec8);
    return;
  }
  *(undefined4 *)((int)puVar2 + 0x1f9) = 0x1029e75;
  *(undefined1 *)((int)puVar2 + 0x1fd) = 3;
  iVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *puVar3 = &DAT_21000ed0;
  uVar4 = 0;
  if ((DAT_21000ed0 == 0) ||
     (uVar4 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar5 = &DAT_21000ed0, uVar4 != 1)) {
    puVar5 = DAT_21000ecc;
  }
  *puVar5 = puVar3;
  if (iVar6 == 0) {
    enableIRQinterrupts();
  }
  DAT_21000ecc = puVar3;
  FUN_0102603c((uint)DAT_21000ec8,uVar4,puVar5,0x21000ec8);
  return;
}


