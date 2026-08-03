/*
 * Function: img_mgmt_state_read
 * Entry:    00054f44
 * Prototype: int __stdcall img_mgmt_state_read(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int img_mgmt_state_read(smp_streamer *ctxt)

{
  bool bVar1;
  uint slot;
  uint uVar2;
  int extraout_r0;
  uint extraout_r0_00;
  int extraout_r0_01;
  int iVar3;
  uint in_r1;
  zcbor_state_t *state;
  int image;
  uint uStack_24;
  
  state = (zcbor_state_t *)(ctxt->writer + 4);
  uStack_24 = in_r1;
  bVar1 = zcbor_tstr_encode_ptr(state,"images",6);
  uVar2 = 0;
  if (bVar1) {
    bVar1 = zcbor_list_start_encode(state,4);
    uVar2 = (uint)bVar1;
  }
  image = 0;
  img_mgmt_take_lock();
  do {
    if (uVar2 == 0) {
LAB_00054f8a:
      img_mgmt_release_lock();
      return 7;
    }
    if (image == 2) {
      bVar1 = zcbor_list_end_encode(state,4);
      if (((bVar1) && (bVar1 = zcbor_tstr_encode_ptr(state,"splitStatus",0xb), bVar1)) &&
         (bVar1 = zcbor_int32_encode(state,(int32_t *)0x0), bVar1)) {
        img_mgmt_release_lock();
        return 0;
      }
      goto LAB_00054f8a;
    }
    uStack_24 = uStack_24 & 0xffffff;
    img_mgmt_get_next_boot_slot(image,(img_mgmt_next_boot_type *)((int)&uStack_24 + 3));
    slot = img_mgmt_active_slot(image);
    uVar2 = slot;
    if (3 < slot) {
      uVar2 = img_mgmt_get_opposite_slot(slot);
    }
    uVar2 = uVar2 ^ 1;
    if ((int)slot < (int)uVar2) {
      bs_list((char *)state,slot);
      iVar3 = extraout_r0;
    }
    else {
      bs_list((char *)state,uVar2);
      uVar2 = slot;
      iVar3 = extraout_r0_01;
    }
    if (iVar3 == 0) goto LAB_00054f8a;
    bs_list((char *)state,uVar2);
    image = image + 1;
    uVar2 = extraout_r0_00;
  } while( true );
}


