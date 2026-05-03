/*
 * Function: FUN_010358cc
 * Entry:    010358cc
 * Prototype: undefined4 __stdcall FUN_010358cc(undefined4 param_1, byte * param_2, undefined4 * param_3)
 */


undefined4 FUN_010358cc(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_21004b1c;
  while( true ) {
    if ((undefined4 **)puVar2 == &DAT_21004b1c) {
      return 0xffffffed;
    }
    iVar1 = FUN_0102aa44((byte *)puVar2[-0x11],param_2);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  *param_3 = puVar2 + -0x11;
  return 0;
}


