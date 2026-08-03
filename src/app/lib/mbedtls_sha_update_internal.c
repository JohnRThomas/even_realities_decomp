/*
 * Function: mbedtls_sha_update_internal
 * Entry:    0007dfe4
 * Prototype: int __stdcall mbedtls_sha_update_internal(void * ctx, uchar * input, size_t ilen)
 */


/* exclude_from_export */

int mbedtls_sha_update_internal(void *ctx,uchar *input,size_t ilen)

{
  uint uVar1;
  drvError_t dVar2;
  size_t sVar3;
  size_t sVar4;
  uint n;
  uchar *pDataIn;
  CCBuffInfo_t apuStack_b0 [2];
  uint8_t auStack_a8 [132];
  
  if (ctx == (void *)0x0) {
    return 1;
  }
  if (ilen != 0) {
    if (input == (uchar *)0x0) {
      return 1;
    }
    uVar1 = *(uint *)((int)ctx + 0x60);
    if (0xffff < ilen) {
LAB_0007e00e:
      do {
        sVar4 = *(uint *)((int)ctx + 0x5c);
        sVar3 = (sVar4 - uVar1) - sVar4 * ((sVar4 - uVar1) / sVar4);
        if (sVar3 == 0) {
          sVar3 = 0xffff;
          pDataIn = input;
          if (sVar4 == uVar1) {
LAB_0007e10e:
            if (0x7f < sVar4) {
              sVar4 = 0x80;
            }
            memmove(auStack_a8,(void *)((int)ctx + 100),sVar4);
            dVar2 = SetDataBuffersInfo(auStack_a8,*(size_t *)((int)ctx + 0x5c),apuStack_b0,
                                       (uint8_t *)0x0,0,(CCBuffInfo_t *)0x0);
            if (dVar2 != 0) {
              return 1;
            }
            dVar2 = ProcessHashDrv(ctx,apuStack_b0,*(uint32_t *)((int)ctx + 0x5c));
            if (dVar2 != 0) {
              return 1;
            }
            sVar4 = *(uint *)((int)ctx + 0x5c);
            *(undefined4 *)((int)ctx + 0x60) = 0;
            uVar1 = 0;
          }
        }
        else {
          if (0xfffe < sVar3) {
            sVar3 = 0xffff;
          }
          memmove((void *)(uVar1 + (int)ctx + 100),input,sVar3);
          sVar4 = *(uint *)((int)ctx + 0x5c);
          uVar1 = *(int *)((int)ctx + 0x60) + sVar3;
          pDataIn = input + sVar3;
          *(uint *)((int)ctx + 0x60) = uVar1;
          sVar3 = 0xffff - sVar3;
          if (sVar4 == uVar1) goto LAB_0007e10e;
        }
        sVar4 = sVar4 * (sVar3 / sVar4);
        if (sVar4 != 0) {
          dVar2 = SetDataBuffersInfo(pDataIn,sVar4,apuStack_b0,(uint8_t *)0x0,0,(CCBuffInfo_t *)0x0)
          ;
          if (dVar2 != 0) {
            return 1;
          }
          dVar2 = ProcessHashDrv(ctx,apuStack_b0,sVar4);
          if (dVar2 != 0) {
            return 1;
          }
          sVar3 = sVar3 - sVar4;
          uVar1 = *(uint *)((int)ctx + 0x60);
          pDataIn = pDataIn + sVar4;
          if (sVar3 != 0) goto LAB_0007e0c6;
LAB_0007e03a:
          ilen = ilen - 0xffff;
          input = input + 0xffff;
          if (ilen < 0x10000) break;
          goto LAB_0007e00e;
        }
        if (sVar3 == 0) goto LAB_0007e03a;
LAB_0007e0c6:
        memmove((void *)((int)ctx + (uVar1 + 0x19) * 4),pDataIn,sVar3);
        ilen = ilen - 0xffff;
        uVar1 = *(int *)((int)ctx + 0x60) + sVar3;
        input = input + 0xffff;
        *(uint *)((int)ctx + 0x60) = uVar1;
      } while (0xffff < ilen);
    }
    sVar3 = *(uint *)((int)ctx + 0x5c);
    n = (sVar3 - uVar1) - sVar3 * ((sVar3 - uVar1) / sVar3);
    if (ilen <= n) {
      n = ilen;
    }
    if (n != 0) {
      memmove((void *)((int)ctx + uVar1 + 100),input,n);
      sVar3 = *(uint *)((int)ctx + 0x5c);
      uVar1 = *(int *)((int)ctx + 0x60) + n;
      ilen = ilen - n;
      input = input + n;
      *(uint *)((int)ctx + 0x60) = uVar1;
    }
    if (sVar3 == uVar1) {
      if (0x7f < sVar3) {
        sVar3 = 0x80;
      }
      memmove(auStack_a8,(void *)((int)ctx + 100),sVar3);
      dVar2 = SetDataBuffersInfo(auStack_a8,*(size_t *)((int)ctx + 0x5c),apuStack_b0,(uint8_t *)0x0,
                                 0,(CCBuffInfo_t *)0x0);
      if (dVar2 != 0) {
        return 1;
      }
      dVar2 = ProcessHashDrv(ctx,apuStack_b0,*(uint32_t *)((int)ctx + 0x5c));
      if (dVar2 != 0) {
        return 1;
      }
      sVar3 = *(uint *)((int)ctx + 0x5c);
      *(undefined4 *)((int)ctx + 0x60) = 0;
    }
    sVar3 = sVar3 * (ilen / sVar3);
    if (sVar3 != 0) {
      dVar2 = SetDataBuffersInfo(input,sVar3,apuStack_b0,(uint8_t *)0x0,0,(CCBuffInfo_t *)0x0);
      if (dVar2 != 0) {
        return 1;
      }
      dVar2 = ProcessHashDrv(ctx,apuStack_b0,sVar3);
      if (dVar2 != 0) {
        return 1;
      }
      input = input + sVar3;
      ilen = ilen - sVar3;
    }
    if (ilen != 0) {
      memmove((void *)((int)ctx + (*(int *)((int)ctx + 0x60) + 0x19) * 4),input,ilen);
      *(size_t *)((int)ctx + 0x60) = *(int *)((int)ctx + 0x60) + ilen;
    }
  }
  return 0;
}


