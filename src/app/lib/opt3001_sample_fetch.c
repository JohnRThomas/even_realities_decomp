/*
 * Function: opt3001_sample_fetch
 * Entry:    00065b8c
 * Prototype: int __stdcall opt3001_sample_fetch(device * dev, undefined chan)
 */


/* exclude_from_export */

int opt3001_sample_fetch(int dev,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uStack_c;
  
  puVar2 = *(undefined2 **)(dev + 0x10);
  uStack_c = param_2;
  if ((param_2 != 0x3a) && (param_2 != 0x11)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan == SENSOR_CHAN_ALL || chan == SENSOR_CHAN_LIGHT",
            "WEST_TOPDIR/zephyr/drivers/sensor/opt3001/opt3001.c",0x46);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *puVar2 = 0;
  iVar1 = opt3001_reg_read(*(device **)(dev + 4),'\0',(uint16_t *)((int)&uStack_c + 2));
  if (iVar1 == 0) {
    *puVar2 = uStack_c._2_2_;
    iVar1 = 0;
  }
  else {
    iVar1 = -5;
  }
  return iVar1;
}


