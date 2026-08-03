/*
 * Function: extract_conversion
 * Entry:    0004ee04
 * Prototype: int __stdcall extract_conversion(undefined4 * param_1)
 */


/* exclude_from_export_ai */

int extract_conversion(undefined4 *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  pbVar2 = (byte *)*param_1;
  while( true ) {
    if (-1 < (int)((uint)(byte)(&DAT_000f6aa2)[*pbVar2] << 0x1d)) break;
    iVar1 = iVar1 * 10 + (uint)*pbVar2 + -0x30;
    pbVar2 = pbVar2 + 1;
  }
  *param_1 = pbVar2;
  return iVar1;
}


