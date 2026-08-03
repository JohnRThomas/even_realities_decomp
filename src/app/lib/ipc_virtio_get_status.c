/*
 * Function: ipc_virtio_get_status
 * Entry:    0008250c
 * Prototype: undefined1 __stdcall ipc_virtio_get_status(int param_1)
 */


/* exclude_from_export */

undefined1 ipc_virtio_get_status(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 1) {
    return **(undefined1 **)(param_1 + 0x88);
  }
  return 4;
}


