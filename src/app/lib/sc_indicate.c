/*
 * Function: sc_indicate
 * Entry:    0005d81c
 * Prototype: void __stdcall sc_indicate(uint16_t start, uint16_t end)
 */


/* exclude_from_export */

void sc_indicate(uint16_t start,uint16_t end)

{
  ushort uVar1;
  uint extraout_r0;
  gatt_sc *iVar3;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  uint bit;
  k_timeout_t timeout;
  
  atomic_set_bit((atomic_t *)&DAT_20006628,1);
  bit = extraout_r1;
  uVar1 = start;
  if ((extraout_r0 & 1) != 0) {
    bit = (uint)DAT_200065f0;
    if (start < bit) {
      DAT_200065f0 = start;
      uVar1 = start;
      if (end <= DAT_200065f2) goto LAB_0005d836;
    }
    else {
      uVar1 = DAT_200065f0;
      if (end <= DAT_200065f2) {
        return;
      }
    }
  }
  DAT_200065f0 = uVar1;
  DAT_200065f2 = end;
LAB_0005d836:
  iVar3._0_1_ = atomic_test_bit((atomic_t *)&DAT_20006628,bit);
  iVar3 = (gatt_sc *)(uint)iVar3._0_1_;
  timeout.ticks._4_4_ = extraout_r1_00;
  timeout.ticks._0_4_ = iVar3;
  sc_work_submit(timeout);
  return;
}


