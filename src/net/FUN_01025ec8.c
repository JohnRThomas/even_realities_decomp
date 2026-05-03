/*
 * Function: FUN_01025ec8
 * Entry:    01025ec8
 * Prototype: undefined __stdcall FUN_01025ec8(void)
 */


void FUN_01025ec8(void)

{
  code *pcVar1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  uint unaff_r4;
  undefined1 *unaff_r6;
  char acStack_1c [12];
  
  disableIRQinterrupts();
  if (DAT_21001c1c != (code *)0x0) {
    (*DAT_21001c1c)();
  }
  FUN_01025da4();
  pcVar1 = DAT_21001c1c;
  acStack_1c[0] = '\0';
  acStack_1c[1] = '\0';
  acStack_1c[2] = '\0';
  acStack_1c[3] = '\0';
  disableIRQinterrupts();
  if (DAT_21001c1c == (code *)0x0) {
    do {
      uVar2 = FUN_01025da4();
      uVar3 = extraout_r2;
      do {
        unaff_r4 = unaff_r4 / (uint)unaff_r6;
LAB_01025eee:
        uVar4 = uVar3 & 0xff;
        uVar3 = uVar3 + 1;
      } while (unaff_r4 != 0);
      acStack_1c[uVar4] = '\0';
      while (uVar4 != 0) {
        uVar4 = uVar4 - 1 & 0xff;
        unaff_r6 = &stack0xfffffff0 + uVar4;
        unaff_r4 = uVar2 / 10;
        acStack_1c[uVar4] = (char)uVar2 + (char)unaff_r4 * -10 + '0';
        uVar2 = unaff_r4;
      }
      (*pcVar1)(acStack_1c);
    } while( true );
  }
  uVar3 = 0;
  unaff_r6 = &LAB_0000000a;
  uVar2 = extraout_r3;
  unaff_r4 = extraout_r3;
  goto LAB_01025eee;
}


