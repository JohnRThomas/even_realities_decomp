/*
 * Function: activate_foreach_backend
 * Entry:    00050570
 * Prototype: uint32_t __stdcall activate_foreach_backend(uint32_t mask)
 */


/* exclude_from_export */

uint32_t activate_foreach_backend(uint32_t mask)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint32_t uVar7;
  
  uVar7 = mask;
  while (mask != 0) {
    bVar2 = (byte)mask;
    bVar3 = (byte)(mask >> 8);
    bVar4 = (byte)(mask >> 0x10);
    bVar1 = (byte)(mask >> 0x18);
    iVar6 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    mask = mask & ~(1 << iVar6);
    if ((*(char *)(&PTR_DAT_0008ba5c + iVar6 * 4) != '\0') &&
       ((*(code **)((&PTR_PTR_0008ba50)[iVar6 * 4] + 0x10) == (code *)0x0 ||
        (iVar5 = (**(code **)((&PTR_PTR_0008ba50)[iVar6 * 4] + 0x10))
                           ((log_backend *)(&PTR_PTR_0008ba50 + iVar6 * 4)), iVar5 == 0)))) {
      uVar7 = uVar7 & ~(1 << iVar6);
      log_backend_enable((log_backend *)(&PTR_PTR_0008ba50 + iVar6 * 4),
                         *(void **)(&PTR_DAT_0008ba54)[iVar6 * 4],4);
    }
  }
  return uVar7;
}


