/*
 * Function: extract_specifier
 * Entry:    0004ee30
 * Prototype: char * __stdcall extract_specifier(uint param_1, uint param_2, byte * param_3, char * param_4, char * param_5)
 */


/* exclude_from_export_ai */

char * extract_specifier(uint param_1,uint param_2,byte *param_3,char *param_4,char *param_5)

{
  uint extraout_r0;
  uint extraout_r1;
  uint extraout_r2;
  byte bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  
  uVar2 = (uint)param_3[3];
  bVar1 = (&DAT_000f6aa2)[uVar2];
  if (uVar2 == 0x6f) {
    uVar2 = 8;
  }
  else {
    if (uVar2 < 0x70) {
      bVar4 = uVar2 == 0x58;
    }
    else {
      bVar4 = (uVar2 & 0xf7) == 0x70;
    }
    if (bVar4) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = 10;
    }
  }
  do {
    __aeabi_uldivmod(param_1,param_2,uVar2,0);
    cVar3 = (char)extraout_r2;
    if (extraout_r2 < 10) {
      cVar3 = cVar3 + '0';
    }
    else if ((bVar1 & 3) == 1) {
      cVar3 = cVar3 + '7';
    }
    else {
      cVar3 = cVar3 + 'W';
    }
    param_5 = param_5 + -1;
    *param_5 = cVar3;
  } while ((param_2 != 0 || param_2 < (uVar2 <= param_1)) &&
          (param_2 = extraout_r1, param_1 = extraout_r0, param_4 < param_5));
  if ((int)((uint)*param_3 << 0x1a) < 0) {
    if (uVar2 == 8) {
      bVar1 = param_3[2] | 8;
    }
    else {
      if (uVar2 != 0x10) {
        return param_5;
      }
      bVar1 = param_3[2] | 0x10;
    }
    param_3[2] = bVar1;
  }
  return param_5;
}


