/*
 * Function: get_object_item
 * Entry:    00067724
 * Prototype: cJSON * __stdcall get_object_item(cJSON * object, char * name, cJSON_bool case_sensitive)
 */


/* exclude_from_export */

cJSON * get_object_item(cJSON *object,char *name,cJSON_bool case_sensitive)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  cJSON *pcVar6;
  uint uVar7;
  byte *pbVar8;
  
  if ((object != (cJSON *)0x0) && (name != (char *)0x0)) {
    pcVar6 = (cJSON *)object->child;
    if (case_sensitive == 0) {
      for (; pcVar6 != (cJSON *)0x0; pcVar6 = (cJSON *)pcVar6->next) {
        pcVar4 = *(char **)((int)&pcVar6->valuedouble + 4);
        if (pcVar4 != (char *)0x0) {
          if (pcVar4 == name) {
LAB_00067786:
            if (*(int *)((int)&pcVar6->valuedouble + 4) == 0) {
              return (cJSON *)0x0;
            }
            return pcVar6;
          }
          pbVar8 = (byte *)(name + -1);
          pbVar5 = (byte *)(pcVar4 + -1);
          while( true ) {
            pbVar8 = pbVar8 + 1;
            uVar2 = (uint)*pbVar8;
            pbVar5 = pbVar5 + 1;
            uVar3 = (uint)*pbVar5;
            uVar7 = uVar2;
            if (((&DAT_000f6aa2)[uVar2] & 3) == 1) {
              uVar7 = uVar2 + 0x20;
            }
            if (((&DAT_000f6aa2)[uVar3] & 3) == 1) {
              uVar3 = uVar3 + 0x20;
            }
            if (uVar7 != uVar3) break;
            if (uVar2 == 0) goto LAB_00067786;
          }
        }
      }
    }
    else {
      for (; pcVar6 != (cJSON *)0x0; pcVar6 = (cJSON *)pcVar6->next) {
        pcVar4 = *(char **)((int)&pcVar6->valuedouble + 4);
        if ((pcVar4 == (char *)0x0) || (iVar1 = strcmp(name,pcVar4), iVar1 == 0)) goto LAB_00067786;
      }
    }
  }
  return (cJSON *)0x0;
}


