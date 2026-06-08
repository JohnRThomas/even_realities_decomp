/*
 * Function: ?_copy_to_frame_buffer
 * Entry:    00080c02
 * Prototype: int __stdcall ?_copy_to_frame_buffer(int param_1, void * param_2, size_t param_3, int param_4, int param_5, int param_6)
 */


int __copy_to_frame_buffer
              (int param_1,void *param_2,size_t param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  
  if (199 < param_6) {
    param_6 = 200;
  }
  if (0x27f < param_5) {
    param_5 = 0x280;
  }
  piVar1 = (int *)(param_1 + param_6 * 4);
  for (iVar2 = 0; iVar2 < param_4; iVar2 = iVar2 + 1) {
    memcpy((void *)(*piVar1 + param_5 / 2),param_2,param_3);
    param_2 = (void *)((int)param_2 + param_3);
    piVar1 = piVar1 + 1;
  }
  return param_6;
}


