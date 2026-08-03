/*
 * Function: linear_range_group_get_win_index
 * Entry:    00087f24
 * Prototype: int __stdcall linear_range_group_get_win_index(linear_range * r, size_t r_cnt, int32_t val_min, int32_t val_max, uint16_t * idx)
 */


/* exclude_from_export */

int linear_range_group_get_win_index
              (linear_range *r,size_t r_cnt,int32_t val_min,int32_t val_max,uint16_t *idx)

{
  int iVar1;
  
  if ((int)(r->step * ((uint)r->max_idx - (uint)r->min_idx) + r->min) < (int)r_cnt) {
    if ((int)(r[1].step * ((uint)r[1].max_idx - (uint)r[1].min_idx) + r[1].min) < (int)r_cnt) {
      return -0x16;
    }
    r = r + 1;
  }
  iVar1 = linear_range_get_win_index(r,r_cnt,val_min,(uint16_t *)val_max);
  return iVar1;
}


