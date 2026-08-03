/*
 * Function: smp_transport_init
 * Entry:    000559a0
 * Prototype: int __stdcall smp_transport_init(smp_transport * smpt)
 */


/* exclude_from_export */

int smp_transport_init(smp_transport *smpt)

{
  char *test;
  char *file;
  int line;
  
  if (smpt[2].work == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(smpt->functions.output != ((void *)0))",
            "WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/transport/src/smp.c",146);
    _ASSERT("\tRequired transport output function pointer cannot be NULL\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  smp_reassembly_init(smpt);
  k_work_init((k_work *)smpt,(void *)0x8426d);
  k_queue_init((k_queue *)&smpt->expected);
  return 0;
}


