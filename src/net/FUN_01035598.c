/*
 * Function: FUN_01035598
 * Entry:    01035598
 * Prototype: undefined __stdcall FUN_01035598(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01035598(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) goto LAB_010355ae;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",0x46,param_4);
  while( true ) {
    param_1 = FUN_0103a370();
LAB_010355ae:
    if (DAT_21004af0 == 1) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",0x47,
                 (uint)DAT_21004af0);
  }
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    (&Peripherals::IPC_NS.SEND_CNF_0_)[iVar3] = *(uint *)(param_1 + iVar3 * 4);
    iVar3 = iVar2;
  } while (iVar2 != 0x10);
  puVar1 = (uint *)(param_1 + 0x3c);
  iVar3 = 0;
  do {
    puVar1 = puVar1 + 1;
    iVar2 = iVar3 + 1;
    (&Peripherals::IPC_NS.RECEIVE_CNF_0_)[iVar3] = *puVar1;
    iVar3 = iVar2;
  } while (iVar2 != 0x10);
  Peripherals::IPC_NS.INTENSET = *(uint *)(param_1 + 0x80);
  return;
}


