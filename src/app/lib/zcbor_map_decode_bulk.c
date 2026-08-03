/*
 * Function: zcbor_map_decode_bulk
 * Entry:    0008402a
 * Prototype: int __stdcall zcbor_map_decode_bulk(zcbor_state_t * zsd, zcbor_map_decode_key_val * map, size_t map_size, size_t * matched)
 */


/* exclude_from_export */

int zcbor_map_decode_bulk
              (zcbor_state_t *zsd,zcbor_map_decode_key_val *map,size_t map_size,size_t *matched)

{
  undefined *m1;
  uint n;
  bool bVar1;
  int iVar2;
  zcbor_map_decode_key_val *pzVar3;
  size_t sVar4;
  zcbor_string local_30;
  
  bVar1 = zcbor_map_start_decode(zsd);
  if (bVar1) {
    *matched = 0;
    pzVar3 = map;
LAB_0008405a:
    do {
      bVar1 = zcbor_tstr_decode(zsd,&local_30);
      n = local_30.len;
      m1 = local_30.value;
      if (!bVar1) break;
      for (sVar4 = 0; map_size != sVar4; sVar4 = sVar4 + 1) {
        if (map + map_size * 5 <= pzVar3) {
          pzVar3 = map;
        }
        if ((n == pzVar3[1]) && (iVar2 = memcmp(m1,(void *)*pzVar3,n), iVar2 == 0)) {
          if ((char)pzVar3[4] != '\0') {
            return -0x70;
          }
          iVar2 = (*(code *)pzVar3[2])(zsd,pzVar3[3]);
          if (iVar2 == 0) {
            return -0x23;
          }
          *(undefined1 *)(pzVar3 + 4) = 1;
          pzVar3 = pzVar3 + 5;
          *matched = *matched + 1;
          goto LAB_0008405a;
        }
        pzVar3 = pzVar3 + 5;
      }
      bVar1 = zcbor_any_skip(zsd,(void *)0x0);
    } while (bVar1);
    bVar1 = list_map_end_decode(zsd);
    if (bVar1) {
      return 0;
    }
  }
  return -0x4d;
}


