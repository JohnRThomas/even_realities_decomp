/*
 * Function: nrfx_ipc_irq_handler
 * Entry:    00069130
 * Prototype: void __stdcall nrfx_ipc_irq_handler(void)
 */


/* exclude_from_export */

void nrfx_ipc_irq_handler(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = Peripherals::IPC_S.INTPEND;
  while( true ) {
    if (uVar6 == 0) {
      return;
    }
    bVar2 = (byte)uVar6;
    bVar3 = (byte)(uVar6 >> 8);
    bVar4 = (byte)(uVar6 >> 0x10);
    bVar1 = (byte)(uVar6 >> 0x18);
    uVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    uVar6 = uVar6 & ~(1 << uVar5);
    if (0xf < uVar5) break;
    (&Peripherals::IPC_S.EVENTS_RECEIVE_0_)[uVar5] = 0;
    if (DAT_2000bd0c != (code *)0x0) {
      (*DAT_2000bd0c)(uVar5,DAT_2000bd14);
    }
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","index < 16",
          "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",487);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


