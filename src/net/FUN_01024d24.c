/*
 * Function: FUN_01024d24
 * Entry:    01024d24
 * Prototype: undefined __stdcall FUN_01024d24(uint param_1, uint param_2, uint * param_3, int * param_4, char * param_5)
 */


void FUN_01024d24(uint param_1,uint param_2,uint *param_3,int *param_4,char *param_5)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  
  if (param_2 < 512000000) {
    uVar5 = param_1 >> 0x1d | param_2 << 3;
    uVar6 = uVar5 / 0xf424;
    uVar2 = (((param_1 << 3) >> 0x10) + uVar5 * 0x10000 + uVar6 * 0xbdc0000) / 0xf424;
    uVar6 = uVar2 | uVar6 << 0x10;
    uVar3 = param_1 + uVar6 * -512000000;
    uVar7 = (uVar3 >> 0xd) * 0x8637 >> 0x10;
    uVar4 = uVar3 + uVar7 * -0x3d09;
    uVar5 = uVar4 * 0x10c6f >> 0x15;
    iVar9 = uVar5 * 0x3d09;
    uVar5 = uVar5 + uVar7 * 0x200;
    if ((uint)(&DAT_00003d08 + iVar9) >> 9 < uVar4) {
      uVar5 = uVar5 + 1;
      cVar8 = '\0';
    }
    else {
      cVar8 = (char)uVar4 - (char)(iVar9 + 0x100U >> 9);
    }
    *param_5 = cVar8;
    uVar2 = uVar2 * 0x1000000;
    *param_4 = uVar2 + uVar5;
    param_4[1] = (uVar6 >> 8) + (uint)CARRY4(uVar2,uVar5);
    *param_3 = uVar3;
    return;
  }
  FUN_01025edc(0x9b,0x96,param_3,param_4);
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0x83,0x1024dc8);
  (*pcVar1)();
}


