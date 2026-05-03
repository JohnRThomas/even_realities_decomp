/*
 * Function: FUN_0100eb7c
 * Entry:    0100eb7c
 * Prototype: undefined __stdcall FUN_0100eb7c(int param_1, int param_2, int param_3)
 */


void FUN_0100eb7c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  uVar2 = (-((param_2 << 0x1d) >> 0x1f) - ((param_2 << 0x19) >> 0x1f)) +
          ((param_2 << 0x1b) >> 0x1f) * -3 + ((param_2 << 0x1a) >> 0x1f) * -0x12 + param_3 +
          ((-((param_2 << 0x1f) >> 0x1f) - ((param_2 << 0x1e) >> 0x1f)) * 3 -
          ((param_2 << 0x1c) >> 0x1f)) * 2;
  uVar3 = uVar2 & 0xff;
  if (uVar3 == 0) {
    cVar4 = '\x01';
    bVar1 = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = uVar3 + 1;
    cVar4 = (char)uVar2 + '\x02';
    *(char *)(param_1 + 4) = (char)param_2;
    bVar1 = (byte)uVar3 & 0x3f;
    uVar3 = uVar3 & 0xff;
  }
  *(char *)(param_1 + 1) = cVar4;
  *(byte *)(param_1 + 3) = bVar1 | *(byte *)(param_1 + 3) & 0xc0;
  if (param_3 != 0) {
    *(char *)(param_1 + ((uVar3 + 4) - param_3)) = (char)param_3 + -1;
  }
  return;
}


