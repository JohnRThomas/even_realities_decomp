/*
 * Function: panic
 * Entry:    00051198
 * Prototype: void __stdcall panic(log_backend * backend)
 */


/* exclude_from_export_ai */

void panic(log_backend *backend)

{
  int iVar1;
  undefined4 in_r1;
  char local_9 [5];
  
  local_9[0] = (char)((uint)in_r1 >> 0x18);
  iVar1 = pm_device_state_get(&uart_dev,(pm_device_state *)local_9);
  if ((iVar1 == 0) && (local_9[0] == '\x01')) {
    pm_device_action_run(&uart_dev,1);
  }
  DAT_2001e1c2 = 1;
  log_output_flush((log_output *)&PTR_char_out_1_0008e898);
  return;
}


