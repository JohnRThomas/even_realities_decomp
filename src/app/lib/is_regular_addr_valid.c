/*
 * Function: is_regular_addr_valid
 * Entry:    0008718c
 * Prototype: bool __stdcall is_regular_addr_valid(off_t addr, size_t len)
 */


/* exclude_from_export */

bool is_regular_addr_valid(off_t addr,size_t len)

{
  bool bVar1;
  uint32_t uVar2;
  
  uVar2 = flash_total_size_get();
  if ((addr < 0) || (uVar2 <= (uint)addr)) {
    bVar1 = false;
  }
  else if (uVar2 - addr < len) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


