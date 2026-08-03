/*
 * Function: i2c_write_read
 * Entry:    00087530
 * Prototype: int __stdcall i2c_write_read(device * dev, uint16_t addr, void * write_buf, size_t num_write, void * read_buf, size_t num_read)
 */


/* exclude_from_export_ai */

int i2c_write_read(device *dev,uint16_t addr,void *write_buf,size_t num_write,void *read_buf,
                  size_t num_read)

{
  int iVar1;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 local_20;
  size_t local_1c;
  void *local_18;
  undefined1 local_14;
  
  local_2c = (undefined1)addr;
  iVar1 = *(int *)dev->config;
  local_20 = 0;
  local_2b = SUB41(write_buf,0);
  local_28 = &local_2c;
  local_18 = read_buf;
  local_24 = 2;
  local_14 = 7;
  local_1c = num_write;
  iVar1 = (**(code **)(*(int *)(iVar1 + 8) + 8))
                    (iVar1,&local_28,2,(short)*(int *)((int)dev->config + 4));
  return iVar1;
}


