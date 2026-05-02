/*
 * Function: display_DelayClose
 * Entry:    0004c9a4
 * Prototype: undefined4 __stdcall display_DelayClose(undefined4 param_1)
 */


undefined4 display_DelayClose(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined2 local_1e;
  undefined4 local_1c;
  
  memset(&uStack_1f,0,0x17);
  local_20 = 4;
  local_1e = 4;
  local_1c = param_1;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a64,&local_20,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    printk("message queue send failed %s\r\n","display_DelayClose");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


