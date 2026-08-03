/*
 * Function: $_data_write
 * Entry:    0007fd06
 * Prototype: void __stdcall $_data_write(uint32_t * input)
 */


/* exclude_from_export_ai */

void __data_write(uint32_t *input)

{
  uint uVar1;
  undefined1 uVar2;
  uint *in_r1;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined1 local_24;
  undefined1 local_23 [4];
  undefined1 local_1f [11];
  
  local_2c = 0;
  memset(local_28,0,0xd);
  uVar6 = *in_r1;
  uVar5 = in_r1[1];
  local_24 = 9;
  uVar3 = 0x18;
  puVar4 = &local_2c;
  do {
    *(char *)puVar4 = (char)(uVar6 >> (uVar3 & 0xff));
    uVar1 = uVar3 & 0xff;
    uVar3 = uVar3 - 8;
    uVar2 = (undefined1)(uVar5 >> uVar1);
    *(undefined1 *)(puVar4 + 1) = uVar2;
    *(undefined1 *)((int)puVar4 + 9) = *(undefined1 *)puVar4;
    *(undefined1 *)((int)puVar4 + 0xd) = uVar2;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  } while (uVar3 != 0xfffffff8);
  __eeprom_st25dv_write_sys((int)input,0x900,&local_2c,0x11);
  return;
}


