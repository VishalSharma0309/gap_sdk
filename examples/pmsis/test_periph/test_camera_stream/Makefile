APP = test
APP_SRCS += test.c
APP_CFLAGS += -O3 -g

override config_args += --config-opt=camera/image-stream=$(CURDIR)/frame_%d.pgm
override config_args += --config-opt=runner/peripherals=true

include $(RULES_DIR)/pmsis_rules.mk
