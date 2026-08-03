/*
 * Function: parse_hex4
 * Entry:    0008864a
 * Prototype: uint __stdcall parse_hex4(uchar * input)
 */


/* exclude_from_export_ai */

uint parse_hex4(uchar *input)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  while( true ) {
    uVar3 = (uint)input[iVar1];
    if (uVar3 - 0x30 < 10) {
      iVar2 = iVar2 + -0x30;
    }
    else if (uVar3 - 0x41 < 6) {
      iVar2 = iVar2 + -0x37;
    }
    else {
      if (5 < uVar3 - 0x61) {
        return 0;
      }
      iVar2 = iVar2 + -0x57;
    }
    if (iVar1 == 3) break;
    iVar2 = (uVar3 + iVar2) * 0x10;
    iVar1 = iVar1 + 1;
  }
  return uVar3 + iVar2;
}


