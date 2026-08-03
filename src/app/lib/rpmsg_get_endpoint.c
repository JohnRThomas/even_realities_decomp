/*
 * Function: rpmsg_get_endpoint
 * Entry:    000890b0
 * Prototype: rpmsg_endpoint * __stdcall rpmsg_get_endpoint(rpmsg_device * rvdev, char * name, uint32_t addr, uint32_t dest_addr)
 */


/* exclude_from_export */

rpmsg_endpoint * rpmsg_get_endpoint(rpmsg_device *rvdev,char *name,uint32_t addr,uint32_t dest_addr)

{
  int iVar1;
  rpmsg_device *prVar2;
  rpmsg_endpoint *s1;
  
  prVar2 = (rpmsg_device *)rvdev->endpoints;
  do {
    if (rvdev == prVar2) {
      return (rpmsg_endpoint *)0x0;
    }
    s1 = (rpmsg_endpoint *)((int)&prVar2[-2].ns_ept + 2);
    if ((addr != 0xffffffff) && (*(uint32_t *)((int)&prVar2[-1].lock + 1) == addr)) {
      return s1;
    }
    while (name != (char *)0x0) {
      while( true ) {
        iVar1 = strncmp(&s1->name_RPMSG_NAME_SIZE_,name,0x20);
        if (iVar1 != 0) goto LAB_00089120;
        if ((dest_addr != 0xffffffff) && (*(uint32_t *)((int)&s1[1].dest_addr + 2) == dest_addr)) {
          return s1;
        }
        if (addr == 0xffffffff) break;
        prVar2 = (rpmsg_device *)prVar2->endpoints;
        if (prVar2 == rvdev) {
          return (rpmsg_endpoint *)0x0;
        }
        s1 = (rpmsg_endpoint *)((int)&prVar2[-2].ns_ept + 2);
        if (addr == *(uint32_t *)((int)&prVar2[-1].lock + 1)) {
          return s1;
        }
      }
      if (*(int *)((int)&s1[1].dest_addr + 2) == -1) {
        return s1;
      }
      prVar2 = (rpmsg_device *)prVar2->endpoints;
      if (prVar2 == rvdev) {
        return (rpmsg_endpoint *)0x0;
      }
      s1 = (rpmsg_endpoint *)((int)&prVar2[-2].ns_ept + 2);
    }
LAB_00089120:
    prVar2 = (rpmsg_device *)prVar2->endpoints;
  } while( true );
}


