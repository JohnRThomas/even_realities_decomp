/*
 * Function: aw9320x_para_loaded
 * Entry:    000316c4
 * Prototype: int32_t __stdcall aw9320x_para_loaded(void)
 */


/* exclude_from_export aw9320x.c */

int32_t aw9320x_para_loaded(void)

{
  aw9320x_i2c_w_t *paVar1;
  aw9320x_err_code aVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = &INT_0008d858;
  do {
    paVar1 = (aw9320x_i2c_w_t *)piVar3[1];
    if (*piVar3 != 0x4414) {
      aw9320x_i2c_write((uint16_t)*piVar3,(uint32_t)piVar3[1]);
      paVar1 = g_aw9320x_func.i2c_func.i2c_w;
    }
    g_aw9320x_func.i2c_func.i2c_w = paVar1;
    iVar4 = iVar4 + 2;
    piVar3 = piVar3 + 2;
  } while (iVar4 != 0x58);
  aVar2 = aw9320x_i2c_write(0x4408,1);
  if (aVar2 == AW_OK) {
    g_aw9320x_func.irq_init = (aw9320x_irq_init_t *)&DAT_00000001;
    aVar2 = aw9320x_i2c_write(0x4414,(uint32_t)g_aw9320x_func.i2c_func.i2c_w);
    iVar4 = -(uint)(aVar2 != AW_OK);
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


