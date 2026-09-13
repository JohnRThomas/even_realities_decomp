cur_dir := $(dir $(lastword $(MAKEFILE_LIST)))

obj-y := $(patsubst $(cur_dir)%,%,$(wildcard $(cur_dir)*.c $(cur_dir)*.cpp $(cur_dir)*.S))
obj-y := $(obj-y:.c=.o)
obj-y := $(obj-y:.cpp=.o)
obj-y := $(obj-y:.S=.o)

ccflags-y += -Iplatform/hal
ccflags-y += -Iapps/common
ccflags-y += -Iutils/hwtimer_list
ccflags-y += -Iutils/cqueue
ccflags-y += -Iapps/key
ccflags-y += -Iapps/common
ccflags-y += -Iapps/utils
ccflags-y += -Iservices/bt_if_enhanced/inc/
ccflags-y += -Iservices/bt_app
ccflags-y += -Iservices/multimedia/audio/codec/sbc/inc/
ccflags-y += -Iservices/ble_stack_v2/modules/rwip/api/
ccflags-y += -Iservices/ble_stack_v2/ip/ble/hl/inc
ccflags-y += -Iservices/ble_stack_v2/modules/ke/api
ccflags-y += -Iservices/ble_stack_v2/modules/common/api/
ccflags-y += -Iplatform/hal/best1501/
