/*
 * Function: __exponent
 * Entry:    0008a55a
 * Prototype: int __stdcall __exponent(char * p0, int exp, int fmtch)
 */


/* exclude_from_export_ai */

int __exponent(char *p0,int exp,int fmtch)

{
  bool bVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  uStack_18 = fmtch;
  uStack_1c = exp;
  *p0 = (char)fmtch;
  if (exp < 0) {
    exp = -exp;
    cVar3 = '-';
  }
  else {
    cVar3 = '+';
  }
  p0[1] = cVar3;
  if (exp < 10) {
    p0[2] = '0';
    pcVar2 = p0 + 4;
    p0[3] = (char)exp + '0';
  }
  else {
    pcVar4 = (char *)((int)&uStack_1c + 3);
    pcVar2 = pcVar4;
    do {
      pcVar5 = pcVar2;
      cVar3 = (char)((uint)exp / 10);
      pcVar5[-1] = (char)exp + cVar3 * -10 + '0';
      bVar1 = 99 < exp;
      exp = (uint)exp / 10;
      pcVar2 = pcVar5 + -1;
    } while (bVar1);
    pcVar5[-2] = cVar3 + '0';
    pcVar2 = p0 + 1;
    for (pcVar7 = pcVar5 + -2; pcVar7 < pcVar4; pcVar7 = pcVar7 + 1) {
      pcVar2 = pcVar2 + 1;
      *pcVar2 = *pcVar7;
    }
    iVar6 = (int)&uStack_18 + (1 - (int)pcVar5);
    if (pcVar4 < pcVar5 + -2) {
      iVar6 = 0;
    }
    pcVar2 = p0 + iVar6 + 2;
  }
  return (int)pcVar2 - (int)p0;
}


