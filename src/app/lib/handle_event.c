/*
 * Function: handle_event
 * Entry:    00056904
 * Prototype: int __stdcall handle_event(dtls_context_t * ctx, session_t * session, dtls_alert_level_t level, ushort code)
 */


/* exclude_from_export */

int handle_event(dtls_context_t *ctx,session_t *session,dtls_alert_level_t level,ushort code)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  uint uStack_18;
  dtls_context_t *local_14;
  
  pbVar1 = (byte *)level;
  do {
    pbVar3 = pbVar1;
    if ((byte *)(level + (uint)code * 8) == pbVar3) {
      iVar2 = handle_event_error(ctx,(int)session);
      return iVar2;
    }
    pbVar1 = pbVar3 + 8;
  } while ((dtls_context_t *)(uint)*pbVar3 != ctx);
  uStack_18 = (uint)*(ushort *)session[4].opaque;
  if (uStack_18 < pbVar3[1]) {
    local_1c = "Too small (%u bytes) event 0x%02x";
    local_20 = 4;
    local_14 = ctx;
    iVar2 = LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2040,&local_20,4,in_stack_ffffffd0,
                    in_stack_ffffffd4,in_stack_ffffffd8);
  }
  else {
    iVar2 = (**(code **)(pbVar3 + 4))(session);
  }
  return iVar2;
}


