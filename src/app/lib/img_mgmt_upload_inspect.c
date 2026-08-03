/*
 * Function: img_mgmt_upload_inspect
 * Entry:    00054b54
 * Prototype: int __stdcall img_mgmt_upload_inspect(img_mgmt_upload_req * req, img_mgmt_upload_action * action)
 */


/* exclude_from_export_ai */

int img_mgmt_upload_inspect(img_mgmt_upload_req *req,img_mgmt_upload_action *action)

{
  int iVar1;
  uint uVar2;
  char *test;
  size_t n;
  char *file;
  int line;
  int *piVar3;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined4 local_38;
  char *local_34;
  img_mgmt_upload_action iStack_30;
  uint local_2c;
  flash_area *local_24;
  image_version iStack_20;
  
  memset(action,0,0x18);
  uVar2 = DAT_2000b564;
  if (req[1] == -1) {
    return 0x14;
  }
  if (req[1] == 0) {
    if ((uint)req[4] < 0x20) {
      return 0x16;
    }
    if (req[2] == -1) {
      return 0x15;
    }
    *action = req[2];
    action[1] = 0;
    piVar3 = (int *)req[3];
    if (*piVar3 != -0x690c47c3) {
      return 0x17;
    }
    n = req[6];
    if (0x20 < n) {
      return 0x18;
    }
    if ((((n != 0) && (DAT_2000b55c != -1)) && (n == DAT_2000b568)) &&
       (iVar1 = memcmp(&DAT_2000b569,(void *)req[5],n), iVar1 == 0)) {
      return 0;
    }
    iVar1 = *req;
    if (iVar1 == -1) {
      iVar1 = 0;
    }
    uVar2 = img_mgmt_active_slot(iVar1);
    if (3 < uVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","slot >= 0 && slot < (2 << 1)",
              "WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/grp/img_mgmt/include/mgmt/mcumgr/grp/img_mgmt/img_mgmt_priv.h"
              ,0x71);
      _ASSERT("\tImpossible slot number\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar1 = img_mgmt_slot_in_use(uVar2 ^ 1);
    if (iVar1 == 0) {
      iVar1 = img_mgmt_flash_area_id(uVar2 ^ 1);
      action[3] = iVar1;
      if (-1 < iVar1) {
        local_2c = flash_area_open((uint8_t)iVar1,&local_24);
        if (local_2c != 0) {
          iStack_30 = action[3];
          local_34 = "Failed to open flash area ID %u: %d";
          local_38 = 4;
          LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x2040,&local_38,4,in_stack_ffffffb8,
                  in_stack_ffffffbc,in_stack_ffffffc0);
          return 10;
        }
        if (local_24->fa_size < (uint)req[2]) {
          flash_area_close(local_24);
          iStack_30 = req[2];
          local_2c = local_24->fa_size;
          local_34 = "Upload too large for slot: %u > %u";
          local_38 = 4;
          LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x2040,&local_38,4,in_stack_ffffffb8,
                  in_stack_ffffffbc,in_stack_ffffffc0);
          return 0x1e;
        }
        flash_area_close(local_24);
        if ((char)req[7] != '\0') {
          iVar1 = img_mgmt_my_version(&iStack_20);
          if (iVar1 != 0) {
            return 0x1a;
          }
          iVar1 = img_mgmt_vercmp(&iStack_20,(image_version *)(piVar3 + 5));
          if (-1 < iVar1) {
            return 0x1b;
          }
        }
        goto LAB_00054cd0;
      }
    }
    else {
      action[3] = -1;
    }
    iVar1 = 9;
  }
  else {
    action[3] = DAT_2000b55c;
    *action = uVar2;
    action[1] = 0;
    if (req[1] == DAT_2000b560) {
      if (uVar2 < (uint)(req[1] + req[4])) {
        return 0x1f;
      }
LAB_00054cd0:
      action[2] = req[4];
      *(undefined1 *)(action + 4) = 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


