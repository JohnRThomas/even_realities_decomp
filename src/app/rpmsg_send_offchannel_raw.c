/*
 * Function: rpmsg_send_offchannel_raw
 * Entry:    000741c4
 * Prototype: undefined4 __stdcall rpmsg_send_offchannel_raw(int param_1, undefined4 param_2, int param_3, int param_4, int param_5)
 */


/* Library Function - Single Match
    rpmsg_send_offchannel_raw
   
   Libraries: application fake_app 2.5.1, network hci_rpmsg 2.5.1 */

undefined4
rpmsg_send_offchannel_raw(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) && (param_4 != 0)) &&
     (((param_3 != -1 && (-1 < param_5)) &&
      (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0x20) + 0x78),
      UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x000741e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xfffff82d;
}


