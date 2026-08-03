/*
 * Function: fmod_outline
 * Entry:    00013db8
 * Prototype: uint __stdcall fmod_outline(int param_1)
 */


/* exclude_from_export */

uint fmod_outline(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  ulonglong in_d0;
  ulonglong uVar7;
  
  uVar5 = (uint)(in_d0 >> 0x20);
  uVar6 = (uint)in_d0;
  uVar2 = (uVar5 & 0x7fffffff) >> 0x14;
  if (uVar2 == 0) {
    if ((in_d0 & 0x7fffffff00000000) == 0 && uVar6 == 0) {
      return uVar6;
    }
    in_d0 = __muldf3(uVar6,uVar5,0,0x43500000);
    uVar5 = (uint)(in_d0 >> 0x20);
    if (-0xc351 < param_1) {
      uVar2 = ((uVar5 & 0x7fffffff) >> 0x14) - 0x36;
      goto LAB_00013e0e;
    }
  }
  else {
    if (uVar2 == 0x7ff) {
      uVar7 = __aeabi_dadd(uVar6,uVar5,uVar6,uVar5);
      return (uint)uVar7;
    }
LAB_00013e0e:
    iVar3 = uVar2 + param_1;
    if (0x7fe < iVar3) {
      uVar1 = 0x7e37e43c;
      if ((int)uVar5 < 0) {
        uVar1 = 0xfe37e43c;
      }
      in_d0 = CONCAT44(uVar1,0x8800759c);
      uVar5 = 0x8800759c;
      puVar4 = (undefined *)0x7e37e43c;
      goto LAB_00013e2e;
    }
    if (0 < iVar3) {
      return (uint)in_d0;
    }
    if (-0x36 < iVar3) {
      uVar5 = 0;
      puVar4 = &DAT_3c900000;
      in_d0 = CONCAT44((uint)(in_d0 >> 0x20) & 0x800fffff | (iVar3 + 0x36) * 0x100000,(uint)in_d0);
      goto LAB_00013e2e;
    }
    in_d0 = 0x1a56e1fc2f8f359;
    if ((int)uVar5 < 0) {
      in_d0 = 0x81a56e1fc2f8f359;
    }
  }
  uVar5 = 0xc2f8f359;
  puVar4 = (undefined *)0x1a56e1f;
LAB_00013e2e:
  uVar7 = __muldf3((uint)in_d0,(uint)(in_d0 >> 0x20),uVar5,(uint)puVar4);
  return (uint)uVar7;
}


