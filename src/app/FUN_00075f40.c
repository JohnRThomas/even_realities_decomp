/*
 * Function: FUN_00075f40
 * Entry:    00075f40
 * Prototype: int __stdcall FUN_00075f40(int * sem, uint initial_count, uint limit)
 */


int FUN_00075f40(int *sem,uint initial_count,uint limit)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = sem[3];
  uVar1 = DAT_2000be60;
  puVar2 = DAT_2000be64;
  if ((int)(uVar3 << 0x1e) < 0) {
    z_impl_k_sem_init((k_sem *)(initial_count + 8),0,1);
    *(undefined4 *)initial_count = 0;
    *(int **)(initial_count + 4) = sem;
    uVar1 = initial_count;
    puVar2 = (uint *)initial_count;
    if (DAT_2000be64 != (uint *)0x0) {
      *DAT_2000be64 = initial_count;
      uVar1 = DAT_2000be60;
      puVar2 = (uint *)initial_count;
    }
  }
  DAT_2000be64 = puVar2;
  DAT_2000be60 = uVar1;
  return (uVar3 & 3) >> 1;
}


