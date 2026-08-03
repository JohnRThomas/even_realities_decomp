/*
 * Function: bt_smp_recv
 * Entry:    00060f8c
 * Prototype: int __stdcall bt_smp_recv(bt_l2cap_chan * chan, net_buf * req_buf)
 */


/* exclude_from_export_ai */

int bt_smp_recv(bt_l2cap_chan *chan,net_buf *req_buf)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bt_smp *smp;
  char local_48 [4];
  char *local_44;
  uint uStack_40;
  uint local_3c;
  char local_28 [4];
  char *local_24;
  
  if ((req_buf->field6_0xc).field0.len == 0) {
    local_24 = "Too small SMP PDU received";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_28);
    return 0;
  }
  pbVar2 = net_buf_simple_pull_mem(&(req_buf->field6_0xc).b,1);
  smp = (bt_smp *)(chan + -0xc);
  bVar1 = atomic_test_bit((atomic_t *)&chan[-0xc].ops,4);
  uVar3 = (uint)*pbVar2;
  if (bVar1) {
    local_44 = "SMP command (code 0x%02x) received after timeout";
  }
  else {
    if (uVar3 < 0xf) {
      if ((&PTR_0008f098)[uVar3 * 2] == (undefined *)0x0) {
        local_44 = "Unhandled SMP code 0x%02x";
        local_48[0] = '\x03';
        local_48[1] = '\0';
        local_48[2] = '\0';
        local_48[3] = '\0';
        uStack_40 = uVar3;
        LOG_ERR(&PTR_s_bt_smp_0008b930,0x1880,local_48);
        iVar4 = 7;
      }
      else {
        bVar1 = atomic_test_and_clear_bit((atomic_t *)smp,uVar3);
        uVar3 = (uint)*pbVar2;
        if (bVar1) {
          uVar5 = (uint)(req_buf->field6_0xc).field0.len;
          if (*(byte *)(&PTR_0008f09c + uVar3 * 2) == uVar5) {
            iVar4 = (*(code *)(&PTR_0008f098)[uVar3 * 2])(smp,req_buf);
            if (iVar4 == 0) {
              return 0;
            }
          }
          else {
            local_44 = "Invalid len %u for code 0x%02x";
            local_48[0] = '\x04';
            local_48[1] = '\0';
            local_48[2] = '\0';
            local_48[3] = '\0';
            uStack_40 = uVar5;
            local_3c = uVar3;
            LOG_ERR(&PTR_s_bt_smp_0008b930,0x2040,local_48);
            iVar4 = 10;
          }
        }
        else {
          local_44 = "Unexpected SMP code 0x%02x";
          local_48[0] = '\x03';
          local_48[1] = '\0';
          local_48[2] = '\0';
          local_48[3] = '\0';
          uStack_40 = uVar3;
          LOG_ERR(&PTR_s_bt_smp_0008b930,0x1880,local_48);
          bVar1 = atomic_test_bit((atomic_t *)&chan[-0xc].ops,3);
          if (!bVar1) {
            return 0;
          }
          iVar4 = 8;
        }
      }
      smp_error(smp,(uint8_t)iVar4);
      return 0;
    }
    local_44 = "Received reserved SMP code 0x%02x";
  }
  local_48[0] = '\x03';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  uStack_40 = uVar3;
  LOG_ERR(&PTR_s_bt_smp_0008b930,0x1880,local_48);
  return 0;
}


