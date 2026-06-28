/*
 * Function: FUN_0000fd28
 * Entry:    0000fd28
 * Prototype: undefined __stdcall FUN_0000fd28(int param_1)
 */


void FUN_0000fd28(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined1 extraout_r2;
  undefined1 uVar4;
  uint in_fpscr;
  double dVar5;
  float fVar6;
  ulonglong uVar7;
  
  FUN_000276bc(param_1,&DAT_20019934);
  DAT_20019934 = 1;
  switch(*(undefined1 *)(param_1 + 5)) {
  case 1:
    FUN_0007f72a(param_1);
    *(undefined1 *)(param_1 + 5) = 2;
    DAT_20019934 = extraout_r2;
    *(undefined1 *)(param_1 + 2) = 0;
    return;
  case 2:
    z_impl_k_sleep((k_timeout_t)0x667);
LAB_0000fd6e:
    uVar4 = 3;
    break;
  case 3:
    if (*(char *)(param_1 + 2) == '\0') {
      if (*(char *)(param_1 + 7) == '\0') {
        if ((DAT_20003046 == '\0') && (*(char *)(param_1 + 0xb) == *(char *)(param_1 + 0xc))) {
          bVar1 = *(byte *)(param_1 + 0x13);
          iVar3 = (uint)bVar1 - (uint)DAT_200100d2;
          if (iVar3 < 0) {
            iVar3 = (uint)DAT_200100d2 - (uint)bVar1;
          }
          if (0x14 < iVar3) {
            DAT_200100d2 = (ushort)bVar1;
            goto LAB_0000fda0;
          }
        }
        else {
LAB_0000fda0:
          *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xc);
          FUN_00027314((undefined1 *)(param_1 + 7),(char *)(param_1 + 0x11),(char *)(param_1 + 0x1c)
                      );
          DAT_20003046 = '\0';
        }
        *(undefined1 *)(param_1 + 5) = 4;
      }
      if (*(char *)(param_1 + 1) != '\0') {
        *(undefined1 *)(param_1 + 1) = 0;
      }
      DAT_200083e4 = 150.0;
switchD_0000fd40_caseD_e:
      __FUN_00026f5c();
      return;
    }
LAB_0000fd76:
    uVar4 = 0xc;
    break;
  case 4:
    iVar3 = __FUN_00026f48();
    fVar6 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    if (fVar6 <= DAT_200083e4) {
      return;
    }
    if (*(char *)(param_1 + 7) == '\0') {
      uVar4 = 9;
    }
    else {
      uVar4 = 5;
    }
    break;
  case 5:
  case 6:
  case 7:
  case 9:
    if (*(char *)(param_1 + 7) == '\0') {
      uVar7 = __floatsidf(*(byte *)(param_1 + 0xb) + 3);
      dVar5 = fmod(2.0,(double)((uVar7 & 0xffffffff00000000) + (uVar7 & 0xffffffff)));
      uVar7 = __subdf(SUB84(dVar5,0),(uint)((ulonglong)dVar5 >> 0x20),0,0x40490000);
      DAT_200083e4 = (float)__truncdfsf2((uint)uVar7,(uint)(uVar7 >> 0x20));
    }
    __FUN_00026f5c();
    uVar4 = 10;
    break;
  default:
    goto switchD_0000fd40_caseD_8;
  case 10:
    if (*(char *)(param_1 + 1) == '\0') {
      iVar3 = __FUN_00026f48();
      fVar6 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
      if (fVar6 < DAT_200083e4) {
        return;
      }
    }
    uVar4 = 0xb;
    break;
  case 0xb:
    cVar2 = *(char *)(param_1 + 7);
    if (*(char *)(param_1 + 1) == '\0') {
      if (cVar2 != '\0') {
        DAT_20019934 = 1;
        return;
      }
      goto LAB_0000fd6e;
    }
    if (*(char *)(param_1 + 2) != '\0') {
      if (cVar2 != '\0') {
        DAT_20019934 = 1;
        return;
      }
      goto LAB_0000fd76;
    }
    if (cVar2 != '\0') {
      DAT_20019934 = 1;
      return;
    }
    uVar4 = 2;
    break;
  case 0xc:
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined1 *)(param_1 + 0xb) = 0x13;
    FUN_00027314((undefined1 *)(param_1 + 7),(char *)(param_1 + 0x11),(char *)(param_1 + 0x1c));
    DAT_20003046 = '\x01';
    *(undefined1 *)(param_1 + 1) = 0;
    __FUN_00026f5c();
    uVar4 = 0xe;
    break;
  case 0xe:
    goto switchD_0000fd40_caseD_e;
  }
  *(undefined1 *)(param_1 + 5) = uVar4;
switchD_0000fd40_caseD_8:
  return;
}


