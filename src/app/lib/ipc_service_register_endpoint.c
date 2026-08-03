/*
 * Function: ipc_service_register_endpoint
 * Entry:    0004fe8c
 * Prototype: int __stdcall ipc_service_register_endpoint(device * instance, ipc_ept * ept, ipc_ept_cfg * cfg)
 */


/* exclude_from_export */

int ipc_service_register_endpoint(device *instance,ipc_ept *ept,ipc_ept_cfg *cfg)

{
  int iVar1;
  undefined *puVar2;
  char local_18 [4];
  char *local_14;
  
  if (((instance == (device *)0x0) || (ept == (ipc_ept *)0x0)) || (cfg == (ipc_ept_cfg *)0x0)) {
    local_14 = "Invalid instance, endpoint or configuration";
    local_18[0] = '\x02';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    LOG_ERR(&PTR_s_ipc_service_0008b988,0x1040,local_18);
    iVar1 = -0x16;
  }
  else {
    puVar2 = instance->api;
    if ((puVar2 != (undefined *)0x0) && (*(int *)(puVar2 + 0xc) != 0)) {
      ept->instance = instance;
                    /* WARNING: Could not recover jumptable at 0x0004fee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(puVar2 + 0xc))(instance,&ept->token);
      return iVar1;
    }
    local_14 = "Invalid backend configuration";
    local_18[0] = '\x02';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    LOG_ERR(&PTR_s_ipc_service_0008b988,0x1040,local_18);
    iVar1 = -5;
  }
  return iVar1;
}


