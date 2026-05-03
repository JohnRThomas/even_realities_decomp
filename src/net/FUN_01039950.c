/*
 * Function: FUN_01039950
 * Entry:    01039950
 * Prototype: char * __stdcall FUN_01039950(int param_1, byte * param_2, uint * param_3)
 */


/* WARNING: Type propagation algorithm not settling */

char * FUN_01039950(int param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *local_48;
  uint local_44;
  char acStack_35 [17];
  
  pcVar6 = *(code **)(param_1 + 4);
  if ((int)((uint)*(byte *)(param_1 + 2) << 0x1e) < 0) {
    pcVar10 = (char *)0x0;
    do {
      while( true ) {
        uVar15 = (uint)*param_2;
        if (uVar15 == 0) {
          return pcVar10;
        }
        if (uVar15 != 0x25) break;
        uVar15 = (uint)param_2[1];
        local_48 = param_2 + 2;
        if (uVar15 == 0x25) goto LAB_0103997e;
        uVar16 = 0;
        uVar12 = 0;
        uVar5 = 0;
        puVar8 = param_3;
        do {
          uVar7 = uVar5;
          param_3 = puVar8;
          if (uVar12 < 0x20) {
            switch(uVar15) {
            default:
              if (9 < uVar15 - 0x30) goto LAB_010399d0;
LAB_01039a36:
              uVar12 = uVar12 | 0x20;
              uVar16 = uVar16 * 10 + (uVar15 - 0x30);
              break;
            case 0x23:
              uVar12 = uVar12 | 0x10;
              break;
            case 0x27:
              break;
            case 0x2b:
              uVar12 = uVar12 | 2;
            case 0x20:
              uVar12 = uVar12 | 4;
              break;
            case 0x2d:
              uVar12 = uVar12 | 8;
              break;
            case 0x30:
              uVar12 = uVar12 | 1;
            }
          }
          else if (uVar12 < 0x80) {
            if (uVar15 - 0x30 < 10) {
              if (-1 < (int)(uVar12 << 0x19)) goto LAB_01039a36;
              uVar7 = uVar5 * 10 + (uVar15 - 0x30);
            }
            else {
LAB_010399d0:
              if (uVar15 == 0x2a) {
                param_3 = puVar8 + 1;
                uVar15 = *puVar8;
                uVar7 = uVar15;
                if (-1 < (int)(uVar12 << 0x19)) {
                  if ((int)uVar15 < 0) {
                    uVar16 = -uVar15;
                    uVar12 = uVar12 | 0x28;
                    uVar7 = uVar5;
                  }
                  else {
                    uVar12 = uVar12 | 0x20;
                    uVar7 = uVar5;
                    uVar16 = uVar15;
                  }
                }
              }
              else {
                if (uVar15 != 0x2e) goto LAB_01039a54;
                if ((int)(uVar12 << 0x19) < 0) {
                  return pcVar10;
                }
                uVar12 = uVar12 | 0x40;
              }
            }
          }
          else {
LAB_01039a54:
            if (uVar15 == 0x6c) {
              if ((int)(uVar12 << 0x18) < 0) {
                uVar12 = uVar12 | 0x200;
              }
              uVar12 = uVar12 | 0x80;
            }
            else if (uVar15 < 0x6d) {
              if (uVar15 != 0x68) {
                if ((uVar15 == 0x6a) || (uVar15 == 0x4c)) {
                  uVar12 = uVar12 | 0x280;
                  goto switchD_010399b2_caseD_27;
                }
                break;
              }
              if ((int)(uVar12 << 0x17) < 0) {
                uVar12 = uVar12 | 0x200;
              }
              uVar12 = uVar12 | 0x100;
            }
            else if ((uVar15 != 0x74) && (uVar15 != 0x7a)) break;
          }
switchD_010399b2_caseD_27:
          pbVar4 = local_48 + 1;
          uVar15 = (uint)*local_48;
          uVar5 = uVar7;
          puVar8 = param_3;
          local_48 = pbVar4;
        } while (uVar15 != 0);
        uVar5 = uVar15 | 0x20;
        if ((int)uVar7 < 0) {
          uVar12 = uVar12 & 0xffffffbf;
          uVar7 = 0;
        }
        if ((uVar5 - 0x65 < 3) || (uVar5 == 0x61)) {
          uVar15 = 7;
          pcVar11 = "*float*";
          puVar8 = (uint *)(((int)param_3 + 7U & 0xfffffff8) + 8);
          goto LAB_01039a9a;
        }
        uVar17 = uVar7;
        uVar14 = uVar7;
        switch(uVar15) {
        case 99:
          puVar8 = param_3 + 1;
          uVar15 = 1;
          pcVar11 = acStack_35 + 1;
          acStack_35[1] = (char)*param_3;
          goto LAB_01039a9a;
        case 100:
        case 0x69:
          if ((int)(uVar12 << 0x18) < 0) {
            if ((int)(uVar12 << 0x16) < 0) {
              puVar9 = (uint *)((int)param_3 + 7U & 0xfffffff8);
              puVar8 = puVar9 + 2;
              uVar2 = *puVar9;
            }
            else {
              puVar8 = param_3 + 1;
              uVar2 = *param_3;
            }
          }
          else {
            puVar8 = param_3 + 1;
            uVar2 = *param_3;
            if ((int)(uVar12 << 0x17) < 0) {
              if ((int)(uVar12 << 0x16) < 0) {
                uVar2 = (uint)(char)uVar2;
              }
              else {
                uVar2 = (uint)(short)uVar2;
              }
            }
          }
          local_44 = uVar12 & 0xffffffef;
          if ((int)uVar2 < 0) {
            uVar2 = -uVar2;
            local_44 = local_44 | 0x400;
LAB_01039baa:
            uVar5 = 10;
            goto LAB_01039bb0;
          }
          if (((uVar2 != 0) || (-1 < (int)(uVar12 << 0x19))) || (uVar7 != 0)) goto LAB_01039baa;
          goto LAB_01039c1c;
        default:
          if (uVar5 == 0x78) {
            if (uVar15 == 0x58) {
              uVar5 = 0x210;
            }
            else {
              uVar5 = 0x10;
            }
            break;
          }
          iVar1 = (*pcVar6)(0x25,param_1);
          if (iVar1 < 0) {
            return (char *)0xffffffff;
          }
          pcVar10 = pcVar10 + 2;
          goto LAB_01039980;
        case 0x6f:
          uVar5 = 8;
          uVar15 = 0;
          break;
        case 0x70:
          uVar12 = uVar12 | 0x10;
          uVar5 = 0x10;
          uVar15 = 0x78;
          break;
        case 0x73:
          puVar8 = param_3 + 1;
          pcVar11 = (char *)*param_3;
          if (pcVar11 == (char *)0x0) {
            pcVar11 = "(null)";
          }
          if ((uVar12 & 0x40) == 0) {
            uVar7 = 0xffffffff;
          }
          uVar15 = FUN_0103bd84(pcVar11,uVar7);
LAB_01039a9a:
          uVar5 = uVar16;
          if (-1 < (int)(uVar12 << 0x1c)) {
            for (; uVar15 < uVar5; uVar5 = uVar5 - 1) {
              iVar1 = (*pcVar6)(0x20,param_1);
              if (iVar1 < 0) {
                return (char *)0xffffffff;
              }
            }
            pcVar10 = pcVar10 + (uVar16 - uVar5);
          }
          pcVar13 = pcVar11;
          while (pcVar13 != pcVar11 + uVar15) {
            iVar1 = (*pcVar6)(*pcVar13,param_1);
            pcVar13 = pcVar13 + 1;
            if (iVar1 < 0) {
              return (char *)0xffffffff;
            }
          }
          iVar1 = uVar5 - uVar15;
          pcVar10 = pcVar13 + ((int)pcVar10 - (int)pcVar11);
          pcVar11 = pcVar10;
          param_3 = puVar8;
          goto LAB_01039dd0;
        case 0x75:
          uVar12 = uVar12 & 0xffffffef;
          uVar5 = 10;
        }
        if ((int)(uVar12 << 0x18) < 0) {
          if ((int)(uVar12 << 0x16) < 0) {
            puVar9 = (uint *)((int)param_3 + 7U & 0xfffffff8);
            puVar8 = puVar9 + 2;
            uVar2 = *puVar9;
          }
          else {
            puVar8 = param_3 + 1;
            uVar2 = *param_3;
          }
        }
        else {
          puVar8 = param_3 + 1;
          uVar2 = *param_3;
          if ((int)(uVar12 << 0x17) < 0) {
            if ((int)(uVar12 << 0x16) < 0) {
              uVar2 = uVar2 & 0xff;
            }
            else {
              uVar2 = uVar2 & 0xffff;
            }
          }
        }
        if (uVar2 == 0) {
          local_44 = uVar12 & 0xffffffe9;
          if ((-1 < (int)(uVar12 << 0x19)) || (uVar7 != 0)) goto LAB_01039bb0;
          uVar5 = uVar12 & 0xffffffe8;
LAB_01039c58:
          local_44 = uVar5 & 0x10;
          uVar17 = uVar14;
          if (local_44 == 0) {
LAB_01039be2:
            local_44 = uVar5 & 0x406;
            if (local_44 != 0) {
              uVar17 = uVar17 + 1;
              local_44 = 0;
            }
          }
          else {
            if (uVar15 != 0) goto LAB_01039cea;
            uVar17 = uVar14 + 1;
          }
        }
        else {
          local_44 = uVar12 & 0xfffffff9;
LAB_01039bb0:
          iVar1 = FUN_0103bd9c(uVar2,acStack_35 + 1,uVar5);
          uVar14 = iVar1 - (int)(acStack_35 + 1);
          uVar5 = local_44;
          if ((-1 < (int)(local_44 << 0x19)) ||
             (uVar5 = local_44 & 0xfffffffe, (int)uVar7 <= (int)uVar14)) goto LAB_01039c58;
          uVar12 = local_44;
          if (uVar15 == 0) {
LAB_01039c1c:
            uVar5 = uVar12 & 0xffffffee;
            goto LAB_01039be2;
          }
          local_44 = local_44 & 0x10;
          if (local_44 == 0) goto LAB_01039be2;
LAB_01039cea:
          uVar17 = uVar17 + 2;
        }
        if (-1 < (int)(uVar5 << 0x1c)) {
          uVar12 = uVar17;
          if (((int)(uVar5 << 0x1f) < 0) && (uVar7 = uVar14, (int)uVar17 < (int)uVar16)) {
            iVar1 = uVar16 - uVar17;
            uVar17 = uVar16;
            uVar12 = uVar16;
            uVar7 = iVar1 + uVar14;
          }
          for (; (int)uVar17 < (int)uVar16; uVar17 = uVar17 + 1) {
            iVar1 = (*pcVar6)(0x20,param_1);
            if (iVar1 < 0) {
              return (char *)0xffffffff;
            }
          }
          pcVar10 = pcVar10 + (uVar17 - uVar12);
        }
        if (local_44 == 0) {
          pcVar11 = pcVar10;
          if ((uVar5 & 0x406) != 0) {
            pcVar10 = pcVar10 + 1;
            if ((uVar5 & 2) == 0) {
              uVar15 = 0x20;
            }
            else {
              uVar15 = 0x2b;
            }
            if ((uVar5 & 0x400) != 0) {
              uVar15 = 0x2d;
            }
            goto LAB_01039d6e;
          }
        }
        else {
          iVar1 = (*pcVar6)(0x30,param_1);
          if (iVar1 < 0) {
            return (char *)0xffffffff;
          }
          if (uVar15 != 0) {
            pcVar10 = pcVar10 + 2;
LAB_01039d6e:
            iVar1 = (*pcVar6)(uVar15,param_1);
            pcVar11 = pcVar10;
            goto joined_r0x01039d76;
          }
          pcVar10 = pcVar10 + 1;
          pcVar11 = pcVar10;
        }
        while (uVar15 = uVar14, (int)uVar14 < (int)(pcVar11 + (uVar7 - (int)pcVar10))) {
          pcVar10 = pcVar10 + 1;
          iVar1 = (*pcVar6)(0x30,param_1);
joined_r0x01039d76:
          if (iVar1 < 0) {
            return (char *)0xffffffff;
          }
        }
        while (uVar15 != 0) {
          iVar1 = (*pcVar6)(acStack_35[uVar15],param_1);
          uVar15 = uVar15 - 1;
          if (iVar1 < 0) {
            return (char *)0xffffffff;
          }
        }
        pcVar10 = pcVar10 + uVar14;
        iVar1 = uVar16 - uVar17;
        pcVar11 = pcVar10;
        param_3 = puVar8;
LAB_01039dd0:
        while (param_2 = local_48, 0 < (int)(pcVar11 + (iVar1 - (int)pcVar10))) {
          pcVar10 = pcVar10 + 1;
          iVar3 = (*pcVar6)(0x20,param_1);
          if (iVar3 < 0) {
            return (char *)0xffffffff;
          }
        }
      }
      local_48 = param_2 + 1;
LAB_0103997e:
      pcVar10 = pcVar10 + 1;
LAB_01039980:
      iVar1 = (*pcVar6)(uVar15,param_1);
      param_2 = local_48;
    } while (-1 < iVar1);
  }
  return (char *)0xffffffff;
}


