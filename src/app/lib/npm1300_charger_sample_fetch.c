/*
 * Function: npm1300_charger_sample_fetch
 * Entry:    00087e44
 * Prototype: int __stdcall npm1300_charger_sample_fetch(device * dev, sensor_channel chan)
 */


/* exclude_from_export */

int npm1300_charger_sample_fetch(device *dev,sensor_channel chan)

{
  int iVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  size_t in_stack_ffffffd8;
  size_t num_read;
  size_t in_stack_ffffffdc;
  undefined1 local_1c;
  byte local_1b;
  byte local_1a;
  byte local_17;
  byte local_14;
  byte local_12;
  
  puVar2 = (ushort *)dev->data;
  puVar3 = (undefined4 *)dev->config;
  iVar1 = i2c_write_read_dt((i2c_dt_spec *)*puVar3,&DAT_00000003,0x34,puVar2 + 3,in_stack_ffffffd8);
  if ((iVar1 == 0) &&
     (iVar1 = i2c_write_read_dt((i2c_dt_spec *)*puVar3,&DAT_00000003,0x36,(void *)((int)puVar2 + 7),
                                in_stack_ffffffd8), iVar1 == 0)) {
    num_read = 0xb;
    iVar1 = i2c_write_read((device *)*puVar3,5,&MemManage,(size_t)&local_1c,&DAT_0000000b,
                           in_stack_ffffffdc);
    if (iVar1 == 0) {
      *puVar2 = local_17 & 3 | (ushort)local_1b << 2;
      puVar2[2] = (ushort)(((uint)local_17 << 0x1c) >> 0x1e) | (ushort)local_1a << 2;
      puVar2[1] = (ushort)(((uint)local_12 << 0x1a) >> 0x1e) | (ushort)local_14 << 2;
      *(undefined1 *)(puVar2 + 4) = local_1c;
      iVar1 = i2c_write_dt((i2c_dt_spec *)*puVar3,&DAT_00000005,1);
      if ((iVar1 == 0) && (iVar1 = i2c_write_dt((i2c_dt_spec *)*puVar3,&DAT_00000005,0), iVar1 == 0)
         ) {
        iVar1 = i2c_write_read_dt((i2c_dt_spec *)*puVar3,&DAT_00000002,7,(void *)((int)puVar2 + 9),
                                  num_read);
      }
    }
  }
  return iVar1;
}


