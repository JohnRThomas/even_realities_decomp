/*
 * Function: _strtol_l
 * Entry:    0007acd0
 * Prototype: long __stdcall _strtol_l(void * rptr, char * nptr, char * * endptr, int base, locale_t loc)
 */


/* exclude_from_export */

long _strtol_l(void *rptr,char *nptr,char **endptr,int base,locale_t loc)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if ((36 < (uint)base) || (pbVar6 = (byte *)nptr, base == 1)) {
    piVar1 = __errno();
    *piVar1 = 22;
    return 0;
  }
  do {
    pbVar5 = pbVar6;
    pbVar6 = pbVar5 + 1;
    uVar4 = (uint)*pbVar5;
    uVar7 = (byte)(&DAT_000f6aa2)[uVar4] & 8;
  } while (((&DAT_000f6aa2)[uVar4] & 8) != 0);
  if (uVar4 == 0x2d) {
    uVar4 = (uint)*pbVar6;
    uVar7 = 1;
    pbVar6 = pbVar5 + 2;
  }
  else if (uVar4 == 0x2b) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = pbVar5 + 2;
  }
  if (base == 0) {
    if (uVar4 != L'0') {
      base = 10;
      goto LAB_0007ad12;
    }
    if ((*pbVar6 & 0xdf) != 'X') {
      base = 8;
      goto LAB_0007ad12;
    }
  }
  else if (((base != 0x10) || (uVar4 != L'0')) || ((*pbVar6 & 0xdf) != 'X')) goto LAB_0007ad12;
  uVar4 = (uint)pbVar6[1];
  base = 0x10;
  pbVar6 = pbVar6 + 2;
LAB_0007ad12:
  iVar3 = 0;
  uVar10 = uVar7 + 0x7fffffff;
  uVar2 = 0;
  uVar9 = uVar10 / (uint)base;
  do {
    uVar8 = uVar4 - 0x30;
    if (9 < uVar8) {
      if (uVar4 - L'A' < 0x1a) {
        uVar8 = uVar4 - L'7';
      }
      else {
        if (0x19 < uVar4 - 0x61) break;
        uVar8 = uVar4 - 0x57;
      }
    }
    if (base <= (int)uVar8) break;
    if (iVar3 != -1) {
      if ((uVar9 < uVar2) || ((uVar9 == uVar2 && ((int)(uVar10 - base * uVar9) < (int)uVar8)))) {
        iVar3 = -1;
      }
      else {
        uVar2 = uVar2 * base + uVar8;
        iVar3 = 1;
      }
    }
    uVar4 = (uint)*pbVar6;
    pbVar6 = pbVar6 + 1;
  } while( true );
  if (iVar3 == -1) {
    *(undefined4 *)rptr = 0x22;
    uVar2 = uVar10;
    if (endptr == (char **)0x0) {
      return uVar10;
    }
  }
  else {
    if (uVar7 != 0) {
      uVar2 = -uVar2;
    }
    if (endptr == (char **)0x0) {
      return uVar2;
    }
    if (iVar3 == 0) goto LAB_0007adc2;
  }
  nptr = (char *)(pbVar6 + -1);
LAB_0007adc2:
  *endptr = nptr;
  return uVar2;
}


