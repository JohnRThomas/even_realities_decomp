/*
 * Function: FUN_01009500
 * Entry:    01009500
 * Prototype: undefined __stdcall FUN_01009500(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01009500(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  disableIRQinterrupts();
  if (DAT_21000a58 != (code *)0x0) {
    bVar1 = 0;
    uVar2 = param_1;
    while( true ) {
      uVar3 = (uint)bVar1;
      bVar1 = bVar1 + 1;
      if (uVar2 == 0) break;
      uVar2 = uVar2 / 10;
    }
    uStack_14 = param_2;
    uStack_10 = param_3;
    uStack_c = param_4;
    *(undefined1 *)((int)&uStack_14 + uVar3) = 0;
    while (uVar3 != 0) {
      uVar3 = uVar3 - 1 & 0xff;
      uVar2 = param_1 & 0xff;
      param_1 = param_1 / 10;
      *(char *)((int)&uStack_14 + uVar3) = (char)(uVar2 % 10) + '0';
    }
    (*DAT_21000a58)(&uStack_14);
  }
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


