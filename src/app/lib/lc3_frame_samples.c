/*
 * Function: lc3_frame_samples
 * Entry:    0006c0e8
 * Prototype: int __stdcall lc3_frame_samples(int dt_us, int sr_hz)
 */


/* exclude_from_export_ai */

int lc3_frame_samples(int dt_us,int sr_hz)

{
  int iVar1;
  
  if (dt_us == 0x1d4c) {
    if (sr_hz == 8000) {
      return 0x3c;
    }
    if (sr_hz == 16000) {
      return 0x78;
    }
    if (sr_hz == 24000) {
      return 0xb4;
    }
    if ((undefined1 *)sr_hz != &DAT_00007d00) {
      if (sr_hz == 48000) {
        iVar1 = 0x168;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  else {
    if (dt_us != 10000) {
      return -1;
    }
    if (sr_hz == 8000) {
      return 0x50;
    }
    if (sr_hz == 16000) {
      return 0xa0;
    }
    if (sr_hz != 24000) {
      if ((undefined1 *)sr_hz == &DAT_00007d00) {
        return 0x140;
      }
      if (sr_hz == 48000) {
        iVar1 = 0x1e0;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  return 0xf0;
}


