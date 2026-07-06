/*
 * Function: metal_zephyr_log_handler
 * Entry:    0006b55c
 * Prototype: void __stdcall metal_zephyr_log_handler(metal_log_level level, char * format, ...)
 */


void metal_zephyr_log_handler(metal_log_level level,char *format,...)

{
  metal_log_level mVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  mVar1 = level;
  if (6 < level - 1U) {
    mVar1 = 0;
  }
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  printk("%s",level_strs[mVar1],in_r2,level_strs,level,format);
  vprintk(format,(va_list)&uStack_8);
  return;
}


