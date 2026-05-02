/*
 * Function: FUN_0004d528
 * Entry:    0004d528
 * Prototype: undefined __stdcall FUN_0004d528(void)
 */


void FUN_0004d528(void)

{
  undefined8 uVar1;
  
  uVar1 = get_bootSeconds();
  uVar1 = __aeabi_ldivmod((uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),1000,0);
  DAT_2000aa90 = (int)uVar1;
  return;
}


