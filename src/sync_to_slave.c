/*
 * Function: sync_to_slave
 * Entry:    00029078
 * Prototype: uint __stdcall sync_to_slave(char * param_1, uint param_2, undefined4 * param_3, uint param_4)
 */


uint sync_to_slave(char *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  undefined4 *puVar4;
  char cVar5;
  GlassesState *pGVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  short sVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  short sVar15;
  undefined4 *puVar16;
  longlong lVar17;
  undefined4 local_124;
  undefined1 uStack_120;
  undefined4 local_11f;
  undefined2 local_11b;
  char local_119;
  undefined4 local_118 [3];
  char local_10c [232];
  
  local_124 = 0;
  memset(&uStack_120,0,0xf8);
  uVar12 = **(undefined4 **)(param_1 + 0xff0);
  cVar5 = FUN_000169b4();
  if ((((cVar5 == '\x01') || (pGVar6 = __get_dashboard_state(), pGVar6->field_0x1 == '\b')) ||
      (cVar5 = FUN_00033d5c(), cVar5 == '\x01')) || (*param_1 == '\x02')) {
    uVar13 = 0;
    goto LAB_000290a4;
  }
  lVar17 = FUN_0007fea6();
  if (((int)*(longlong *)(param_1 + 0x1078) == 0 && *(int *)(param_1 + 0x107c) == 0) ||
     (lVar3 = lVar17 - *(longlong *)(param_1 + 0x1078),
     (int)(uint)((uint)lVar3 < 0x1389) <= (int)((ulonglong)lVar3 >> 0x20))) {
    uVar14 = 500;
  }
  else {
    uVar14 = 5000;
    if (param_2 != 0) {
      uVar14 = 3000;
    }
  }
  sVar15 = 0x1f5;
  while (sVar11 = 0, DAT_20019a6a != '\0') {
    sVar15 = sVar15 + -1;
    sVar11 = 0;
    if (sVar15 == 0) break;
    k_msleep(1);
  }
  while (DAT_20019a5d != '\0') {
    k_msleep(1);
    sVar11 = sVar11 + 1;
  }
  uVar13 = (uint)DAT_2000304e;
  if ((sVar11 == 0) || (uVar13 != param_2)) {
    if (uVar13 == 1) {
      if (param_2 == 0) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ESB send data after suspend cmd, ignore it.\n");
          }
          else {
            ble_printk("%s(): ESB send data after suspend cmd, ignore it.\n","sync_to_slave",
                       &DAT_20019a5d,BLE_DEBUG);
          }
        }
      }
      else {
        if (param_2 != 1) goto LAB_0002925e;
        if (499 < DAT_200100d4) goto LAB_00029186;
LAB_000291c6:
        if (0 < LOG_LEVEL) {
          pcVar7 = "%s(): ESB send same cmd, ignore it %d.\n";
          goto LAB_0002914a;
        }
      }
      goto LAB_00029164;
    }
    if (param_2 == 0) goto LAB_00029186;
    if (uVar13 == param_2) {
      if ((param_2 != 7) && (4 < param_2 - 0xc)) {
        if (DAT_200100d4 < 500) goto LAB_000291c6;
        goto LAB_0002925e;
      }
    }
    else {
LAB_0002925e:
      if ((int)param_2 < 3) goto LAB_00029186;
    }
LAB_000291de:
    DAT_20019a5d = 1;
    cVar5 = param_1[0xda];
    if (param_1[0xd5] == '\n') {
      cVar1 = *(char *)(*(int *)(param_1 + 0x1004) + 7);
    }
    else {
      cVar1 = param_1[0xee8];
    }
    param_1[0xda] = cVar5 + '\x01';
    param_1[0xd4] = (byte)param_2 & 0x3f | cVar1 << 6;
    param_1[0xc9] = param_1[0xc9] & 0x3fU | 0x40;
    *(undefined2 *)(param_1 + 0xd6) = *(undefined2 *)(param_1 + 0x108a);
    *(short *)(param_1 + 0xd8) =
         (short)*(undefined4 *)(param_1 + 0xeb8) + *(short *)(param_1 + 0x108c);
    local_124 = CONCAT31(local_124._1_3_,2);
    uVar8 = *(undefined4 *)(param_1 + 0xd0);
    *(undefined4 *)(param_1 + 0xd0) = uVar12;
    if ((param_3 == (undefined4 *)0x0) || (param_4 == 0)) {
      uVar9 = 0;
LAB_00029258:
      *(undefined4 *)(param_1 + 0xe5) = uVar9;
    }
    else {
      if (4 < param_4) {
        uVar9 = *param_3;
        goto LAB_00029258;
      }
      memcpy(param_1 + 0xe5,param_3,param_4);
    }
    local_124._1_3_ = (undefined3)*(undefined4 *)(param_1 + 0xc9);
    uStack_120 = (undefined1)((uint)*(undefined4 *)(param_1 + 0xc9) >> 0x18);
    local_11f = *(undefined4 *)(param_1 + 0xcd);
    local_11b = *(undefined2 *)(param_1 + 0xd1);
    local_119 = param_1[0xd3];
    pcVar7 = param_1 + 0xd4;
    puVar4 = local_118;
    do {
      puVar16 = puVar4;
      pcVar10 = pcVar7;
      uVar9 = *(undefined4 *)(pcVar10 + 4);
      pcVar7 = pcVar10 + 8;
      *puVar16 = *(undefined4 *)pcVar10;
      puVar16[1] = uVar9;
      puVar4 = puVar16 + 2;
    } while (pcVar7 != param_1 + 0xe4);
    puVar16[2] = *(undefined4 *)pcVar7;
    *(char *)(puVar16 + 3) = pcVar10[0xc];
    param_1[0x106e] = '\x01';
    bVar2 = param_1[0xec];
    if (((bVar2 == 6) || (bVar2 == 0)) || (param_2 != 0)) {
LAB_0002940a:
      (**(code **)(param_1 + 0x774))(&local_124,0x21);
      uVar13 = 0;
      while (param_1[0x106e] != '\x02') {
        uVar13 = uVar13 + 1 & 0xffff;
        if (uVar13 == uVar14) {
          uVar13 = uVar14;
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): sync to slave failed!!!!!! wait_count %d\n");
            }
            else {
              ble_printk("%s(): sync to slave failed!!!!!! wait_count %d\n","sync_to_slave",uVar14,
                         BLE_DEBUG);
            }
            if (param_1[0x106e] == '\x02') break;
          }
          __set_date(uVar8);
          goto LAB_00029428;
        }
        k_msleep(1);
      }
      __set_date(uVar12);
