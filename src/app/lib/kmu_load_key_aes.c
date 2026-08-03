/*
 * Function: kmu_load_key_aes
 * Entry:    0007eecc
 * Prototype: undefined4 __stdcall kmu_load_key_aes(int param_1, int param_2)
 */


/* exclude_from_export */

undefined4 kmu_load_key_aes(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 1) {
    Peripherals::CRYPTOCELL_S.ENABLE = 1;
    Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED = 0;
    Peripherals::KMU_S.SELECTKEYSLOT = param_1 + 1;
    if ((&Peripherals::UICR_S.KEYSLOT_CONFIG_0__DEST)[param_1 * 2] != 0x50845400) {
LAB_0007f07a:
      Peripherals::KMU_S.SELECTKEYSLOT = 0;
      return 0xf70006;
    }
    Peripherals::KMU_S.TASKS_PUSH_KEYSLOT = 1;
    do {
      uVar1 = Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED;
      uVar3 = Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR;
      uVar2 = Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED;
      if (uVar1 != 0 || uVar3 != 0) {
        if (uVar3 != 0) goto LAB_0007f096;
        if (uVar2 == 0) {
          Peripherals::KMU_S.SELECTKEYSLOT = 0;
          Peripherals::CRYPTOCELL_S.ENABLE = 1;
          Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR = 0;
          Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED = 0;
          Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED = 0;
          Peripherals::KMU_S.SELECTKEYSLOT = param_1 + 2;
          if ((&Peripherals::UICR_S.KEYSLOT_CONFIG_1__DEST)[param_1 * 2] != 0x50845410)
          goto LAB_0007f082;
          Peripherals::KMU_S.TASKS_PUSH_KEYSLOT = 1;
          goto LAB_0007ef72;
        }
        break;
      }
    } while (uVar2 == 0);
  }
  else if (param_2 == 2) {
    Peripherals::CRYPTOCELL_S.ENABLE = 1;
    Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED = 0;
    Peripherals::KMU_S.SELECTKEYSLOT = param_1 + 1;
    if ((&Peripherals::UICR_S.KEYSLOT_CONFIG_0__DEST)[param_1 * 2] != 0x50845400) goto LAB_0007f07a;
    Peripherals::KMU_S.TASKS_PUSH_KEYSLOT = 1;
    do {
      uVar1 = Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED;
      uVar3 = Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR;
      uVar2 = Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED;
      if (uVar1 != 0 || uVar3 != 0) {
        if (uVar3 != 0) {
LAB_0007f096:
          Peripherals::KMU_S.SELECTKEYSLOT = 0;
          return 0xf70001;
        }
        if (uVar2 == 0) {
          Peripherals::KMU_S.SELECTKEYSLOT = 0;
          Peripherals::CRYPTOCELL_S.ENABLE = 1;
          Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR = 0;
          Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED = 0;
          Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED = 0;
          Peripherals::KMU_S.SELECTKEYSLOT = param_1 + 2;
          if ((&Peripherals::UICR_S.KEYSLOT_CONFIG_1__DEST)[param_1 * 2] != 0x50845410)
          goto LAB_0007f082;
          Peripherals::KMU_S.TASKS_PUSH_KEYSLOT = 1;
          goto LAB_0007f068;
        }
        break;
      }
    } while (uVar2 == 0);
  }
  else {
    if (param_2 != 0) {
      return 0xf1000c;
    }
    Peripherals::CRYPTOCELL_S.ENABLE = 1;
    Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED = 0;
    Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED = 0;
    Peripherals::KMU_S.SELECTKEYSLOT = param_1 + 1;
    if ((&Peripherals::UICR_S.KEYSLOT_CONFIG_0__DEST)[param_1 * 2] != 0x50845400) {
LAB_0007f082:
      Peripherals::KMU_S.SELECTKEYSLOT = 0;
      return 0xf70006;
    }
    Peripherals::KMU_S.TASKS_PUSH_KEYSLOT = 1;
    do {
      uVar1 = Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED;
      uVar3 = Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR;
      uVar2 = Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED;
      if (uVar1 != 0 || uVar3 != 0) {
        if (uVar3 != 0) goto LAB_0007f096;
        if (uVar2 == 0) {
          Peripherals::KMU_S.SELECTKEYSLOT = 0;
          return 0;
        }
        break;
      }
    } while (uVar2 == 0);
  }
  goto LAB_0007f088;
  while (uVar2 == 0) {
LAB_0007ef72:
    uVar1 = Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED;
    uVar3 = Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR;
    uVar2 = Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED;
    if (uVar1 != 0 || uVar3 != 0) goto LAB_0007ef82;
  }
  goto LAB_0007f088;
LAB_0007ef82:
  if (uVar3 != 0) {
    Peripherals::KMU_S.SELECTKEYSLOT = 0;
    return 0xf70001;
  }
  if (uVar2 == 0) {
    Peripherals::KMU_S.SELECTKEYSLOT = 0;
    return 0;
  }
  goto LAB_0007f088;
  while (uVar2 == 0) {
LAB_0007f068:
    uVar1 = Peripherals::KMU_S.EVENTS_KEYSLOT_PUSHED;
    uVar3 = Peripherals::KMU_S.EVENTS_KEYSLOT_ERROR;
    uVar2 = Peripherals::KMU_S.EVENTS_KEYSLOT_REVOKED;
    if (uVar1 != 0 || uVar3 != 0) goto LAB_0007ef82;
  }
LAB_0007f088:
  Peripherals::KMU_S.SELECTKEYSLOT = 0;
  return 0xf70002;
}


