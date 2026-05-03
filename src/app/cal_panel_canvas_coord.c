/*
 * Function: cal_panel_canvas_coord
 * Entry:    000450dc
 * Prototype: undefined __stdcall cal_panel_canvas_coord(int * param_1, int * param_2)
 */


void cal_panel_canvas_coord(int *param_1,int *param_2)

{
  GlassesState *pGVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    iVar3 = *param_1;
    pGVar1 = __get_dashboard_state();
    switch(pGVar1->field_0xec1) {
    case 1:
      iVar2 = 0x16;
      break;
    case 2:
      iVar2 = 8;
      break;
    default:
      iVar2 = 0;
      break;
    case 4:
      iVar2 = -4;
      break;
    case 5:
      iVar2 = -8;
      break;
    case 6:
      iVar2 = -10;
      break;
    case 7:
      iVar2 = -0xc;
      break;
    case 8:
      iVar2 = -0xe;
      break;
    case 9:
      iVar2 = -0x10;
    }
    *param_1 = iVar2;
    pGVar1 = __get_dashboard_state();
    if (*(char *)pGVar1 == '\x01') {
      *param_1 = -*param_1;
    }
    if ((*param_1 != iVar3) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        pGVar1 = __get_dashboard_state();
        printk("%s(): canvas_distance_gear:%d, pos_x:%d\n","cal_panel_canvas_coord",
               (uint)(byte)pGVar1->field_0xec1,*param_1);
      }
      else {
        pGVar1 = __get_dashboard_state();
        ble_printk("%s(): canvas_distance_gear:%d, pos_x:%d\n","cal_panel_canvas_coord",
                   (uint)(byte)pGVar1->field_0xec1,*param_1);
      }
    }
  }
  if (param_2 != (int *)0x0) {
    iVar2 = *param_2;
    pGVar1 = __get_dashboard_state();
    iVar3 = (8 - (uint)(byte)pGVar1->field_0xec0) * 0x23;
    *param_2 = iVar3;
    if ((iVar3 - iVar2 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        pGVar1 = __get_dashboard_state();
        printk("%s(): raster_height_gear:%d, pos_y:%d\n","cal_panel_canvas_coord",
               (uint)(byte)pGVar1->field_0xec0,*param_2);
        return;
      }
      pGVar1 = __get_dashboard_state();
      ble_printk("%s(): raster_height_gear:%d, pos_y:%d\n","cal_panel_canvas_coord",
                 (uint)(byte)pGVar1->field_0xec0,*param_2);
      return;
    }
  }
  return;
}


