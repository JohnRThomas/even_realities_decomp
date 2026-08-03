/*
 * Function: log_output_process
 * Entry:    00050da4
 * Prototype: uint32_t __stdcall log_output_process(log_output * output, uint32_t flags, bool func_on, log_timestamp_t timestamp, char * domain, char * source, k_tid_t tid, uint8_t level)
 */


/* exclude_from_export */

uint32_t log_output_process(log_output *output,uint32_t flags,bool func_on,log_timestamp_t timestamp
                           ,char *domain,char *source,k_tid_t tid,uint8_t level)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  code *out;
  uint32_t extraout_r0;
  int in_r3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined3 in_stack_00000015;
  undefined1 *local_3c;
  byte *local_38;
  
  uVar8 = timestamp._4_4_ & 0xff;
  local_38 = (byte *)source;
  local_3c = tid;
  if ((timestamp & 0xff00000000) == 0) {
    if (in_r3 == 1) {
      if (domain == (char *)0x0) {
LAB_00050efc:
        if (tid != (k_tid_t)0x0) {
          uVar8 = 0;
          goto LAB_00050f4a;
        }
        goto LAB_0005101a;
      }
      out = (code *)0x50d4d;
    }
    else {
      if (domain == (char *)0x0) goto LAB_00050efc;
      out = (code *)&UNK_00082681;
    }
LAB_00050f14:
    iVar2 = cbpprintf(out,(void *)0x82659,output);
    if (iVar2 < 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err >= 0",
              "WEST_TOPDIR/zephyr/subsys/logging/log_output.c",537);
LAB_00050dde:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
joined_r0x00050f40:
    if (local_3c != (undefined1 *)0x0) {
LAB_00050f4a:
      puVar6 = local_3c;
      if (&DAT_0000000f < local_3c) {
        puVar6 = &MemManage;
      }
      newline_print(output,_level);
      for (iVar2 = 0; iVar2 < (int)uVar8; iVar2 = iVar2 + 1) {
        print_formatted(output," ");
      }
      print_formatted(output,"%02x ",(uint)*local_38);
      puVar9 = &DAT_00000001;
      do {
        if (((uint)puVar9 & 7) == 0) {
          print_formatted(output," ");
        }
        if (puVar9 < puVar6) {
          print_formatted(output,"%02x ",(uint)local_38[(int)puVar9]);
        }
        else {
          print_formatted(output,"   ");
        }
        puVar9 = puVar9 + 1;
      } while (puVar9 != &MemManage);
      puVar9 = (undefined1 *)0x0;
      print_formatted(output,"|");
      do {
        uVar4 = (uint)local_38[(int)puVar9];
        if (((&DAT_000f6aa2)[uVar4] & 0x97) == 0) {
          uVar4 = 0x2e;
        }
        print_formatted(output,"%c",uVar4);
        while( true ) {
          puVar9 = puVar9 + 1;
          if (puVar9 == &MemManage) {
            local_38 = local_38 + (int)puVar6;
            local_3c = local_3c + -(int)puVar6;
            goto joined_r0x00050f40;
          }
          if (((uint)puVar9 & 7) == 0) {
            print_formatted(output," ");
          }
          if (puVar9 < puVar6) break;
          print_formatted(output," ");
        }
      } while( true );
    }
    if ((timestamp & 0xff00000000) == 0) goto LAB_0005101a;
  }
  else {
    if (4 < uVar8) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","level <= 4U",
              "WEST_TOPDIR/zephyr/subsys/logging/log_output.c",447);
      goto LAB_00050dde;
    }
    uVar4 = level & 8;
    pcVar1 = z_log_get_tag();
    if (pcVar1 == (char *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = print_formatted(output,"%s ",pcVar1);
    }
    if ((level & 2) != 0) {
      if ((level & 0x44) == 0) {
        iVar3 = print_formatted(output,"[%08lu] ",flags);
      }
      else {
        iVar3 = 0;
        if (DAT_2000aac4 != 0) {
          uVar5 = (flags / DAT_2000aac0) / DAT_2000aac4;
          uVar7 = (flags / DAT_2000aac0 - DAT_2000aac4 * uVar5) * 1000;
          uVar10 = uVar7 / DAT_2000aac4;
          iVar3 = print_formatted(output,"[%02u:%02u:%02u.%03u,%03u] ",uVar5 / 0xe10,
                                  (uVar5 % 0xe10) / 0x3c,(uVar5 % 0xe10) % 0x3c,uVar10,
                                  ((uVar7 - DAT_2000aac4 * uVar10) * 1000) / DAT_2000aac4);
        }
      }
      iVar2 = iVar2 + iVar3;
    }
    if ((level & 1) != 0) {
      pcVar1 = (&PTR_0008e854)[uVar8];
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "\x1b[0m";
      }
      print_formatted(output,"%s",pcVar1);
    }
    if ((level & 8) != 0) {
      uVar4 = print_formatted(output,"<%s> ",*(undefined4 *)(&DAT_0008e868 + uVar8 * 4));
    }
    if (func_on != 0) {
      iVar3 = print_formatted(output,"%s/",(uint)func_on);
      uVar4 = uVar4 + iVar3;
    }
    if (in_r3 != 0) {
      iVar3 = print_formatted(output,"%s: ");
      uVar4 = uVar4 + iVar3;
    }
    uVar8 = uVar4 + iVar2;
    if (domain != (char *)0x0) {
      out = (code *)0x50d4d;
      goto LAB_00050f14;
    }
    if (tid != (k_tid_t)0x0) goto LAB_00050f4a;
  }
  if ((int)(_level << 0x1f) < 0) {
    print_formatted(output,"%s","\x1b[0m");
  }
  newline_print(output,_level);
LAB_0005101a:
  log_output_flush(output);
  return extraout_r0;
}


