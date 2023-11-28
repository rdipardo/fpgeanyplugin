#!/usr/bin/sh
#
# Various Geany symbols that h2pas cannot transpile.
#
# SPDX-FileCopyrightText: (c) 2023 Robert Di Pardo
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Permitted usage is detailed in the COPYING file.
#
FEATURE_MACROS=(
  'G_BEGIN_DECLS'
  'G_END_DECLS'
  'G_GNUC_CONST'
  'G_GNUC_DEPRECATED'
  'GEANY_DEPRECATED'
  'G_GNUC_NULL_TERMINATED'
  'G_GNUC_WARN_UNUSED_RESULT'
)
FUNC_MACRO_DEFS=(
  'EMPTY'
  'GEANY_DEPRECATED_FOR'
  'NZV'
  'PLUGIN_SET_INFO'
  'PLUGIN_SET_TRANSLATABLE_INFO'
  'PLUGIN_VERSION_CHECK'
  'SETPTR'
  'documents'
  'filetypes'
  'foreach_c_array'
  'foreach_dir'
  'foreach_document'
  'foreach_list'
  'foreach_list_safe'
  'foreach_ptr_array'
  'foreach_range'
  'foreach_str'
  'setptr'
  'utils_get_setting'
)
MISC=(
  'G_GNUC_PRINTF'
  'G_DEPRECATED_FOR'
  'GEANY_DEPRECATED_FOR'
  '_FOR'
)
