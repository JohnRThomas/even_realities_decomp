/*
 * Function: bt_rpmsg_rx
 * Entry:    000634f8
 * Prototype: void __stdcall bt_rpmsg_rx(uint8_t * data, size_t len)
 */


/* exclude_from_export */

void bt_rpmsg_rx(uint8_t *data,size_t len)

{
  net_buf *buf;
  net_buf *buf_00;
  uint8_t *mem;
  uint uVar1;
  size_t len_00;
  uint uVar2;
  bool discardable;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  k_timeout_t timeout_01;
  char local_58 [4];
  char *local_54;
  uint uStack_50;
  size_t local_4c;
  uint local_44 [5];
  char local_30 [4];
  char *local_2c;
  
  uVar2 = (uint)*data;
  uVar1 = len - 1;
  if (uVar2 == 4) {
    if (uVar1 < 2) {
      local_2c = "Not enough data for event header";
LAB_0006353a:
      local_30[0] = '\x02';
      local_30[1] = '\0';
      local_30[2] = '\0';
      local_30[3] = '\0';
      LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1040,local_30);
      return;
    }
    if (data[1] == '>') {
      discardable = data[3] == '\x02';
    }
    else {
      discardable = false;
    }
    len_00 = len - 3;
    local_44[0] = CONCAT22(local_44[0]._2_2_,*(ushort *)(data + 1));
    if (len_00 != *(ushort *)(data + 1) >> 8) {
      local_2c = "Event payload length is not correct";
      goto LAB_0006353a;
    }
    if (discardable) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x50000;
    }
    while( true ) {
      timeout_01.ticks._4_4_ = 0;
      timeout_01.ticks._0_4_ = uVar1;
      buf = bt_buf_get_evt((uint8_t)local_44[0],discardable,timeout_01);
      if (buf != (net_buf *)0x0) break;
      if (discardable) {
        return;
      }
      local_30[0] = '\x02';
      local_30[1] = '\0';
      local_30[2] = '\0';
      local_30[3] = '\0';
      local_2c = "Couldn\'t allocate a buffer after waiting 10 seconds.";
      LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1080,local_30);
    }
    buf_00 = (net_buf *)&buf->field6_0xc;
    net_buf_add_mem(buf_00,local_44,2);
    local_4c = net_buf_simple_tailroom((net_buf_simple *)buf_00);
    if (len_00 <= local_4c) {
      mem = data + 3;
LAB_0006365e:
      net_buf_add_mem(buf_00,mem,len_00);
      bt_recv(buf);
      return;
    }
  }
  else if (uVar2 == 5) {
    if (uVar1 < 4) {
      local_2c = "Not enough data for ISO header";
      goto LAB_0006353a;
    }
    timeout_00.ticks._4_4_ = 0;
    timeout_00.ticks._0_4_ = len;
    buf = bt_buf_get_rx(5,timeout_00);
    if (buf == (net_buf *)0x0) {
      local_2c = "No available ISO buffers!";
      goto LAB_0006353a;
    }
    local_44[0] = *(uint *)(data + 1);
    buf_00 = (net_buf *)&buf->field6_0xc;
    net_buf_add_mem(buf_00,local_44,4);
    len_00 = len - 5;
    if (len_00 != (local_44[0] >> 0x10 & 0x3fff)) {
      local_2c = "ISO payload length is not correct";
      goto LAB_00063634;
    }
    local_4c = net_buf_simple_tailroom((net_buf_simple *)buf_00);
    if (len_00 <= local_4c) {
      mem = data + 5;
      goto LAB_0006365e;
    }
  }
  else {
    if (uVar2 != 2) {
      local_54 = "Unknown HCI type %u";
      local_58[0] = '\x03';
      local_58[1] = '\0';
      local_58[2] = '\0';
      local_58[3] = '\0';
      uStack_50 = uVar2;
      LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1840,local_58);
      return;
    }
    if (uVar1 < 4) {
      local_2c = "Not enough data for ACL header";
      goto LAB_0006353a;
    }
    timeout.ticks._4_4_ = 0;
    timeout.ticks._0_4_ = len;
    buf = bt_buf_get_rx(3,timeout);
    if (buf == (net_buf *)0x0) {
      local_2c = "No available ACL buffers!";
      goto LAB_0006353a;
    }
    local_44[0] = *(uint *)(data + 1);
    buf_00 = (net_buf *)&buf->field6_0xc;
    net_buf_add_mem(buf_00,local_44,4);
    len_00 = len - 5;
    if (len_00 != local_44[0] >> 0x10) {
      local_2c = "ACL payload length is not correct";
LAB_00063634:
      local_30[0] = '\x02';
      local_30[1] = '\0';
      local_30[2] = '\0';
      local_30[3] = '\0';
      LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1040,local_30);
      goto LAB_00063642;
    }
    local_4c = net_buf_simple_tailroom((net_buf_simple *)buf_00);
    if (len_00 <= local_4c) {
      mem = data + 5;
      goto LAB_0006365e;
    }
  }
  local_54 = "Not enough space in buffer %zu/%zu";
  local_58[0] = '\x04';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  uStack_50 = len_00;
  LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x2040,local_58);
LAB_00063642:
  net_buf_unref(buf);
  return;
}


