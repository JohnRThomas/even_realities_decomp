/*
 * Function: aw9320x_check_sum
 * Entry:    0003176c
 * Prototype: int32_t __stdcall aw9320x_check_sum(uint8_t * para_data, uint32_t arr_len)
 */


/* exclude_from_export aw9320x.c */

int32_t aw9320x_check_sum(uint8_t *para_data,uint32_t arr_len)

{
  byte *pbVar1;
  int32_t iVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar3 = (undefined *)0x0;
  iVar4 = 4;
  do {
    pbVar1 = fw_para_data + iVar4;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + *pbVar1;
  } while (iVar4 != 0x1be4);
  iVar2 = 0;
  if (puVar3 != &UNK_0009244d) {
    iVar2 = -1;
  }
  return iVar2;
}


