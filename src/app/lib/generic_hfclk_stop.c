/*
 * Function: generic_hfclk_stop
 * Entry:    000639e8
 * Prototype: undefined __stdcall generic_hfclk_stop(void)
 */


/* exclude_from_export */

void generic_hfclk_stop(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar2 = DAT_2000bb30 & 0xfffffffd;
  iVar3 = DAT_2000bb30 << 0x1f;
  DAT_2000bb30 = uVar2;
  if (-1 < iVar3) {
    nrfx_clock_stop(NRF_CLOCK_DOMAIN_HFCLK);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


