/*
 * Function: FUN_00029684
 * Entry:    00029684
 * Prototype: undefined __stdcall FUN_00029684(void)
 */


void FUN_00029684(void)

{
  byte bVar1;
  byte bVar2;
  GlassesState *pGVar3;
  undefined *puVar4;
  uint uVar5;
  
  pGVar3 = __get_dashboard_state();
  if (-1 < (int)((uint)(byte)pGVar3->field20_0xc8[0x1c] << 0x1d)) {
    pGVar3 = __get_dashboard_state();
    bVar2 = pGVar3->field_0x6de;
    if (((bVar2 & 4) == 0) && (puVar4 = FUN_0003519c(), puVar4 != (undefined *)0x0)) {
      pGVar3 = __get_dashboard_state();
      if (*(char *)pGVar3 == '\x01') {
        bVar1 = puVar4[0xd];
        if (bVar1 == 1) {
          DAT_20019a66 = bVar1;
          pGVar3 = __get_dashboard_state();
          uVar5 = sync_to_slave((char *)pGVar3,10,(undefined4 *)(puVar4 + 8),4);
          if ((int)uVar5 < 3000) {
            FUN_00035204((uint)(byte)puVar4[0xc],2);
            return;
          }
        }
        else if (bVar1 == 3) {
          pGVar3 = __get_dashboard_state();
          uVar5 = sync_to_slave((char *)pGVar3,0xb,(undefined4 *)(puVar4 + 8),4);
          if ((int)uVar5 < 3000) {
            FUN_00035204((uint)(byte)puVar4[0xc],4);
            confirm_message(*(int *)(puVar4 + 8));
            DAT_20019a66 = bVar2 & 4;
          }
        }
      }
      else if (DAT_20019a6d == '\0') {
        if (puVar4[0xd] == '\0') {
          DAT_20019a66 = 1;
          pGVar3 = __get_dashboard_state();
          FUN_000294d0((int)pGVar3,0xc,puVar4,0xda);
          DAT_20019a50 = '\0';
        }
        else if (puVar4[0xd] == '\x02') {
          DAT_20019a50 = DAT_20019a50 + 1;
          if (DAT_20019a50 < 10) {
            pGVar3 = __get_dashboard_state();
            FUN_000294d0((int)pGVar3,0xd,puVar4 + 0xda,0xda);
            return;
          }
          DAT_20019a50 = DAT_20019a6d;
          FUN_00035204((uint)(byte)puVar4[0xc],0);
          DAT_20019a66 = 0;
        }
      }
    }
  }
  return;
}


