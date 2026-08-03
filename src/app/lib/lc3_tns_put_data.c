/*
 * Function: lc3_tns_put_data
 * Entry:    00073de0
 * Prototype: void __stdcall lc3_tns_put_data(lc3_bits_t * bits, lc3_tns_data_t * data)
 */


/* exclude_from_export_ai */

void lc3_tns_put_data(lc3_bits_t *bits,lc3_tns_data_t *data)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  lc3_bits_t lVar5;
  uint uVar6;
  int iVar7;
  lc3_tns_data_t *plVar8;
  int iVar9;
  lc3_tns_data_t *plVar10;
  
  if (0 < *(int *)data->opaque) {
    iVar9 = 0;
    plVar10 = data + 1;
    plVar8 = data;
    do {
      plVar10 = plVar10 + 1;
      iVar7 = *(int *)plVar10->opaque;
      uVar3 = bits[8];
      lVar5 = uVar3 + 1;
      if ((int)lVar5 < 0x21) {
        bits[8] = lVar5;
        bits[7] = bits[7] | (uint)(0 < iVar7) << (uVar3 & 0xff);
      }
      else {
        lc3_put_bits_generic(bits,(uint)(0 < iVar7),1);
      }
      if (0 < iVar7) {
        bVar1 = data[1].opaque[0];
        uVar6 = (bits[2] >> 10) *
                (uint)*(ushort *)(&UNK_00093c30 + (iVar7 + -1) * 4 + (uint)bVar1 * 0x44) + bits[1];
        bits[1] = uVar6;
        uVar3 = (uint)*(ushort *)(&UNK_00093c30 + (iVar7 + -1) * 4 + (uint)bVar1 * 0x44 + 2) *
                (bits[2] >> 10);
        uVar4 = bits[4] | uVar6 >> 0x18;
        lVar5 = uVar6 & 0xffffff;
        bits[2] = uVar3;
        bits[4] = uVar4;
        bits[1] = lVar5;
        if (uVar3 < 0x10000) {
          lc3_ac_write_renorm(bits);
          lVar5 = bits[1];
          uVar3 = bits[2];
          uVar4 = bits[4];
        }
        iVar2 = *(int *)plVar8[4].opaque + 8;
        uVar6 = (uVar3 >> 10) * (uint)*(ushort *)(&DAT_000939f0 + iVar2 * 4) + lVar5;
        bits[1] = uVar6;
        uVar3 = (uVar3 >> 10) * (uint)*(ushort *)(&DAT_000939f2 + iVar2 * 4);
        bits[1] = uVar6 & 0xffffff;
        bits[2] = uVar3;
        bits[4] = uVar4 | uVar6 >> 0x18;
        if (uVar3 < 0x10000) {
          lc3_ac_write_renorm(bits);
        }
        if (iVar7 != 1) {
          iVar2 = *(int *)plVar8[5].opaque + 8;
          uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093a34 + iVar2 * 4) + bits[1];
          bits[1] = uVar4;
          uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093a36 + iVar2 * 4);
          bits[2] = uVar3;
          bits[4] = bits[4] | uVar4 >> 0x18;
          bits[1] = uVar4 & 0xffffff;
          if (uVar3 < 0x10000) {
            lc3_ac_write_renorm(bits);
          }
          if (iVar7 != 2) {
            iVar2 = *(int *)plVar8[6].opaque + 8;
            uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093a78 + iVar2 * 4) + bits[1];
            bits[1] = uVar4;
            uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093a7a + iVar2 * 4);
            bits[2] = uVar3;
            bits[4] = bits[4] | uVar4 >> 0x18;
            bits[1] = uVar4 & 0xffffff;
            if (uVar3 < 0x10000) {
              lc3_ac_write_renorm(bits);
            }
            if (iVar7 != 3) {
              iVar2 = *(int *)plVar8[7].opaque + 8;
              uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093abc + iVar2 * 4) + bits[1];
              bits[1] = uVar4;
              uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093abe + iVar2 * 4);
              bits[2] = uVar3;
              bits[4] = bits[4] | uVar4 >> 0x18;
              bits[1] = uVar4 & 0xffffff;
              if (uVar3 < 0x10000) {
                lc3_ac_write_renorm(bits);
              }
              if (iVar7 != 4) {
                iVar2 = *(int *)plVar8[8].opaque + 8;
                uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b00 + iVar2 * 4) + bits[1];
                bits[1] = uVar4;
                uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b02 + iVar2 * 4);
                bits[2] = uVar3;
                bits[4] = bits[4] | uVar4 >> 0x18;
                bits[1] = uVar4 & 0xffffff;
                if (uVar3 < 0x10000) {
                  lc3_ac_write_renorm(bits);
                }
                if (iVar7 != 5) {
                  iVar2 = *(int *)plVar8[9].opaque + 8;
                  uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b44 + iVar2 * 4) + bits[1];
                  bits[1] = uVar4;
                  uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b46 + iVar2 * 4);
                  bits[2] = uVar3;
                  bits[4] = bits[4] | uVar4 >> 0x18;
                  bits[1] = uVar4 & 0xffffff;
                  if (uVar3 < 0x10000) {
                    lc3_ac_write_renorm(bits);
                  }
                  if (iVar7 != 6) {
                    iVar2 = *(int *)plVar8[10].opaque + 8;
                    uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b88 + iVar2 * 4) + bits[1]
                    ;
                    bits[1] = uVar4;
                    uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093b8a + iVar2 * 4);
                    bits[2] = uVar3;
                    bits[4] = bits[4] | uVar4 >> 0x18;
                    bits[1] = uVar4 & 0xffffff;
                    if (uVar3 < 0x10000) {
                      lc3_ac_write_renorm(bits);
                    }
                    if (iVar7 != 7) {
                      iVar7 = *(int *)plVar8[0xb].opaque + 8;
                      uVar4 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093bcc + iVar7 * 4) +
                              bits[1];
                      bits[1] = uVar4;
                      uVar3 = (bits[2] >> 10) * (uint)*(ushort *)(&DAT_00093bce + iVar7 * 4);
                      bits[2] = uVar3;
                      bits[4] = bits[4] | uVar4 >> 0x18;
                      bits[1] = uVar4 & 0xffffff;
                      if (uVar3 < 0x10000) {
                        lc3_ac_write_renorm(bits);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      iVar9 = iVar9 + 1;
      plVar8 = plVar8 + 8;
    } while (iVar9 < *(int *)data->opaque);
  }
  return;
}


