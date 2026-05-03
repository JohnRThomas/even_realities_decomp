/*
 * Function: FUN_0101e6d0
 * Entry:    0101e6d0
 * Prototype: char * __stdcall FUN_0101e6d0(uint param_1, char * param_2, uint param_3)
 */


/* WARNING: Removing unreachable block (ram,0x0101e806) */
/* WARNING: Removing unreachable block (ram,0x0101e810) */
/* WARNING: Removing unreachable block (ram,0x0101e81e) */
/* WARNING: Removing unreachable block (ram,0x0101e7ba) */
/* WARNING: Removing unreachable block (ram,0x0101e7c6) */
/* WARNING: Removing unreachable block (ram,0x0101e796) */
/* WARNING: Removing unreachable block (ram,0x0101e830) */
/* WARNING: Removing unreachable block (ram,0x0101e79a) */
/* WARNING: Removing unreachable block (ram,0x0101e7b4) */
/* WARNING: Removing unreachable block (ram,0x0101e7d6) */
/* WARNING: Removing unreachable block (ram,0x0101e7e4) */
/* WARNING: Removing unreachable block (ram,0x0101e7ea) */
/* WARNING: Removing unreachable block (ram,0x0101e7f8) */
/* WARNING: Removing unreachable block (ram,0x0101e800) */
/* WARNING: Removing unreachable block (ram,0x0101e826) */
/* WARNING: Removing unreachable block (ram,0x0101e79e) */
/* WARNING: Removing unreachable block (ram,0x0101e7a4) */
/* WARNING: Removing unreachable block (ram,0x0101e836) */
/* WARNING: Removing unreachable block (ram,0x0101e842) */
/* WARNING: Removing unreachable block (ram,0x0101e850) */
/* WARNING: Removing unreachable block (ram,0x0101e858) */
/* WARNING: Removing unreachable block (ram,0x0101e866) */
/* WARNING: Removing unreachable block (ram,0x0101e86e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * FUN_0101e6d0(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  if (DAT_2100113c != 0) {
    uVar5 = 0;
    pcVar3 = (char *)0x0;
    iVar1 = DAT_2100113c;
    do {
      pcVar4 = *(char **)(iVar1 + 0x10);
      if ((pcVar3 == (char *)0x0) || (pcVar4 < pcVar3)) {
        if (pcVar4 == (char *)0x0) {
          pcVar3 = (char *)FUN_01009500(0x37,300,param_3,iVar1);
                    /* WARNING: Read-only address (ram,0x00000170) is written */
                    /* WARNING: Read-only address (ram,0x00000174) is written */
                    /* WARNING: Read-only address (ram,0x00000178) is written */
                    /* WARNING: Read-only address (ram,0x0000017c) is written */
          return pcVar3;
        }
        uVar5 = (uint)*(ushort *)(iVar1 + 0x14);
        pcVar3 = pcVar4;
      }
      iVar1 = *(int *)(iVar1 + 0x18);
    } while (iVar1 != 0);
    if (pcVar3 != (char *)0x0) {
      if (param_2 < pcVar3) {
        uVar2 = (uint)(param_2 + -1 + (int)pcVar3) / (uint)param_2;
        if (uVar2 <= (uint)pcVar3 / param_1) {
          while (((pcVar4 = (char *)((uint)pcVar3 / uVar2), pcVar3 != (char *)(uVar2 * (int)pcVar4)
                  || (pcVar4 != (char *)(param_3 * ((uint)pcVar4 / param_3)))) ||
                 (pcVar4 != (char *)(uVar5 * ((uint)pcVar4 / uVar5))))) {
            uVar2 = uVar2 + 1;
            if ((uint)pcVar3 / param_1 < uVar2) {
              _UNK_00000170 = 0xffffffff;
              _UNK_00000174 = 0xffffffff;
              _UNK_00000178 = 0xffffffff;
              _UNK_0000017c = 0xffff;
              return param_2;
            }
          }
          _UNK_00000170 = 0xffffffff;
          _UNK_00000174 = 0xffffffff;
          _UNK_00000178 = 0xffffffff;
          _UNK_0000017c = 0xffff;
          return pcVar4;
        }
      }
      else {
        uVar5 = (uint)param_2 / (uint)pcVar3;
        if ((uint)(pcVar3 + (param_1 - 1)) / (uint)pcVar3 <= uVar5) {
          pcVar4 = (char *)((int)pcVar3 * uVar5);
          do {
            if ((pcVar4 == (char *)((int)pcVar3 * ((uint)pcVar4 / (uint)pcVar3))) &&
               (pcVar4 == (char *)(param_3 * ((uint)pcVar4 / param_3)))) {
              _UNK_00000170 = 0xffffffff;
              _UNK_00000174 = 0xffffffff;
              _UNK_00000178 = 0xffffffff;
              _UNK_0000017c = 0xffff;
              return pcVar4;
            }
            uVar5 = uVar5 - 1;
            pcVar4 = pcVar4 + -(int)pcVar3;
          } while ((uint)(pcVar3 + (param_1 - 1)) / (uint)pcVar3 <= uVar5);
        }
      }
    }
  }
  _UNK_00000170 = 0xffffffff;
  _UNK_00000174 = 0xffffffff;
  _UNK_00000178 = 0xffffffff;
  _UNK_0000017c = 0xffff;
  return param_2;
}


