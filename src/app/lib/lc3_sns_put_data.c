/*
 * Function: lc3_sns_put_data
 * Entry:    00072284
 * Prototype: void __stdcall lc3_sns_put_data(lc3_bits_t * bits, lc3_sns_data_t * data)
 */


/* exclude_from_export_ai */

void lc3_sns_put_data(lc3_bits_t *bits,lc3_sns_data_t *data)

{
  byte bVar1;
  uint uVar2;
  uint v;
  lc3_bits_t lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  lc3_bits_t lVar8;
  
  uVar6 = bits[8];
  uVar4 = uVar6 + 5;
  uVar2 = *(uint *)data->opaque;
  if ((int)uVar4 < 0x21) {
    bits[8] = uVar4;
    bits[7] = bits[7] | uVar2 << (uVar6 & 0xff);
    uVar6 = uVar6 + 10;
    uVar2 = *(uint *)data[1].opaque;
    if ((int)uVar6 < 0x21) goto LAB_000722a6;
LAB_0007239a:
    lc3_put_bits_generic(bits,uVar2,5);
    uVar6 = bits[8];
    uVar4 = uVar6 + 1;
    uVar2 = *(int *)data[2].opaque >> 1;
    if (0x20 < (int)uVar4) goto LAB_000723b0;
LAB_000722bc:
    bits[8] = uVar4;
    bits[7] = bits[7] | uVar2 << (uVar6 & 0xff);
  }
  else {
    lc3_put_bits_generic(bits,uVar2,5);
    uVar4 = bits[8];
    uVar2 = *(uint *)data[1].opaque;
    uVar6 = uVar4 + 5;
    if (0x20 < (int)uVar6) goto LAB_0007239a;
LAB_000722a6:
    bits[8] = uVar6;
    bits[7] = bits[7] | uVar2 << (uVar4 & 0xff);
    uVar4 = uVar6 + 1;
    uVar2 = *(int *)data[2].opaque >> 1;
    if ((int)uVar4 < 0x21) goto LAB_000722bc;
LAB_000723b0:
    lc3_put_bits_generic(bits,uVar2,1);
    uVar4 = bits[8];
  }
  uVar6 = *(uint *)data[4].opaque;
  uVar7 = *(uint *)data[3].opaque;
  uVar5 = *(uint *)data[2].opaque & 1;
  v = (int)uVar7 >> uVar5;
  if (uVar2 == 0) {
    if (uVar5 == 0) {
      uVar7 = (uint)data[6].opaque[1] + (*(int *)data[5].opaque + 1) * 2;
    }
    else {
      uVar7 = uVar7 & 1;
    }
    uVar2 = uVar4 + 1;
    uVar6 = uVar7 * 0x2477f4 + uVar6;
    if ((int)uVar2 < 0x21) {
      bits[8] = uVar2;
      bits[7] = bits[7] | v << (uVar4 & 0xff);
    }
    else {
      lc3_put_bits_generic(bits,v,1);
      uVar2 = bits[8];
    }
    lVar8 = uVar2 + 1;
    bVar1 = data[6].opaque[0];
    if ((int)lVar8 < 0x21) {
      bits[8] = lVar8;
      bits[7] = bits[7] | (uint)bVar1 << (uVar2 & 0xff);
    }
    else {
      lc3_put_bits_generic(bits,(uint)bVar1,1);
      lVar8 = bits[8];
    }
    lVar3 = lVar8 + 0x19;
    if (0x20 < (int)lVar3) {
      lc3_put_bits_generic(bits,uVar6,0x19);
      return;
    }
    goto LAB_00072354;
  }
  if (uVar5 == 0) {
    if ((int)(uVar4 + 2) < 0x21) goto LAB_0007232e;
LAB_000723be:
    lc3_put_bits_generic(bits,v,2);
    uVar2 = bits[8];
    bVar1 = data[6].opaque[0];
    lVar8 = uVar2 + 1;
  }
  else {
    uVar6 = (uVar7 & 1) + (uVar6 + 0x73a600) * 2;
    if (0x20 < (int)(uVar4 + 2)) goto LAB_000723be;
LAB_0007232e:
    uVar2 = uVar4 + 2;
    bits[8] = uVar2;
    lVar8 = uVar4 + 3;
    bits[7] = bits[7] | v << (uVar4 & 0xff);
    bVar1 = data[6].opaque[0];
  }
  if ((int)lVar8 < 0x21) {
    bits[8] = lVar8;
    bits[7] = bits[7] | (uint)bVar1 << (uVar2 & 0xff);
  }
  else {
    lc3_put_bits_generic(bits,(uint)bVar1,1);
    lVar8 = bits[8];
  }
  lVar3 = lVar8 + 0x18;
  if (0x20 < (int)lVar3) {
    lc3_put_bits_generic(bits,uVar6,0x18);
    return;
  }
LAB_00072354:
  bits[7] = bits[7] | uVar6 << (lVar8 & 0xff);
  bits[8] = lVar3;
  return;
}


