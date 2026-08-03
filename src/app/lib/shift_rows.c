/*
 * Function: shift_rows
 * Entry:    0008371c
 * Prototype: void __stdcall shift_rows(uint8_t * s)
 */


/* exclude_from_export_ai */

void shift_rows(uint8_t *s)

{
  uint8_t local_18;
  uint8_t local_17;
  uint8_t local_16;
  uint8_t local_15;
  uint8_t local_14;
  uint8_t local_13;
  uint8_t local_12;
  uint8_t local_11;
  uint8_t local_10;
  uint8_t local_f;
  uint8_t local_e;
  uint8_t local_d;
  uint8_t local_c;
  uint8_t local_b;
  uint8_t local_a;
  uint8_t local_9;
  
  _local_18 = CONCAT13(s[0xf],CONCAT12(s[10],CONCAT11(s[5],*s)));
  _local_14 = CONCAT13(s[3],CONCAT12(s[0xe],CONCAT11(s[9],s[4])));
  _local_10 = CONCAT13(s[7],CONCAT12(s[2],CONCAT11(s[0xd],s[8])));
  _local_c = CONCAT13(s[0xb],CONCAT12(s[6],CONCAT11(s[1],s[0xc])));
  _copy(s,0x10,&local_18,0x10);
  return;
}


