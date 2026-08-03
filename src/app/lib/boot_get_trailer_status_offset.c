/*
 * Function: boot_get_trailer_status_offset
 * Entry:    00086e90
 * Prototype: ssize_t __stdcall boot_get_trailer_status_offset(size_t area_size)
 */


/* exclude_from_export_ai */

ssize_t boot_get_trailer_status_offset(size_t area_size)

{
  return area_size - 0x20;
}


