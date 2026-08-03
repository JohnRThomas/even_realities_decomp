/*
 * Function: aw9320x_init_irq_handle
 * Entry:    0008047a
 * Prototype: int32_t __stdcall aw9320x_init_irq_handle(void)
 */


/* exclude_from_export aw9320x.c */

int32_t aw9320x_init_irq_handle(void)

{
  int8_t iVar1;
  char cVar2;
  uint32_t local_c;
  
  cVar2 = 'e';
  local_c = 0;
  while( true ) {
    iVar1 = aw9320x_i2c_read(0x4410,&local_c);
    if (iVar1 < '\0') {
      return -1;
    }
    if ((int)(local_c << 0x1f) < 0) break;
    cVar2 = cVar2 + -1;
    AW_DELAY(1);
    if (cVar2 == '\0') {
      return -2;
    }
  }
  return 0;
}


