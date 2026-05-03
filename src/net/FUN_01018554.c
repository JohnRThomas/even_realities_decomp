/*
 * Function: FUN_01018554
 * Entry:    01018554
 * Prototype: undefined __stdcall FUN_01018554(undefined * param_1, int param_2)
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_01018554(undefined *param_1,int param_2)

{
  uint uVar1;
  uint extraout_r2;
  undefined *puVar2;
  undefined *extraout_r3;
  
  if (param_1 != (undefined *)0x0) {
    if (DAT_2100100c != '\0') {
      FUN_010210b0();
      param_1 = (undefined *)FUN_010204a8();
      DAT_2100100c = '\0';
    }
    DAT_2100104a = 0;
    DAT_21001000 = 1;
    DAT_2100104c = 0;
    FUN_0101bcf4(param_1);
    return;
  }
  if (param_2 != 0) {
    puVar2 = &DAT_21000f90;
    if (DAT_21001000 < 0xb) {
      FUN_01009500(0x32,&DAT_00001617,(uint)DAT_21001000,&DAT_21000f90);
      uVar1 = extraout_r2;
      puVar2 = extraout_r3;
    }
    else {
      uVar1 = (uint)DAT_21001000;
      if (uVar1 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x01018582. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)(DAT_21001054 + 8) + (DAT_21001000 + 0x3ffffff5) * 4))();
        return;
      }
    }
    FUN_01009500(0x32,&DAT_00001618,uVar1,puVar2);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


