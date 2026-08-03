/*
 * Function: lc3_setup_encoder
 * Entry:    0006c23c
 * Prototype: lc3_encoder_t __stdcall lc3_setup_encoder(int dt_us, int sr_hz, int sr_pcm_hz, void * mem)
 */


/* exclude_from_export_ai */

lc3_encoder_t lc3_setup_encoder(int dt_us,int sr_hz,int sr_pcm_hz,void *mem)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *buf;
  uint uVar6;
  uint uVar7;
  
  if (sr_pcm_hz < 1) {
    sr_pcm_hz = sr_hz;
  }
  if (dt_us == 0x1d4c) {
    if (sr_hz == 8000) {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        iVar1 = 0;
        uVar2 = 3;
        iVar4 = 0;
        uVar6 = 0;
        uVar7 = 0;
      }
      else {
        if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x3e80) {
          uVar7 = 1;
        }
        else if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x5dc0) {
          uVar7 = 2;
        }
        else {
          if ((undefined1 *)sr_pcm_hz != &DAT_00007d00) {
            if ((undefined1 *)sr_pcm_hz != (undefined1 *)0xbb80) {
              return 0;
            }
            iVar4 = 0;
            iVar1 = 1;
            uVar2 = 3;
            uVar7 = 4;
            uVar6 = 0;
            goto LAB_0006c2ce;
          }
          uVar7 = 3;
        }
        iVar1 = 0;
        uVar2 = 3;
        iVar4 = 0;
        uVar6 = 0;
      }
      goto LAB_0006c2ce;
    }
    uVar2 = 3;
    iVar4 = 0;
  }
  else if (dt_us == 10000) {
    if (sr_hz == 8000) {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        iVar1 = 0;
        uVar2 = 4;
        iVar4 = 1;
        uVar6 = 0;
        uVar7 = 0;
      }
      else if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x3e80) {
        iVar1 = 0;
        iVar4 = 1;
        uVar2 = 4;
        uVar6 = 0;
        uVar7 = 1;
      }
      else {
        if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x5dc0) {
          uVar7 = 2;
        }
        else {
          if ((undefined1 *)sr_pcm_hz != &DAT_00007d00) {
            if ((undefined1 *)sr_pcm_hz != (undefined1 *)0xbb80) {
              return 0;
            }
            iVar1 = 1;
            uVar2 = 4;
            uVar6 = 0;
            iVar4 = iVar1;
            uVar7 = uVar2;
            goto LAB_0006c2ce;
          }
          uVar7 = 3;
        }
        iVar1 = 0;
        uVar2 = 4;
        iVar4 = 1;
        uVar6 = 0;
      }
      goto LAB_0006c2ce;
    }
    uVar2 = 4;
    iVar4 = 1;
  }
  else {
    if (sr_hz == 8000) {
      return 0;
    }
    uVar2 = 5;
    iVar4 = 2;
  }
  if (sr_hz == 16000) {
    if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
      return 0;
    }
    uVar7 = 1;
    uVar6 = 1;
    if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x3e80) goto LAB_0006c3ae;
LAB_0006c2a6:
    uVar6 = uVar7;
    if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x5dc0) {
      if (iVar4 == 2) {
        return 0;
      }
      iVar1 = 0;
      uVar7 = 2;
    }
    else if ((undefined1 *)sr_pcm_hz == &DAT_00007d00) {
      if (iVar4 == 2) {
        return 0;
      }
      iVar1 = 0;
      uVar7 = 3;
    }
    else {
      if ((undefined1 *)sr_pcm_hz != (undefined1 *)0xbb80) {
        return 0;
      }
      if (iVar4 == 2) {
        return 0;
      }
      iVar1 = 1;
      uVar7 = 4;
    }
  }
  else {
    if (sr_hz == 24000) {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        return 0;
      }
      uVar6 = 2;
    }
    else if ((undefined1 *)sr_hz == &DAT_00007d00) {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        return 0;
      }
      uVar6 = 3;
    }
    else if (sr_hz == 48000) {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        return 0;
      }
      uVar6 = 4;
    }
    else {
      if ((undefined1 *)sr_pcm_hz == (undefined1 *)0x1f40) {
        return 0;
      }
      uVar6 = 5;
    }
    uVar7 = uVar6;
    if ((undefined1 *)sr_pcm_hz != (undefined1 *)0x3e80) goto LAB_0006c2a6;
LAB_0006c3ae:
    if (iVar4 == 2) {
      return 0;
    }
    iVar1 = 0;
    uVar7 = 1;
  }
  if (uVar7 < uVar6) {
    return 0;
  }
LAB_0006c2ce:
  if (mem == (void *)0x0) {
    return 0;
  }
  iVar5 = uVar6 + 1;
  if (uVar6 == 4) {
    iVar5 = 6;
  }
  iVar3 = (iVar1 + uVar7) * uVar2 + uVar2;
  memset(mem,0,0x4b0);
  iVar1 = iVar5 * 10 + iVar3 * 0x14 >> 1;
  *(char *)mem = (char)iVar4;
  buf = (void *)((int)mem + 0x4ac);
  *(void **)((int)mem + 0x4a8) = (void *)((int)buf + (iVar3 * 0x14 + iVar1) * 4);
  *(void **)((int)mem + 0x4a4) = (void *)((int)buf + iVar1 * 4);
  iVar4 = (dt_us * sr_pcm_hz) / 1000000;
  *(char *)((int)mem + 1) = (char)uVar6;
  *(char *)((int)mem + 2) = (char)uVar7;
  *(void **)((int)mem + 0x4a0) = (void *)((int)buf + iVar5 * 0x14);
  if (dt_us == 0x1d4c) {
    iVar1 = (iVar4 * 0x17) / 0x1e;
  }
  else {
    iVar1 = iVar4 * 5;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar1 = iVar1 >> 3;
  }
  memset(buf,0,(iVar4 + (sr_pcm_hz / 800 + iVar4) / 2 + iVar1) * 4);
  return (lc3_encoder_t)mem;
}


