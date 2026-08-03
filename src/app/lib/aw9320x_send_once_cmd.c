/*
 * Function: aw9320x_send_once_cmd
 * Entry:    000317e0
 * Prototype: int32_t __stdcall aw9320x_send_once_cmd(uint8_t module, uint8_t command, uint8_t * send_value, uint16_t send_val_len)
 */


/* exclude_from_export aw9320x.c */

int32_t aw9320x_send_once_cmd
                  (uint8_t module,uint8_t command,uint8_t *send_value,uint16_t send_val_len)

{
  uint uVar1;
  aw9320x_err_code aVar2;
  int8_t iVar3;
  undefined4 *ptr;
  uint32_t ms;
  ushort *ptr_00;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  uint uVar9;
  bool bVar10;
  uint32_t local_24;
  
  uVar6 = (uint)send_val_len;
  uVar4 = (uint)command;
  uVar9 = uVar6 + 0xe & 0xffff;
  local_24 = uVar4;
  ptr = malloc(uVar9);
  if (ptr == (undefined4 *)0x0) {
    return -1;
  }
  *ptr = 0x2000008;
  *(char *)((int)ptr + 5) = (char)(uVar6 + 0xc);
  *(char *)(ptr + 1) = (char)(uVar6 + 0xc >> 8);
  iVar7 = module + uVar4 + uVar6;
  pbVar5 = send_value;
  while ((uint)((int)pbVar5 - (int)send_value) < uVar6) {
    iVar7 = iVar7 + ((uint)pbVar5[1] << 0x10 | (uint)*pbVar5 << 0x18 | (uint)pbVar5[3] |
                    (uint)pbVar5[2] << 8);
    pbVar5 = pbVar5 + 4;
  }
  uVar1 = -iVar7;
  *(char *)((int)ptr + 6) = (char)(uVar1 >> 0x18);
  *(char *)((int)ptr + 7) = (char)(uVar1 >> 0x10);
  *(ushort *)(ptr + 2) = (ushort)((uVar1 & 0xff) << 8) | (ushort)(uVar1 >> 8) & 0xff;
  *(uint8_t *)((int)ptr + 10) = module;
  *(uint8_t *)((int)ptr + 0xb) = command;
  *(ushort *)(ptr + 3) = (ushort)((uVar6 & 0xff) << 8) | send_val_len >> 8;
  if ((uVar6 != 0) && (send_value != (uint8_t *)0x0)) {
    memcpy((void *)((int)ptr + 0xe),send_value,uVar6);
  }
  cVar8 = '\x05';
  do {
    iVar7 = (**(code **)(g_aw9320x_func.i2c_func.i2c_r + 4))(ptr,uVar9);
    if (-1 < iVar7) break;
    cVar8 = cVar8 + -1;
  } while (cVar8 != -1);
  free(ptr);
  if (cVar8 == -1) {
    return -1;
  }
  aVar2 = aw9320x_i2c_write(0x1c10,0x20000800);
  if (aVar2 != AW_OK) {
    return -1;
  }
  aVar2 = aw9320x_i2c_write(0x4408,0x15);
  if (aVar2 != AW_OK) {
    return -1;
  }
  uVar6 = AW_UPDATE_FW_STATE_2001aa7b - 1 & 0xff;
  if (uVar6 < 5) {
    uVar9 = (uint)(byte)(&DAT_000a7355)[uVar6];
    ms = (uint32_t)(byte)(&DAT_000a7350)[uVar6];
  }
  else {
    ms = 0;
    uVar9 = 0;
  }
  AW_DELAY(ms);
  local_24 = 0;
  if (AW_UPDATE_FW_STATE_2001aa7b == SEND_UPDATE_FW_CMD) {
    iVar7 = 100;
  }
  else {
    iVar7 = 10;
  }
  while( true ) {
    iVar3 = aw9320x_i2c_read(0x4410,&local_24);
    if (iVar3 != '\0') {
      return -1;
    }
    if ((int)(local_24 << 2) < 0) break;
    AW_DELAY(1);
    bVar10 = iVar7 == 0;
    iVar7 = iVar7 + -1;
    if (bVar10) {
      return -1;
    }
  }
  uVar6 = uVar9 + 0xc & 0xff;
  local_24 = local_24 & 0xffff0000;
  ptr_00 = malloc(uVar6);
  if (ptr_00 == (ushort *)0x0) {
    return -1;
  }
  cVar8 = '\x05';
  local_24 = CONCAT31(local_24._1_3_,0x18);
  while (iVar7 = (**(code **)g_aw9320x_func.i2c_func.i2c_r)(&local_24,2,ptr_00,uVar6), iVar7 < 0) {
    cVar8 = cVar8 + -1;
    if (cVar8 == -1) {
      free(ptr_00);
      return -1;
    }
  }
  *ptr_00 = *ptr_00 << 8 | *ptr_00 >> 8;
  ptr_00[1] = ptr_00[1] << 8 | ptr_00[1] >> 8;
  ptr_00[5] = ptr_00[5] << 8 | ptr_00[5] >> 8;
  uVar6 = *(uint *)(ptr_00 + 2);
  *(uint *)(ptr_00 + 2) =
       uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
  if ((uint)(byte)ptr_00[4] != (uint)module) {
    return -1;
  }
  if (*(byte *)((int)ptr_00 + 9) != uVar4) {
    return -1;
  }
  if (*(int *)(ptr_00 + 6) != 0) {
    return -1;
  }
  free(ptr_00);
  return 0;
}


