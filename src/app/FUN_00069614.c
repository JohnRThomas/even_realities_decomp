/*
 * Function: $_FUN_00069614
 * Entry:    00069614
 * Prototype: undefined __stdcall $_FUN_00069614(undefined4 param_1, int param_2, undefined4 param_3, uint param_4)
 */


void __FUN_00069614(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  bool bVar5;
  int local_14;
  int local_10;
  uint local_c;
  
  uVar3 = Peripherals::PDM0_S.EVENTS_STARTED;
  local_c._1_3_ = (uint3)(param_4 >> 8);
  local_14._1_3_ = (uint3)((uint)param_2 >> 8);
  if (uVar3 == 0) {
    uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
    iVar1 = param_2;
    uVar2 = param_4;
    if (uVar3 != 0) {
      Peripherals::PDM0_S.EVENTS_STOPPED = 0;
      uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
      Peripherals::PDM0_S.ENABLE = 0;
      DAT_2000bd29 = '\0';
      local_10 = (&DAT_2000bd1c)[(byte)DAT_2000bd2a];
      local_c = (uint)local_c._1_3_ << 8;
      local_14 = (uint)local_14._1_3_ << 8;
      if (local_10 != 0) {
        (&DAT_2000bd1c)[(byte)DAT_2000bd2a] = 0;
        (*DAT_2000bd18)(&local_14);
      }
      local_10 = (&DAT_2000bd1c)[~(uint)(byte)DAT_2000bd2a & 1];
      if (local_10 != 0) {
        (&DAT_2000bd1c)[~(uint)(byte)DAT_2000bd2a & 1] = 0;
        (*DAT_2000bd18)(&local_14);
      }
      DAT_2000bd2a._0_1_ = 0;
      iVar1 = local_14;
      uVar2 = local_c;
    }
    goto LAB_0006968c;
  }
  Peripherals::PDM0_S.EVENTS_STARTED = 0;
  uVar3 = Peripherals::PDM0_S.EVENTS_STARTED;
  uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
  if (uVar3 != 0) {
    Peripherals::PDM0_S.EVENTS_STOPPED = 0;
    uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
  }
  uVar3 = ~(uint)(byte)DAT_2000bd2a & 1;
  if (((&DAT_2000bd1c)[uVar3] == 0) && (DAT_2000bd29 != '\x02')) {
    iVar1 = param_2;
    uVar3 = param_4;
    if (DAT_2000bd2a._1_1_ == '\0') {
      local_14 = (uint)local_14._1_3_ << 8;
      local_c = CONCAT31(local_c._1_3_,1);
      DAT_2000bd2a._1_1_ = '\x01';
      local_10 = 0;
      goto LAB_0006967c;
    }
  }
  else {
    bVar5 = DAT_2000bd29 == '\x02';
    if (bVar5) {
      puVar4 = (undefined4 *)0x1;
    }
    else {
      puVar4 = &DAT_2000bd18 + (byte)DAT_2000bd2a;
    }
    if (bVar5) {
      DAT_2000bd29 = (char)puVar4;
      local_10 = 2;
    }
    else {
      local_10 = puVar4[1];
      puVar4[1] = 0;
    }
    local_c = param_4 & 0xffffff00;
    DAT_2000bd2a._1_1_ = '\0';
    if (bVar5) {
      local_10 = 0;
    }
    else {
      DAT_2000bd2a._0_1_ = (byte)uVar3;
    }
    local_14 = CONCAT31(local_14._1_3_,1);
LAB_0006967c:
    (*DAT_2000bd18)(&local_14);
    iVar1 = local_14;
    uVar3 = local_c;
  }
  local_c = uVar3;
  local_14 = iVar1;
  iVar1 = local_14;
  uVar2 = local_c;
  if (DAT_2000bd29 == '\x02') {
    DAT_2000bd29 = '\x01';
  }
LAB_0006968c:
  local_c = uVar2;
  local_14 = iVar1;
  if (DAT_2000bd2c != '\0') {
    local_14 = CONCAT31(local_14._1_3_,1);
    local_10 = 0;
    local_c = local_c & 0xffffff00;
    DAT_2000bd2c = '\0';
    (*DAT_2000bd18)(&local_14);
  }
  return;
}


