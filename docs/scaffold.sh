#!/usr/bin/env bash
#
# Collect symbol declarations from all used units.
#
# SPDX-FileCopyrightText: (c) 2024 Robert Di Pardo
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Permitted usage is detailed in the COPYING file.
#
LCL_UNITS=(
  'lazglib2.pas'
  'lazgobject2.pas'
  'lazgio2.pas'
  'lazgdk3.pas'
  'lazgtk3.pas'
  'lazatk1.pas'
  'lazcairo1.pas'
  'lazpango1.pas'
  'lazgmodule2.pas'
  'lazgdkpixbuf2.pas'
  'lazharfbuzz0.pas'
)
FPGEANY_UNITS=(
  'geanyplugin.pp'
  'geanyplugin240.pp'
)
case "$1" in
  'fpgeanyplugin' )
    SRC_PATH='../src'
    UNITS=( "${FPGEANY_UNITS[@]}" )
    DEFINES=
    ;;
  'lcl' | * )
    SRC_PATH=$(./resolve_paths "$2" 2>/dev/null | tr -d '[:space:]')
    UNITS=( "${LCL_UNITS[@]}" )
    DEFINES='-dFPGEANY_DOCS'
    ;;
esac
[ ! -d "$SRC_PATH" ] && echo "Invalid unit path: '$SRC_PATH'" && exit 2
for unit in "${UNITS[@]}"; do
  echo -e "\nExtracting symbols from ${unit%%.*} ..."
  makeskel --disable-private --disable-arguments --disable-errors \
    --package="$1" --input="$DEFINES $SRC_PATH/$unit" \
    --output="$1/units/${unit%%.*}.xml" 1>/dev/null
done
