/*
 * Function: attr_read_group_cb
 * Entry:    000854bc
 * Prototype: bool __stdcall attr_read_group_cb(net_buf * frag, ssize_t read, void * user_data)
 */


/* exclude_from_export */

bool attr_read_group_cb(net_buf *frag,ssize_t read,void *user_data)

{
  uint uVar1;
  
  uVar1 = (uint)**(byte **)((int)user_data + 0xc);
  if (uVar1 == 0) {
    **(byte **)((int)user_data + 0xc) = (byte)(read + 4U);
  }
  else if (uVar1 != read + 4U) {
    *(short *)(*(int *)((int)user_data + 8) + 0x10) =
         *(short *)(*(int *)((int)user_data + 8) + 0x10) + -4;
    *(undefined4 *)((int)user_data + 0x10) = 0;
    return false;
  }
  return true;
}


