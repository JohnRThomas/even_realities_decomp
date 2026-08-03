/*
 * Function: _strtoul_l
 * Entry:    0007ade0
 * Prototype: ulong __stdcall _strtoul_l(void * rptr, char * nptr, char * * endptr, int base, locale_t loc)
 */


/* exclude_from_export */

ulong _strtoul_l(void *rptr,char *nptr,char **endptr,int base,locale_t loc)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  pbVar4 = (byte *)nptr;
  do {
    pbVar3 = pbVar4;
    pbVar4 = pbVar3 + 1;
    uVar2 = (uint)*pbVar3;
    bVar6 = (&DAT_000f6aa2)[uVar2] & 8;
  } while (((&DAT_000f6aa2)[uVar2] & 8) != 0);
  if (uVar2 == L'-') {
    uVar2 = (uint)*pbVar4;
    bVar6 = 1;
    pbVar4 = pbVar3 + 2;
  }
  else if (uVar2 == L'+') {
    uVar2 = (uint)*pbVar4;
    pbVar4 = pbVar3 + 2;
  }
  if (base == 0) {
    if (uVar2 != 0x30) {
      base = 10;
      goto LAB_0007ae0a;
    }
    if ((*pbVar4 & 0xdf) != 0x58) {
      base = 8;
      goto LAB_0007ae0a;
    }
  }
  else if (((base != 0x10) || (uVar2 != 0x30)) || ((*pbVar4 & 0xdf) != 0x58)) goto LAB_0007ae0a;
  uVar2 = (uint)pbVar4[1];
  base = 0x10;
  pbVar4 = pbVar4 + 2;
LAB_0007ae0a:
  iVar5 = 0;
  uVar7 = 0xffffffff / (uint)base;
  uVar1 = 0;
  do {
    uVar8 = uVar2 - 0x30;
    if (9 < uVar8) {
      if (uVar2 - 0x41 < 0x1a) {
        uVar8 = uVar2 - 0x37;
      }
      else {
        if (0x19 < uVar2 - 0x61) break;
        uVar8 = uVar2 - 0x57;
      }
    }
    if (base <= (int)uVar8) break;
    if (iVar5 != -1) {
      if ((uVar7 < uVar1) || ((uVar7 == uVar1 && ((int)~(base * uVar7) < (int)uVar8)))) {
        iVar5 = -1;
      }
      else {
        uVar1 = uVar1 * base + uVar8;
        iVar5 = 1;
      }
    }
    uVar2 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
  } while( true );
  if (iVar5 == -1) {
    *(undefined4 *)rptr = 0x22;
    uVar1 = 0xffffffff;
    if (endptr == (char **)0x0) {
      return 0xffffffff;
    }
  }
  else {
    if (bVar6 != 0) {
      uVar1 = -uVar1;
    }
    if (endptr == (char **)0x0) {
      return uVar1;
    }
    if (iVar5 == 0) goto LAB_0007aebc;
  }
  nptr = (char *)(pbVar4 + -1);
LAB_0007aebc:
  *endptr = nptr;
  return uVar1;
}


