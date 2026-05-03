/*
 * Function: FUN_01018150
 * Entry:    01018150
 * Prototype: uint __stdcall FUN_01018150(void)
 */


uint FUN_01018150(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar1;
  puVar2 = (undefined *)FUN_01029dd6((ushort *)&DAT_21001014,0);
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    puVar2 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 1;
  DAT_2100104c = 0;
  puVar2 = FUN_0101bcf4(puVar2);
  return (uint)puVar2;
}


