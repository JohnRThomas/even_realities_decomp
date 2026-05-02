/*
 * Function: rpmsg_deinit_vdev
 * Entry:    000893a6
 * Prototype: undefined __stdcall rpmsg_deinit_vdev(int * param_1)
 */


/* Library Function - Single Match
    rpmsg_deinit_vdev
   
   Libraries: application fake_app 2.5.1, network hci_rpmsg 2.5.1 */

void rpmsg_deinit_vdev(int *param_1)

{
  if (param_1 != (int *)0x0) {
    while (param_1 != (int *)*param_1) {
      rpmsg_destroy_ept((rpmsg_endpoint *)((int *)*param_1 + -0xd));
    }
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
  }
  return;
}


