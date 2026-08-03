/*
 * Function: att_timeout
 * Entry:    0005cbcc
 * Prototype: void __stdcall att_timeout(k_work * work)
 */


/* exclude_from_export */

void att_timeout(k_work *work)

{
  k_work_delayable *pkVar1;
  char *s;
  undefined1 *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  char acStack_44 [12];
  char acStack_38 [32];
  
  pkVar1 = k_work_delayable_from_work((k_work *)(work[-0x16].node.next)->next);
  switch(*(undefined1 *)&(pkVar1->work).node.next) {
  case 0:
    s = "public";
    break;
  case 1:
    s = "random";
    break;
  case 2:
    s = "public-id";
    break;
  case 3:
    s = "random-id";
    break;
  default:
    snprintk(acStack_44,10,"0x%02x");
    goto LAB_0005cbfc;
  }
  strcpy(acStack_44,s);
LAB_0005cbfc:
  local_50 = (char *)(uint)*(byte *)((int)&(pkVar1->work).node.next + 1);
  local_54 = (char *)(uint)*(byte *)((int)&(pkVar1->work).node.next + 2);
  local_58 = (undefined1 *)(uint)*(byte *)((int)&(pkVar1->work).node.next + 3);
  local_4c = acStack_44;
  snprintk(acStack_38,0x1e,"%02X:%02X:%02X:%02X:%02X:%02X (%s)",
           (uint)*(byte *)((int)&(pkVar1->work).handler + 2),
           (uint)*(byte *)((int)&(pkVar1->work).handler + 1),(uint)*(byte *)&(pkVar1->work).handler)
  ;
  local_54 = "ATT Timeout for device %s";
  local_4c = (char *)CONCAT22(local_4c._2_2_,0x200);
  local_58 = &DAT_01000003;
  local_50 = acStack_38;
  LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1c40,(byte *)&local_58);
  bt_att_disconnected((bt_l2cap_chan *)&work[-0x16].queue);
  return;
}


