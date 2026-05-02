/*
 * Function: FUN_00019d14
 * Entry:    00019d14
 * Prototype: int __stdcall FUN_00019d14(int param_1, byte * param_2, undefined4 param_3)
 */


int FUN_00019d14(int param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  byte *pbVar2;
  
  if (LOG_LEVEL == 5) {
    pbVar2 = *(byte **)(param_1 + 0x10);
    printk("spim tx(len=%d): %02x,%02x,%02x,%02x, %02x,%02x,%02x,%02x\n",
           *(undefined4 *)(param_1 + 0x14),(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],
           (uint)pbVar2[3],(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],(uint)pbVar2[3]);
  }
  iVar1 = master_process_put_req((char *)(param_1 + -0x77c),*(byte **)(param_1 + 0x10),param_2);
  if (LOG_LEVEL == 5) {
    printk("spim ret(len=%d): %02x,%02x,%02x,%02x, %02x,%02x,%02x,%02x\n",param_3,(uint)*param_2,
           (uint)param_2[1],(uint)param_2[2],(uint)param_2[3],(uint)*param_2,(uint)param_2[1],
           (uint)param_2[2],(uint)param_2[3]);
  }
  return iVar1;
}


