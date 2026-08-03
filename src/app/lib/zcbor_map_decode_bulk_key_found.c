/*
 * Function: zcbor_map_decode_bulk_key_found
 * Entry:    000840d8
 * Prototype: bool __stdcall zcbor_map_decode_bulk_key_found(zcbor_map_decode_key_val * map, size_t map_size, char * key)
 */


/* exclude_from_export_ai */

bool zcbor_map_decode_bulk_key_found(zcbor_map_decode_key_val *map,size_t map_size,char *key)

{
  size_t n;
  int iVar1;
  zcbor_map_decode_key_val *pzVar2;
  zcbor_map_decode_key_val *pzVar3;
  
  pzVar3 = map + map_size * 5;
  for (pzVar2 = map; pzVar2 < pzVar3; pzVar2 = pzVar2 + 5) {
    if ((char *)*pzVar2 == key) {
      return (bool)(char)pzVar2[4];
    }
  }
  n = strlen(key);
  while( true ) {
    if (pzVar3 <= map) {
      return false;
    }
    if ((map[1] == n) && (iVar1 = memcmp(key,(void *)*map,n), iVar1 == 0)) break;
    map = map + 5;
  }
  return (bool)(char)map[4];
}


