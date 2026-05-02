/*
 * Function: display_powerEvent
 * Entry:    0004ca80
 * Prototype: undefined4 __stdcall display_powerEvent(int param_1)
 */


undefined4 display_powerEvent(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20 [24];
  
  memset(local_20,0,0x18);
  if (param_1 == 1) {
    local_20[0] = 7;
  }
  else {
    local_20[0] = 8;
  }
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a64,local_20,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    printk("message queue send failed %s\r\n","display_powerEvent");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


