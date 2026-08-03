/*
 * Function: smp_process_packet
 * Entry:    00054694
 * Prototype: int __stdcall smp_process_packet(smp_streamer * streamer, net_buf * req)
 */


/* exclude_from_export_ai */

int smp_process_packet(smp_streamer *streamer,net_buf *req)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  net_buf *nb;
  undefined4 uVar5;
  undefined4 *puVar6;
  mgmt_handler *pmVar7;
  undefined *arg;
  undefined4 uVar8;
  smp_hdr *src_hdr;
  smp_hdr *src_hdr_00;
  uint8_t *puVar9;
  uint uVar10;
  int32_t input;
  code *pcVar11;
  net_buf *pnVar12;
  zcbor_state_t *state;
  int *piVar13;
  smp_hdr local_38;
  char *local_30;
  uint local_2c;
  
  do {
    uVar1 = (req->field6_0xc).field0.len;
    input = 0;
    if (uVar1 == 0) {
LAB_000546a6:
      smp_free_buf(req,streamer->smpt);
      nb = (net_buf *)0x0;
      arg = streamer->smpt;
LAB_000547b2:
      smp_free_buf(nb,arg);
      return (int)(int32_t *)input;
    }
    if (uVar1 < 8) {
      input = (int32_t)&DAT_00000009;
      goto LAB_000546a6;
    }
    puVar9 = (req->field6_0xc).field0.data;
    uVar5 = *(undefined4 *)puVar9;
    uVar8 = *(undefined4 *)(puVar9 + 4);
    local_38.nh_len = (word)((uint)uVar5 >> 0x10);
    uVar3 = local_38.nh_len << 8 | local_38.nh_len >> 8;
    local_38._0_2_ = SUB42(uVar5,0);
    local_38.nh_len = uVar3;
    local_38.nh_group = (word)uVar8;
    uVar1 = local_38.nh_group << 8 | local_38.nh_group >> 8;
    local_38._6_2_ = SUB42((uint)uVar8 >> 0x10,0);
    local_38.nh_group = uVar1;
    net_buf_simple_pull(&(req->field6_0xc).b);
    uVar5 = local_38._0_4_;
    if ((req->field6_0xc).field0.len < uVar3) {
      input = (int32_t)&DAT_00000009;
LAB_000548a4:
      pnVar12 = (net_buf *)0x0;
      nb = req;
LAB_0005475e:
      cbor_nb_writer_init((cbor_nb_writer *)streamer->writer,nb);
      piVar13 = (int *)streamer->writer;
      state = (zcbor_state_t *)(piVar13 + 1);
      bVar4 = zcbor_map_start_encode(state,2);
      if (bVar4) {
        local_30 = "rc";
        local_2c = 2;
        bVar4 = zcbor_tstr_encode(state,(zcbor_string *)&local_30);
        if ((!bVar4) || (bVar4 = zcbor_int32_encode(state,(int32_t *)input), !bVar4))
        goto LAB_000547a0;
        bVar4 = zcbor_map_end_encode(state,2);
        if (bVar4) {
          smp_make_rsp_hdr(&local_38,(smp_hdr *)&local_30,
                           (piVar13[1] - *(int *)(*piVar13 + 0xc)) - 8);
          *(short *)(*piVar13 + 0x10) = (short)piVar13[1] - (short)*(undefined4 *)(*piVar13 + 0xc);
          smp_write_hdr((smp_streamer *)streamer->writer,src_hdr_00);
          (**(code **)(streamer->smpt + 0x2c))(nb);
          nb = (net_buf *)0x0;
        }
      }
      else {
LAB_000547a0:
        zcbor_map_end_encode(state,2);
      }
      smp_free_buf(pnVar12,streamer->smpt);
      arg = streamer->smpt;
      goto LAB_000547b2;
    }
    uVar10 = local_38._0_4_ & 5;
    if ((local_38._0_4_ & 5) != 0) {
      input = (int32_t)&NMI;
      goto LAB_000548a4;
    }
    nb = smp_alloc_rsp(req,streamer->smpt);
    if (nb == (net_buf *)0x0) {
      input = (int32_t)&DAT_00000002;
      goto LAB_000548a4;
    }
    puVar6 = (undefined4 *)streamer->reader;
    *puVar6 = req;
    zcbor_new_state((zcbor_state_t *)(puVar6 + 1),4,(req->field6_0xc).field0.data,
                    (uint)(req->field6_0xc).field0.len,1);
    cbor_nb_writer_init((cbor_nb_writer *)streamer->writer,nb);
    piVar13 = (int *)streamer->writer;
    piVar13[0xd] = uVar10;
    pnVar12 = req;
    if (1 < (local_38._0_4_ & 0x1f) >> 3) {
      input = (int32_t)&DAT_0000000d;
      goto LAB_0005475e;
    }
    pmVar7 = mgmt_find_handler(uVar1,(ushort)local_38.nh_id);
    if (pmVar7 == (mgmt_handler *)0x0) {
LAB_00054856:
      input = (int32_t)&NMI;
      goto LAB_0005475e;
    }
    if ((local_38._0_4_ & 7) == 0) {
      pcVar11 = (code *)pmVar7->mh_read;
    }
    else {
      if ((local_38._0_4_ & 7) != 2) {
        input = 3;
        goto LAB_0005475e;
      }
      pcVar11 = (code *)pmVar7->mh_write;
    }
    if (pcVar11 == (code *)0x0) goto LAB_00054856;
    bVar4 = zcbor_map_start_encode((zcbor_state_t *)(streamer->writer + 4),0xf);
    if (!bVar4) {
      input = (int32_t)&DAT_00000007;
      goto LAB_0005475e;
    }
    input = (*pcVar11)(streamer);
    bVar4 = zcbor_map_end_encode((zcbor_state_t *)(streamer->writer + 4),0xf);
    if (!bVar4) {
      if ((int32_t *)input == (int32_t *)0x0) {
        input = (int32_t)&DAT_00000007;
      }
      goto LAB_0005475e;
    }
    if ((int32_t *)input != (int32_t *)0x0) goto LAB_0005475e;
    sVar2 = *(short *)((int)piVar13 + 0x36);
    if ((sVar2 != 0) && ((uVar5 & 0x18) == 0)) {
      pcVar11 = (code *)mgmt_find_error_translation_function(*(uint16_t *)(piVar13 + 0xd));
      if (pcVar11 == (code *)0x0) {
        input = (int32_t)&DAT_00000001;
      }
      else {
        input = (*pcVar11)(sVar2);
        if ((int32_t *)input == (int32_t *)0x0) goto LAB_00054840;
        if (nb == (net_buf *)0x0) goto LAB_000548a4;
      }
      goto LAB_0005475e;
    }
    smp_make_rsp_hdr(&local_38,(smp_hdr *)&local_30,(piVar13[1] - *(int *)(*piVar13 + 0xc)) - 8);
    *(short *)(*piVar13 + 0x10) = (short)piVar13[1] - (short)*(undefined4 *)(*piVar13 + 0xc);
    smp_write_hdr((smp_streamer *)streamer->writer,src_hdr);
LAB_00054840:
    input = (**(code **)(streamer->smpt + 0x2c))(nb);
    if ((int32_t *)input != (int32_t *)0x0) goto LAB_000548a4;
    net_buf_simple_pull(&(req->field6_0xc).b);
  } while( true );
}


