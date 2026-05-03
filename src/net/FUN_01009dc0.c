/*
 * Function: FUN_01009dc0
 * Entry:    01009dc0
 * Prototype: undefined __stdcall FUN_01009dc0(void)
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_01009dc0(void)

{
  undefined *puVar1;
  int iVar2;
  int local_14;
  uint local_10;
  int local_c;
  
  for (local_c = 10; -1 < local_c; local_c = local_c + -1) {
    puVar1 = &DAT_21000b7c;
    iVar2 = *(int *)(&DAT_21000b7c + local_c * 4);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 4) == -1) {
        *(undefined1 *)(iVar2 + 4) = 0;
      }
      else {
        local_10 = 0;
        local_14 = local_c;
        while (local_14 = local_14 + -1, -1 < local_14) {
          puVar1 = &DAT_21000b7c;
          if ((*(int *)(&DAT_21000b7c + local_14 * 4) != 0) &&
             (puVar1 = (undefined *)(uint)*(byte *)(*(int *)(&DAT_21000b7c + local_14 * 4) + 4),
             puVar1 == (undefined *)(uint)*(byte *)(iVar2 + 4))) {
            puVar1 = (undefined *)(uint)*(byte *)(*(int *)(&DAT_21000b7c + local_14 * 4) + 2);
            local_10 = local_10 + (int)puVar1;
          }
        }
        if (0xff < local_10) {
          FUN_01009500(0x17,0xfa,puVar1,local_10);
        }
        *(char *)(iVar2 + 4) = (char)local_10;
      }
    }
  }
  return;
}


