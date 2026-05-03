/*
 * Function: FUN_0100ec48
 * Entry:    0100ec48
 * Prototype: char __stdcall FUN_0100ec48(int param_1)
 */


char FUN_0100ec48(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  
  bVar1 = *(byte *)(param_1 + 4);
  bVar4 = *(byte *)(param_1 + 3) & 0x3f;
  if ((*(byte *)(param_1 + 3) & 0x3f) != 0) {
    bVar4 = 1;
  }
  cVar2 = (bVar4 & bVar1 >> 4) * '\x03' + (bVar4 & bVar1 >> 2) + (bVar4 & bVar1 >> 6) +
          ((bVar4 & bVar1 >> 3) + (bVar4 & bVar1 >> 5) * '\t' +
          ((bVar4 & bVar1 >> 1) + (bVar1 & bVar4)) * '\x03') * '\x02';
  cVar3 = '\0';
  if (cVar2 != '\0') {
    cVar3 = cVar2 + '\x01';
  }
  return cVar3;
}


