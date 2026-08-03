/*
 * Function: deregister_ept
 * Entry:    0008248a
 * Prototype: int __stdcall deregister_ept(device * instance, void * token)
 */


/* exclude_from_export_ai */

int deregister_ept(device *instance,void *token)

{
  int iVar1;
  
  if (*(int *)(instance->data + 0x3bc) == 2) {
    if (token == (void *)0x0) {
      iVar1 = -2;
    }
    else {
      rpmsg_destroy_ept(token);
      memset(token,0,0x70);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}


