/*
 * Function: boot_read_swap_state_by_id
 * Entry:    00088622
 * Prototype: int __stdcall boot_read_swap_state_by_id(int flash_area_id, boot_swap_state * state)
 */


/* exclude_from_export */

int boot_read_swap_state_by_id(int flash_area_id,boot_swap_state *state)

{
  int iVar1;
  flash_area *local_c;
  
  local_c = (flash_area *)state;
  iVar1 = flash_area_open((uint8_t)flash_area_id,&local_c);
  if (iVar1 == 0) {
    iVar1 = boot_read_swap_state(local_c,state);
    flash_area_close(local_c);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


