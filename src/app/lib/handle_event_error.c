/*
 * Function: handle_event_error
 * Entry:    0005682c
 * Prototype: undefined __stdcall handle_event_error(undefined4 param_1, int param_2)
 */


/* exclude_from_export */

void handle_event_error(undefined4 param_1,int param_2)

{
  ushort uVar1;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined1 *local_28;
  char *local_24;
  undefined4 uStack_20;
  uint local_1c;
  char *pcStack_18;
  undefined2 local_14;
  
  uVar1 = *(ushort *)(param_2 + 0x10);
  pcStack_18 = bt_hex(*(void **)(param_2 + 0xc),(uint)uVar1);
  local_24 = "Unhandled event 0x%02x len %u: %s";
  local_14 = 0x402;
  local_28 = &DAT_01000005;
  uStack_20 = param_1;
  local_1c = (uint)uVar1;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2c80,&local_28,&DAT_01000005,in_stack_ffffffc8,
          in_stack_ffffffcc,in_stack_ffffffd0);
  return;
}


