/*
 * Function: AW_DELAY
 * Entry:    0003160c
 * Prototype: void __stdcall AW_DELAY(uint32_t ms)
 */


/* exclude_from_export aw9320x.c */

void AW_DELAY(uint32_t ms)

{
                    /* WARNING: Could not recover jumptable at 0x00031612. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(g_aw9320x_func.i2c_func.i2c_r + 0xc))(ms);
  return;
}


