/*
 * Function: bt_is_ready
 * Entry:    00057f10
 * Prototype: bool __stdcall bt_is_ready(void)
 */


/* exclude_from_export_ai */

bool bt_is_ready(void)

{
  return SUB41((uint)(DAT_200020d4 << 0x1d) >> 0x1f,0);
}


