/*
 * Function: z_sys_init_run_level
 * Entry:    00074a58
 * Prototype: void __stdcall z_sys_init_run_level(init_level level)
 */


/* exclude_from_export */

void z_sys_init_run_level(init_level level)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(&PTR_DAT_0009c1fc)[level + INIT_LEVEL_PRE_KERNEL_1];
  for (puVar3 = (undefined4 *)(&PTR_DAT_0009c1fc)[level]; puVar3 < puVar5; puVar3 = puVar3 + 2) {
    pcVar2 = (code *)*puVar3;
    iVar4 = puVar3[1];
    if (iVar4 == 0) {
      (*pcVar2)();
    }
    else {
      if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(iVar4), iVar1 != 0)) {
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if (0xfe < iVar1) {
          iVar1 = 0xff;
        }
        **(undefined1 **)(iVar4 + 0xc) = (char)iVar1;
      }
      *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
    }
  }
  return;
}


