/*
 * Function: spec_put_side
 * Entry:    00072bc4
 * Prototype: undefined __stdcall spec_put_side(lc3_bits_t * param_1, int param_2, int param_3, uint * param_4)
 */


/* exclude_from_export */

void spec_put_side(lc3_bits_t *param_1,int param_2,int param_3,uint *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int n;
  uint uVar4;
  uint uVar5;
  
  iVar2 = (param_3 * (param_2 + 3) + param_2 + 3) * 5;
  n = (0x10 < iVar2) + 5;
  if (0x20 < iVar2) {
    n = (0x10 < iVar2) + 6;
  }
  iVar3 = (int)param_4[1] >> 1;
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  if (0x40 < iVar2) {
    n = n + 1;
  }
  uVar4 = param_1[8];
  uVar5 = uVar4 + n;
  if ((int)uVar5 < 0x21) {
    param_1[8] = uVar5;
    param_1[7] = param_1[7] | iVar3 - 1U << (uVar4 & 0xff);
    bVar1 = (byte)param_4[2];
  }
  else {
    lc3_put_bits_generic(param_1,iVar3 - 1U,n);
    uVar5 = param_1[8];
    bVar1 = (byte)param_4[2];
  }
  uVar4 = uVar5 + 1;
  if ((int)uVar4 < 0x21) {
    param_1[8] = uVar4;
    param_1[7] = param_1[7] | (uint)bVar1 << (uVar5 & 0xff);
    uVar5 = *param_4;
  }
  else {
    lc3_put_bits_generic(param_1,(uint)bVar1,1);
    uVar4 = param_1[8];
    uVar5 = *param_4;
  }
  if ((int)(uVar4 + 8) < 0x21) {
    param_1[7] = param_1[7] | uVar5 << (uVar4 & 0xff);
    param_1[8] = uVar4 + 8;
    return;
  }
  lc3_put_bits_generic(param_1,uVar5,8);
  return;
}


