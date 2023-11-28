/**
 *  @file h2pas.in.h
 *  Input file for the h2pas transpiler, with additional dependencies
 *  and custom ordering to avoid forward declarations.
 */
/*
 * Copyright (C) 2023 Robert Di Pardo
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General
 * Public License along with this program. If not, see
 * <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and permission notice:
 *
 *      Copyright 2009 The Geany contributors
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef H2PAS_IN_H
#define H2PAS_IN_H

#ifndef HAVE_PLUGINS
#    define HAVE_PLUGINS
#endif

/* Scintilla */
#include "Sci_Position.h"
#include "Scintilla.h"
#include "ScintillaWidget.h"
/* Tag manager */
#include "tm_source_file.h"
#include "tm_parser.h"
#include "tm_tag.h"
#include "tm_workspace.h"
/* Geany objects */
#include "filetypes.h"
#include "editor.h"
#include "build.h"
#include "search.h"
#include "document.h"
#include "project.h"
#include "encodings.h"
#include "dialogs.h"
#include "keybindings.h"
#include "keybindingsprivate.h"
#include "highlighting.h"
#include "msgwindow.h"
#include "navqueue.h"
#include "prefs.h"
#include "sciwrappers.h"
#include "spawn.h"
#include "keyfile.h"
#include "stash.h"
#include "support.h"
#include "symbols.h"
#include "templates.h"
#include "toolbar.h"
#include "ui_utils.h"
#include "utils.h"
#include "geanyfunctions.h"
#include "geany.h"
#include "pluginutils.h"
#include "plugindata.h"
#include "app.h"

#endif /* ~H2PAS_IN_H */
