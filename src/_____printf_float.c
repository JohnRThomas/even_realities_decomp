/*
 * Function: $_?__printf_float
 * Entry:    0007a83c
 * Prototype: int __stdcall $_?__printf_float(void)
 */


int _____printf_float(void)

{
  bool bVar1;
  byte bVar2;
  undefined4 in_r0;
  int iVar3;
  code *pcVar4;
  char *pcVar5;
  void *pvVar6;
  int iVar7;
  uint *in_r1;
  uint *puVar8;
  undefined4 in_r2;
  char *pcVar9;
  code *in_r3;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  uint uVar15;
  void *s;
  undefined1 uVar16;
  int *in_stack_00000000;
  code *local_24;
  
  bVar2 = (byte)in_r1[6];
  pcVar9 = (char *)((int)in_r1 + 0x43);
  local_24 = in_r3;
  if (0x78 < bVar2) {
switchD_0007a878_caseD_65:
    *(byte *)((int)in_r1 + 0x42) = bVar2;
LAB_0007a8e4:
    uVar11 = 1;
LAB_0007aa40:
    in_r1[4] = uVar11;
    *(undefined1 *)((int)in_r1 + 0x43) = 0;
    goto LAB_0007a952;
  }
  pcVar14 = pcVar9;
  if (bVar2 < 99) {
    if (bVar2 == 0) {
LAB_0007aa1e:
      in_r1[4] = 0;
      goto LAB_0007a952;
    }
    if (bVar2 != 0x58) goto switchD_0007a878_caseD_65;
    pcVar5 = "0123456789ABCDEF";
    uVar16 = 0x58;
  }
  else {
    switch(bVar2) {
    case 99:
      uVar10 = *(undefined4 *)*in_stack_00000000;
      *in_stack_00000000 = (int)((undefined4 *)*in_stack_00000000 + 1);
      *(char *)((int)in_r1 + 0x42) = (char)uVar10;
      goto LAB_0007a8e4;
    case 100:
    case 0x69:
      uVar12 = *in_r1;
      puVar8 = (uint *)*in_stack_00000000;
      *in_stack_00000000 = (int)(puVar8 + 1);
      if (((int)(uVar12 << 0x18) < 0) || (-1 < (int)(uVar12 << 0x19))) {
        uVar11 = *puVar8;
      }
      else {
        uVar11 = (uint)(short)*puVar8;
      }
      if (-1 < (int)uVar11) {
        pcVar5 = "0123456789ABCDEF";
        uVar12 = 10;
        goto LAB_0007a99e;
      }
      in_r1[2] = in_r1[1];
      *(undefined1 *)((int)in_r1 + 0x43) = 0x2d;
      if (-1 < (int)in_r1[1]) {
        *in_r1 = uVar12 & 0xfffffffb;
      }
      uVar11 = -uVar11;
      pcVar5 = "0123456789ABCDEF";
      uVar12 = 10;
      goto LAB_0007a91c;
    default:
      goto switchD_0007a878_caseD_65;
    case 0x6e:
      puVar13 = (undefined4 *)*in_stack_00000000;
      uVar12 = *in_r1;
      uVar11 = in_r1[5];
      *in_stack_00000000 = (int)(puVar13 + 1);
      puVar8 = (uint *)*puVar13;
      if (((int)(uVar12 << 0x18) < 0) || (-1 < (int)(uVar12 << 0x19))) {
        *puVar8 = uVar11;
      }
      else {
        *(short *)puVar8 = (short)uVar11;
      }
      goto LAB_0007aa1e;
    case 0x6f:
    case 0x75:
      puVar8 = (uint *)*in_stack_00000000;
      uVar11 = *in_r1;
      *in_stack_00000000 = (int)(puVar8 + 1);
      if (((int)(uVar11 << 0x18) < 0) || (-1 < (int)(uVar11 << 0x19))) {
        uVar11 = *puVar8;
      }
      else {
        uVar11 = (uint)(ushort)*puVar8;
      }
      pcVar5 = "0123456789ABCDEF";
      if (bVar2 == 0x6f) {
        uVar12 = 8;
      }
      else {
        uVar12 = 10;
      }
      goto LAB_0007a998;
    case 0x70:
      *in_r1 = *in_r1 | 0x20;
    case 0x78:
      uVar16 = 0x78;
      pcVar5 = "0123456789abcdef";
      break;
    case 0x73:
      puVar13 = (undefined4 *)*in_stack_00000000;
      *in_stack_00000000 = (int)(puVar13 + 1);
      s = (void *)*puVar13;
      pvVar6 = memchr(s,0,in_r1[1]);
      if (pvVar6 != (void *)0x0) {
        in_r1[1] = (int)pvVar6 - (int)s;
      }
      uVar11 = in_r1[1];
      goto LAB_0007aa40;
    }
  }
  *(undefined1 *)((int)in_r1 + 0x45) = uVar16;
  puVar8 = (uint *)*in_stack_00000000;
  uVar12 = *in_r1;
  *in_stack_00000000 = (int)(puVar8 + 1);
  if (((int)(uVar12 << 0x18) < 0) || (-1 < (int)(uVar12 << 0x19))) {
    uVar11 = *puVar8;
  }
  else {
    uVar11 = (uint)(ushort)*puVar8;
  }
  if ((int)(uVar12 << 0x1f) < 0) {
    *in_r1 = uVar12 | 0x20;
  }
  if (uVar11 == 0) {
    *in_r1 = *in_r1 & 0xffffffdf;
  }
  uVar12 = 0x10;
LAB_0007a998:
  *(undefined1 *)((int)in_r1 + 0x43) = 0;
LAB_0007a99e:
  uVar15 = in_r1[1];
  in_r1[2] = uVar15;
  if ((((int)uVar15 < 0) || (*in_r1 = *in_r1 & 0xfffffffb, uVar11 != 0)) || (uVar15 != 0)) {
LAB_0007a91c:
    do {
      pcVar14 = pcVar14 + -1;
      *pcVar14 = pcVar5[uVar11 - uVar12 * (uVar11 / uVar12)];
      bVar1 = uVar12 <= uVar11;
      uVar11 = uVar11 / uVar12;
    } while (bVar1);
  }
  if (((uVar12 == 8) && ((int)(*in_r1 << 0x1f) < 0)) && ((int)in_r1[1] <= (int)in_r1[4])) {
    pcVar14[-1] = '0';
    pcVar14 = pcVar14 + -1;
  }
  in_r1[4] = (int)pcVar9 - (int)pcVar14;
LAB_0007a952:
  iVar3 = _printf_common(in_r0,in_r1,(uint *)&local_24,in_r2,in_r3);
  if ((iVar3 == -1) || (iVar3 = (*in_r3)(), iVar3 == -1)) {
LAB_0007a966:
    pcVar4 = (code *)0xffffffff;
  }
  else {
    if ((int)(*in_r1 << 0x1e) < 0) {
      for (iVar3 = 0; iVar3 < (int)(in_r1[3] - (int)local_24); iVar3 = iVar3 + 1) {
        iVar7 = (*in_r3)();
        if (iVar7 == -1) goto LAB_0007a966;
      }
    }
    pcVar4 = (code *)in_r1[3];
    if ((int)in_r1[3] < (int)local_24) {
      pcVar4 = local_24;
    }
  }
  return (int)pcVar4;
}


