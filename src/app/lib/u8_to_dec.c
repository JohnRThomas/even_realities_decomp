/*
 * Function: u8_to_dec
 * Entry:    000813e2
 * Prototype: uint8_t __stdcall u8_to_dec(char * buf, uint8_t buflen, uint8_t value)
 */


/* exclude_from_export */

uint8_t u8_to_dec(char *buf,uint8_t buflen,uint8_t value)

{
  int iVar1;
  uint8_t uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 100;
  iVar5 = 4;
  uVar2 = '\0';
  do {
    uVar3 = (uint)value;
    if (buflen == '\0') {
      return uVar2;
    }
    while( true ) {
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) {
        *buf = '\0';
        return uVar2;
      }
      if (((uVar4 <= uVar3) || (uVar4 == 1)) || (uVar2 != '\0')) break;
      iVar1 = uVar4 * (uVar3 / uVar4);
      uVar4 = uVar4 / 10;
      uVar3 = uVar3 - iVar1 & 0xff;
    }
    *buf = (char)(uVar3 / uVar4) + '0';
    value = (char)uVar3 - (char)uVar4 * (char)(uVar3 / uVar4);
    uVar4 = uVar4 / 10;
    buflen = buflen + 0xff;
    uVar2 = uVar2 + '\x01';
    buf = buf + 1;
  } while( true );
}


