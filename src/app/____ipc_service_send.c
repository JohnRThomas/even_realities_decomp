/*
 * Function: $_?_ipc_service_send
 * Entry:    0004fef0
 * Prototype: int __stdcall $_?_ipc_service_send(ipc_ept * ept, void * data, size_t len)
 */


int ____ipc_service_send(ipc_ept *ept,void *data,size_t len)

{
  int iVar1;
  undefined *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (ept == (ipc_ept *)0x0) {
    LOG_ERR(0x8b988);
    iVar1 = -0x16;
  }
  else {
    puVar2 = ept->instance;
    if (puVar2 == (undefined *)0x0) {
      LOG_ERR(0x8b988);
      iVar1 = -2;
    }
    else {
      if ((*(int *)(puVar2 + 8) != 0) &&
         (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(puVar2 + 8) + 8),
         UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0004ff62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*UNRECOVERED_JUMPTABLE)(puVar2,ept->token,data,len);
        return iVar1;
      }
      LOG_ERR(0x8b988);
      iVar1 = -5;
    }
  }
  return iVar1;
}


