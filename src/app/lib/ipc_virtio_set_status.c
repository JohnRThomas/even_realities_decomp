/*
 * Function: ipc_virtio_set_status
 * Entry:    000824fc
 * Prototype: undefined __stdcall ipc_virtio_set_status(int param_1, undefined1 param_2)
 */


/* exclude_from_export */

void ipc_virtio_set_status(int param_1,undefined1 param_2)

{
  if (*(int *)(param_1 + 0x18) == 0) {
    **(undefined1 **)(param_1 + 0x88) = param_2;
  }
  return;
}


