/*
 * Function: gpio_nrfx_pin_configure
 * Entry:    000873a0
 * Prototype: int __stdcall gpio_nrfx_pin_configure(device * port, gpio_pin_t pin, gpio_flags_t flags)
 */


/* exclude_from_export_ai */

int gpio_nrfx_pin_configure(device *port,gpio_pin_t pin,gpio_flags_t flags)

{
  bool bVar1;
  int iVar2;
  uint num_bytes;
  undefined *puVar3;
  
  num_bytes = (uint)pin;
  puVar3 = port->config;
  bVar1 = k_is_in_isr();
  if (bVar1) {
    iVar2 = -0xb;
  }
  else if (num_bytes < 5) {
    if ((((((-1 < (int)(flags << 0xf)) && (-1 < (int)(flags << 0x15))) &&
          (-1 < (int)(flags << 0x14))) && ((-1 < (int)(flags << 0xc) && (-1 < (int)(flags << 0xe))))
         ) || (iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes),
              -1 < iVar2)) &&
       (((iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes + 0x14 & 0xff),
         -1 < iVar2 &&
         (iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes + 10 & 0xff),
         -1 < iVar2)) &&
        ((iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes + 0xf & 0xff),
         -1 < iVar2 &&
         (iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes + 5 & 0xff),
         -1 < iVar2)))))) {
      iVar2 = i2c_write_dt(*(i2c_dt_spec **)(puVar3 + 4),&DAT_00000006,num_bytes + 0x19 & 0xff);
      return iVar2;
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}


