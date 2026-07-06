/*
 * Function: cal_panel_canvas_coord
 * Entry:    000450dc
 * Prototype: undefined __stdcall cal_panel_canvas_coord(int * horizontal_offset, int * vertical_offset)
 */


void cal_panel_canvas_coord(int *horizontal_offset,int *vertical_offset)

{
  GlassesState *pGVar1;
  int iVar2;
  int iVar3;
  
  if (horizontal_offset != (int *)0x0) {
    iVar3 = *horizontal_offset;
    pGVar1 = __get_dashboard_state();
    switch((pGVar1->jdb_panel_context).field_0x355) {
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
    *horizontal_offset = iVar2;
    pGVar1 = __get_dashboard_state();
    if (pGVar1->is_master == true) {
      *horizontal_offset = -*horizontal_offset;
    }
    if ((*horizontal_offset != iVar3) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        pGVar1 = __get_dashboard_state();
        printk("%s(): canvas_distance_gear:%d, pos_x:%d\n","cal_panel_canvas_coord",
               (uint)(byte)(pGVar1->jdb_panel_context).field_0x355,*horizontal_offset);
      }
      else {
        pGVar1 = __get_dashboard_state();
        ble_printk("%s(): canvas_distance_gear:%d, pos_x:%d\n","cal_panel_canvas_coord",
                   (uint)(byte)(pGVar1->jdb_panel_context).field_0x355,*horizontal_offset);
      }
    }
  }
  if (vertical_offset != (int *)0x0) {
    iVar2 = *vertical_offset;
    pGVar1 = __get_dashboard_state();
    iVar3 = (8 - (uint)(byte)(pGVar1->jdb_panel_context).__raster_height_offset) * 35;
    *vertical_offset = iVar3;
    if ((iVar3 - iVar2 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        pGVar1 = __get_dashboard_state();
        printk("%s(): raster_height_gear:%d, pos_y:%d\n","cal_panel_canvas_coord",
               (uint)(byte)(pGVar1->jdb_panel_context).__raster_height_offset,*vertical_offset);
        return;
      }
      pGVar1 = __get_dashboard_state();
      ble_printk("%s(): raster_height_gear:%d, pos_y:%d\n","cal_panel_canvas_coord",
                 (uint)(byte)(pGVar1->jdb_panel_context).__raster_height_offset,*vertical_offset);
      return;
    }
  }
  return;
}


