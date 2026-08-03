/*
 * Function: bt_le_adv_start
 * Entry:    00058c44
 * Prototype: int __stdcall bt_le_adv_start(bt_le_adv_param * param, bt_data * ad, size_t ad_len, bt_data * sd, size_t sd_len)
 */


/* exclude_from_export */

int bt_le_adv_start(bt_le_adv_param *param,bt_data *ad,size_t ad_len,bt_data *sd,size_t sd_len)

{
  int iVar1;
  undefined4 extraout_r1;
  size_t sVar2;
  k_timeout_t delay;
  
  iVar1 = bt_le_adv_start_legacy((bt_le_ext_adv *)&bt_dev,param,ad,ad_len,sd,sd_len);
  sVar2 = 0;
  while( true ) {
    if (ad_len == sVar2) {
      return iVar1;
    }
    if ((((short)*ad == 0x101) && ((byte *)ad[1] != (byte *)0x0)) &&
       ((int)((uint)*(byte *)ad[1] << 0x1f) < 0)) break;
    sVar2 = sVar2 + 1;
    ad = ad + 2;
  }
  k_work_init_delayable((k_work_delayable *)&DAT_20002030,(void *)0x58d21);
  delay.ticks._4_4_ = 0x3c0000;
  delay.ticks._0_4_ = extraout_r1;
  k_work_reschedule((k_work_delayable *)&DAT_20002030,delay);
  return iVar1;
}


