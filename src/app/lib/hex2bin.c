/*
 * Function: hex2bin
 * Entry:    000814a2
 * Prototype: size_t __stdcall hex2bin(char * hex, size_t hexlen, uint8_t * buf, size_t buflen)
 */


/* exclude_from_export_ai */

size_t hex2bin(char *hex,size_t hexlen,uint8_t *buf,size_t buflen)

{
  int iVar1;
  uint8_t *x;
  undefined1 *extraout_r2;
  char *extraout_r2_00;
  char *extraout_r2_01;
  char cVar2;
  char *pcVar3;
  size_t sVar4;
  uint8_t *puVar5;
  undefined4 uStack_1c;
  uint8_t *puStack_18;
  
  sVar4 = (hexlen & 1) + (hexlen >> 1);
  if (buflen < sVar4) {
LAB_000814b6:
    sVar4 = 0;
  }
  else {
    uStack_1c = hexlen;
    puStack_18 = buf;
    if ((hexlen & 1) != 0) {
      iVar1 = char2hex(*hex,(uint8_t *)((int)&uStack_1c + 3));
      if (iVar1 < 0) goto LAB_000814b6;
      hex = hex + 1;
      buf = extraout_r2 + 1;
      *extraout_r2 = uStack_1c._3_1_;
    }
    puVar5 = buf + (hexlen >> 1);
    pcVar3 = hex + 1;
    while (buf != puVar5) {
      iVar1 = char2hex(pcVar3[-1],(uint8_t *)((int)&uStack_1c + 3));
      if (iVar1 < 0) goto LAB_000814b6;
      cVar2 = uStack_1c._3_1_ * '\x10';
      *extraout_r2_00 = cVar2;
      iVar1 = char2hex(*pcVar3,x);
      if (iVar1 < 0) goto LAB_000814b6;
      *extraout_r2_01 = cVar2 + uStack_1c._3_1_;
      pcVar3 = pcVar3 + 2;
      buf = (uint8_t *)(extraout_r2_01 + 1);
    }
  }
  return sVar4;
}


