/*
 * Function: FUN_01025edc
 * Entry:    01025edc
 * Prototype: undefined __stdcall FUN_01025edc(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01025edc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  uint extraout_r2;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  undefined1 *unaff_r6;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  pcVar1 = DAT_21001c1c;
  disableIRQinterrupts();
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  if (DAT_21001c1c == (code *)0x0) {
    do {
      param_1 = FUN_01025da4();
      uVar2 = extraout_r2;
      do {
        unaff_r4 = unaff_r4 / (uint)unaff_r6;
LAB_01025eee:
        uVar3 = uVar2 & 0xff;
        uVar2 = uVar2 + 1;
      } while (unaff_r4 != 0);
      *(undefined1 *)((int)&uStack_14 + uVar3) = 0;
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1 & 0xff;
        unaff_r6 = &stack0xfffffff8 + uVar3;
        unaff_r4 = param_1 / 10;
        *(char *)((int)&uStack_14 + uVar3) = (char)param_1 + (char)unaff_r4 * -10 + '0';
        param_1 = unaff_r4;
      }
      (*pcVar1)(&uStack_14);
    } while( true );
  }
  uVar2 = 0;
  unaff_r6 = &LAB_0000000a;
  unaff_r4 = param_1;
  goto LAB_01025eee;
}


