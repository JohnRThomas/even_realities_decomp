/*
 * Function: cmp
 * Entry:    0008ad5e
 * Prototype: int __stdcall cmp(void * param_1, void * param_2)
 */


/* exclude_from_export_ai */

int cmp(void *param_1,void *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)((int)param_2 + 0x10);
  iVar1 = *(int *)((int)param_1 + 0x10) - iVar3;
  if (iVar1 == 0) {
    puVar4 = (uint *)((int)param_1 + 0x14U) + iVar3;
    puVar2 = (uint *)((int)param_2 + iVar3 * 4 + 0x14);
    do {
      puVar4 = puVar4 + -1;
      puVar2 = puVar2 + -1;
      if (*puVar4 != *puVar2) {
        if (*puVar4 < *puVar2) {
          return -1;
        }
        return 1;
      }
    } while ((uint *)((int)param_1 + 0x14U) < puVar4);
  }
  return iVar1;
}


