/*
 * Function: FUN_0103bd9c
 * Entry:    0103bd9c
 * Prototype: undefined __stdcall FUN_0103bd9c(uint param_1, char * param_2, uint param_3)
 */


void FUN_0103bd9c(uint param_1,char *param_2,uint param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  
  if ((int)(param_3 << 0x16) < 0) {
    param_3 = param_3 & 0xfffffdff;
    cVar2 = '\a';
  }
  else {
    cVar2 = '\'';
  }
  do {
    uVar4 = param_1 - param_3 * (param_1 / param_3);
    cVar3 = (char)uVar4;
    if (9 < (uVar4 & 0xff)) {
      cVar3 = cVar3 + cVar2;
    }
    *param_2 = cVar3 + '0';
    bVar1 = param_3 <= param_1;
    param_2 = param_2 + 1;
    param_1 = param_1 / param_3;
  } while (bVar1);
  return;
}


