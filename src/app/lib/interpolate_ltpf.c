/*
 * Function: interpolate_ltpf
 * Entry:    0006c710
 * Prototype: undefined __stdcall interpolate_ltpf(short * param_1, int param_2, int param_3, undefined2 * param_4)
 */


/* exclude_from_export */

void interpolate_ltpf(short *param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar1 = param_3 * 8;
  iVar10 = (int)param_1[-2];
  iVar7 = (int)param_1[-1];
  iVar8 = (int)*param_1;
  if (param_4 < param_4 + param_2) {
    psVar6 = param_1 + 5;
    do {
      sVar2 = psVar6[-4];
      sVar5 = (short)iVar8;
      iVar9 = (int)*(short *)(&DAT_0008f828 + iVar1);
      *param_4 = (short)((int)(short)iVar10 * (int)*(short *)(&DAT_0008f82e + iVar1) +
                         (int)(short)iVar7 * (int)*(short *)(&DAT_0008f82c + iVar1) +
                         sVar2 * iVar9 + (int)*(short *)(&DAT_0008f82a + iVar1) * (int)sVar5 >> 0xf)
      ;
      sVar3 = psVar6[-3];
      iVar10 = (int)sVar3;
      param_4[1] = (short)((int)(short)iVar7 * (int)*(short *)(&DAT_0008f82e + iVar1) +
                           (int)sVar5 * (int)*(short *)(&DAT_0008f82c + iVar1) +
                           iVar9 * iVar10 + (int)*(short *)(&DAT_0008f82a + iVar1) * (int)sVar2 >>
                          0xf);
      sVar4 = psVar6[-2];
      iVar7 = (int)sVar4;
      param_4[2] = (short)((int)sVar5 * (int)*(short *)(&DAT_0008f82e + iVar1) +
                           (int)sVar2 * (int)*(short *)(&DAT_0008f82c + iVar1) +
                           iVar9 * iVar7 + (int)*(short *)(&DAT_0008f82a + iVar1) * (int)sVar3 >>
                          0xf);
      iVar8 = (int)psVar6[-1];
      psVar6 = psVar6 + 4;
      param_4[3] = (short)((int)sVar2 * (int)*(short *)(&DAT_0008f82e + iVar1) +
                           (int)sVar3 * (int)*(short *)(&DAT_0008f82c + iVar1) +
                           iVar9 * iVar8 + (int)*(short *)(&DAT_0008f82a + iVar1) * (int)sVar4 >>
                          0xf);
      param_4 = param_4 + 4;
    } while (psVar6 != (short *)((int)param_1 + (param_2 * 2 - 1U & 0xfffffff8) + 0x12));
  }
  return;
}


