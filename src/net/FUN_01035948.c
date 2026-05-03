/*
 * Function: FUN_01035948
 * Entry:    01035948
 * Prototype: undefined4 __stdcall FUN_01035948(byte * param_1, undefined4 * param_2)
 */


undefined4 FUN_01035948(byte *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_21004b0c;
  while( true ) {
    if ((undefined4 **)puVar2 == &DAT_21004b0c) {
      return 0xfffffffe;
    }
    iVar1 = FUN_0102aa44((byte *)puVar2[-9],param_1);
    if ((iVar1 == 0) && (param_2 != (undefined4 *)0x0)) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  *param_2 = puVar2 + -9;
  return 0;
}


