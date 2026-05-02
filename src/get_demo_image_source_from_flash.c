/*
 * Function: get_demo_image_source_from_flash
 * Entry:    00037e44
 * Prototype: undefined __stdcall get_demo_image_source_from_flash(void)
 */


void get_demo_image_source_from_flash(void)

{
  undefined4 *buf;
  GlassesState *pGVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
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
    printk("[%s-%d]malloc error \n","get_demo_image_source_from_flash",0x54);
    return;
  }
  memset(buf,0,0x50);
  pGVar1 = __get_dashboard_state();
  pcVar11 = *(code **)&pGVar1->field_0x1044;
  pGVar1 = __get_dashboard_state();
  iVar2 = (*pcVar11)(pGVar1,0x1c0000,buf,0x50);
  if (iVar2 == 0) {
    local_60 = *buf;
    uStack_5c = buf[1];
    auStack_58 = (undefined1  [4])buf[2];
    local_54 = (undefined2)buf[3];
    iVar2 = strncmp((char *)&local_60,"BM",2);
    if (iVar2 == 0) {
      puVar8 = (undefined4 *)((int)buf + 0xe);
      puVar12 = local_50;
      do {
        uVar7 = *puVar8;
        uVar6 = puVar8[1];
        puVar8 = puVar8 + 2;
        *puVar12 = uVar7;
        puVar12[1] = uVar6;
        puVar12 = puVar12 + 2;
      } while (puVar8 != (undefined4 *)((int)buf + 0x36));
      iVar2 = FUN_000806d6((undefined4 *)(auStack_58 + 2));
      iVar3 = FUN_000806d6(local_50 + 1);
      iVar4 = FUN_000806d6(local_50 + 2);
      if (local_42 == 1) {
        iVar9 = iVar3 + 7;
        DAT_2000a9a4 = 0;
        if (iVar9 < 0) {
          iVar9 = iVar3 + 0xe;
        }
        DAT_2000a9a8 = 0;
        iVar9 = iVar9 >> 3;
        iVar10 = iVar3 + 0x1f;
        if (iVar10 < 0) {
          iVar10 = iVar3 + 0x3e;
        }
        iVar2 = iVar2 + 0x1c0000 + (iVar4 + -1) * (iVar10 >> 5) * 4;
        for (uVar13 = 0; (int)uVar13 < iVar4; uVar13 = uVar13 + 1) {
          DAT_2000a9a4 = 0;
          memset(buf,0,0x50);
          pGVar1 = __get_dashboard_state();
          pcVar11 = *(code **)&pGVar1->field_0x1044;
          pGVar1 = __get_dashboard_state();
          iVar5 = (*pcVar11)(pGVar1,iVar2,buf,iVar9);
          if (iVar5 != 0) {
            uVar7 = 0x7e;
            goto LAB_00037e88;
          }
          for (iVar5 = 0; iVar5 < iVar9; iVar5 = iVar5 + 1) {
            pixelto4bithex_for_flash
                      ((uint)(byte)~*(byte *)((int)buf + iVar5),iVar3,uVar13 & 0xffff,iVar9);
          }
          if (DAT_2000a9ac != (void *)0x0) {
            DAT_2000a9a8 = 0;
            pGVar1 = __get_dashboard_state();
            memcpy(*(void **)(&pGVar1->field_0xb90 + uVar13 * 4),DAT_2000a9ac,0x140);
          }
          iVar2 = iVar2 + (iVar10 >> 5) * -4;
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
    uVar7 = 0x5a;
LAB_00037e88:
    printk("[%s-%d] read pic from flash failed !\n","get_demo_image_source_from_flash",uVar7);
  }
  free(buf);
  return;
}


