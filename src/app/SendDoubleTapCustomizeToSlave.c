/*
 * Function: SendDoubleTapCustomizeToSlave
 * Entry:    0004c08c
 * Prototype: undefined4 __stdcall SendDoubleTapCustomizeToSlave(undefined1 param_1)
 */


undefined4 SendDoubleTapCustomizeToSlave(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined2 local_1e;
  undefined1 local_1c;
  
  memset(&uStack_1f,0,0x17);
  local_20 = 8;
  local_1e = 1;
  local_1c = param_1;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003acc,&local_20,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    printk("message queue send failed %s\r\n","SendDoubleTapCustomizeToSlave");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


