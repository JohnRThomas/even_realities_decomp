/*
 * Function: work_callback
 * Entry:    00065148
 * Prototype: void __stdcall work_callback(k_work * work)
 */


/* exclude_from_export */

void work_callback(k_work *work)

{
  byte bVar1;
  int iVar2;
  sys_snode_t *psVar3;
  char *test;
  char *file;
  int line;
  sys_snode_t *psVar4;
  uint uVar5;
  byte *pbVar6;
  size_t in_stack_ffffffa4;
  undefined1 uStack_50;
  byte abStack_4f [43];
  
  iVar2 = i2c_write_read((device *)work[-1].node.next,0,(void *)0x0,(size_t)&uStack_50,&DAT_00000026
                         ,in_stack_ffffffa4);
  if (-1 < iVar2) {
    uVar5 = 0;
    pbVar6 = &DAT_000f4174;
    do {
      bVar1 = *pbVar6;
      if ((pbVar6[1] & abStack_4f[bVar1]) != 0) {
        psVar3 = work[1].node.next;
        if (psVar3 != (sys_snode_t *)0x0) {
          psVar4 = psVar3->next;
          while (psVar3 != (sys_snode_t *)0x0) {
            if ((1 << (uVar5 & 0xff) & (uint)psVar3[2].next) != 0) {
              if (psVar3[1].next == (sys_snode_t *)0x0) {
                _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb->handler",
                        "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio/gpio_utils.h",93);
                _ASSERT("\tNo callback handler!\n",test,file,line);
                    /* WARNING: Subroutine does not return */
                k_panic();
              }
              (*(code *)psVar3[1].next)();
            }
            psVar3 = psVar4;
            if (psVar4 != (sys_snode_t *)0x0) {
              psVar4 = psVar4->next;
            }
          }
        }
        iVar2 = i2c_write_dt((i2c_dt_spec *)work[-1].node.next,(uint8_t *)0x0,bVar1 + 1 & 0xff);
        if (iVar2 < 0) {
          return;
        }
      }
      uVar5 = uVar5 + 1;
      pbVar6 = pbVar6 + 2;
    } while (uVar5 != 8);
  }
  return;
}


