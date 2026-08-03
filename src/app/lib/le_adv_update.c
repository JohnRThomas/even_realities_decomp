/*
 * Function: le_adv_update
 * Entry:    00084986
 * Prototype: int __stdcall le_adv_update(bt_le_ext_adv * adv, bt_data * ad, size_t ad_len, bt_data * sd, size_t sd_len, bool ext_adv, bool scannable, adv_name_type name_type)
 */


/* exclude_from_export_ai */

int le_adv_update(bt_le_ext_adv *adv,bt_data *ad,size_t ad_len,bt_data *sd,size_t sd_len,
                 bool ext_adv,bool scannable,adv_name_type name_type)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined1 local_40;
  undefined1 local_3f;
  char *local_3c;
  bt_ad local_38;
  undefined1 *local_30;
  undefined4 local_2c;
  
  memset(&local_38,0,0x10);
  if (scannable) {
    local_3c = bt_get_name();
    if (ad != (bt_data *)0x0) {
      for (sVar3 = 0; ad_len != sVar3; sVar3 = sVar3 + 1) {
        if (*(byte *)((int)ad + sVar3) - 8 < 2) {
          return -0x16;
        }
      }
    }
    if (sd != (bt_data *)0x0) {
      for (sVar3 = 0; sd_len != sVar3; sVar3 = sVar3 + 1) {
        if (*(byte *)((int)sd + sVar3) - 8 < 2) {
          return -0x16;
        }
      }
    }
    sVar3 = strlen(local_3c);
    local_40 = 9;
    local_3f = (undefined1)sVar3;
    sVar3 = 2;
    local_2c = 1;
    local_30 = &local_40;
  }
  else {
    sVar3 = 1;
  }
  local_38.data = (undefined *)ad;
  local_38.len = ad_len;
  iVar1 = hci_set_ad(0x2008,&local_38,sVar3);
  if (iVar1 == 0) {
    if (ext_adv) {
      sVar3 = 1;
      if (scannable == true) {
        local_2c = 1;
        sVar3 = 2;
        local_30 = &local_40;
      }
      local_38.len = sd_len;
      local_38.data = (undefined *)sd;
      iVar2 = hci_set_ad(0x2009,&local_38,sVar3);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    adv->BT_ADV_NUM_FLAGS_ = adv->BT_ADV_NUM_FLAGS_ | 4;
  }
  return iVar1;
}


