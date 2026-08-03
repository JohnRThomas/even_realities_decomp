/*
 * Function: lc3_encoder_size
 * Entry:    0006c174
 * Prototype: uint __stdcall lc3_encoder_size(int dt_us, int sr_hz)
 */


/* exclude_from_export_ai */

uint lc3_encoder_size(int dt_us,int sr_hz)

{
  int iVar1;
  int iVar2;
  
  if (dt_us == 0x1d4c) {
    if (sr_hz == 8000) {
      iVar2 = 0x5f;
      iVar1 = 0x3c;
    }
    else {
      if (sr_hz != 16000) goto LAB_0006c19a;
      iVar2 = 0xbe;
      iVar1 = 0x78;
    }
LAB_0006c206:
    iVar1 = (iVar1 * 0x17) / 0x1e;
  }
  else {
    if (dt_us != 10000) {
      return 0;
    }
    if (sr_hz == 8000) {
      iVar2 = 0x7d;
      iVar1 = 0x50;
    }
    else if (sr_hz == 16000) {
      iVar2 = 0xfa;
      iVar1 = 0xa0;
    }
    else {
LAB_0006c19a:
      if (((sr_hz != 24000) && ((undefined1 *)sr_hz != &DAT_00007d00)) && (sr_hz != 48000)) {
        return 0;
      }
      iVar1 = (sr_hz * dt_us) / 1000000;
      iVar2 = iVar1 + (sr_hz / 800 + iVar1) / 2;
      if (dt_us == 0x1d4c) goto LAB_0006c206;
    }
    iVar1 = iVar1 * 5;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar1 = iVar1 >> 3;
  }
  return (iVar1 + iVar2 + 300) * 4;
}


