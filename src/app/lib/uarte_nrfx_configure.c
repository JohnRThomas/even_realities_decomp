/*
 * Function: uarte_nrfx_configure
 * Entry:    00065d80
 * Prototype: int __stdcall uarte_nrfx_configure(device * dev, uart_config * cfg)
 */


/* exclude_from_export */

int uarte_nrfx_configure(device *dev,uart_config *cfg)

{
  char cVar1;
  uart_config uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  
  if (*(char *)((int)cfg + 5) == '\x01') {
    uVar8 = 0;
  }
  else {
    if (*(char *)((int)cfg + 5) != '\x03') {
      return -0x86;
    }
    uVar8 = 0x10;
  }
  if (*(char *)((int)cfg + 6) != '\x03') {
    return -0x86;
  }
  uVar7 = (uint)*(byte *)((int)cfg + 7);
  if ((uVar7 != 0) && (uVar7 != 1)) {
    return -0x86;
  }
  cVar1 = (char)cfg[1];
  if (cVar1 == '\x01') {
    uVar5 = 0x100;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\0') {
        return -0x86;
      }
      uVar3 = 0;
      uVar5 = 0;
      goto LAB_00065daa;
    }
    uVar5 = 0;
  }
  uVar3 = 0xe;
LAB_00065daa:
  pcVar4 = (char *)*cfg;
  if (pcVar4 == (char *)0x9600) {
    pcVar4 = (char *)0x9d0000;
  }
  else if (pcVar4 < (char *)0x9601) {
    if (pcVar4 == (char *)0x2580) {
      pcVar4 = (char *)0x275000;
    }
    else if (pcVar4 < (char *)0x2581) {
      if (pcVar4 == (char *)0x4b0) {
        pcVar4 = (char *)0x4f000;
      }
      else if (pcVar4 < (char *)0x4b1) {
        if (pcVar4 == (char *)0x12c) {
          pcVar4 = (char *)0x14000;
        }
        else {
          if (pcVar4 != (char *)0x258) {
            return -0x86;
          }
          pcVar4 = (char *)0x27000;
        }
      }
      else if (pcVar4 == (char *)0x960) {
        pcVar4 = " recv down recving\n";
      }
      else {
        if (pcVar4 != (char *)0x12c0) {
          return -0x86;
        }
        pcVar4 = (char *)0x13b000;
      }
    }
    else if (pcVar4 == (char *)0x7080) {
      pcVar4 = (char *)0x75c000;
    }
    else if (pcVar4 < (char *)0x7081) {
      if (pcVar4 == (char *)0x3840) {
        pcVar4 = (char *)0x3af000;
      }
      else {
        if (pcVar4 != (char *)0x4b00) {
          return -0x86;
        }
        pcVar4 = (char *)0x4ea000;
      }
    }
    else {
      if (pcVar4 != (char *)0x7a12) {
        return -0x86;
      }
      pcVar4 = (char *)0x800000;
    }
  }
  else if (pcVar4 == "") {
    pcVar4 = (char *)0x3b00000;
  }
  else if (pcVar4 < (char *)0x38401) {
    if (pcVar4 == (char *)0x12c00) {
      pcVar4 = (char *)0x13a9000;
    }
    else if (pcVar4 < (char *)0x12c01) {
      if (pcVar4 == (char *)0xdac0) {
        pcVar4 = (char *)0xe50000;
      }
      else {
        if (pcVar4 != (char *)0xe100) {
          return -0x86;
        }
        pcVar4 = (char *)0xeb0000;
      }
    }
    else {
      if (pcVar4 != (char *)0x1c200) {
        return -0x86;
      }
      pcVar4 = (char *)0x1d60000;
    }
  }
  else if (pcVar4 == "") {
    pcVar4 = (char *)0xf000000;
  }
  else if ("" < pcVar4) {
    if (pcVar4 != " gyroscope full-scale\r\n") {
      return -0x86;
    }
    pcVar4 = (char *)0x10000000;
  }
  else if (pcVar4 == (char *)0x3d090) {
    pcVar4 = (char *)0x4000000;
  }
  else {
    if (pcVar4 != (char *)0x70800) {
      return -0x86;
    }
    pcVar4 = (char *)0x7400000;
  }
  puVar6 = dev->data;
  *(char **)(*(int *)dev->config + 0x524) = pcVar4;
  *(uint *)(*(int *)dev->config + 0x56c) = uVar3 | uVar8 | uVar5 | uVar7;
  uVar2 = cfg[1];
  *(uart_config *)(puVar6 + 4) = *cfg;
  *(uart_config *)(puVar6 + 8) = uVar2;
  return 0;
}


