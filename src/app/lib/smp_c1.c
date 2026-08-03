/*
 * Function: smp_c1
 * Entry:    000869f2
 * Prototype: int __stdcall smp_c1(uint8_t * k, uint8_t * r, uint8_t * preq, uint8_t * pres, bt_addr_le_t * ia, bt_addr_le_t * ra, uint8_t * enc_data)
 */


/* exclude_from_export_ai */

int smp_c1(uint8_t *k,uint8_t *r,uint8_t *preq,uint8_t *pres,bt_addr_le_t *ia,bt_addr_le_t *ra,
          uint8_t *enc_data)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar5;
  byte local_38;
  uint8_t local_37;
  undefined4 local_36;
  undefined2 local_32;
  uint8_t local_30;
  undefined4 local_2f;
  undefined2 local_2b;
  uint8_t local_29;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_22;
  undefined2 local_1e;
  int local_1c;
  byte *pbVar4;
  
  local_38 = ia->type;
  local_37 = ra->type;
  local_36 = *(undefined4 *)preq;
  local_32 = *(undefined2 *)(preq + 4);
  local_30 = preq[6];
  local_2f = *(undefined4 *)pres;
  local_2b = *(undefined2 *)(pres + 4);
  local_29 = pres[6];
  pbVar1 = &local_38;
  pbVar4 = r;
  pbVar5 = enc_data;
  do {
    pbVar3 = pbVar4 + 1;
    *pbVar5 = *pbVar4 ^ *pbVar1;
    pbVar1 = pbVar1 + 1;
    pbVar4 = pbVar3;
    pbVar5 = pbVar5 + 1;
  } while (pbVar3 != r + 0x10);
  local_1c = internal_encrypt_le(k,enc_data,enc_data);
  if (local_1c == 0) {
    local_24 = *(undefined2 *)((ra->a).val + 4);
    local_28 = *(undefined4 *)(ra->a).val;
    local_22 = *(undefined4 *)(ia->a).val;
    local_1e = *(undefined2 *)((ia->a).val + 4);
    pbVar1 = (byte *)&local_28;
    pbVar4 = enc_data;
    do {
      pbVar5 = pbVar4 + 1;
      *pbVar4 = *pbVar4 ^ *pbVar1;
      pbVar1 = pbVar1 + 1;
      pbVar4 = pbVar5;
    } while (pbVar5 != enc_data + 0x10);
    iVar2 = internal_encrypt_le(k,enc_data,enc_data);
    return iVar2;
  }
  return local_1c;
}


