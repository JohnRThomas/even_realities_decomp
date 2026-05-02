/*
 * Function: is_ext_flash_burned
 * Entry:    00033b34
 * Prototype: undefined4 __stdcall is_ext_flash_burned(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 is_ext_flash_burned(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uVar2 = 0;
  uVar3 = 0;
  uStack_24 = param_2;
  uStack_20 = param_3;
LAB_00033b48:
  uStack_24 = CONCAT22(0xffff,(undefined2)uStack_24);
  switch(uVar3) {
  case 1:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x200000,0x10);
    if ((iVar1 != 0) ||
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x3f8c98,0x10), iVar1 != 0)) break;
    if (uStack_24._2_2_ != -0x2547) {
      return 1;
    }
    uVar3 = 2;
LAB_00033b92:
    uVar2 = 0;
    goto LAB_00033b48;
  case 2:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x500000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x515768,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != 0x1265) {
        return 1;
      }
      uVar3 = 3;
      goto LAB_00033b92;
    }
    break;
  case 3:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x520000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x97c44f,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != -0x2547) {
        return 1;
      }
      uVar3 = 4;
      goto LAB_00033b92;
    }
    break;
  case 4:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0xa20000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0xa2b77f,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != -0x2bee) {
        return 1;
      }
      uVar3 = 5;
      goto LAB_00033b92;
    }
    break;
  case 5:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0xa40000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0xdbedcf,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != -0x2547) {
        return 1;
      }
      uVar3 = 6;
      goto LAB_00033b92;
    }
    break;
  case 6:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x180000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x1af0d8,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != 0x2632) {
        return 1;
      }
      return 0;
    }
    break;
  default:
    iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x140000,0x10);
    if ((iVar1 == 0) &&
       (iVar1 = calc_flash_crc((ushort *)((int)&uStack_24 + 2),0x17fcf8,0x10), iVar1 == 0)) {
      if (uStack_24._2_2_ != 0xd59) {
        return 1;
      }
      uVar3 = 1;
      goto LAB_00033b92;
    }
    uVar3 = 0;
  }
  if (uVar2 == 5) {
    return 2;
  }
  sleep(100);
  uVar2 = uVar2 + 1 & 0xff;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): flash read fail, retry again, retry time %d\n");
    }
    else {
      ble_printk("%s(): flash read fail, retry again, retry time %d\n","is_ext_flash_burned",uVar2,
                 BLE_DEBUG);
    }
  }
  goto LAB_00033b48;
}


