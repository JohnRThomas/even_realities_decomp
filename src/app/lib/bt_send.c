/*
 * Function: bt_send
 * Entry:    00057674
 * Prototype: int __stdcall bt_send(net_buf * buf)
 */


/* exclude_from_export */

int bt_send(net_buf *buf)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0005767c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(DAT_20002168 + 0x14))(buf);
  return iVar1;
}


