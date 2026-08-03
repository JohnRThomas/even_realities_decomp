/*
 * Function: sha256_compress
 * Entry:    00052d88
 * Prototype: undefined __stdcall sha256_compress(uint * param_1, int param_2)
 */


/* exclude_from_export_ai */

void sha256_compress(uint *param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  uint uVar13;
  undefined *puVar14;
  undefined *puVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined *puVar19;
  undefined **ppuVar20;
  uint uVar21;
  undefined *puVar22;
  undefined *puVar23;
  undefined *puVar24;
  undefined *puVar25;
  undefined *local_98;
  undefined *local_94;
  undefined **local_6c;
  uint local_68 [17];
  
  iVar17 = 0;
  puVar4 = (undefined *)*param_1;
  puVar5 = (undefined *)param_1[1];
  puVar6 = (undefined *)param_1[2];
  puVar7 = (undefined *)param_1[3];
  puVar8 = (undefined *)param_1[4];
  puVar9 = (undefined *)param_1[5];
  puVar10 = (undefined *)param_1[6];
  puVar11 = (undefined *)param_1[7];
  puVar19 = puVar8;
  puVar1 = puVar4;
  puVar14 = puVar5;
  puVar2 = puVar11;
  ppuVar20 = &PTR_DAT_0008eaa0;
  puVar15 = puVar6;
  puVar25 = puVar9;
  puVar24 = puVar7;
  puVar3 = puVar10;
  do {
    local_94 = puVar3;
    puVar3 = puVar25;
    puVar22 = puVar15;
    puVar15 = puVar14;
    puVar14 = puVar1;
    puVar25 = puVar19;
    uVar16 = *(uint *)(param_2 + iVar17);
    uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
             uVar16 >> 0x18;
    puVar19 = *ppuVar20;
    *(uint *)((int)local_68 + iVar17) = uVar16;
    puVar12 = puVar19 + ((uint)local_94 & ~(uint)puVar25 ^ (uint)puVar25 & (uint)puVar3) +
                        (((uint)puVar25 >> 0xb | (int)puVar25 << 0x15) ^
                         ((uint)puVar25 >> 6 | (int)puVar25 << 0x1a) ^
                        ((uint)puVar25 >> 0x19 | (int)puVar25 << 7)) + uVar16 + (int)puVar2;
    iVar17 = iVar17 + 4;
    puVar19 = puVar12 + (int)puVar24;
    puVar1 = puVar12 + (((uint)puVar14 >> 0xd | (int)puVar14 << 0x13) ^
                        ((uint)puVar14 >> 2 | (int)puVar14 << 0x1e) ^
                       ((uint)puVar14 >> 0x16 | (int)puVar14 << 10)) +
                       (((uint)puVar15 ^ (uint)puVar22) & (uint)puVar14 ^
                       (uint)puVar15 & (uint)puVar22);
    puVar2 = local_94;
    ppuVar20 = ppuVar20 + 1;
    puVar24 = puVar22;
  } while (iVar17 != 0x40);
  local_6c = &PTR_DAT_0008eadc;
  uVar16 = 0x10;
  do {
    local_98 = puVar1;
    puVar23 = puVar3;
    puVar12 = puVar15;
    puVar24 = puVar19;
    puVar15 = puVar14;
    puVar3 = puVar25;
    uVar21 = uVar16 + 1;
    uVar13 = local_68[uVar21 & 0xf];
    uVar18 = local_68[uVar16 + 0xe & 0xf];
    uVar13 = local_68[uVar16 + 9 & 0xf] + local_68[uVar16 & 0xf] +
             ((uVar13 >> 0x12 | uVar13 << 0xe) ^ (uVar13 >> 7 | uVar13 << 0x19) ^ uVar13 >> 3) +
             ((uVar18 >> 0x13 | uVar18 << 0xd) ^ (uVar18 >> 0x11 | uVar18 << 0xf) ^ uVar18 >> 10);
    local_6c = local_6c + 1;
    puVar25 = *local_6c;
    local_68[uVar16 & 0xf] = uVar13;
    puVar2 = local_94 +
             (int)(puVar25 +
                  uVar13 + ((uint)puVar23 & ~(uint)puVar24 ^ (uint)puVar24 & (uint)puVar3) +
                           (((uint)puVar24 >> 0xb | (int)puVar24 << 0x15) ^
                            ((uint)puVar24 >> 6 | (int)puVar24 << 0x1a) ^
                           ((uint)puVar24 >> 0x19 | (int)puVar24 << 7)));
    puVar19 = puVar2 + (int)puVar22;
    puVar25 = puVar24;
    puVar14 = local_98;
    uVar16 = uVar21;
    puVar22 = puVar12;
    puVar1 = puVar2 + (((uint)puVar15 ^ (uint)puVar12) & (uint)local_98 ^
                      (uint)puVar15 & (uint)puVar12) +
                      (((uint)local_98 >> 0xd | (int)local_98 << 0x13) ^
                       ((uint)local_98 >> 2 | (int)local_98 << 0x1e) ^
                      ((uint)local_98 >> 0x16 | (int)local_98 << 10));
    local_94 = puVar23;
  } while (uVar21 != 0x40);
  *param_1 = (uint)(puVar4 + (int)(puVar2 + (((uint)puVar15 ^ (uint)puVar12) & (uint)local_98 ^
                                            (uint)puVar15 & (uint)puVar12) +
                                            (((uint)local_98 >> 0xd | (int)local_98 << 0x13) ^
                                             ((uint)local_98 >> 2 | (int)local_98 << 0x1e) ^
                                            ((uint)local_98 >> 0x16 | (int)local_98 << 10))));
  param_1[1] = (uint)(puVar5 + (int)local_98);
  param_1[2] = (uint)(puVar6 + (int)puVar15);
  param_1[3] = (uint)(puVar7 + (int)puVar12);
  param_1[4] = (uint)(puVar8 + (int)puVar19);
  param_1[5] = (uint)(puVar9 + (int)puVar24);
  param_1[6] = (uint)(puVar10 + (int)puVar3);
  param_1[7] = (uint)(puVar11 + (int)puVar23);
  return;
}


