/*
 * Function: regulator_npm1300_ship_mode
 * Entry:    0008799e
 * Prototype: undefined __stdcall regulator_npm1300_ship_mode(int param_1)
 */


/* exclude_from_export */

void regulator_npm1300_ship_mode(int param_1)

{
  i2c_write_dt((i2c_dt_spec *)**(undefined4 **)(param_1 + 4),&DAT_0000000b,2);
  return;
}


