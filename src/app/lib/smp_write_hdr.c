/*
 * Function: smp_write_hdr
 * Entry:    0008401c
 * Prototype: int __stdcall smp_write_hdr(smp_streamer * streamer, smp_hdr * src_hdr)
 */


/* exclude_from_export_ai */

int smp_write_hdr(smp_streamer *streamer,smp_hdr *src_hdr)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(streamer->smpt + 0xc);
  *puVar1 = *(undefined4 *)src_hdr;
  puVar1[1] = *(undefined4 *)&src_hdr->nh_group;
  return (int)streamer;
}


