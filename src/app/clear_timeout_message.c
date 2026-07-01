/*
 * Function: clear_timeout_message
 * Entry:    0003537c
 * Prototype: undefined __stdcall clear_timeout_message(int param_1)
 */


void clear_timeout_message(int param_1)

{
  byte bVar1;
  int iVar2;
  GlassesState *pGVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = 0;
  iVar8 = 0;
  iVar6 = 0;
  DAT_20019a5c = 1;
LAB_00035398:
  iVar2 = (&DAT_2000878c)[iVar6 * 0x6d];
  iVar5 = (&DAT_20008790)[iVar6 * 0x6d];
  if (iVar2 == 0) {
    if (iVar7 == 0) goto LAB_000353e8;
    if (iVar8 == 0) {
      iVar8 = iVar7;
      if (iVar5 == 0) {
        iVar5 = iVar6 + 1;
        goto joined_r0x00035516;
      }
      if (-1 < (int)((uint)(byte)(&DAT_2000879b)[iVar6 * 0x1b4] << 0x1f)) goto LAB_000353d0;
LAB_0003540e:
      if (param_1 == 0) {
LAB_00035412:
        uVar4 = FUN_00080732();
        iVar2 = (&DAT_20008790)[iVar6 * 0x6d];
        pGVar3 = __get_dashboard_state();
        if (uVar4 <= iVar2 + (uint)(byte)pGVar3->field_0x10d7) goto LAB_000353d0;
      }
    }
    else {
      if (-1 < (int)((uint)(byte)(&DAT_2000879b)[iVar6 * 0x1b4] << 0x1f)) {
LAB_000353b4:
        iVar5 = iVar6 + iVar8;
joined_r0x00035516:
        if (iVar5 < 10) goto LAB_000354d0;
        goto LAB_00035478;
      }
      if (param_1 == 0) {
        if (iVar5 == 0) goto LAB_000353b4;
        goto LAB_00035412;
      }
      if (iVar5 == 0) goto LAB_000353b4;
    }
    iVar8 = iVar8 + 1;
    iVar5 = iVar8 + iVar6;
    memset(&DAT_2000878c + iVar6 * 0x6d,0,0x1b4);
    if (9 < iVar5) goto LAB_00035478;
    if ((&DAT_2000878c)[iVar6 * 0x6d] != 0) {
      iVar6 = iVar6 + 1;
      goto LAB_00035398;
    }
  }
  else {
    iVar7 = 1;
LAB_000353e8:
    if (iVar5 == 0) {
      if (iVar8 != 0) {
        iVar5 = iVar6 + iVar8;
        if (9 < iVar5) goto LAB_00035478;
        if (iVar2 == 0) goto LAB_000354d0;
LAB_000354c2:
        iVar6 = iVar6 + 1;
        goto LAB_00035398;
      }
      goto LAB_000353ee;
    }
    bVar1 = (&DAT_2000879b)[iVar6 * 0x1b4];
    if ((bVar1 & 1) != 0) goto LAB_0003540e;
    if ((iVar2 != 0) && (uVar4 = FUN_00080732(), (&DAT_20008790)[iVar6 * 0x6d] + 5 < uVar4)) {
      iVar8 = iVar8 + 1;
      iVar5 = iVar8 + iVar6;
      memset(&DAT_2000878c + iVar6 * 0x6d,bVar1 & 1,0x1b4);
      if (iVar5 < 10) {
        if ((&DAT_2000878c)[iVar6 * 0x6d] != 0) goto LAB_000354c2;
        goto LAB_000354d0;
      }
      goto LAB_00035478;
    }
LAB_000353d0:
    iVar5 = iVar8 + iVar6;
    if (9 < iVar5) goto LAB_00035478;
    if (((&DAT_2000878c)[iVar6 * 0x6d] != 0) || (iVar8 == 0)) goto LAB_000353ee;
  }
LAB_000354d0:
  if ((&DAT_2000879c)[iVar5 * 0x1b4] == '\0') {
    iVar8 = iVar8 + 1;
    goto LAB_00035398;
  }
  memcpy(&DAT_2000878c + iVar6 * 0x6d,&DAT_2000878c + iVar5 * 0x6d,0x1b4);
  memset(&DAT_2000878c + iVar5 * 0x6d,0,0x1b4);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ######clear_timeout_message copy data from %d to  i %d\n",
             "clear_timeout_message",iVar5,iVar6);
    }
    else {
      ble_printk("%s(): ######clear_timeout_message copy data from %d to  i %d\n",
                 "clear_timeout_message",iVar5,iVar6);
    }
  }
LAB_000353ee:
  iVar6 = iVar6 + 1;
  if (iVar6 == 10) {
LAB_00035478:
    pGVar3 = __get_dashboard_state();
    uVar4 = FUN_00035310();
    pGVar3->field20_0xc8[0x15] = (char)uVar4;
    DAT_20019a5c = 0;
    return;
  }
  goto LAB_00035398;
}


