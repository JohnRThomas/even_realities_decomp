/*
 * Function: FUN_000534b8
 * Entry:    000534b8
 * Prototype: undefined __stdcall FUN_000534b8(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void FUN_000534b8(void)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  dword thread;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 uVar4;
  byte unaff_lr;
  undefined4 unaff_s16;
  undefined4 unaff_s17;
  undefined4 unaff_s18;
  undefined4 unaff_s19;
  undefined4 unaff_s20;
  undefined4 unaff_s21;
  undefined4 unaff_s22;
  undefined4 unaff_s23;
  undefined4 unaff_s24;
  undefined4 unaff_s25;
  undefined4 unaff_s26;
  undefined4 unaff_s27;
  undefined4 unaff_s28;
  undefined4 unaff_s29;
  undefined4 unaff_s30;
  undefined4 unaff_s31;
  
  *(byte *)(_current.base + 0xd5) = unaff_lr;
  uVar4 = getProcessStackPointer();
  *(undefined4 *)(_current.base + 0x30) = unaff_r4;
  *(undefined4 *)(_current.base + 0x34) = unaff_r5;
  *(undefined4 *)(_current.base + 0x38) = unaff_r6;
  *(undefined4 *)(_current.base + 0x3c) = unaff_r7;
  *(undefined4 *)(_current.base + 0x40) = unaff_r8;
  *(undefined4 *)(_current.base + 0x44) = unaff_r9;
  *(undefined4 *)(_current.base + 0x48) = unaff_r10;
  *(undefined4 *)(_current.base + 0x4c) = unaff_r11;
  *(undefined4 *)(_current.base + 0x50) = uVar4;
  if ((unaff_lr & 0x10) == 0) {
    *(undefined4 *)(_current.base + 0x94) = unaff_s16;
    *(undefined4 *)(_current.base + 0x98) = unaff_s17;
    *(undefined4 *)(_current.base + 0x9c) = unaff_s18;
    *(undefined4 *)(_current.base + 0xa0) = unaff_s19;
    *(undefined4 *)(_current.base + 0xa4) = unaff_s20;
    *(undefined4 *)(_current.base + 0xa8) = unaff_s21;
    *(undefined4 *)(_current.base + 0xac) = unaff_s22;
    *(undefined4 *)(_current.base + 0xb0) = unaff_s23;
    *(undefined4 *)(_current.base + 0xb4) = unaff_s24;
    *(undefined4 *)(_current.base + 0xb8) = unaff_s25;
    *(undefined4 *)(_current.base + 0xbc) = unaff_s26;
    *(undefined4 *)(_current.base + 0xc0) = unaff_s27;
    *(undefined4 *)(_current.base + 0xc4) = unaff_s28;
    *(undefined4 *)(_current.base + 200) = unaff_s29;
    *(undefined4 *)(_current.base + 0xcc) = unaff_s30;
    *(undefined4 *)(_current.base + 0xd0) = unaff_s31;
  }
  thread = _current.poller;
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  _current.base = _current.poller;
  _DAT_e000ed04 = 0x8000000;
  uVar4 = *(undefined4 *)(_current.poller + 0x8c);
  *(undefined4 *)(_current.poller + 0x8c) = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar4);
  }
  cVar1 = isThreadModePrivileged();
  isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar1 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar1 = isUsingMainStack();
      setStackMode(cVar1 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(*(undefined4 *)(thread + 0x50));
  }
  configure_builtin_stack_guard((k_thread *)thread);
  return;
}


