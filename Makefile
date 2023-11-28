#
# Builds the fpgeanyplugin package and sample project.
#
# SPDX-FileCopyrightText: (c) 2023 Robert Di Pardo
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Permitted usage is detailed in the COPYING file.
#
.PHONY: all clean deps plugin clean-deps geany-deps

PACKAGE = fpgeanyplugin
GEANY_VERSION_TAG ?= 2.0.0

PPC ?= /usr/bin/ppcx64
PPCFLAGS = -MObjFPC
DEFINES = -dLCL -dLCLgtk3
VERBOSITY = -l -vewnibq -vm5023
BUILD_MODE = Release

ifdef DEBUG
	PPCFLAGS += -Scagi -CirotR -O1 -g -gl -gh -Xg -gt
	BUILD_MODE = Debug
else
	PPCFLAGS += -Scgi -O3 -Xs -XX
endif

ifdef SEARCH_PATHS
	VERBOSITY += -vt
endif

ifdef LOGGING
	VERBOSITY += -vv
endif

ifdef QUIET
	VERBOSITY = -v0
endif

OUT_DIR = $(shell $(PPC) -iTP)-$(shell $(PPC) -iTO)/$(BUILD_MODE)
PPCFLAGS += -FE./lib/$(OUT_DIR) -Fi./lib/$(OUT_DIR) -Fu./lib/$(OUT_DIR) -Fu./src @gtk3.cfg

all: plugin

$(PACKAGE): deps lib/$(OUT_DIR)
	$(PPC) $(PPCFLAGS) $(DEFINES) $(VERBOSITY) $(PACKAGE).pas

plugin: $(PACKAGE) example/bin/$(OUT_DIR)
	$(PPC) $(PPCFLAGS) -FU./example/bin/$(OUT_DIR) $(DEFINES) $(VERBOSITY) \
	-o./example/bin/$(OUT_DIR)/$(PACKAGE)demo.$(if $(findstring Win,$(OS)),dll -WR,so -Cg) \
	example/$(PACKAGE)demo.lpr

deps:
	@./scripts/build_gtk3_widgets $(BUILD_MODE)

geany-deps:
	@./scripts/parse_headers $(GEANY_VERSION_TAG)

clean-deps:
	git clean -dxf src

clean:
	-rm -rf lib/$(OUT_DIR)/* example/bin/$(OUT_DIR)/*

lib/$(OUT_DIR):
	@mkdir -p $@

example/bin/$(OUT_DIR):
	@mkdir -p $@
