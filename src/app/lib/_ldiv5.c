/*
 * Function: _ldiv5
 * Entry:    000819f8
 * Prototype: void __stdcall _ldiv5(uint64_t * v)
 */


/* exclude_from_export_ai */

void _ldiv5(uint64_t *v)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = (ulonglong)(uint)*v * 0x33333333;
  lVar2 = (ulonglong)*(uint *)((int)v + 4) * 0x33333333;
  lVar3 = lVar1 + lVar2;
  *v = lVar2 + (ulonglong)
               ((int)((ulonglong)lVar3 >> 0x20) +
               (uint)CARRY4((uint)lVar3,
                            (uint)(&DAT_33333333 +
                                  (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xcccccccc < (uint)lVar1)
                                  )));
  return;
}


