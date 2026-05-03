/*
 * Function: display_MasterSendClose
 * Entry:    0004ca40
 * Prototype: undefined4 __stdcall display_MasterSendClose(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4
display_MasterSendClose(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  memset((void *)((int)&local_20 + 1),0,0x17);
  local_20 = CONCAT31(local_20._1_3_,6);
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a64,&local_20,(k_timeout_t)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    printk("message queue send failed %s\r\n","display_MasterSendClose");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


