/*
 * Function: mpu_configure_regions_and_partition
 * Entry:    00053d40
 * Prototype: int __stdcall mpu_configure_regions_and_partition(int param_1)
 */


/* exclude_from_export */

int mpu_configure_regions_and_partition(int param_1)

{
  log_msg_desc desc;
  int extraout_r0;
  int extraout_r0_00;
  int iVar1;
  int extraout_r0_01;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r4;
  int unaff_r5;
  uint *unaff_r6;
  uint *puVar5;
  int unaff_r7;
  uint uVar6;
  int unaff_r9;
  int unaff_r10;
  uint uVar7;
  dword in_stack_ffffffe0;
  uint8_t *in_stack_ffffffe4;
  void *in_stack_ffffffe8;
  undefined4 uStack_10;
  char *pcStack_c;
  int iStack_8;
  
  do {
    mpu_set_rnr(param_1 - 1);
    if (unaff_r10 != extraout_r0_00) {
      unaff_r10 = -0x16;
LAB_00053f54:
      pcStack_c = "Invalid underlying region index %u";
      iStack_8 = unaff_r10;
LAB_00053f6e:
      uStack_10 = 3;
      desc.level = (dword)&uStack_10;
      desc.domain = 0x1840;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffe0;
      z_impl_z_log_msg_static_create(&PTR_s_mpu_0008b9d8,desc,in_stack_ffffffe4,in_stack_ffffffe8);
      return -0x16;
    }
    if ((unaff_r10 == -0x16) || (unaff_r4 <= unaff_r10)) goto LAB_00053f54;
    *(int *)(unaff_r5 + 0x98) = unaff_r10;
    *(int *)(unaff_r5 + 0x98) = unaff_r10;
    uVar6 = *(uint *)(unaff_r5 + 0xa0) | 0x1f;
    uVar3 = *unaff_r6;
    uVar2 = unaff_r6[1];
    uVar7 = (uVar2 + uVar3) - 1;
    if ((*(uint *)(unaff_r5 + 0x9c) & 0xffffffe0) == uVar3) {
      if (uVar6 != uVar7) {
        *(int *)(unaff_r5 + 0x98) = unaff_r10;
        *(uint *)(unaff_r5 + 0x9c) = *(uint *)(unaff_r5 + 0x9c) & 0x1f | uVar2 + uVar3 & 0xffffffe0;
LAB_00053ff0:
        iVar1 = region_allocate_and_init((uint8_t)unaff_r4,(arm_mpu_region *)unaff_r6);
LAB_00053ff4:
        if (iVar1 == -0x16) {
          return -0x16;
        }
        goto LAB_00053ffa;
      }
      region_allocate_and_init((uint8_t)unaff_r10,(arm_mpu_region *)unaff_r6);
    }
    else {
      uVar2 = uVar3 - 1 & 0xffffffe0;
      *(int *)(unaff_r5 + 0x98) = unaff_r10;
      if (uVar6 == uVar7) {
        *(uint *)(unaff_r5 + 0xa0) = *(uint *)(unaff_r5 + 0xa0) & 0x1f | uVar2;
        goto LAB_00053ff0;
      }
      *(uint *)(unaff_r5 + 0xa0) = uVar2 | *(uint *)(unaff_r5 + 0xa0) & 0x1f;
      iVar1 = region_allocate_and_init((uint8_t)unaff_r4,(arm_mpu_region *)unaff_r6);
      if (iVar1 == -0x16) {
        return -0x16;
      }
      *(int *)(unaff_r5 + 0x98) = unaff_r10;
      *(byte *)(unaff_r7 + 0x10) =
           *(byte *)(unaff_r7 + 0x10) & 0xe0 | (byte)*(undefined4 *)(unaff_r5 + 0x9c) & 0x1f;
      *(byte *)(unaff_r7 + 0x10) =
           *(byte *)(unaff_r7 + 0x10) & 0x1f | (byte)((*(uint *)(unaff_r5 + 0xa0) >> 1 & 7) << 5);
      uVar4 = *unaff_r6;
      uVar3 = unaff_r6[1];
      *(uint *)(unaff_r7 + 8) = uVar4 + uVar3;
      uVar2 = iVar1 + 1U & 0xff;
      *(uint *)(unaff_r7 + 0x14) = ((uVar4 + uVar3 & 0xffffffe0) + (uVar6 - 1)) - uVar7 & 0xffffffe0
      ;
      if (7 < uVar2) {
        iVar1 = region_allocate_and_init_error(uVar2);
        goto LAB_00053ff4;
      }
      region_init(uVar2,(arm_mpu_region *)(unaff_r7 + 8));
      iVar1 = extraout_r0_01;
LAB_00053ffa:
      unaff_r4 = iVar1 + 1;
    }
    do {
      unaff_r9 = unaff_r9 + 1;
      puVar5 = unaff_r6 + 3;
      if (*(int *)(unaff_r7 + 4) <= unaff_r9) {
        return unaff_r4;
      }
      uVar2 = unaff_r6[4];
      unaff_r6 = puVar5;
    } while (uVar2 == 0);
    if (((uVar2 < 0x20) || ((uVar2 & 0x1f) != 0)) || (uVar3 = *puVar5, (uVar3 & 0x1f) != 0)) {
      pcStack_c = "Partition %u: sanity check failed.";
      iStack_8 = unaff_r9;
      goto LAB_00053f6e;
    }
    mpu_set_rnr(uVar3);
    param_1 = uVar2 + uVar3;
    unaff_r10 = extraout_r0;
  } while( true );
}


