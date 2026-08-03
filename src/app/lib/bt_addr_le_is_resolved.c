/*
 * Function: bt_addr_le_is_resolved
 * Entry:    000845c4
 * Prototype: bool __stdcall bt_addr_le_is_resolved(bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

bool bt_addr_le_is_resolved(bt_addr_le_t *addr)

{
  return SUB41(((uint)addr->type << 0x1e) >> 0x1f,0);
}


