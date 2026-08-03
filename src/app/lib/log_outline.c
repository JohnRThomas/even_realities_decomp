/*
 * Function: log_outline
 * Entry:    00012fe8
 * Prototype: undefined4 __stdcall log_outline(void)
 */


/* exclude_from_export */

undefined4 log_outline(void)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ulonglong in_d0;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  uint local_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  uVar5 = (uint)(in_d0 >> 0x20);
  uVar6 = (uint)in_d0;
  if ((int)uVar5 < 0x100000) {
    if ((in_d0 & 0x7fffffff00000000) == 0 && uVar6 == 0) {
      uVar12 = 0xc350000000000000;
LAB_0001300c:
      uVar12 = __divdf3((uint)uVar12,(uint)(uVar12 >> 0x20),0,0);
      return (int)uVar12;
    }
    if ((longlong)in_d0 < 0) {
      uVar12 = __subdf(uVar6,uVar5,uVar6,uVar5);
      goto LAB_0001300c;
    }
    in_d0 = __muldf3(uVar6,uVar5,0,0x43500000);
    uVar5 = (uint)(in_d0 >> 0x20);
    iVar9 = -0x36;
  }
  else {
    iVar9 = 0;
  }
  uVar12 = in_d0;
  if ((int)uVar5 < 0x7ff00000) {
    uVar11 = uVar5 & 0xfffff;
    uVar10 = ((int)uVar5 >> 0x14) + -0x3ff + iVar9 + ((int)&PTR_DAT_00095f64 + uVar11 >> 0x14);
    uVar12 = __subdf((uint)in_d0,(int)&PTR_DAT_00095f64 + uVar11 & 0x100000 ^ 0x3ff00000 | uVar11,0,
                     0x3ff00000);
    uVar6 = (uint)(uVar12 >> 0x20);
    uVar5 = (uint)uVar12;
    if ((uVar11 + 2 & 0xfffff) < 3) {
      bVar1 = __aeabi_dcmpeq(uVar5,uVar6,0,0);
      if (bVar1) {
        if (uVar10 == 0) {
          return 0;
        }
        uVar12 = __floatsidf(uVar10);
        uVar5 = (uint)(uVar12 >> 0x20);
        in_d0 = __muldf3((uint)uVar12,uVar5,0xfee00000,0x3fe62e42);
        uVar12 = __muldf3((uint)uVar12,uVar5,0x35793c76,0x3dea39ef);
        goto LAB_00013042;
      }
      uVar13 = __muldf3(uVar5,uVar6,0x55555555,0x3fd55555);
      uVar13 = __subdf(0,0x3fe00000,(uint)uVar13,(uint)(uVar13 >> 0x20));
      uVar14 = __muldf3(uVar5,uVar6,uVar5,uVar6);
      uVar15 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),(uint)uVar14,(uint)(uVar14 >> 0x20));
      if (uVar10 != 0) {
        uVar13 = __floatsidf(uVar10);
        uVar12 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),0xfee00000,0x3fe62e42);
LAB_0001312e:
        uVar13 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),0x35793c76,0x3dea39ef);
LAB_00013280:
        uVar13 = __subdf((uint)uVar15,(uint)(uVar15 >> 0x20),(uint)uVar13,(uint)(uVar13 >> 0x20));
        uVar15 = __subdf((uint)uVar13,(uint)(uVar13 >> 0x20),uVar5,uVar6);
      }
    }
    else {
      uVar13 = __aeabi_dadd(uVar5,uVar6,0,0x40000000);
      uVar14 = __divdf3(uVar5,uVar6,(uint)uVar13,(uint)(uVar13 >> 0x20));
      uVar13 = __floatsidf(uVar10);
      local_40 = (uint)uVar14;
      uStack_3c = (uint)(uVar14 >> 0x20);
      uVar14 = __muldf3(local_40,uStack_3c,local_40,uStack_3c);
      uVar7 = (uint)(uVar14 >> 0x20);
      uVar3 = (uint)uVar14;
      uVar14 = __muldf3(uVar3,uVar7,uVar3,uVar7);
      uVar8 = (uint)(uVar14 >> 0x20);
      uVar4 = (uint)uVar14;
      uVar14 = __muldf3(uVar4,uVar8,0xdf3e5244,0x3fc2f112);
      uVar14 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),0x96cb03de,0x3fc74664);
      uVar14 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),uVar4,uVar8);
      uVar14 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),0x94229359,0x3fd24924);
      uVar14 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),uVar4,uVar8);
      uVar14 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),0x55555593,0x3fe55555);
      uVar14 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),uVar3,uVar7);
      uVar15 = __muldf3(uVar4,uVar8,0xd078c69f,0x3fc39a09);
      uVar15 = __aeabi_dadd((uint)uVar15,(uint)(uVar15 >> 0x20),0x1d8e78af,0x3fcc71c5);
      uVar15 = __muldf3((uint)uVar15,(uint)(uVar15 >> 0x20),uVar4,uVar8);
      uVar15 = __aeabi_dadd((uint)uVar15,(uint)(uVar15 >> 0x20),0x9997fa04,0x3fd99999);
      uVar15 = __muldf3((uint)uVar15,(uint)(uVar15 >> 0x20),uVar4,uVar8);
      local_30 = (uint)uVar14;
      uStack_2c = (uint)(uVar14 >> 0x20);
      uVar14 = __aeabi_dadd(local_30,uStack_2c,(uint)uVar15,(uint)(uVar15 >> 0x20));
      uVar3 = (uint)(uVar14 >> 0x20);
      local_38 = (uint)uVar13;
      uStack_34 = (uint)(uVar13 >> 0x20);
      if ((int)(0x6b851 - uVar11 | uVar11 - 0x6147a) < 1) {
        uVar14 = __subdf(uVar5,uVar6,(uint)uVar14,uVar3);
        uVar15 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),local_40,uStack_3c);
        if (uVar10 != 0) {
          uVar12 = __muldf3(local_38,uStack_34,0xfee00000,0x3fe62e42);
          goto LAB_0001312e;
        }
      }
      else {
        uVar13 = __muldf3(uVar5,uVar6,0,0x3fe00000);
        uVar15 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),uVar5,uVar6);
        uVar11 = (uint)(uVar15 >> 0x20);
        uVar13 = __aeabi_dadd((uint)uVar14,uVar3,(uint)uVar15,uVar11);
        uVar13 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),local_40,uStack_3c);
        uVar3 = (uint)(uVar13 >> 0x20);
        if (uVar10 != 0) {
          uVar12 = __muldf3(local_38,uStack_34,0xfee00000,0x3fe62e42);
          uVar14 = __muldf3(local_38,uStack_34,0x35793c76,0x3dea39ef);
          uVar13 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),(uint)uVar13,uVar3);
          goto LAB_00013280;
        }
        uVar15 = __subdf((uint)uVar15,uVar11,(uint)uVar13,uVar3);
      }
    }
    uVar12 = __subdf((uint)uVar12,(uint)(uVar12 >> 0x20),(uint)uVar15,(uint)(uVar15 >> 0x20));
    uVar2 = (undefined4)uVar12;
  }
  else {
LAB_00013042:
    uVar12 = __aeabi_dadd((uint)in_d0,(uint)(in_d0 >> 0x20),(uint)uVar12,(uint)(uVar12 >> 0x20));
    uVar2 = (undefined4)uVar12;
  }
  return uVar2;
}


