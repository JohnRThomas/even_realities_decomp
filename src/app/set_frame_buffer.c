/*
 * Function: ?_set_frame_buffer
 * Entry:    000452f0
 * Prototype: int __stdcall ?_set_frame_buffer(undefined4 param_1)
 */


int __set_frame_buffer(byte *param_1)

{
  __frame_buffer = param_1;
  return 0;
}


