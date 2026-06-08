/*
 * Function: ?_parse_message_type
 * Entry:    00035ed8
 * Prototype: undefined4 __stdcall ?_parse_message_type(int param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 __parse_message_type(int param_1)

{
  int iVar1;
  GlassesState *pGVar2;
  undefined4 uVar3;
  size_t sVar4;
  char *s2;
  char *pcVar5;
  
  s2 = &DAT_2000879c + param_1 * 0x1b4;
  iVar1 = strncmp("com.android.phone_missed",s2,0x18);
  if ((iVar1 == 0) || (iVar1 = strncmp("com.apple.mobilephone_missed",s2,0x1c), iVar1 == 0)) {
    uVar3 = 1;
  }
  else {
    iVar1 = strncmp("com.android.phone_incall",s2,0x18);
    if ((iVar1 == 0) || (iVar1 = strncmp("com.apple.mobilephone",s2,0x15), iVar1 == 0)) {
      uVar3 = 2;
    }
    else {
      iVar1 = strncmp("com.apple.MobileSMS",s2,0x13);
      uVar3 = 0;
      if (iVar1 != 0) {
        iVar1 = strncmp("com.android.even_sms",s2,0x14);
        uVar3 = 0;
        if (iVar1 != 0) {
          pGVar2 = __get_dashboard_state();
          pcVar5 = &DAT_20003175;
          if (pGVar2->field2791_0x1080[0] != 0) {
            pcVar5 = &DAT_200032b5;
          }
          for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 0x20) {
            sVar4 = strlen(pcVar5);
            sVar4 = sVar4 & 0xff;
            if (0x1e < sVar4) {
              sVar4 = 0x1f;
            }
            iVar1 = strncmp(pcVar5,s2,sVar4);
            if (iVar1 == 0) {
              return 3;
            }
          }
          pGVar2 = __get_dashboard_state();
          pcVar5 = &DAT_20003055;
          if (pGVar2->field2791_0x1080[0] != 0) {
            pcVar5 = &DAT_200030f5;
          }
          for (; *pcVar5 != '\0'; pcVar5 = pcVar5 + 0x20) {
            sVar4 = strlen(pcVar5);
            sVar4 = sVar4 & 0xff;
            if (0x1e < sVar4) {
              sVar4 = 0x1f;
            }
            iVar1 = strncmp(pcVar5,s2,sVar4);
            if (iVar1 == 0) {
              return 4;
            }
          }
          uVar3 = 5;
        }
      }
    }
  }
  return uVar3;
}


