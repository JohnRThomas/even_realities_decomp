/*
 * Function: bt_receive_cb
 * Entry:    00018070
 * Prototype: undefined __stdcall bt_receive_cb(k_work * param_1, byte * packet_data, uint packet_size)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_receive_cb(k_work *param_1,byte *packet_data,uint packet_size)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  k_work_delayable *pkVar4;
  GlassesState *pGVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 extraout_r2;
  char *pcVar12;
  ulonglong uVar13;
  char local_158 [20];
  char local_144 [32];
  undefined1 local_124;
  undefined1 auStack_123 [259];
  
  local_144[0] = '\0';
  local_144[1] = '\0';
  local_144[2] = '\0';
  local_144[3] = '\0';
  memset(local_144 + 4,0,0x1a);
  memset(&local_124,0,0x101);
  pkVar4 = k_work_delayable_from_work(param_1);
  switch(*(undefined1 *)&(pkVar4->work).node.next) {
  case 0:
    pcVar12 = "public";
    break;
  case 1:
    pcVar12 = "random";
    break;
  case 2:
    pcVar12 = "public-id";
    break;
  case 3:
    pcVar12 = "random-id";
    break;
  default:
    snprintk(local_158,10,"0x%02x");
    goto LAB_000180b8;
  }
  strcpy(local_158,pcVar12);
LAB_000180b8:
  uVar6 = (uint)*(byte *)((int)&(pkVar4->work).node.next + 1);
  uVar7 = (uint)*(byte *)((int)&(pkVar4->work).node.next + 2);
  uVar8 = (uint)*(byte *)((int)&(pkVar4->work).node.next + 3);
  uVar9 = (uint)*(byte *)&(pkVar4->work).handler;
  uVar10 = (uint)*(byte *)((int)&(pkVar4->work).handler + 1);
  pcVar12 = local_158;
  snprintk(local_144,0x1e,"%02X:%02X:%02X:%02X:%02X:%02X (%s)",
           (uint)*(byte *)((int)&(pkVar4->work).handler + 2),uVar10,uVar9,uVar8,uVar7,uVar6,
           local_158);
  if (0 < LOG_LEVEL) {
    uVar10 = (uint)*packet_data;
    uVar9 = (uint)packet_data[1];
    uVar8 = (uint)packet_data[2];
    uVar7 = (uint)packet_data[3];
    uVar6 = (uint)packet_data[4];
    pcVar12 = (char *)(uint)packet_data[5];
    if (BLE_DEBUG == 0) {
      printk(
            "%s(): **Received data from: %s, len=%d,cmd 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x,receiver_thd_is_running is %d\n"
            );
    }
    else {
      ble_printk("%s(): **Received data from: %s, len=%d,cmd 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x,receiver_thd_is_running is %d\n"
                 ,"bt_receive_cb",local_144,packet_size,uVar10,uVar9,uVar8,uVar7,uVar6,pcVar12,
                 (uint)*(byte *)(_DAT_20006c10 + 0x248));
    }
  }
  iVar2 = _DAT_20006c10;
  uVar13 = sys_clock_tick_get();
  iVar3 = _DAT_20006c10;
  lVar1 = (uVar13 & 0xffffffff) * 1000;
  *(uint *)(iVar2 + 0x368) =
       (uint)lVar1 >> 0xf |
       ((int)(uVar13 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
  iVar2 = _DAT_20006c10;
  if ((*(char *)(iVar3 + 0x248) == '\0') && (*(int *)(iVar3 + 0x220) == 0)) {
    if (packet_size < 0x15) {
      memcpy(*(void **)(_DAT_20006c10 + 0x254),packet_data,packet_size);
      memset((void *)(*(int *)(iVar2 + 0x254) + packet_size),0,0x14 - packet_size);
      *(undefined4 *)(iVar2 + 0x358) = 0;
      *(uint *)(iVar2 + 0x360) = packet_size;
    }
    else {
      if (0x100 < packet_size) {
        if (BLE_DEBUG == 0) {
          uVar11 = 0x6f;
          goto LAB_00018206;
        }
        uVar11 = 0x6f;
        goto LAB_000181f8;
      }
      memcpy((void *)(_DAT_20006c10 + 600),packet_data,packet_size);
      *(uint *)(iVar2 + 0x358) = packet_size;
    }
    *(undefined4 *)(iVar2 + 0x35c) = 1;
    k_sem_give((k_sem *)(iVar2 + 0x218));
  }
  else {
    local_158[0] = '\0';
    local_158[1] = '\0';
    local_158[2] = '\0';
    local_158[3] = '\0';
    memset(local_158 + 4,0,0x10);
    if (*packet_data == 0x18) {
      local_158[1] = 0xc9;
      (**(code **)(_DAT_20006c10 + 0xc))(local_158,0x14);
      pGVar5 = __get_dashboard_state();
      if ((*(char *)pGVar5 == '\x02') &&
         (pGVar5 = __get_dashboard_state(), pGVar5->field20_0xc8[0xd] == '\x06')) {
        z_impl_k_sleep((k_timeout_t)0x667);
      }
      pGVar5 = __get_dashboard_state();
      FUN_0007ff66((int)pGVar5,0);
      return;
    }
    if (packet_size < 0x101) {
      local_124 = (char)packet_size;
      memset(auStack_123,0,0x100);
      memcpy(auStack_123,packet_data,packet_size);
      enqueue_bt_data(auStack_123,(char)packet_size);
      if (LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): enqueue because busy\n","bt_receive_cb",extraout_r2,BLE_DEBUG);
        return;
      }
      printk("%s(): enqueue because busy\n");
      return;
    }
    if (BLE_DEBUG == 0) {
      uVar11 = 0x5e;
LAB_00018206:
      printk("[%s-%d]len is %d, too large ! \n","bt_receive_cb",uVar11,packet_size);
      return;
    }
    uVar11 = 0x5e;
LAB_000181f8:
    ble_printk("[%s-%d]len is %d, too large ! \n","bt_receive_cb",uVar11,packet_size,uVar10,uVar9,
               uVar8,uVar7,uVar6,pcVar12);
  }
  return;
}


