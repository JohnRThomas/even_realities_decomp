/*
 * Function: FUN_010174c8
 * Entry:    010174c8
 * Prototype: undefined __stdcall FUN_010174c8(ushort * param_1, int param_2)
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_010174c8(ushort *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint extraout_r2;
  uint extraout_r2_00;
  undefined *puVar3;
  undefined *extraout_r3;
  char cVar4;
  
  cVar1 = DAT_2100001c;
  if (DAT_2100001c == '\x7f') {
    FUN_01017028(param_1,param_2,0x7f,&DAT_2100001c);
    puVar3 = &DAT_21000f90;
    if (DAT_21001000 < 5) {
      FUN_01009500(0x32,&DAT_0000164b,(uint)DAT_21001000,&DAT_21000f90);
      uVar2 = extraout_r2_00;
      puVar3 = extraout_r3;
    }
    else {
      uVar2 = (uint)DAT_21001000;
      if (uVar2 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0101755a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)(DAT_21001054 + 0xc) + (DAT_21001000 + 0x3ffffffb) * 4))
                  (extraout_r2 >> 0x1e);
        return;
      }
    }
    FUN_01009500(0x32,&DAT_0000164c,uVar2,puVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_2100001c = 0x7f;
  if (DAT_21001000 == 5) {
    cVar4 = '\0';
  }
  else if (DAT_21001000 == 8) {
    cVar4 = '\x03';
  }
  else {
    cVar4 = '\x01';
  }
  uVar2 = FUN_0101a2a0(param_1,param_2,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009,
                       cVar1,cVar4);
  if (uVar2 != 0) {
    FUN_01019e60();
    return;
  }
  return;
}


