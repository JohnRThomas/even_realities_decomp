/*
 * Function: FUN_01023250
 * Entry:    01023250
 * Prototype: undefined __stdcall FUN_01023250(uint param_1, uint * param_2, int param_3, undefined4 param_4)
 */


void FUN_01023250(uint param_1,uint *param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  
  if (param_3 == 0) {
    Peripherals::DPPIC_NS.CHENCLR = 1 << (param_1 & 0xff);
    return;
  }
  puVar1 = (uint *)FUN_01025a1c(0,param_2,param_3,param_4);
  *puVar1 = param_1 | 0x80000000;
  *param_2 = param_1 | 0x80000000;
  Peripherals::DPPIC_NS.CHENSET = 1 << (param_1 & 0xff);
  return;
}


