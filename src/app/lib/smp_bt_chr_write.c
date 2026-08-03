/*
 * Function: smp_bt_chr_write
 * Entry:    00055d04
 * Prototype: ssize_t __stdcall smp_bt_chr_write(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset, uint8_t flags)
 */


/* exclude_from_export */

ssize_t smp_bt_chr_write(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset,
                        uint8_t flags)

{
  log_msg_desc desc;
  conn_param_data *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  conn_param_data *pcVar5;
  int extraout_r1;
  k_timeout_t delay;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 local_38;
  char *local_34;
  bt_conn *pbStack_30;
  bt_le_conn_param *local_28;
  undefined4 uStack_24;
  
  pcVar1 = conn_param_data_get(conn);
  if (pcVar1 == (conn_param_data *)0x0) {
    local_34 = "Null cpd object for connection %p";
    local_38 = 3;
    desc.level = (dword)&local_38;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffb8;
    pbStack_30 = conn;
    z_impl_z_log_msg_static_create
              (&PTR_s_mcumgr_smp_0008b9c8,desc,in_stack_ffffffbc,in_stack_ffffffc0);
  }
  else {
    iVar2 = smp_reassembly_expected(&smp_bt_transport);
    iVar3 = smp_reassembly_collect(&smp_bt_transport,buf,len);
    if (iVar3 != -0xc) {
      if (iVar3 < 0) {
        puVar4 = smp_reassembly_get_ud(&smp_bt_transport);
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = 0;
          *(undefined1 *)(puVar4 + 1) = 0;
        }
        smp_reassembly_drop(&smp_bt_transport);
        return -0x13;
      }
      if (iVar2 < 0) {
        puVar4 = smp_reassembly_get_ud(&smp_bt_transport);
        pcVar5 = conn_param_data_get(conn);
        if (pcVar5 != (conn_param_data *)0x0) {
          iVar2 = (uint)(byte)pcVar5[5].smp_notify_sem << 0x1f;
          if (-1 < iVar2) {
            local_28 = &bt_le_conn_param_00090006;
            uStack_24._0_2_ = 0;
            uStack_24._2_2_ = 0x2a;
            conn_param_set(conn,(bt_le_conn_param *)&local_28);
            *(byte *)&pcVar5[5].smp_notify_sem = (byte)pcVar5[5].smp_notify_sem | 1;
            iVar2 = extraout_r1;
          }
          delay.ticks._4_4_ = 0x28000;
          delay.ticks._0_4_ = iVar2;
          k_work_reschedule((k_work_delayable *)&pcVar5->ework,delay);
        }
        *puVar4 = conn;
        *(undefined1 *)(puVar4 + 1) = *(undefined1 *)((int)&pcVar1[5].smp_notify_sem + 1);
      }
      if (iVar3 != 0) {
        return (uint)len;
      }
      smp_reassembly_complete(&smp_bt_transport,false);
      return (uint)len;
    }
  }
  return -0x11;
}


