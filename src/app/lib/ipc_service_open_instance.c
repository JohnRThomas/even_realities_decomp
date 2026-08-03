/*
 * Function: ipc_service_open_instance
 * Entry:    0004fe30
 * Prototype: int __stdcall ipc_service_open_instance(device * instance)
 */


/* exclude_from_export */

int ipc_service_open_instance(device *instance)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (instance == (device *)0x0) {
    LOG_ERR(&PTR_s_ipc_service_0008b988,0x1040,&stack0xfffffff0);
    iVar1 = -0x16;
  }
  else if ((undefined4 *)instance->api == (undefined4 *)0x0) {
    LOG_ERR(&PTR_s_ipc_service_0008b988,0x1040,&stack0xfffffff0);
    iVar1 = -5;
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)instance->api;
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0004fe7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


