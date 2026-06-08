/*
 * Function: bt_receive_cb
 * Entry:    00018070
 * Prototype: undefined __stdcall bt_receive_cb(k_work * param_1, byte * packet_data, uint packet_size)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void bt_receive_cb(k_work *param_1,byte *packet_data,uint packet_size)

{
  longlong lVar1;
  undefined4 uVar2;
  k_work_delayable *pkVar3;
  GlassesState *pGVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 extraout_r2;
  char *pcVar11;
  ulonglong uVar12;
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
  pkVar3 = k_work_delayable_from_work(param_1);
  switch(*(undefined1 *)&(pkVar3->work).node.next) {
  case 0:
    pcVar11 = "public";
    break;
  case 1:
    pcVar11 = "random";
    break;
  case 2:
    pcVar11 = "public-id";
    break;
  case 3:
    pcVar11 = "random-id";
    break;
  default:
    snprintk(local_158,10,"0x%02x");
    goto LAB_000180b8;
  }
  strcpy(local_158,pcVar11);
LAB_000180b8:
  uVar5 = (uint)*(byte *)((int)&(pkVar3->work).node.next + 1);
  uVar6 = (uint)*(byte *)((int)&(pkVar3->work).node.next + 2);
  uVar7 = (uint)*(byte *)((int)&(pkVar3->work).node.next + 3);
  uVar8 = (uint)*(byte *)&(pkVar3->work).handler;
  uVar9 = (uint)*(byte *)((int)&(pkVar3->work).handler + 1);
  pcVar11 = local_158;
  snprintk(local_144,0x1e,"%02X:%02X:%02X:%02X:%02X:%02X (%s)",
           (uint)*(byte *)((int)&(pkVar3->work).handler + 2),uVar9,uVar8,uVar7,uVar6,uVar5,local_158
          );
  if (0 < LOG_LEVEL) {
    uVar9 = (uint)*packet_data;
    uVar8 = (uint)packet_data[1];
    uVar7 = (uint)packet_data[2];
    uVar6 = (uint)packet_data[3];
    uVar5 = (uint)packet_data[4];
    pcVar11 = (char *)(uint)packet_data[5];
    if (BLE_DEBUG == 0) {
      printk(
            "%s(): **Received data from: %s, len=%d,cmd 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x,receiver_thd_is_running is %d\n"
            );
    }
    else {
      ble_printk("%s(): **Received data from: %s, len=%d,cmd 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x,receiver_thd_is_running is %d\n"
                 ,"bt_receive_cb",local_144,packet_size);
    }
  }
  uVar10 = GLOBAL_STATE._52_4_;
  uVar12 = sys_clock_tick_get();
  uVar2 = GLOBAL_STATE._52_4_;
  lVar1 = (uVar12 & 0xffffffff) * 1000;
  *(uint *)(uVar10 + 0x368) =
       (uint)lVar1 >> 0xf |
       ((int)(uVar12 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000;
  uVar10 = GLOBAL_STATE._52_4_;
  if ((*(char *)(uVar2 + 0x248) == '\0') && (*(int *)(uVar2 + 0x220) == 0)) {
    if (packet_size < 0x15) {
      memcpy(*(void **)(GLOBAL_STATE._52_4_ + 0x254),packet_data,packet_size);
      memset((void *)(*(int *)(uVar10 + 0x254) + packet_size),0,0x14 - packet_size);
      *(undefined4 *)(uVar10 + 0x358) = 0;
      *(uint *)(uVar10 + 0x360) = packet_size;
    }
    else {
      if (0x100 < packet_size) {
        if (BLE_DEBUG == 0) {
          uVar10 = 0x6f;
          goto LAB_00018206;
        }
        uVar10 = 0x6f;
        goto LAB_000181f8;
      }
      memcpy((void *)(GLOBAL_STATE._52_4_ + 600),packet_data,packet_size);
      *(uint *)(uVar10 + 0x358) = packet_size;
    }
    *(undefined4 *)(uVar10 + 0x35c) = 1;
    k_sem_give((k_sem *)(uVar10 + 0x218));
  }
  else {
    local_158[0] = '\0';
    local_158[1] = '\0';
    local_158[2] = '\0';
    local_158[3] = '\0';
    memset(local_158 + 4,0,0x10);
    if (*packet_data == 0x18) {
      local_158[1] = 0xc9;
      (**(code **)(GLOBAL_STATE._52_4_ + 0xc))(local_158,0x14);
      pGVar4 = __get_dashboard_state();
      if ((*(char *)pGVar4 == '\x02') &&
         (pGVar4 = __get_dashboard_state(), pGVar4->field_0xd5 == '\x06')) {
        z_impl_k_sleep((k_timeout_t)0x667);
      }
      pGVar4 = __get_dashboard_state();
      FUN_0007ff66((int)pGVar4,0);
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
      uVar10 = 0x5e;
LAB_00018206:
      printk("[%s-%d]len is %d, too large ! \n","bt_receive_cb",uVar10,packet_size,uVar9,uVar8,uVar7
             ,uVar6,uVar5,pcVar11);
      return;
    }
    uVar10 = 0x5e;
LAB_000181f8:
    ble_printk("[%s-%d]len is %d, too large ! \n","bt_receive_cb",uVar10,packet_size);
  }
  return;
}


