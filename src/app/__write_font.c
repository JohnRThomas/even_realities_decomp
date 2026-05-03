/*
 * Function: ?_write_font
 * Entry:    000247f0
 * Prototype: int __stdcall ?_write_font(undefined4 param_1, void * param_2, size_t param_3)
 */


int __write_font(undefined4 param_1,void *param_2,size_t param_3)

{
  bool bVar1;
  GlassesState *pGVar2;
  char *fmt;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 local_1028;
  undefined1 auStack_1024 [4096];
  
  local_1028 = 0;
  iVar5 = 1;
  memset(auStack_1024,0,0xffc);
  do {
    bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
    if (bVar1) {
      pGVar2 = __get_dashboard_state();
      pcVar4 = *(code **)&pGVar2->field_0x1044;
      pGVar2 = __get_dashboard_state();
      iVar3 = (*pcVar4)(pGVar2,param_1,&local_1028,0x1000);
      if (iVar3 == 0) {
        iVar3 = memcmp(param_2,&local_1028,param_3);
        if (iVar3 == 0) {
          printk("write font data and read data is same, exit\n");
          return 0;
        }
        pGVar2 = __get_dashboard_state();
        pcVar4 = *(code **)&pGVar2->field_0x104c;
        pGVar2 = __get_dashboard_state();
        iVar3 = (*pcVar4)(pGVar2,param_1,0x1000);
        if (iVar3 == 0) {
          pGVar2 = __get_dashboard_state();
          pcVar4 = *(code **)&pGVar2->field_0x1048;
          pGVar2 = __get_dashboard_state();
          iVar3 = (*pcVar4)(pGVar2,param_1,param_2,param_3);
          if (iVar3 == 0) {
            pGVar2 = __get_dashboard_state();
            pcVar4 = *(code **)&pGVar2->field_0x1044;
            pGVar2 = __get_dashboard_state();
            iVar3 = (*pcVar4)(pGVar2,param_1,&local_1028,0x1000);
            if (iVar3 == 0) {
              iVar3 = memcmp(param_2,&local_1028,param_3);
              if (iVar3 == 0) {
                return 0;
              }
              printk("flash verify font failed\n");
              iVar3 = 1;
              goto LAB_00024830;
            }
            fmt = "Flash read font failed! %d\n";
          }
          else {
            fmt = "Flash write font failed! %d\n";
          }
        }
        else {
          fmt = "Flash erase font failed! %d\n";
        }
        printk(fmt,iVar3);
      }
      else {
        printk("Flash read font failed! %d\n",iVar3);
      }
    }
    else {
      printk(" [%s] device not ready.\n","mx25r6435f@0");
      iVar3 = -1;
    }
LAB_00024830:
    iVar5 = iVar5 + 1;
    if (iVar5 == 0xb) {
      return iVar3;
    }
    z_impl_k_sleep((k_timeout_t)0xccd);
  } while( true );
}


