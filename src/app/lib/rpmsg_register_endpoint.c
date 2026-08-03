/*
 * Function: rpmsg_register_endpoint
 * Entry:    0007421c
 * Prototype: void __stdcall rpmsg_register_endpoint(rpmsg_device * rdev, rpmsg_endpoint * ept, char * name, uint32_t src, uint32_t dest, rpmsg_ept_cb cb, rpmsg_ns_unbind_cb ns_unbind_cb)
 */


/* exclude_from_export */

void rpmsg_register_endpoint
               (rpmsg_device *rdev,rpmsg_endpoint *ept,char *name,uint32_t src,uint32_t dest,
               rpmsg_ept_cb cb,rpmsg_ns_unbind_cb ns_unbind_cb)

{
  dword dVar1;
  undefined1 *puVar2;
  
  if (name == (char *)0x0) {
    name = "";
  }
  strcpy(&ept->name_RPMSG_NAME_SIZE_,name);
  *(uint32_t *)((int)&ept[1].addr + 2) = src;
  *(uint32_t *)((int)&ept[1].dest_addr + 2) = dest;
  *(rpmsg_device **)((int)&ept[1].rdev + 2) = rdev;
  *(rpmsg_ept_cb *)((int)&ept[1].cb + 2) = cb;
  *(rpmsg_ns_unbind_cb *)((int)&ept[1].ns_unbind_cb + 2) = ns_unbind_cb;
  dVar1 = rdev->ns_ept;
  puVar2 = (undefined1 *)((int)&ept[1].node + 2);
  *(rpmsg_device **)((int)&ept[1].node + 2) = rdev;
  *(dword *)((int)&ept[1].priv + 2) = dVar1;
  rdev->ns_ept = (dword)puVar2;
  **(dword **)((int)&ept[1].priv + 2) = (dword)puVar2;
  return;
}