LAB_00029428:
      if (uVar13 < uVar14) {
        *(longlong *)(param_1 + 0x1078) = lVar17;
      }
      goto LAB_000290a4;
    }
    uVar13 = (uint)(byte)param_1[0xee8];
    if ((byte)param_1[0xeb] == uVar13) {
      if (param_1[0xd5] == '\x10') {
        if ((param_1[0xe9] == param_1[0xcc]) && (param_1[0xce] == '\0')) {
          if (uVar13 != 2) goto LAB_0002939c;
          goto LAB_00029480;
        }
        param_1[0xda] = cVar5;
        if (0 < LOG_LEVEL) {
          pcVar7 = "%s(): ESB send even ai is changed or receiving, ignore it.\n";
          goto LAB_00029300;
        }
      }
      else if ((byte)param_1[0xeb] == 2) {
        uVar13 = (uint)(byte)param_1[0xcc];
        if ((byte)param_1[0xe9] == uVar13) {
          uVar13 = (uint)(byte)param_1[0xce];
          if (uVar13 == 0) goto LAB_00029480;
          param_1[0xda] = cVar5;
          if (0 < LOG_LEVEL) {
            pcVar7 = "%s(): ESB send up package is receiving, ignore it.\n";
            goto LAB_00029300;
          }
        }
        else {
          param_1[0xda] = cVar5;
          if (0 < LOG_LEVEL) {
            pcVar7 = "%s(): ESB send up package is changed, ignore it.\n";
            goto LAB_00029300;
          }
        }
      }
      else {
LAB_0002939c:
        if (uVar13 == 1) {
          uVar13 = (uint)(byte)param_1[0xcd];
          if ((byte)param_1[0xea] == uVar13) {
            uVar13 = (uint)(byte)param_1[0xcf];
            if (uVar13 == 0) goto LAB_00029480;
            param_1[0xda] = cVar5;
            if (0 < LOG_LEVEL) {
              pcVar7 = "%s(): ESB send down package is receiving, ignore it.\n";
              goto LAB_00029300;
            }
          }
          else {
            param_1[0xda] = cVar5;
            if (0 < LOG_LEVEL) {
              pcVar7 = "%s(): ESB send down package is changed, ignore it.\n";
              goto LAB_00029300;
            }
          }
        }
        else {
LAB_00029480:
          if (((bVar2 == param_1[0xd5]) || (uVar13 = (uint)(byte)param_1[0xd5], uVar13 < 7)) ||
             (bVar2 < 7)) goto LAB_0002940a;
          param_1[0xda] = cVar5;
          if (0 < LOG_LEVEL) {
            pcVar7 = "%s(): ESB send package id is changed, ignore it.\n";
LAB_00029300:
            if (BLE_DEBUG == 0) {
              printk(pcVar7);
            }
            else {
              ble_printk(pcVar7,"sync_to_slave",uVar13,BLE_DEBUG);
            }
          }
        }
      }
    }
    else {
      param_1[0xda] = cVar5;
      if (0 < LOG_LEVEL) {
        pcVar7 = "%s(): ESB send imu status is changed, ignore it.\n";
        goto LAB_00029300;
      }
    }
  }
  else {
    if (param_2 == 0) {
LAB_00029186:
      DAT_2000304e = (byte)param_2;
      goto LAB_000291de;
    }
    if (0 < LOG_LEVEL) {
      pcVar7 = "%s(): ESB send same type cmd %d, exit\n";
LAB_0002914a:
      if (BLE_DEBUG == 0) {
        printk(pcVar7);
      }
      else {
        ble_printk(pcVar7,"sync_to_slave",param_2,BLE_DEBUG);
      }
    }
LAB_00029164:
    DAT_2000304e = 0;
  }
  uVar13 = 5000;
LAB_000290a4:
  DAT_200100d4 = (short)uVar13;
  DAT_20019a5d = 0;
  return uVar13;
}


