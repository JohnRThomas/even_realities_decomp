/*
 * Function: FUN_00045460
 * Entry:    00045460
 * Prototype: undefined4 __stdcall FUN_00045460(int param_1, int param_2)
 */


undefined4 FUN_00045460(int param_1,int param_2)

{
  _clean_fb_data(__frame_buffer,0,param_1,param_2,param_1 + 0x28,param_2 + 0x28);
  return 0;
}


