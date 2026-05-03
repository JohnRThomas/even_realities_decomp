/*
 * Function: FUN_01033f6c
 * Entry:    01033f6c
 * Prototype: undefined4 __stdcall FUN_01033f6c(byte * param_1)
 */


undefined4 FUN_01033f6c(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (DAT_21006459 == '\0') {
    uVar4 = 0xfffffff3;
  }
  else if (param_1 == (byte *)0x0) {
    uVar4 = 0xffffffea;
  }
  else if (DAT_21004a5c == 0) {
    uVar4 = 0xffffffc3;
  }
  else {
    uVar4 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar4 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = *(byte *)(&DAT_21004a34)[DAT_21004a58];
    *param_1 = bVar1;
    param_1[1] = *(byte *)((&DAT_21004a34)[DAT_21004a58] + 1);
    param_1[2] = *(byte *)((&DAT_21004a34)[DAT_21004a58] + 2);
    param_1[4] = *(byte *)((&DAT_21004a34)[DAT_21004a58] + 4);
    param_1[3] = *(byte *)((&DAT_21004a34)[DAT_21004a58] + 3);
    FUN_0103bdd4((int)(param_1 + 5),(undefined1 *)((&DAT_21004a34)[DAT_21004a58] + 5),(uint)bVar1);
    DAT_21004a58 = DAT_21004a58 + 1;
    if (7 < DAT_21004a58) {
      DAT_21004a58 = 0;
    }
    DAT_21004a5c = DAT_21004a5c + -1;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar4 = 0;
  }
  return uVar4;
}


