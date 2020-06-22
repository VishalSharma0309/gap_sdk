# User Test
#------------------------------------

APP              = test
APP_SRCS        += spi_test.c
APP_INC         +=
APP_CFLAGS      +=

ifeq ($(ASYNC), 1)
APP_CFLAGS      += -DASYNC=1
endif

include $(GAP_SDK_HOME)/tools/rules/pmsis_rules.mk