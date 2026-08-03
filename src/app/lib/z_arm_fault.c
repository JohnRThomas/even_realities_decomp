/*
 * Function: z_arm_fault
 * Entry:    00053e64
 * Prototype: undefined __stdcall z_arm_fault(undefined4 param_1, k_thread * param_2, undefined4 param_3, undefined4 param_4)
 */


/* exclude_from_export_ai */

void z_arm_fault(undefined4 param_1,k_thread *param_2,undefined4 param_3,undefined4 param_4)

{
  k_thread *pkStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  pkStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  arm_core_mpu_configure_static_mpu_regions
            ((z_arm_mpu_partition *)&PTR_bt_dev_0008ebcc,'\x01',(uint32_t)&bt_dev,
             (uint32_t)&DAT_2007e000);
  uStack_c = 0;
  pkStack_14 = &ancs_work_thread;
  uStack_10 = 0x7a210;
  arm_core_mpu_mark_areas_for_dynamic_regions((z_arm_mpu_partition *)&pkStack_14,'\x01');
  return;
}


