/*
 * Function: linear_range_get_win_index
 * Entry:    00087db2
 * Prototype: int __stdcall linear_range_get_win_index(linear_range * r, int32_t val_min, int32_t val_max, uint16_t * idx)
 */


/* exclude_from_export */

int linear_range_get_win_index(linear_range *r,int32_t val_min,int32_t val_max,uint16_t *idx)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  
  uVar1 = r->min_idx;
  iVar4 = r->min;
  uVar3 = r->step;
  iVar2 = uVar3 * ((uint)r->max_idx - (uint)uVar1) + iVar4;
  if ((val_max < iVar4) || (iVar2 < val_min)) {
LAB_00087dce:
    iVar2 = -0x16;
  }
  else {
    uVar5 = uVar1;
    if ((val_min < iVar4) || (uVar5 = r->max_idx, iVar2 < val_max)) {
      *idx = uVar5;
      return -0x22;
    }
    if (uVar3 == 0) {
      *idx = uVar1;
    }
    else {
      uVar3 = (uint)uVar1 + ((val_min - iVar4) + (uVar3 - 1)) / uVar3;
      *idx = (uint16_t)uVar3;
      if ((uint)val_max < r->step * ((uVar3 & 0xffff) - (uint)r->min_idx) + r->min)
      goto LAB_00087dce;
    }
    iVar2 = 0;
  }
  return iVar2;
}


