/*
 * Function: ccc_set
 * Entry:    0005e238
 * Prototype: int __stdcall ccc_set(char * name, size_t len_rd, settings_read_cb read_cb, void * cb_arg)
 */


/* exclude_from_export_ai */

int ccc_set(char *name,size_t len_rd,settings_read_cb read_cb,void *cb_arg)

{
  int iVar1;
  char *in_stack_00000000;
  undefined1 *local_110;
  char *local_10c;
  char *pcStack_108;
  undefined2 local_104;
  char *local_100;
  char *local_fc;
  bt_addr_le_t bStack_f8;
  bt_addr_le_t *local_f0;
  undefined1 local_ec;
  undefined1 *local_e8;
  uint uStack_e4;
  undefined1 auStack_e0 [16];
  char local_d0 [4];
  char *local_cc;
  
  iVar1 = settings_name_steq(in_stack_00000000,"bt/ccc",&local_100);
  if (iVar1 == 0) {
    iVar1 = open_cb();
  }
  else {
    settings_name_next(local_100,&local_fc);
    if (local_100 == (char *)0x0) {
      local_cc = "Insufficient number of arguments";
      local_d0[0] = '\x02';
      local_d0[1] = '\0';
      local_d0[2] = '\0';
      local_d0[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_d0);
    }
    else {
      if ((local_fc == (char *)0x0) ||
         (pcStack_108 = (char *)strtoul(local_fc,(char **)0x0,10), pcStack_108 == (char *)0x0)) {
        local_ec = 0;
        iVar1 = bt_settings_decode_key(local_100,&bStack_f8);
        if (iVar1 == 0) {
          local_f0 = &bStack_f8;
          if (len_rd == 0) {
            local_e8 = (undefined1 *)0x0;
            uStack_e4 = 0;
          }
          else {
            uStack_e4 = (*(code *)read_cb)(cb_arg,auStack_e0,0xc0);
            if ((int)uStack_e4 < 0) {
              local_10c = "Failed to decode value (err %zd)";
              local_110 = (undefined1 *)0x3;
              pcStack_108 = (char *)uStack_e4;
              LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1840,(char *)&local_110);
              return uStack_e4;
            }
            uStack_e4 = uStack_e4 >> 2;
            local_e8 = auStack_e0;
          }
          bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d099,&local_f0);
          return 0;
        }
        iVar1 = 0x1c40;
        local_10c = "Unable to decode address %s";
        pcStack_108 = local_100;
        local_104 = 0x200;
        local_110 = &DAT_01000003;
      }
      else {
        iVar1 = 0x1840;
        local_10c = "Invalid local identity %lu";
        local_110 = (undefined1 *)0x3;
      }
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,iVar1,(char *)&local_110);
    }
    iVar1 = -0x16;
  }
  return iVar1;
}


