PZSDK_PATH?=/opt/pzsdk.ver5.0
DEFAULT_MAKE=$(PZSDK_PATH)/make/default_pzcl_kernel.mk

PZC_TARGET_ARCH?=sc2

TARGET=kernel.pz
PZCSRC=kernel.pzc

CLANG_OPT?=-O3 -std=c++11

vpath %.pzc ../pzc

include $(DEFAULT_MAKE)
