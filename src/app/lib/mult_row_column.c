/*
 * Function: mult_row_column
 * Entry:    0008378e
 * Prototype: void __stdcall mult_row_column(uint8_t * out, uint8_t * in)
 */


/* exclude_from_export_ai */

void mult_row_column(uint8_t *out,uint8_t *in)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar1 = _double_byte(*in);
  bVar2 = _double_byte(in[1]);
  *out = bVar2 ^ bVar1 ^ in[1] ^ in[2] ^ in[3];
  bVar1 = *in;
  bVar2 = _double_byte(in[1]);
  bVar3 = _double_byte(in[2]);
  out[1] = bVar3 ^ bVar2 ^ bVar1 ^ in[2] ^ in[3];
  bVar1 = in[1];
  bVar2 = *in;
  bVar3 = _double_byte(in[2]);
  bVar4 = _double_byte(in[3]);
  out[2] = bVar4 ^ bVar3 ^ bVar2 ^ bVar1 ^ in[3];
  bVar4 = _double_byte(*in);
  bVar1 = in[1];
  bVar2 = *in;
  bVar3 = in[2];
  bVar5 = _double_byte(in[3]);
  out[3] = bVar4 ^ bVar2 ^ bVar1 ^ bVar3 ^ bVar5;
  return;
}


