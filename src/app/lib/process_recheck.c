/*
 * Function: process_recheck
 * Entry:    00081926
 * Prototype: int __stdcall process_recheck(onoff_manager * mgr)
 */


/* exclude_from_export */

int process_recheck(onoff_manager *mgr)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)&mgr[1].monitors & 7;
  if ((*(ushort *)&mgr[1].monitors & 7) == 0) {
    if (mgr->clients == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 3;
    }
    return iVar1;
  }
  if (uVar2 != 2) {
    if (uVar2 != 1) {
      return 0;
    }
    if (mgr->clients == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 5;
    }
    return iVar1;
  }
  return (uint)(*(short *)((int)&mgr[1].monitors + 2) == 0) << 2;
}


