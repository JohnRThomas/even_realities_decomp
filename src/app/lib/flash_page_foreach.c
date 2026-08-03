/*
 * Function: flash_page_foreach
 * Entry:    00087272
 * Prototype: void __stdcall flash_page_foreach(device * dev, flash_page_cb cb, void * data)
 */


/* exclude_from_export */

void flash_page_foreach(device *dev,flash_page_cb cb,void *data)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  
  iVar2 = 0;
  (**(code **)(dev->api + 0x10))(dev,&local_34,&local_30);
  uVar3 = 0;
  iVar6 = 0;
  do {
    if (local_30 <= uVar3) {
      return;
    }
    puVar5 = (uint *)(local_34 + uVar3 * 8);
    local_28 = puVar5[1];
    for (uVar4 = 0; local_24 = iVar6 + uVar4, uVar4 < *puVar5; uVar4 = uVar4 + 1) {
      local_2c = iVar2;
      iVar1 = (*(code *)cb)(&local_2c,data);
      if (iVar1 == 0) {
        return;
      }
      iVar2 = iVar2 + local_28;
    }
    uVar3 = uVar3 + 1;
    iVar6 = local_24;
  } while( true );
}


