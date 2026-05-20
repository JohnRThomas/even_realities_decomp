/*
 * Function: gui_clock_draw
 * Entry:    00046728
 * Prototype: undefined4 __stdcall gui_clock_draw(uint param_1, int param_2, int param_3, int param_4, int param_5, undefined4 param_6, char param_7)
 */


/* WARNING: Type propagation algorithm not settling */

undefined4
gui_clock_draw(uint param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              char param_7)

{
  size_t sVar1;
  GlassesState *pGVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  byte *pbVar7;
  size_t sVar8;
  void *local_50;
  uint local_4c;
  uint local_48 [2];
  undefined2 uStack_40;
  ushort local_3e;
  uint local_3c;
  byte local_38 [20];
  
  local_48[1] = 0;
  uStack_40 = 0;
  local_3e = 0;
  local_3c = 0;
  FUN_0004d1e0(param_1,(undefined2 *)(local_48 + 1));
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[8] = 0;
  local_38[9] = 0;
  local_38[10] = 0;
  local_38[0xb] = 0;
  local_38[0xc] = 0;
  local_38[0xd] = 0;
  local_38[0xe] = 0;
  local_38[0xf] = 0;
  uVar5 = (uint)local_3e;
  if (param_7 == '\0') {
    if (uVar5 < 0xd) {
      if (uVar5 == 0) {
        local_3e = 0xc;
      }
    }
    else {
      local_3e = local_3e - 0xc;
    }
    uVar5 = local_3e / 10;
    uVar6 = local_3e + (short)uVar5 * -10;
  }
  else {
    uVar5 = uVar5 / 10;
    uVar6 = local_3e + (short)uVar5 * -10;
  }
  __sprintf_chk((char *)local_38,0,0x10,"%d%d%s%d%d",uVar5,(uint)uVar6,":",(local_3c & 0xffff) / 10,
                (local_3c & 0xffff) % 10);
  sVar1 = strlen((char *)local_38);
  switch(param_6) {
  case 0:
    uVar5 = 0;
    break;
  case 1:
    iVar3 = FUN_000452e4();
    if (iVar3 << 0x1e < 0) {
      _clean_fb_data(DAT_2000aa14,0,param_2,param_3,param_4,param_5);
    }
    pbVar7 = local_38;
    iVar3 = param_2;
    for (sVar8 = 0; sVar1 != sVar8; sVar8 = sVar8 + 1) {
      local_50 = (void *)0x0;
      iVar4 = resource_manger_get(1,(uint)*pbVar7,&local_4c,local_48,&local_50,(undefined1 *)0x0);
      if ((iVar4 == 0) && (local_50 != (void *)0x0)) {
        FUN_00080c02(DAT_2000aa14,local_50,(int)local_4c / 2,local_48[0],iVar3,param_3);
        iVar3 = iVar3 + local_4c + 6;
      }
      else if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n"
                 ,"gui_clock_draw",(uint)*pbVar7,"EVEN_DASHBOARD_CLOCK_32x_TTF");
        }
        else {
          ble_printk("%s(): The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n"
                     ,"gui_clock_draw",(uint)*pbVar7,"EVEN_DASHBOARD_CLOCK_32x_TTF");
        }
      }
      pbVar7 = pbVar7 + 1;
    }
    goto LAB_00046850;
  case 2:
    iVar3 = FUN_000452e4();
    if (iVar3 << 0x1e < 0) {
      _clean_fb_data(DAT_2000aa14,0,param_2,param_3,param_4,param_5);
    }
    sVar8 = 0;
    pbVar7 = local_38;
    iVar3 = param_2;
    while (sVar1 != sVar8) {
      local_50 = (void *)0x0;
      iVar4 = resource_manger_get(2,(uint)*pbVar7,&local_4c,local_48,&local_50,(undefined1 *)0x0);
      sVar8 = sVar8 + 1;
      if ((iVar4 == 0) && (local_50 != (void *)0x0)) {
        FUN_00080c02(DAT_2000aa14,local_50,(int)local_4c / 2,local_48[0],iVar3,param_3);
        if (pbVar7[1] == 0x3a) {
          iVar4 = local_4c + 7;
        }
        else {
          iVar4 = local_4c + 2;
        }
        iVar3 = iVar3 + iVar4;
        if (*pbVar7 == 0x3a) {
          iVar3 = iVar3 + 7;
        }
      }
      else if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n"
                 ,"gui_clock_draw",(uint)*pbVar7,"EVEN_DASHBOARD_CLOCK_32x_TTF");
        }
        else {
          ble_printk("%s(): The content cannot be found in the current font library,unicode content = %2d,font libray is %s\n"
                     ,"gui_clock_draw",(uint)*pbVar7,"EVEN_DASHBOARD_CLOCK_32x_TTF");
        }
      }
      pbVar7 = pbVar7 + 1;
    }
LAB_00046850:
    iVar3 = FUN_000452e4();
    if (-1 < iVar3 << 0x1e) {
      return 0;
    }
    pGVar2 = __get_dashboard_state();
    iVar3 = *(int *)&pGVar2->field_0xeb4;
    pGVar2 = __get_dashboard_state();
    _reflash_fb_data_to_lcd(iVar3,*(int *)&pGVar2->field_0xeb8,param_2,param_3,param_4,param_5);
    return 0;
  case 3:
    uVar5 = 3;
    break;
  default:
    goto switchD_00046798_default;
  }
  gui_utf_draw(0,(char *)local_38,uVar5,param_2,param_3,param_4,param_5,1,0,0,(undefined *)0x0,0);
switchD_00046798_default:
  return 0;
}


