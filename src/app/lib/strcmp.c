/*
 * Function: strcmp
 * Entry:    0000eefe
 * Prototype: int __stdcall strcmp(char * s1, char * s2)
 */


/* exclude_from_export */

int strcmp(char *s1,char *s2)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = (uint)(byte)*s1;
    bVar1 = *s2;
    bVar3 = uVar2 == 1;
    if (uVar2 != 0) {
      bVar3 = uVar2 == bVar1;
    }
    s1 = s1 + 1;
    s2 = s2 + 1;
  } while (bVar3);
  return uVar2 - bVar1;
}


