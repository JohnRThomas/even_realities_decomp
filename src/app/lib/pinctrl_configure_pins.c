/*
 * Function: pinctrl_configure_pins
 * Entry:    0008768e
 * Prototype: int __stdcall pinctrl_configure_pins(pinctrl_soc_pin_t * pins, uint8_t pin_cnt, uintptr_t reg)
 */


/* exclude_from_export */

int pinctrl_configure_pins(pinctrl_soc_pin_t *pins,uint8_t pin_cnt,uintptr_t reg)

{
  NRF_GPIO_Type *pNVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  pinctrl_soc_pin_t *ppVar6;
  uint uVar7;
  uint local_2c [2];
  
  ppVar6 = pins + pin_cnt;
  do {
    if (ppVar6 == pins) {
      return 0;
    }
    uVar2 = *pins;
    uVar4 = uVar2 & 0x7f;
    uVar5 = (uVar2 & 0x1fff) >> 9;
    if (uVar4 == 0x7f) {
      uVar4 = 0xffffffff;
    }
    local_2c[0] = uVar4;
    switch(uVar2 >> 0x10) {
    case 0:
      *(uint *)(reg + 0x50c) = uVar4;
      goto LAB_000876f6;
    case 1:
      *(uint *)(reg + 0x514) = uVar4;
      goto LAB_00087704;
    case 2:
      *(uint *)(reg + 0x508) = uVar4;
      goto LAB_000876f6;
    case 3:
      *(uint *)(reg + 0x510) = uVar4;
      goto LAB_00087704;
    default:
      return -0x86;
    case 0xb:
      *(uint *)(reg + 0x508) = uVar4;
      goto LAB_0008771e;
    case 0xc:
      *(uint *)(reg + 0x50c) = uVar4;
LAB_0008771e:
      if (uVar5 != 0) goto LAB_00087704;
      if (uVar4 != 0xffffffff) {
        uVar5 = 6;
        uVar7 = 0;
        uVar2 = 0;
        goto LAB_000877a4;
      }
      goto LAB_000876fa;
    case 0x14:
      *(uint *)(reg + 0x540) = uVar4;
      if (uVar4 != 0xffffffff) goto LAB_0008773e;
      goto LAB_000876fa;
    case 0x15:
      *(uint *)(reg + 0x544) = uVar4;
LAB_00087704:
      if (uVar4 != 0xffffffff) {
        uVar7 = 0;
        uVar2 = uVar7;
        goto LAB_000877a4;
      }
      goto LAB_000876fa;
    case 0x16:
      *(uint *)(reg + 0x560) = uVar4;
      goto LAB_00087760;
    case 0x17:
      *(uint *)(reg + 0x564) = uVar4;
      goto LAB_00087760;
    case 0x18:
      *(uint *)(reg + 0x568) = uVar4;
      goto LAB_00087760;
    case 0x19:
      *(uint *)(reg + 0x56c) = uVar4;
LAB_00087760:
      if (uVar4 != 0xffffffff) {
        if ((int)(*pins << 0x11) < 0) {
LAB_00087770:
          pNVar1 = nrf_gpio_pin_port_decode(local_2c);
          pNVar1[2] = 1 << (local_2c[0] & 0xff);
        }
        else {
LAB_0008773e:
          pNVar1 = nrf_gpio_pin_port_decode(local_2c);
          pNVar1[3] = 1 << (local_2c[0] & 0xff);
        }
        uVar7 = 1;
        uVar2 = uVar7;
        goto LAB_000877a4;
      }
      goto LAB_000876fa;
    case 0x1d:
      *(uint *)(reg + 0x524) = uVar4;
      break;
    case 0x1e:
      *(uint *)(reg + 0x528) = uVar4;
LAB_000876f6:
      if (uVar4 != 0xffffffff) goto LAB_00087770;
      goto LAB_000876fa;
    case 0x1f:
      *(uint *)(reg + 0x530) = uVar4;
      break;
    case 0x20:
      *(uint *)(reg + 0x534) = uVar4;
      break;
    case 0x21:
      *(uint *)(reg + 0x538) = uVar4;
      break;
    case 0x22:
      *(uint *)(reg + 0x53c) = uVar4;
    }
    if (uVar4 != 0xffffffff) {
      uVar7 = 0;
      uVar2 = 1;
LAB_000877a4:
      uVar3 = *pins;
      if ((uVar3 & 0x2000) != 0) {
        uVar2 = 1;
        uVar7 = 0;
      }
      local_2c[0] = uVar4;
      pNVar1 = nrf_gpio_pin_port_decode(local_2c);
      pNVar1[local_2c[0] + 0x80] =
           uVar5 << 8 | ((uVar3 & 0x1ff) >> 7) << 2 | uVar7 |
           pNVar1[local_2c[0] + 0x80] & 0xfffcf0f0 | uVar2 << 1;
    }
LAB_000876fa:
    pins = pins + 1;
  } while( true );
}


