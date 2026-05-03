/*
 * Function: FUN_01011a4c
 * Entry:    01011a4c
 * Prototype: undefined __stdcall FUN_01011a4c(int param_1, int param_2)
 */


void FUN_01011a4c(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_0100d268((uint)*(byte *)(param_1 + 0x1b));
  if (((*(char *)(param_1 + 0x1a) != '\0') && (puVar2 != (undefined4 *)0x0)) &&
     (cVar1 = FUN_0100c404((uint)*(byte *)(param_1 + 0x1b)), cVar1 == '\0')) {
    *(undefined1 *)(param_1 + 0x60) = 1;
    FUN_0100b314(puVar2,(undefined1 *)(param_1 + 0x61),param_2);
    FUN_0100d3e4((undefined4 *)(param_1 + 0x61),(uint)*(byte *)(param_1 + 0x1b));
  }
  if ((((int)((uint)*(ushort *)(param_1 + 2) << 0x1d) < 0) &&
      (puVar2 = (undefined4 *)FUN_0100d280((uint)*(byte *)(param_1 + 0x1b)),
      puVar2 != (undefined4 *)0x0)) &&
     (cVar1 = FUN_0100c3ec((uint)*(byte *)(param_1 + 0x1b)), cVar1 == '\0')) {
    *(undefined1 *)(param_1 + 0x6e) = 1;
    FUN_0100b314(puVar2,(undefined1 *)(param_1 + 0x6f),param_2);
    FUN_0100e828((int)DAT_21000f20,(undefined4 *)(param_1 + 0x6f));
    FUN_0100e854(DAT_21000f20,'\x01');
    return;
  }
  return;
}


