/*
 * Function: sendAudioStreamFileToApp
 * Entry:    0004b480
 * Prototype: undefined4 __stdcall sendAudioStreamFileToApp(undefined1 param_1, undefined1 param_2)
 */


undefined4 sendAudioStreamFileToApp(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  
  memset(&uStack_27,0,0x17);
  local_28 = 2;
  local_26 = 2;
  local_24 = param_1;
  local_23 = param_2;
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003acc,&local_28,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    printk("message queue send failed %s\r\n","sendAudioStreamFileToApp");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


