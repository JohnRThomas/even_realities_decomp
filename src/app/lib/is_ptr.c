/*
 * Function: is_ptr
 * Entry:    00081398
 * Prototype: bool __stdcall is_ptr(char * fmt, int n)
 */


/* exclude_from_export */

bool is_ptr(char *fmt,int n)

{
  bool bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  bVar1 = false;
  do {
    pbVar3 = (byte *)(fmt + 1);
    uVar2 = (uint)(byte)*fmt;
    if (uVar2 == 0) {
      return (bool)*fmt;
    }
    if (bVar1 != false) {
      if (iVar4 == n) {
        if (uVar2 == 0x70) {
          return bVar1;
        }
        if (uVar2 - 0x40 < 0x3b) {
          return false;
        }
      }
      else if (uVar2 - 0x40 < 0x3b) {
        uVar2 = (uint)(byte)fmt[1];
        iVar4 = iVar4 + 1;
        if (uVar2 == 0) {
          return (bool)fmt[1];
        }
        bVar1 = false;
        pbVar3 = (byte *)(fmt + 2);
      }
    }
    fmt = (char *)pbVar3;
    if (uVar2 == 0x25) {
      bVar1 = (bool)(bVar1 ^ 1);
    }
  } while( true );
}


