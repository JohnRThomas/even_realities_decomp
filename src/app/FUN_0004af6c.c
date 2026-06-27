/*
 * Function: FUN_0004af6c
 * Entry:    0004af6c
 * Prototype: undefined __stdcall FUN_0004af6c(int param_1, uint param_2, undefined4 param_3, uint param_4)
 */


void FUN_0004af6c(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  jdb_panel_context *pjVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_1c;
  
  local_1c = param_4 & 0xffffff00;
  uVar4 = param_2;
  pjVar1 = get_jdb_panel_context();
  iVar3 = pjVar1->__frame_buffers;
  iVar2 = (param_2 & 0x1ff) << 10;
  *(undefined1 *)(iVar3 + -5) = 2;
  *(byte *)(iVar3 + -3) = (byte)((uint)(param_1 << 0x16) >> 0x1e) | (byte)((uint)iVar2 >> 8);
  *(char *)(iVar3 + -4) = (char)((uint)iVar2 >> 0x10);
  *(char *)(iVar3 + -2) = (char)param_1;
  *(undefined1 *)(iVar3 + -1) = 0xff;
  __lock_lcd_mutex(-1);
  (**(code **)(pjVar1->field849_0x378 + 8))
            (pjVar1->field849_0x378,iVar3 + -5,param_4 + 6,&local_1c,1,uVar4,param_3);
  __unlock_lcd_mutex();
  return;
}


