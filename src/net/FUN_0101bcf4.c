/*
 * Function: FUN_0101bcf4
 * Entry:    0101bcf4
 * Prototype: undefined * __stdcall FUN_0101bcf4(undefined * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0101bd58) */
/* WARNING: Removing unreachable block (ram,0x0101bd88) */
/* WARNING: Removing unreachable block (ram,0x0101bd8a) */
/* WARNING: Removing unreachable block (ram,0x0101bd8c) */
/* WARNING: Removing unreachable block (ram,0x0101be0a) */
/* WARNING: Removing unreachable block (ram,0x0101bdd2) */
/* WARNING: Removing unreachable block (ram,0x0101bdf8) */
/* WARNING: Removing unreachable block (ram,0x0101be04) */
/* WARNING: Removing unreachable block (ram,0x0101bed0) */
/* WARNING: Removing unreachable block (ram,0x0101bf14) */
/* WARNING: Removing unreachable block (ram,0x0101bdac) */
/* WARNING: Removing unreachable block (ram,0x0101bee2) */
/* WARNING: Removing unreachable block (ram,0x0101bdb4) */
/* WARNING: Removing unreachable block (ram,0x0101bea0) */
/* WARNING: Removing unreachable block (ram,0x0101bdba) */
/* WARNING: Removing unreachable block (ram,0x0101bdc0) */
/* WARNING: Removing unreachable block (ram,0x0101bdc4) */
/* WARNING: Removing unreachable block (ram,0x0101bdc8) */
/* WARNING: Removing unreachable block (ram,0x0101be0e) */
/* WARNING: Removing unreachable block (ram,0x0101bea6) */
/* WARNING: Removing unreachable block (ram,0x0101bee8) */
/* WARNING: Removing unreachable block (ram,0x0101bef2) */
/* WARNING: Removing unreachable block (ram,0x0101bf02) */
/* WARNING: Removing unreachable block (ram,0x0101beac) */
/* WARNING: Removing unreachable block (ram,0x0101be52) */
/* WARNING: Removing unreachable block (ram,0x0101be66) */
/* WARNING: Removing unreachable block (ram,0x0101be70) */
/* WARNING: Removing unreachable block (ram,0x0101beb8) */
/* WARNING: Removing unreachable block (ram,0x0101be7a) */
/* WARNING: Removing unreachable block (ram,0x0101be90) */

undefined * FUN_0101bcf4(undefined *param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int extraout_r2_03;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  byte abStack_20 [24];
  
  if ((DAT_210010b4 != '\0') && (DAT_210010a1 == '\0')) {
    pbVar2 = FUN_0101ab8c(abStack_20,0,(uint *)0x0,(uint *)0x0);
    if (pbVar2 == (byte *)0x0) {
      DAT_210010a2 = 1;
      param_1 = (undefined *)0x0;
    }
    else {
      pbVar2 = FUN_01019a04();
      param_1 = (undefined *)FUN_010239c8((uint)*pbVar2,abStack_20);
      if (param_1 == (undefined *)0x0) {
        FUN_01009500(0x21,0x7cb,extraout_r2,extraout_r3);
        FUN_01009500(0x21,0x8c3,extraout_r2_00,0x8400426);
        FUN_01009500(0x21,0x854,extraout_r2_01,extraout_r3_00);
        FUN_01009500(0x21,0x40f,extraout_r2_02,extraout_r3_01);
        *(int *)extraout_r2_03 = extraout_r2_03;
        *(byte **)(extraout_r2_03 + 4) = &DAT_210010a0;
        return (undefined *)(uint)DAT_210010a0;
      }
    }
  }
  if (DAT_210010b4 != '\0') {
    FUN_01020e34();
    puVar1 = FUN_01023284();
    DAT_210010b4 = 0;
    DAT_210010b5 = 0;
    return puVar1;
  }
  return param_1;
}


