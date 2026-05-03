/*
 * Function: FUN_0004d44c
 * Entry:    0004d44c
 * Prototype: undefined __stdcall FUN_0004d44c(undefined4 param_1, int param_2, int param_3)
 */


void FUN_0004d44c(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  printk("dump_hex(%s):",param_1);
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1) {
    if ((uVar1 & 7) == 0) {
      printk("\n");
    }
    printk("0x%02x,",(uint)*(byte *)(param_2 + uVar1));
  }
  printk("\n");
  return;
}


