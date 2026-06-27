/*
 * Function: uart_callback
 * Entry:    00034998
 * Prototype: undefined __stdcall uart_callback(undefined4 param_1, undefined1 * param_2, uint param_3)
 */


void uart_callback(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  char *s;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  int line;
  int line_00;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 *local_1c;
  
  local_1c = param_2;
  switch(*param_2) {
  case 0:
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Tx sent %d bytes\n");
      }
      else {
        ble_printk("%s(): Tx sent %d bytes\n","uart_callback",*(undefined4 *)(param_2 + 8),BLE_DEBUG
                  );
      }
    }
    for (uVar3 = 0; uVar3 < *(uint *)(param_2 + 8); uVar3 = uVar3 + 1) {
      printk("%02x ",(uint)*(byte *)(*(int *)(param_2 + 4) + uVar3));
    }
    break;
  case 1:
    if (LOG_LEVEL < 1) {
      return;
    }
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): Tx aborted\n","uart_callback",param_3,BLE_DEBUG);
      return;
    }
    printk("%s(): Tx aborted\n");
    return;
  case 2:
    uVar3 = *(uint *)(param_2 + 8);
    for (uVar5 = uVar3 & 0xffff; (uVar5 & 0xffff) < 0xf8; uVar5 = uVar5 + 1) {
      iVar2 = *(int *)(param_2 + 4);
      param_3 = (uint)*(byte *)(iVar2 + uVar5);
      s = (char *)(iVar2 + uVar5);
      if (((param_3 == 0x5a) && (param_3 = (uint)(byte)s[1], param_3 == 0xa5)) &&
         (param_3 = (uint)(byte)s[2], param_3 == 0x7f)) {
        param_3 = (uint)(byte)(s[3] + 5U);
        if ((int)param_3 <= (int)(0x100 - uVar5)) {
          cVar1 = '\0';
          pcVar6 = s;
          for (iVar4 = 0; iVar4 < (int)(param_3 - 1); iVar4 = iVar4 + 1) {
            cVar1 = cVar1 + *pcVar6;
            pcVar6 = pcVar6 + 1;
          }
          if (*(char *)(iVar2 + param_3 + uVar5 + -1) == cVar1) {
            DAT_2001adf7 = s[3] + 5U;
            memcpy(&DAT_2001adf8,s,param_3);
            memset(*(void **)(param_2 + 4),0,0x100);
            return;
          }
        }
      }
    }
    printk("recv data %d bytes:",*(undefined4 *)(param_2 + 0xc),param_3,uVar5 & 0xffff,param_1);
    for (uVar5 = 0; uVar5 < *(uint *)(param_2 + 0xc); uVar5 = uVar5 + 1) {
      printk("%02x ",(uint)*(byte *)(*(int *)(param_2 + 4) + uVar3 + uVar5));
    }
    break;
  case 3:
    printk("*************alloc new rx buf*************\n");
    iVar2 = k_mem_slab_alloc((k_mem_slab *)&DAT_20003958,&local_1c,(k_timeout_t)0x0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)(param_3 + 8) + 0x10))(param_3,local_1c,0x100);
      if (iVar2 == 0) {
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","../src/production_test/serial_port.c",0x54
             );
      _ASSERT("\tFailed to provide new buffer\n",test_00,file_00,line_00);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","../src/production_test/serial_port.c",0x51
             );
      _ASSERT("\tFailed to allocate slab\n",test,file,line);
    }
                    /* WARNING: Subroutine does not return */
    k_panic();
  case 4:
    printk(
          "****************************UART_RX_BUF_RELEASED***************************************\n"
          );
    k_mem_slab_free((k_mem_slab *)&DAT_20003958,*(void **)(param_2 + 4));
    return;
  default:
    return;
  }
  printk("\n");
  return;
}


