/*
 * Function: FUN_0100dac8
 * Entry:    0100dac8
 * Prototype: bool __stdcall FUN_0100dac8(uint * param_1, uint param_2)
 */


bool FUN_0100dac8(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar2;
  
  if (param_2 == 0) {
    return true;
  }
  if (param_2 - 1 < 7) {
    uVar3 = 0;
    uVar4 = uVar3;
  }
  else {
    uVar4 = 0;
    puVar1 = param_1;
    do {
      puVar2 = puVar1 + 1;
      uVar4 = *puVar1 | uVar4;
      puVar1 = puVar2;
    } while (puVar2 != param_1 + ((param_2 >> 2) - 1 & 0xff) + 1);
    uVar3 = param_2 & 0xfc;
    uVar4 = uVar4 & 0xff | (uVar4 << 0x10) >> 0x18 | (uVar4 << 8) >> 0x18 | uVar4 >> 0x18;
    if ((param_2 & 0xffffff03) == 0) goto LAB_0100db8c;
  }
  uVar4 = uVar4 | *(byte *)((int)param_1 + uVar3);
  uVar5 = uVar3 + 1 & 0xff;
  if (uVar5 < param_2) {
    uVar4 = uVar4 | *(byte *)((int)param_1 + uVar5);
    uVar5 = uVar3 + 2 & 0xff;
    if (uVar5 < param_2) {
      uVar4 = uVar4 | *(byte *)((int)param_1 + uVar5);
      uVar5 = uVar3 + 3 & 0xff;
      if (uVar5 < param_2) {
        uVar4 = uVar4 | *(byte *)((int)param_1 + uVar5);
        uVar5 = uVar3 + 4 & 0xff;
        if (uVar5 < param_2) {
          uVar4 = uVar4 | *(byte *)((int)param_1 + uVar5);
          uVar5 = uVar3 + 5 & 0xff;
          if (uVar5 < param_2) {
            uVar3 = uVar3 + 6 & 0xff;
            uVar4 = uVar4 | *(byte *)((int)param_1 + uVar5);
            if (uVar3 < param_2) {
              uVar4 = uVar4 | *(byte *)((int)param_1 + uVar3);
            }
          }
        }
      }
    }
  }
LAB_0100db8c:
  return uVar4 == 0;
}


