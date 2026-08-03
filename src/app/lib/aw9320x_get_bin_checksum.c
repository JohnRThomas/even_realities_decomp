/*
 * Function: aw9320x_get_bin_checksum
 * Entry:    0008043e
 * Prototype: uint32_t __stdcall aw9320x_get_bin_checksum(uint8_t * w_bin_offset, uint32_t update_data_len, uint32_t check_len)
 */


/* exclude_from_export */

uint32_t aw9320x_get_bin_checksum(uint8_t *w_bin_offset,uint32_t update_data_len,uint32_t check_len)

{
  uint tmp;
  int index;
  uint i;
  int check_sum;
  
  index = 0;
  check_sum = 0;
  for (i = 0; i < check_len; i = i + 4) {
    if (i < update_data_len) {
      tmp = (uint)w_bin_offset[index + 3] | (uint)w_bin_offset[index] << 0x18 |
            (uint)w_bin_offset[index + 1] << 0x10 | (uint)w_bin_offset[index + 2] << 8;
      index = index + 4;
    }
    else {
      tmp = 0xffffffff;
    }
    check_sum = check_sum + tmp;
  }
  return -check_sum;
}


