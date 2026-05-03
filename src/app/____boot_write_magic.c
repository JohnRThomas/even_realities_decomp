/*
 * Function: $_?_boot_write_magic
 * Entry:    000672a0
 * Prototype: int __stdcall $_?_boot_write_magic(flash_area * fap)
 */


int ____boot_write_magic(flash_area *fap)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 local_28 [5];
  
  puVar6 = local_28;
  uVar3 = fap->fa_size;
  flash_area_erased_val(fap);
  pcVar5 = (char *)&DAT_0009ce24;
  do {
    uVar1 = *(undefined4 *)pcVar5;
    uVar4 = *(undefined4 *)(pcVar5 + 4);
    pcVar5 = pcVar5 + 8;
    *puVar6 = uVar1;
    puVar6[1] = uVar4;
    puVar6 = puVar6 + 2;
  } while (pcVar5 != "%s(): RTC has sync at %lld ms\n");
  iVar2 = ____flash_area_write(fap,uVar3 - 0x10 & 0xfffffff8,local_28,0x10);
  return (uint)(iVar2 != 0);
}


