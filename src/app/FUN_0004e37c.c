/*
 * Function: FUN_0004e37c
 * Entry:    0004e37c
 * Prototype: int __stdcall FUN_0004e37c(int addr, int * data, uint len)
 */


int FUN_0004e37c(int addr,int *data,uint len)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  k_timeout_t timeout;
  
  iVar1 = console_write(addr);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar2 = addr * 0x28;
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1;
    z_impl_k_mutex_lock((k_mutex *)(iVar2 + 0x20002574),timeout);
    iVar1 = (**(code **)(*(int *)(&DAT_2000256c + iVar2) + 4))
                      (*(undefined4 *)(&DAT_20002568 + iVar2),data,len);
    z_impl_k_mutex_unlock((k_mutex *)(iVar2 + 0x20002574));
  }
  return iVar1;
}


