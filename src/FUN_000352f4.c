/*
 * Function: FUN_000352f4
 * Entry:    000352f4
 * Prototype: uint __stdcall FUN_000352f4(void)
 */


uint FUN_000352f4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0;
  puVar2 = &DAT_2000878c;
  do {
    if (*(char *)(puVar2 + 4) == '\0') {
      return uVar1 & 0xff;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 0x6d;
  } while (uVar1 != 10);
  return 10;
}


