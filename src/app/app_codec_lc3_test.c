/*
 * Function: app_codec_lc3_test
 * Entry:    00030200
 * Prototype: undefined __stdcall app_codec_lc3_test(void * param_1, int param_2)
 */


void app_codec_lc3_test(void *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  uint size;
  uint uVar3;
  void *mem;
  void *ptr;
  void *src;
  char *fmt;
  lc3_encoder_t encoder;
  undefined4 extraout_r2;
  char *pcVar4;
  size_t size_00;
  size_t size_01;
  void *out;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  size = lc3_encoder_size(10000,16000);
  uVar3 = lc3_frame_samples(10000,16000);
  mem = malloc(size);
  size_01 = (uVar3 & 0x7fff) * 2;
  ptr = malloc(size_01);
  size_00 = (param_2 / (int)size_01 & 0xffffU) * 0x14;
  src = malloc(size_00);
  if (mem == (void *)0x0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): malloc error\r\n\n");
      }
      else {
        ble_printk("%s(): malloc error\r\n\n","app_codec_lc3_test",extraout_r2,BLE_DEBUG);
      }
    }
LAB_00030290:
    mem = ptr;
    if (ptr != (void *)0x0) goto LAB_0003027a;
  }
  else {
    if (ptr != (void *)0x0) {
      if (src != (void *)0x0) {
        cVar1 = FUN_00033d5c();
        if ((cVar1 != '\x01') || (bVar2 = z_device_is_ready((device *)&DAT_0008b3a0), bVar2)) {
          encoder = lc3_setup_encoder(10000,16000,0,mem);
          out = src;
          do {
            if (out == (void *)(size_00 + (int)src)) {
              cVar1 = FUN_00033d5c();
              if (cVar1 != '\x01') {
                if (DAT_20008558 == 0) {
                  enqueue_dmic(src);
                }
                else {
                  local_30 = 0;
                  uStack_2c = 0;
                  FUN_0004d4f8((longlong *)&local_30);
                  if (2 < LOG_LEVEL) {
                    if (BLE_DEBUG == 0) {
                      printk("%s(): send audio stream data to storage thread,timestemp = %lld\n",
                             "app_codec_lc3_test");
                    }
                    else {
                      ble_printk("%s(): send audio stream data to storage thread,timestemp = %lld\n"
                                 ,"app_codec_lc3_test",local_30,uStack_2c);
                    }
                  }
                  sendAudioStram2Cache(src);
                }
                goto LAB_0003034e;
              }
              if (0x40ffff < DAT_20002404) goto LAB_0003034e;
              pcVar4 = (char *)____qspi_nor_write((device *)&DAT_0008b3a0,DAT_20002404,src,size_00);
              if (pcVar4 != (char *)0x0) {
                if (LOG_LEVEL < 1) goto LAB_0003034e;
                fmt = "%s(): Flash write failed! %d\n\n";
                goto LAB_000302f2;
              }
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): Flash write to addr 0x%x\n\n");
                }
                else {
                  ble_printk("%s(): Flash write to addr 0x%x\n\n","app_codec_lc3_test",DAT_20002404,
                             BLE_DEBUG);
                }
              }
              DAT_20002404 = DAT_20002404 + size_00;
              goto LAB_0003034e;
            }
            pcVar4 = (char *)lc3_encode(encoder,0,param_1,1,0x14,out);
            out = (void *)((int)out + 0x14);
            param_1 = (void *)((int)param_1 + size_01);
          } while (pcVar4 == (char *)0x0);
          if (0 < LOG_LEVEL) {
            fmt = "%s(): lc3_encode did not return zero %d\n";
            goto LAB_000302f2;
          }
        }
        else if (0 < LOG_LEVEL) {
          pcVar4 = "mx25r6435f@0";
          fmt = "%s():  [%s] device not ready.\n\n";
LAB_000302f2:
          if (BLE_DEBUG == 0) {
            printk(fmt);
          }
          else {
            ble_printk(fmt,"app_codec_lc3_test",pcVar4,BLE_DEBUG);
          }
        }
LAB_0003034e:
        free(mem);
        free(ptr);
        goto LAB_00030266;
      }
      if (LOG_LEVEL < 1) {
        free(mem);
        src = ptr;
        goto LAB_00030266;
      }
LAB_000302ae:
      if (BLE_DEBUG == 0) {
        printk("%s(): malloc error\r\n\n");
      }
      else {
        ble_printk("%s(): malloc error\r\n\n","app_codec_lc3_test",extraout_r2,BLE_DEBUG);
      }
      free(mem);
      goto LAB_00030290;
    }
    if (0 < LOG_LEVEL) goto LAB_000302ae;
LAB_0003027a:
    free(mem);
  }
  if (src == (void *)0x0) {
    return;
  }
LAB_00030266:
  free(src);
  return;
}


