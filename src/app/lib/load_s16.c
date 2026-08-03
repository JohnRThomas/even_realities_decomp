/*
 * Function: load_s16
 * Entry:    0006bf60
 * Prototype: undefined __stdcall load_s16(byte * param_1, short * param_2, int param_3)
 */


/* exclude_from_export */

void load_s16(byte *param_1,short *param_2,int param_3)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  uint in_fpscr;
  undefined4 uVar6;
  
  iVar4 = param_1[2] + 1;
  if (param_1[2] == 4) {
    iVar4 = 6;
  }
  psVar3 = (short *)(*(int *)(param_1 + 0x4a0) + -2);
  puVar2 = *(undefined4 **)(param_1 + 0x4a4);
  psVar5 = psVar3 + (*param_1 + 3) * iVar4 * 0x14;
  if (param_3 == 1) {
    do {
      sVar1 = *param_2;
      param_2 = param_2 + 1;
      uVar6 = VectorSignedToFloat((int)sVar1,(byte)(in_fpscr >> 0x16) & 3);
      psVar3 = psVar3 + 1;
      *psVar3 = sVar1;
      *puVar2 = uVar6;
      puVar2 = puVar2 + 1;
    } while (psVar3 != psVar5);
  }
  else {
    do {
      sVar1 = *param_2;
      param_2 = param_2 + param_3;
      uVar6 = VectorSignedToFloat((int)sVar1,(byte)(in_fpscr >> 0x16) & 3);
      psVar3 = psVar3 + 1;
      *psVar3 = sVar1;
      *puVar2 = uVar6;
      puVar2 = puVar2 + 1;
    } while (psVar3 != psVar5);
  }
  return;
}


