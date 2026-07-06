/*
 * Function: ?_draw_time
 * Entry:    00036e78
 * Prototype: undefined __stdcall ?_draw_time(char * param_1, dashboard_ts_context * param_2)
 */


void __draw_time(char *param_1,dashboard_ts_context *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  GlassesState *pGVar4;
  int iVar5;
  int iVar6;
  GlassesState *pGVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  
  pGVar4 = __get_dashboard_state();
  iVar5 = FUN_00080732();
  uVar11 = iVar5 - (int)param_2;
  memset(param_1,0,0x20);
  uVar10 = uVar11 & ~((int)uVar11 >> 0x1f);
  if (BLE_DEBUG == 0) {
    printk("currentTime is %d,recvTime is %d,unReadTime is %d \n",iVar5,param_2,uVar10);
  }
  else {
    ble_printk("currentTime is %d,recvTime is %d,unReadTime is %d \n",iVar5,param_2,uVar10);
  }
  bVar1 = get_current_language();
  uVar11 = uVar11 - 0x3c;
  if (bVar1 == 6) {
    if (0x7fffffc3 < uVar11) {
      pcVar8 = "Jetzt";
      goto LAB_00036eca;
    }
    if (uVar10 - 0x3c < 0xdd4) {
      uVar10 = uVar10 / 0x3c;
      pcVar8 = "Vor %d Min.";
    }
    else {
      if (0x1c1f < uVar10 - 0xe10) {
        if ((undefined **)(uVar10 - 0x2a30) < &PTR_DAT_00012750) {
          local_2c = 0;
          local_28 = 0;
          local_24 = 0;
          __init_burial_point_date(param_2,(undefined2 *)&local_2c);
          uVar11 = local_24 & 0xffff;
          uVar10 = local_28 >> 0x10;
LAB_00036fba:
          pcVar8 = "%02d:%02d";
LAB_00036fbc:
          sprintf(param_1,pcVar8,uVar10,uVar11);
          goto LAB_00036efa;
        }
        if (uVar10 - 0x15180 < 0x15180) {
          pcVar8 = "Gestern";
        }
        else {
          if (0x6977f < uVar10 - 0x2a300) {
            local_2c = 0;
            local_28 = 0;
            local_24 = 0;
            __init_burial_point_date(param_2,(undefined2 *)&local_2c);
            uVar2 = (ushort)local_28;
            uVar3 = local_2c._2_2_;
LAB_00037006:
            uVar11 = (uint)uVar3;
            uVar10 = (uint)uVar2;
            pcVar8 = "%02d/%02d";
            goto LAB_00036fbc;
          }
LAB_00036fe4:
          pcVar8 = (char *)FUN_0004d2cc(param_2);
        }
        goto LAB_00036eca;
      }
      pcVar8 = "Vor %d Std.";
      uVar10 = uVar10 / 0xe10;
    }
    goto LAB_00036ef4;
  }
  if (bVar1 == 5) {
    if (uVar11 < 0x7fffffc4) {
      if (uVar10 - 0x3c < 0xdd4) {
        pcVar8 = "%d min";
        uVar10 = uVar10 / 0x3c;
      }
      else {
        if (0x1c1f < uVar10 - 0xe10) {
          if ((undefined **)(uVar10 - 0x2a30) < &PTR_DAT_00012750) goto LAB_0003704e;
          if (0x1517f < uVar10 - 0x15180) goto LAB_00037288;
          pcVar8 = "Hier";
          goto LAB_00036eca;
        }
        pcVar8 = "%d h";
        uVar10 = uVar10 / 0xe10;
      }
LAB_00036ef4:
      sprintf(param_1,pcVar8,uVar10);
      goto LAB_00036efa;
    }
    pcVar8 = "Maintenant";
  }
  else if (bVar1 == 7) {
    if (uVar11 < 0x7fffffc4) {
      if (uVar10 - 0x3c < 0xdd4) {
        pcVar8 = "hace %d\'";
        uVar10 = uVar10 / 0x3c;
      }
      else {
        if (0x1c1f < uVar10 - 0xe10) {
          if ((undefined **)(uVar10 - 0x2a30) < &PTR_DAT_00012750) goto LAB_0003704e;
          if (0x1517f < uVar10 - 0x15180) goto LAB_00037288;
          pcVar8 = "Ayer";
          goto LAB_00036eca;
        }
        pcVar8 = "hace %d h";
        uVar10 = uVar10 / 0xe10;
      }
      goto LAB_00036ef4;
    }
    pcVar8 = "Ahora";
  }
  else if (bVar1 == 0xe) {
    if (uVar11 < 0x7fffffc4) {
      if (uVar10 - 0x3c < 0xdd4) {
        pcVar8 = "%d min fa";
        uVar10 = uVar10 / 0x3c;
      }
      else {
        if (0x1c1f < uVar10 - 0xe10) {
          if ((undefined **)(uVar10 - 0x2a30) < &PTR_DAT_00012750) {
LAB_0003704e:
            local_2c = 0;
            local_28 = 0;
            local_24 = 0;
            __init_burial_point_date(param_2,(undefined2 *)&local_2c);
            if (BLE_DEBUG == 0) {
              printk("date: %u: %04d/%02d/%02d-%02d:%02d:%02d",param_2,local_2c & 0xffff,
                     local_2c >> 0x10,local_28 & 0xffff,local_28 >> 0x10,local_24 & 0xffff,
                     local_24 >> 0x10);
            }
            else {
              ble_printk("date: %u: %04d/%02d/%02d-%02d:%02d:%02d",param_2,local_2c & 0xffff,
                         local_2c >> 0x10);
            }
            if (BLE_DEBUG == 0) {
              pGVar7 = __get_dashboard_state();
              printk("time_disp_mode is %d \n",(uint)(byte)pGVar7->dashboard_ts->time_disp_mode);
            }
            else {
              pGVar7 = __get_dashboard_state();
              ble_printk("time_disp_mode is %d \n",(uint)(byte)pGVar7->dashboard_ts->time_disp_mode)
              ;
            }
            pGVar7 = __get_dashboard_state();
            uVar10 = local_28 >> 0x10;
            uVar11 = local_24 & 0xffff;
            if ((char)pGVar7->dashboard_ts->time_disp_mode != '\0') {
              if (uVar10 < 0xd) {
                if (uVar10 == 0) {
                  uVar10 = 0xc;
                  local_28 = CONCAT22(0xc,(ushort)local_28);
                }
                pcVar8 = "%02d:%02dam";
              }
              else {
                uVar9 = uVar10 - 0xc;
                uVar10 = uVar9 & 0xffff;
                pcVar8 = "%02d:%02dpm";
                local_28 = CONCAT22((short)uVar9,(ushort)local_28);
              }
              goto LAB_00036fbc;
            }
            goto LAB_00036fba;
          }
          if (0x1517f < uVar10 - 0x15180) {
LAB_00037288:
            if (0x6977f < uVar10 - 0x2a300) {
              local_2c = 0;
              local_28 = 0;
              local_24 = 0;
              __init_burial_point_date(param_2,(undefined2 *)&local_2c);
              uVar2 = local_2c._2_2_;
              uVar3 = (ushort)local_28;
              goto LAB_00037006;
            }
            goto LAB_00036fe4;
          }
          pcVar8 = "Ieri";
          goto LAB_00036eca;
        }
        pcVar8 = "%d ore fa";
        uVar10 = uVar10 / 0xe10;
      }
      goto LAB_00036ef4;
    }
    pcVar8 = "Adesso";
  }
  else {
    if (uVar11 < 0x7fffffc4) {
      if (uVar10 - 0x3c < 0xdd4) {
        pcVar8 = "%dm ago";
        uVar10 = uVar10 / 0x3c;
      }
      else {
        if (0x1c1f < uVar10 - 0xe10) {
          if ((undefined **)(uVar10 - 0x2a30) < &PTR_DAT_00012750) goto LAB_0003704e;
          if (0x1517f < uVar10 - 0x15180) goto LAB_00037288;
          pcVar8 = "Yesterday";
          goto LAB_00036eca;
        }
        pcVar8 = "%dh ago";
        uVar10 = uVar10 / 0xe10;
      }
      goto LAB_00036ef4;
    }
    pcVar8 = "Now";
  }
LAB_00036eca:
  strcpy(param_1,pcVar8);
LAB_00036efa:
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  iVar6 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  _clean_fb_data((byte *)&(pGVar4->jdb_panel_context).__panel_buffer,0,iVar5 + 0x196,(uint)uVar2,
                 iVar6 + 0x200,uVar3 + 0x1b);
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  iVar6 = FUN_000809e2();
  uVar3 = FUN_00080a3a();
  gui_utf_draw_align_right
            (0,param_1,0,iVar5 + 0x196,(uint)uVar2,iVar6 + 0x200,uVar3 + 0x1b,1,0,0,(undefined *)0x0
             ,0);
  if (BLE_DEBUG != 0) {
    iVar5 = FUN_000809e2();
    ble_printk("gui_getScreenoffset_x=%d,timeDiffBuf is %s \n",iVar5,param_1);
    return;
  }
  iVar5 = FUN_000809e2();
  printk("gui_getScreenoffset_x=%d,timeDiffBuf is %s \n",iVar5,param_1);
  return;
}


