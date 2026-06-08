/*
 * Function: aw93203_init
 * Entry:    00032130
 * Prototype: void __stdcall aw93203_init(void)
 */


void aw93203_init(void)

{
  int32_t iVar1;
  
  iVar1 = aw9320x_init(&aw9320x_func);
  if (-1 < iVar1) {
    g_aw9320x_func.delay = (aw9320x_delay_t *)&DAT_00000001;
  }
  return;
}


