/*
 * Function: $_?_VFPRINTF
 * Entry:    0007c038
 * Prototype: int __stdcall $_?_VFPRINTF(undefined4 * param_1, int * param_2, byte * param_3, uint * param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0007c1a0) */

int ____VFPRINTF(undefined4 *param_1,int *param_2,byte *param_3,uint *param_4)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  uint *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint *local_8c;
  uint local_88;
  uint local_84;
  undefined4 uStack_80;
  uint local_7c;
  int local_74;
  byte local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_45;
  undefined4 local_30;
  
  if (((int)((uint)*(ushort *)(param_2 + 3) << 0x18) < 0) && (param_2[4] == 0)) {
    pvVar2 = ____calloc((size_t)param_1,0x40);
    *param_2 = (int)pvVar2;
    param_2[4] = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      *param_1 = 0xc;
      return -1;
    }
    param_2[5] = 0x40;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar6 = param_3;
  local_8c = param_4;
LAB_0007c08c:
  pbVar5 = pbVar6;
  if (*pbVar5 != 0) goto code_r0x0007c094;
  goto LAB_0007c098;
code_r0x0007c094:
  pbVar6 = pbVar5 + 1;
  if (*pbVar5 == 0x25) {
LAB_0007c098:
    uVar7 = (int)pbVar5 - (int)param_3;
    if (uVar7 != 0) {
      iVar3 = __ssputs_r(param_1,param_2,param_3,uVar7);
      if (iVar3 == -1) {
LAB_0007c1fe:
        if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
          return -1;
        }
        return local_74;
      }
      local_74 = local_74 + uVar7;
    }
    if (*pbVar5 == 0) goto LAB_0007c1fe;
    local_88 = 0;
    local_7c = 0;
    local_45 = 0;
    local_30 = 0;
    local_84 = 0xffffffff;
    uStack_80 = 0;
    pbVar6 = pbVar5 + 1;
    while( true ) {
      pbVar5 = pbVar6 + 1;
      pvVar2 = memchr("#-0+ ",(uint)*pbVar6,5);
      if (pvVar2 == (void *)0x0) break;
      local_88 = 1 << ((int)pvVar2 - 0xf6ba2U & 0xff) | local_88;
      pbVar6 = pbVar5;
    }
    if ((int)(local_88 << 0x1b) < 0) {
      local_45 = 0x20;
    }
    if ((int)(local_88 << 0x1c) < 0) {
      local_45 = 0x2b;
    }
    if (*pbVar6 == 0x2a) {
      puVar4 = local_8c + 1;
      local_7c = *local_8c;
      local_8c = puVar4;
      if ((int)local_7c < 0) {
        local_7c = -local_7c;
        local_88 = local_88 | 2;
      }
    }
    else {
      bVar1 = false;
      uVar7 = local_7c;
      pbVar5 = pbVar6;
      while( true ) {
        if (9 < *pbVar5 - 0x30) break;
        uVar7 = uVar7 * 10 + (*pbVar5 - 0x30);
        bVar1 = true;
        pbVar5 = pbVar5 + 1;
      }
      if (bVar1) {
        local_7c = uVar7;
      }
    }
    if (*pbVar5 == 0x2e) {
      if (pbVar5[1] == 0x2a) {
        pbVar5 = pbVar5 + 2;
        uVar7 = *local_8c;
        local_8c = local_8c + 1;
        local_84 = uVar7 | (int)uVar7 >> 0x1f;
      }
      else {
        bVar1 = false;
        uVar7 = 0;
        local_84 = 0;
        while( true ) {
          pbVar5 = pbVar5 + 1;
          if (9 < *pbVar5 - 0x30) break;
          uVar7 = uVar7 * 10 + (*pbVar5 - 0x30);
          bVar1 = true;
        }
        if (bVar1) {
          local_84 = uVar7;
        }
      }
    }
    pvVar2 = memchr("hlL",(uint)*pbVar5,3);
    if (pvVar2 != (void *)0x0) {
      pbVar5 = pbVar5 + 1;
      local_88 = local_88 | 0x40 << ((int)pvVar2 - 0xf6ba8U & 0xff);
    }
    param_3 = pbVar5 + 1;
    local_70 = *pbVar5;
    pvVar2 = memchr("efgEFG",(uint)local_70,6);
    if (pvVar2 == (void *)0x0) {
      uVar7 = _____printf_float();
    }
    else {
      uVar7 = _____printf_i((int)param_1,&local_88,param_2,(undefined *)0x8aee7,(int *)&local_8c);
    }
    if (uVar7 == 0xffffffff) goto LAB_0007c1fe;
    local_74 = local_74 + uVar7;
    pbVar6 = param_3;
  }
  goto LAB_0007c08c;
}


