/*
 * Function: ipc_static_vrings_deinit
 * Entry:    0008253c
 * Prototype: undefined4 __stdcall ipc_static_vrings_deinit(void * param_1)
 */


undefined4 ipc_static_vrings_deinit(void *param_1)

{
  memset(param_1,0,0x30);
  memset((void *)((int)param_1 + 0xbc),0,0x18);
  memset((void *)((int)param_1 + 0xa4),0,0x18);
  virtqueue_free(*(void **)((int)param_1 + 0xd8));
  virtqueue_free(*(void **)((int)param_1 + 0xd4));
  *(undefined4 *)((int)param_1 + 0xa0) = 0;
  metal_device_close((int)param_1 + 0x34);
  metal_finish();
  if (*(code **)((int)param_1 + 0x6c) != (code *)0x0) {
    (**(code **)((int)param_1 + 0x6c))((void *)((int)param_1 + 0x40));
  }
  memset((void *)((int)param_1 + 0x40),0,0x38);
  return 0;
}


