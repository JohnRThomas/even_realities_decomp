/*
 * Function: char2hex
 * Entry:    00081472
 * Prototype: int __stdcall char2hex(char c, uint8_t * x)
 */


/* exclude_from_export_ai */

int char2hex(char c,uint8_t *x)

{
  char cVar1;
  uint8_t uVar2;
  int iVar3;
  
  iVar3 = (int)c;
  uVar2 = (uint8_t)(iVar3 - 0x30U);
  if (9 < (iVar3 - 0x30U & 0xff)) {
    if (iVar3 - 0x61U < 6) {
      cVar1 = -0x57;
    }
    else {
      if (5 < iVar3 - 0x41U) {
        return -0x16;
      }
      cVar1 = -0x37;
    }
    uVar2 = c + cVar1;
  }
  *x = uVar2;
  return 0;
}


