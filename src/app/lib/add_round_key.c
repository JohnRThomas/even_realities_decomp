/*
 * Function: add_round_key
 * Entry:    00083692
 * Prototype: void __stdcall add_round_key(uint8_t * s, uint * k)
 */


/* exclude_from_export_ai */

void add_round_key(uint8_t *s,uint *k)

{
  *s = *(byte *)((int)k + 3) ^ *s;
  s[1] = (byte)*(undefined2 *)((int)k + 2) ^ s[1];
  s[2] = s[2] ^ (byte)(*k >> 8);
  s[3] = s[3] ^ (byte)*k;
  s[4] = *(byte *)((int)k + 7) ^ s[4];
  s[5] = (byte)*(undefined2 *)((int)k + 6) ^ s[5];
  s[6] = s[6] ^ (byte)(k[1] >> 8);
  s[7] = s[7] ^ (byte)k[1];
  s[8] = *(byte *)((int)k + 0xb) ^ s[8];
  s[9] = (byte)*(undefined2 *)((int)k + 10) ^ s[9];
  s[10] = s[10] ^ (byte)(k[2] >> 8);
  s[0xb] = s[0xb] ^ (byte)k[2];
  s[0xc] = *(byte *)((int)k + 0xf) ^ s[0xc];
  s[0xd] = (byte)*(undefined2 *)((int)k + 0xe) ^ s[0xd];
  s[0xe] = s[0xe] ^ (byte)(k[3] >> 8);
  s[0xf] = s[0xf] ^ (byte)k[3];
  return;
}


