/*
 * Function: get_uuid_size
 * Entry:    00051c2c
 * Prototype: size_t __stdcall get_uuid_size(bt_uuid * uuid)
 */


/* exclude_from_export */

size_t get_uuid_size(bt_uuid *uuid)

{
  size_t sVar1;
  int in_r1;
  char *in_r2;
  
  if ((bt_uuid *)&DAT_00000002 < uuid) {
    sVar1 = LOG_ERR((char **)uuid,in_r1,in_r2);
    return sVar1;
  }
  return (uint)uuid[0xef5a6].type;
}


