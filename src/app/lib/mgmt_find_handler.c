/*
 * Function: mgmt_find_handler
 * Entry:    00054600
 * Prototype: mgmt_handler * __stdcall mgmt_find_handler(uint16_t group_id, uint16_t command_id)
 */


/* exclude_from_export_ai */

mgmt_handler * mgmt_find_handler(uint16_t group_id,uint16_t command_id)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_2000b32c;
  if (DAT_2000b32c != (int *)0x0) {
    piVar2 = (int *)*DAT_2000b32c;
  }
  iVar4 = (uint)command_id * 8;
  piVar1 = DAT_2000b32c;
  do {
    if (piVar1 == (int *)0x0) {
      return (mgmt_handler *)0x0;
    }
    if (*(uint16_t *)((int)piVar1 + 10) == group_id) {
      if ((uint)*(ushort *)((int)piVar1 + 8) <= (uint)command_id) {
        return (mgmt_handler *)0x0;
      }
      iVar3 = *(int *)((int)piVar1 + 4);
      if ((*(int *)(iVar3 + iVar4) != 0) || (*(int *)(iVar3 + iVar4 + 4) != 0)) {
        return (mgmt_handler *)(iVar3 + iVar4);
      }
    }
    piVar1 = piVar2;
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)*piVar2;
    }
  } while( true );
}


