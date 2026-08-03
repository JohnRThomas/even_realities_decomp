/*
 * Function: __ieee754_log
 * Entry:    00012d08
 * Prototype: uint __stdcall __ieee754_log(undefined4 param_1, undefined4 param_2)
 */


/* exclude_from_export_ai */

uint __ieee754_log(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  ulonglong in_d0;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 local_30;
  uint local_28;
  uint uStack_24;
  
  uVar8 = CONCAT44(unaff_r9,unaff_r8);
  local_30 = CONCAT44(param_2,param_1);
  uVar6 = (uint)(in_d0 >> 0x20);
  uVar5 = (uint)in_d0;
  uVar4 = uVar6 & 0x7fffffff;
  iVar1 = (int)uVar6 >> 0x1f;
  if (uVar4 < 0x40862e42) {
    if (uVar4 < 0x3fd62e43) {
      if (uVar4 < 0x3e300000) {
        uVar8 = __aeabi_dadd(uVar5,uVar6,0x8800759c,0x7e37e43c);
        bVar2 = __ltdf2((uint)uVar8,(uint)(uVar8 >> 0x20),0,0x3ff00000);
        if (bVar2) {
          uVar4 = 0;
          uVar3 = 0x3ff00000;
          goto LAB_00012d5c;
        }
        uVar4 = 0;
        uVar8 = CONCAT44(unaff_r9,unaff_r8);
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      if (uVar4 < 0x3ff0a2b2) {
        uVar4 = iVar1 * 2 + 1;
        uVar8 = __subdf(uVar5,uVar6,*(uint *)(&DAT_0008c008 + iVar1 * -8),
                        *(uint *)(&DAT_0008c00c + iVar1 * -8));
        local_30 = *(ulonglong *)(&LAB_0008bff8 + iVar1 * -8);
      }
      else {
LAB_00012e86:
        uVar8 = __muldf3(uVar5,uVar6,0x652b82fe,0x3ff71547);
        uVar8 = __aeabi_dadd((uint)uVar8,(uint)(uVar8 >> 0x20),*(uint *)(&DAT_0008c018 + iVar1 * -8)
                             ,*(uint *)(&DAT_0008c01c + iVar1 * -8));
        uVar4 = _cast_double_to_int((uint)uVar8,(uint)(uVar8 >> 0x20));
        uVar9 = __floatsidf(uVar4);
        uVar3 = (uint)(uVar9 >> 0x20);
        uVar8 = __muldf3((uint)uVar9,uVar3,0xfee00000,0x3fe62e42);
        uVar8 = __subdf(uVar5,uVar6,(uint)uVar8,(uint)(uVar8 >> 0x20));
        local_30 = __muldf3((uint)uVar9,uVar3,0x35793c76,0x3dea39ef);
      }
      in_d0 = __subdf((uint)uVar8,(uint)(uVar8 >> 0x20),(uint)local_30,local_30._4_4_);
    }
    uVar7 = (uint)(in_d0 >> 0x20);
    uVar3 = (uint)in_d0;
    uVar9 = __muldf3(uVar3,uVar7,uVar3,uVar7);
    uVar5 = (uint)(uVar9 >> 0x20);
    uVar6 = (uint)uVar9;
    uVar9 = __muldf3(uVar6,uVar5,0x72bea4d0,0x3e663769);
    uVar9 = __subdf((uint)uVar9,(uint)(uVar9 >> 0x20),0xc5d26bf1,0x3ebbbd41);
    uVar9 = __muldf3((uint)uVar9,(uint)(uVar9 >> 0x20),uVar6,uVar5);
    uVar9 = __aeabi_dadd((uint)uVar9,(uint)(uVar9 >> 0x20),0xaf25de2c,0x3f11566a);
    uVar9 = __muldf3((uint)uVar9,(uint)(uVar9 >> 0x20),uVar6,uVar5);
    uVar9 = __subdf((uint)uVar9,(uint)(uVar9 >> 0x20),0x16bebd93,0x3f66c16c);
    uVar9 = __muldf3((uint)uVar9,(uint)(uVar9 >> 0x20),uVar6,uVar5);
    uVar9 = __aeabi_dadd((uint)uVar9,(uint)(uVar9 >> 0x20),0x5555553e,0x3fc55555);
    uVar9 = __muldf3((uint)uVar9,(uint)(uVar9 >> 0x20),uVar6,uVar5);
    uVar9 = __subdf(uVar3,uVar7,(uint)uVar9,(uint)(uVar9 >> 0x20));
    uVar5 = (uint)(uVar9 >> 0x20);
    uVar6 = (uint)uVar9;
    uVar9 = __muldf3(uVar3,uVar7,uVar6,uVar5);
    local_28 = (uint)uVar9;
    uStack_24 = (uint)(uVar9 >> 0x20);
    if (uVar4 == 0) {
      uVar8 = __subdf(uVar6,uVar5,0,0x40000000);
      uVar8 = __divdf3(local_28,uStack_24,(uint)uVar8,(uint)(uVar8 >> 0x20));
      uVar8 = __subdf((uint)uVar8,(uint)(uVar8 >> 0x20),uVar3,uVar7);
      uVar8 = __subdf(0,0x3ff00000,(uint)uVar8,(uint)(uVar8 >> 0x20));
      return (uint)uVar8;
    }
    uVar9 = __subdf(0,0x40000000,uVar6,uVar5);
    uVar9 = __divdf3(local_28,uStack_24,(uint)uVar9,(uint)(uVar9 >> 0x20));
    uVar9 = __subdf((uint)local_30,local_30._4_4_,(uint)uVar9,(uint)(uVar9 >> 0x20));
    uVar8 = __subdf((uint)uVar9,(uint)(uVar9 >> 0x20),(uint)uVar8,(uint)(uVar8 >> 0x20));
    uVar8 = __subdf(0,0x3ff00000,(uint)uVar8,(uint)(uVar8 >> 0x20));
    uVar5 = (uint)uVar8;
    if (-0x3fe < (int)uVar4) {
      return uVar5;
    }
    uVar3 = (int)(uVar8 >> 0x20) + (uVar4 + 1000) * 0x100000;
    uVar4 = 0;
    uVar6 = 0x1700000;
LAB_00012d7e:
    uVar8 = __muldf3(uVar5,uVar3,uVar4,uVar6);
    uVar4 = (uint)uVar8;
  }
  else {
    if (uVar4 < 0x7ff00000) {
      bVar2 = __ltdf2(uVar5,uVar6,0xfefa39ef,0x40862e42);
      if (bVar2) {
        uVar5 = 0x8800759c;
        uVar3 = 0x7e37e43c;
        uVar4 = uVar5;
        uVar6 = uVar3;
        goto LAB_00012d7e;
      }
      bVar2 = __gedf2(uVar5,uVar6,0xd52d3051,0xc0874910);
      if (!bVar2) goto LAB_00012e86;
    }
    else {
      uVar4 = uVar5;
      uVar3 = uVar6;
      if ((in_d0 & 0xfffff00000000) != 0 || uVar5 != 0) {
LAB_00012d5c:
        uVar8 = __aeabi_dadd(uVar5,uVar6,uVar4,uVar3);
        return (uint)uVar8;
      }
      if (-1 < (longlong)in_d0) {
        return uVar5;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}


