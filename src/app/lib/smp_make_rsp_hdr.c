/*
 * Function: smp_make_rsp_hdr
 * Entry:    00083fae
 * Prototype: void __stdcall smp_make_rsp_hdr(smp_hdr * req_hdr, smp_hdr * rsp_hdr, size_t len)
 */


/* exclude_from_export_ai */

void smp_make_rsp_hdr(smp_hdr *req_hdr,smp_hdr *rsp_hdr,size_t len)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar1 = req_hdr->nh_op_ver_flags;
  uVar2 = req_hdr->nh_group;
  bVar3 = req_hdr->nh_seq;
  bVar4 = req_hdr->nh_id;
  if ((bVar1 & 7) == 0) {
    bVar5 = 1;
  }
  else {
    bVar5 = 3;
  }
  rsp_hdr->nh_op_ver_flags = 0;
  rsp_hdr->nh_flags = 0;
  rsp_hdr->nh_len = 0;
  rsp_hdr->nh_op_ver_flags =
       bVar5 | ((bVar1 & 0x1f) >> 3 != 0) << 3 | rsp_hdr->nh_op_ver_flags & 0xe0;
  rsp_hdr->nh_len = (ushort)((len & 0xff) << 8) | (ushort)(len >> 8) & 0xff;
  rsp_hdr->nh_group = uVar2 << 8 | uVar2 >> 8;
  rsp_hdr->nh_seq = bVar3;
  rsp_hdr->nh_id = bVar4;
  return;
}


