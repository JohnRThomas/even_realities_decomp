/*
 * Function: ?_nfc_related
 * Entry:    0002c710
 * Prototype: undefined __stdcall ?_nfc_related(undefined4 param_1, uint param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void __nfc_related(undefined4 param_1,uint param_2,undefined4 param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  GlassesState *pGVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 uVar7;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  undefined8 uVar8;
  longlong lVar9;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_2c = param_2;
  uStack_28 = param_3;
  iVar3 = z_impl_k_sem_init(&nfc_msg_sem,0,10);
  uVar7 = extraout_r2;
  if (iVar3 == 0) {
    uVar7 = 1;
    DAT_20019a56 = 1;
  }
  printk("[csh_debug_nfc] g_nfcMsgSemInitOk is %d \n",(uint)DAT_20019a56,uVar7,&DAT_20019a56,param_1
        );
  iVar3 = 0;
LAB_0002c732:
  do {
    pGVar4 = __get_dashboard_state();
    if (pGVar4->field_0x1 == '\b') {
      FUN_0002c6f4(10000);
      FUN_00033b18();
      uVar5 = 0x667;
    }
    else {
      pGVar4 = __get_dashboard_state();
      if (pGVar4->field_0x1 == '\x01') {
        uVar5 = 0x28000;
      }
      else {
        cVar2 = FUN_00033d5c();
        uVar7 = extraout_r1;
        if (cVar2 != '\x01') {
          do {
            timeout.ticks._4_4_ = 0x18000;
            timeout.ticks._0_4_ = uVar7;
            iVar6 = z_impl_k_sem_take(&nfc_msg_sem,timeout);
            cVar2 = DAT_20019a62;
            if (iVar6 != 0) {
              DAT_20019a62 = cVar2;
              if ((DAT_20019a62 == '\0') &&
                 (pGVar4 = __get_dashboard_state(), pGVar4->field_0x1 != '\b')) {
                lVar9 = FUN_0007fea6();
                lVar1 = CONCAT44(DAT_2000426c,DAT_20004268);
                uVar8 = FUN_0007fea6();
                uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
                if ((DAT_2000426c <= uVar5 &&
                     (uint)((uint)uVar8 <= DAT_20004268) <= DAT_2000426c - uVar5) &&
                   (lVar9 = lVar9 - lVar1, uVar5 = (uint)((ulonglong)lVar9 >> 0x20),
                   uVar5 != 0 || uVar5 < (3000 < (uint)lVar9))) {
                  set_box_status(IN_BOX,false);
                  set_box_status(LID_CLOSED,false);
                  DAT_20019a62 = cVar2;
                }
              }
              goto LAB_0002c732;
            }
            uStack_2c = uStack_2c & 0xffffff;
            uVar8 = FUN_0007fea6();
            uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
            if (DAT_2000426c <= uVar5 && (uint)((uint)uVar8 <= DAT_20004268) <= DAT_2000426c - uVar5
               ) {
              FUN_0002c6f4(0);
            }
            FUN_00027848((int)&uStack_2c + 3);
            if ((int)((uStack_2c >> 0x18) << 0x1a) < 0) {
              __init_nfc_comm();
              break;
            }
            iVar3 = iVar3 + 1;
            uVar7 = extraout_r1_00;
          } while (iVar3 < 10);
          set_box_status(IN_BOX,true);
          iVar3 = 0;
          goto LAB_0002c732;
        }
        iVar6 = __init_nfc_comm();
        if (iVar6 == 0) {
          set_box_status(IN_BOX,true);
          FUN_0002c6f4(0);
        }
        else {
          lVar9 = FUN_0007fea6();
          lVar1 = CONCAT44(DAT_2000426c,DAT_20004268);
          uVar8 = FUN_0007fea6();
          uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
          if ((DAT_2000426c <= uVar5 && (uint)((uint)uVar8 <= DAT_20004268) <= DAT_2000426c - uVar5)
             && (lVar9 = lVar9 - lVar1, uVar5 = (uint)((ulonglong)lVar9 >> 0x20),
                uVar5 != 0 || uVar5 < (5000 < (uint)lVar9))) {
            set_box_status(IN_BOX,false);
          }
        }
        pGVar4 = __get_dashboard_state();
        if (pGVar4->field_0x10a0 == '\x01') {
          __init_serial_comm();
        }
        uVar5 = 0x1334;
      }
    }
    timeout_00.ticks._4_4_ = 0;
    timeout_00.ticks._0_4_ = uVar5;
    z_impl_k_sleep(timeout_00);
  } while( true );
}


