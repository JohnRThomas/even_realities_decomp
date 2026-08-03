/*
 * Function: rx_flush
 * Entry:    00088204
 * Prototype: uint8_t __stdcall rx_flush(device * dev, uint8_t * buf, uint32_t len)
 */


/* exclude_from_export_ai */

uint8_t rx_flush(device *dev,uint8_t *buf,uint32_t len)

{
  char cVar1;
  device **ppdVar2;
  device **ppdVar3;
  int iVar4;
  undefined *puVar5;
  device *pdStack_18;
  uint8_t *puStack_14;
  
  ppdVar2 = &pdStack_18;
  puVar5 = dev->name;
  iVar4 = *(int *)(puVar5 + 0x53c);
  if (buf == (uint8_t *)0x0) {
    len = 5;
    ppdVar3 = (device **)0x0;
  }
  else {
    pdStack_18 = dev;
    puStack_14 = buf;
    ppdVar2 = memset(buf,0,len);
    ppdVar3 = ppdVar2;
  }
  *(device ***)(puVar5 + 0x534) = ppdVar2;
  *(uint32_t *)(puVar5 + 0x538) = len;
  *(undefined4 *)(puVar5 + 0x110) = 0;
  *(undefined4 *)(puVar5 + 0x2c) = 1;
  do {
  } while (*(int *)(puVar5 + 0x110) == 0);
  *(undefined4 *)(puVar5 + 0x110) = 0;
  if ((ppdVar3 != (device **)0x0) && (iVar4 == *(int *)(puVar5 + 0x53c))) {
    ppdVar2 = ppdVar3;
    do {
      if (ppdVar2 == (device **)((int)ppdVar3 + len)) {
        return '\0';
      }
      cVar1 = *(char *)ppdVar2;
      ppdVar2 = (device **)((int)ppdVar2 + 1);
    } while (cVar1 == '\0');
  }
  return (uint8_t)*(int *)(puVar5 + 0x53c);
}


