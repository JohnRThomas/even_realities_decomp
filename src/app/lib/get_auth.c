/*
 * Function: get_auth
 * Entry:    00060814
 * Prototype: uint8_t __stdcall get_auth(bt_smp * smp, uint8_t auth)
 */


/* exclude_from_export_ai */

uint8_t get_auth(bt_smp *smp,uint8_t auth)

{
  uint8_t uVar1;
  byte *pbVar2;
  byte bVar3;
  
  if (DAT_2001e2a6 == '\0') {
    bVar3 = auth & 7;
  }
  else {
    bVar3 = auth & 0xf;
  }
  uVar1 = get_io_capa();
  if (uVar1 == '\x03') {
    bVar3 = bVar3 & 0xb;
  }
  else {
    bVar3 = bVar3 | 4;
  }
  pbVar2 = smp[3].mackey + 0xb;
  if (*(int *)pbVar2 == -1) {
    *(uint *)pbVar2 = (uint)DAT_20003750;
  }
  if (*(int *)pbVar2 == 0) {
    bVar3 = bVar3 & 0xfe;
  }
  else {
    bVar3 = bVar3 | 1;
  }
  return bVar3;
}


