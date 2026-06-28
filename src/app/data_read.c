/*
 * Function: $_data_read
 * Entry:    0007fa08
 * Prototype: void __stdcall $_data_read(uint32_t * output)
 */


void __data_read(uint32_t *output)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *in_r1;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_30;
  int local_2c;
  void *local_28;
  size_t local_24;
  
  if (((output != (uint32_t *)0x0) && (in_r1 != (int *)0x0)) && (*in_r1 != 0)) {
    uVar4 = in_r1[1];
    uVar1 = __read_block((byte *)output);
    if (uVar4 < uVar1) {
      iVar2 = __read_block((byte *)output);
      in_r1[1] = iVar2;
    }
    else {
      local_30 = *in_r1;
      local_2c = in_r1[1];
      iVar3 = i2c_write_byte((byte *)output,&local_30);
      iVar2 = local_2c;
      if (iVar3 == 0) {
        if (*(byte *)((int)output + 1) != 0) {
          memcpy((void *)(*in_r1 + local_2c),(void *)output[1],(uint)*(byte *)((int)output + 1));
          iVar2 = iVar2 + (uint)*(byte *)((int)output + 1);
        }
        if (*(byte *)((int)output + 2) != 0) {
          memcpy((void *)(*in_r1 + iVar2),(void *)output[2],(uint)*(byte *)((int)output + 2));
          iVar2 = iVar2 + (uint)*(byte *)((int)output + 2);
        }
        iVar6 = *in_r1;
        iVar3 = in_r1[1];
        uVar1 = __i2c_read_byte((int)output);
        if (uVar1 <= (uint)(iVar3 - iVar2)) {
          iVar3 = 1;
          iVar5 = 0;
          while (iVar3 = write_block((int)output,&local_28,iVar3), iVar3 != 0) {
            if (local_24 != 0) {
              memcpy((void *)(iVar2 + iVar5 + iVar6),local_28,local_24);
            }
            iVar3 = 0;
            iVar5 = iVar5 + local_24;
          }
          in_r1[1] = iVar2 + iVar5;
        }
      }
    }
  }
  return;
}


