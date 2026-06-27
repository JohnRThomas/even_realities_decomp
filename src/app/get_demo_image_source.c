/*
 * Function: get_demo_image_source
 * Entry:    00038078
 * Prototype: undefined __stdcall get_demo_image_source(uint param_1)
 */


void get_demo_image_source(uint param_1)

{
  undefined4 *buf;
  GlassesState *pGVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int extraout_r2;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [4];
  undefined2 local_54;
  undefined4 local_50 [3];
  ushort local_42;
  
  buf = malloc(0x50);
  if (buf == (undefined4 *)0x0) {
    printk("[%s-%d]malloc error \n","get_demo_image_source",0xd3);
    return;
  }
  memset(buf,0,0x50);
  if (4 < param_1) {
    printk("error imgIdx is %d,reset as zero !\n",param_1);
    param_1 = 0;
  }
  pGVar1 = __get_dashboard_state();
  pcVar11 = *(code **)&pGVar1->field_0x1044;
  pGVar1 = __get_dashboard_state();
  iVar10 = param_1 * 0x3ebe + 0x180000;
  iVar2 = (*pcVar11)(pGVar1,iVar10,buf,0x50);
  if (iVar2 == 0) {
    local_60 = *buf;
    uStack_5c = buf[1];
    auStack_58 = (undefined1  [4])buf[2];
    local_54 = (undefined2)buf[3];
    iVar2 = strncmp((char *)&local_60,"BM",2);
    if (iVar2 == 0) {
      puVar7 = (undefined4 *)((int)buf + 0xe);
      puVar12 = local_50;
      do {
        uVar6 = *puVar7;
        uVar5 = puVar7[1];
        puVar7 = puVar7 + 2;
        *puVar12 = uVar6;
        puVar12[1] = uVar5;
        puVar12 = puVar12 + 2;
      } while (puVar7 != (undefined4 *)((int)buf + 0x36));
      FUN_000806d6((undefined4 *)(auStack_58 + 2));
      iVar2 = FUN_000806d6(local_50 + 1);
      iVar3 = FUN_000806d6(local_50 + 2);
      if (local_42 == 1) {
        iVar8 = iVar2 + 7;
        DAT_2000a9a4 = 0;
        if (iVar8 < 0) {
          iVar8 = iVar2 + 0xe;
        }
        DAT_2000a9a8 = 0;
        iVar8 = iVar8 >> 3;
        iVar9 = iVar2 + 0x1f;
        if (iVar9 < 0) {
          iVar9 = iVar2 + 0x3e;
        }
        iVar10 = iVar10 + extraout_r2 + (iVar3 + -1) * (iVar9 >> 5) * 4;
        for (uVar13 = 0; (int)uVar13 < iVar3; uVar13 = uVar13 + 1) {
          DAT_2000a9a4 = 0;
          memset(buf,0,0x50);
          pGVar1 = __get_dashboard_state();
          pcVar11 = *(code **)&pGVar1->field_0x1044;
          pGVar1 = __get_dashboard_state();
          iVar4 = (*pcVar11)(pGVar1,iVar10,buf,iVar8);
          if (iVar4 != 0) {
            uVar6 = 0x103;
            goto LAB_000380d4;
          }
          for (iVar4 = 0; iVar4 < iVar8; iVar4 = iVar4 + 1) {
            pixelto4bithex((uint)(byte)~*(byte *)((int)buf + iVar4),iVar2,uVar13 & 0xffff,iVar8);
          }
          if (DAT_2000a9ac != (void *)0x0) {
            DAT_2000a9a8 = 0;
            pGVar1 = __get_dashboard_state();
            memcpy((void *)(&(pGVar1->jdb_panel_context).field9_0x24)[uVar13],DAT_2000a9ac,0x140);
          }
          iVar10 = iVar10 + (iVar9 >> 5) * -4;
        }
      }
      else {
        printf("Unsupported bit depth - %d\r\n",(uint)local_42);
      }
    }
    else {
      printk("File is not BMP format \n");
    }
  }
  else {
    uVar6 = 0xdf;
LAB_000380d4:
    printk("[%s-%d] read pic from flash failed !\n","get_demo_image_source",uVar6);
  }
  free(buf);
  return;
}


