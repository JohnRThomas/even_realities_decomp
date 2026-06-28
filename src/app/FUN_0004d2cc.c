/*
 * Function: FUN_0004d2cc
 * Entry:    0004d2cc
 * Prototype: undefined __stdcall FUN_0004d2cc(uint param_1)
 */


void FUN_0004d2cc(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  __init_burial_point_date((dashboard_ts_context *)param_1,(undefined2 *)&local_24);
  uVar3 = local_24 & 0xffff;
  uVar1 = local_24 >> 0x10;
  uVar4 = local_20 & 0xffff;
  printk("date: %u: %04d/%02d/%02d-%02d:%02d:%02d\n",param_1,uVar3,uVar1,uVar4,local_20 >> 0x10,
         local_1c & 0xffff,local_1c >> 0x10);
  iVar2 = FUN_000807aa(uVar3,uVar1,uVar4);
  get_string(iVar2 + 0x3bU & 0xff);
  return;
}


