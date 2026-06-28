/*
 * Function: FUN_0006b556
 * Entry:    0006b556
 * Prototype: undefined __stdcall FUN_0006b556(undefined4 param_1, char * param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0006b556(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  printk("%s","metal: emergency: ",param_3,&PTR_s_metal__emergency__0008f730,0,param_2);
  vprintk(param_2,(va_list)&uStack_8);
  return;
}


