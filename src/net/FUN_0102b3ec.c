/*
 * Function: FUN_0102b3ec
 * Entry:    0102b3ec
 * Prototype: undefined4 __stdcall FUN_0102b3ec(void)
 */


undefined4 FUN_0102b3ec(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  
  iVar1 = FUN_0102dd18(0x103bf6c);
  if ((iVar1 < 0) && (iVar1 != -0x78)) {
    if (DAT_21000580 < 1) {
      return 0xffffffff;
    }
    pcVar2 = "ipc service open fail\n";
    uVar3 = extraout_r1;
    uVar4 = extraout_r2;
  }
  else {
    iVar1 = FUN_0102dd74(0x103bf6c,(int *)&DAT_210045f8,0x21000584);
    if (-1 < iVar1) {
      FUN_0103705c((int *)&DAT_21000914,extraout_r1_00,0xffffffff,0xffffffff);
      DAT_21004600 = 1;
      if (1 < DAT_21000580) {
        FUN_01039ee2((byte *)"ipc service ready!\n\n",extraout_r1_01,1,DAT_21000580);
      }
      return 0;
    }
    if (DAT_21000580 < 1) {
      return 0xffffffff;
    }
    pcVar2 = "ipc service register endpoint failed\n";
    uVar3 = extraout_r1_00;
    uVar4 = extraout_r2_00;
  }
  FUN_01039ee2((byte *)pcVar2,uVar3,uVar4,DAT_21000580);
  return 0xffffffff;
}


