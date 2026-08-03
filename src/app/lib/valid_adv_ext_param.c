/*
 * Function: valid_adv_ext_param
 * Entry:    000588c0
 * Prototype: bool __stdcall valid_adv_ext_param(bt_le_adv_param * param)
 */


/* exclude_from_export_ai */

bool valid_adv_ext_param(bt_le_adv_param *param)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = param->options;
  if ((-1 < (int)(uVar3 << 0x15)) &&
     (((puVar2 = param->peer, puVar2 == (undefined *)0x0 || ((uVar3 & 1) != 0)) &&
      ((uint)param->id < (uint)DAT_20002007)))) {
    iVar1 = memcmp((void *)((int)&bt_dev + (uint)param->id * 7),&DAT_000f0b50,7);
    if (iVar1 == 0) {
      return false;
    }
    if ((((uVar3 & 1) == 0) && (DAT_20002070 < 9)) && (param->interval_min < 0xa0)) {
      return false;
    }
    if ((uVar3 & 0x30) == 0) {
      if ((-1 < (int)(uVar3 << 0x1b)) && (puVar2 != (undefined *)0x0)) goto LAB_0005890e;
    }
    else {
      if (puVar2 == (undefined *)0x0) {
        return false;
      }
      if (-1 < (int)(uVar3 << 0x1b)) goto LAB_0005890e;
    }
    if (((param->interval_min <= param->interval_max) && (0x1f < param->interval_min)) &&
       (param->interval_max < 0x4001)) {
LAB_0005890e:
      if ((uVar3 & 0x38000) != 0x38000) {
        return true;
      }
      return false;
    }
  }
  return false;
}


