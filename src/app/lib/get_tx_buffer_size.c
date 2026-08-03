/*
 * Function: get_tx_buffer_size
 * Entry:    00082188
 * Prototype: int __stdcall get_tx_buffer_size(device * instance, void * token)
 */


/* exclude_from_export_ai */

int get_tx_buffer_size(device *instance,void *token)

{
  return *(int *)(instance->data + 0x3c0);
}


