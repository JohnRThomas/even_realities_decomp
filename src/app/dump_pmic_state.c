/*
 * Function: ?_dump_pmic_state
 * Entry:    000161b0
 * Prototype: undefined4 __stdcall ?_dump_pmic_state(size_t param_1, uint3 param_2, undefined4 param_3)
 */


undefined4 __dump_pmic_state(size_t param_1,uint3 param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = (uint)param_2;
  uStack_10 = param_3;
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x10);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x11);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x12);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x13);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x14);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x15);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x16);
  i2c_write_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x17);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x10,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x10 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x11,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x11 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x12,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x12 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x13,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x13 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x14,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x14 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x15,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x15 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x16,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x16 is %x\n",uStack_14 >> 0x18);
  i2c_write_read_dt((i2c_dt_spec *)&PTR_s_pmic_6b_0008b430,&DAT_00000003,0x17,
                    (void *)((int)&uStack_14 + 3),param_1);
  printk("0x17 is %x\n",uStack_14 >> 0x18);
  return 0;
}


