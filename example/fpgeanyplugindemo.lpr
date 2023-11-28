(*
 Copyright (C) 2023 Robert Di Pardo

 This program is free software: you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation, either version
 3 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be
 useful, but WITHOUT ANY WARRANTY; without even the implied
 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General
 Public License along with this program. If not, see
 <https://www.gnu.org/licenses/>.
*)

library fpgeanyplugindemo;

{$mode objfpc}{$macro on}

{$ifdef MsWindows}
  {TODO: Set path according to your environment}
  {$LibraryPath 'C:\Users\Rob\scoop\apps\msys2\current\mingw64\lib'}
  {$Linklib 'libgtk-3.dll.a'}
  {$Linklib 'libgdk-3.dll.a'}
  {$Linklib 'libgobject-2.0.dll.a'}
  {$Linklib 'libharfbuzz.dll.a'}
  {$AppType GUI}
  {$R *.res}
{$endif}

uses
lazglib2, lazgobject2, lazgtk3,
{$ifdef FPGEANY_LEGACY_API}
  geanyplugin240
{$else}
  geanyplugin
{$endif};

{$ifndef GETTEXT_PACKAGE}
  {$define GETTEXT_PACKAGE:=PGChar('geany-plugins')}
{$endif}

{$ifndef LOCALEDIR}
  {$ifdef Unix}
    {$define LOCALEDIR:=PGChar('/usr/share/geany/locale')}
  {$else}
    {$define LOCALEDIR:=PGChar('C:\\Program Files\\Geany\\share\\locale')}
  {$endif}
{$endif}

const
  PLUGIN_NAME = 'Free Pascal Plugin Demo';
  PLUGIN_VERSION = '1.0';
  PLUGIN_AUTHOR = 'Robert Di Pardo <dipardo.r@gmail.com>';
  PLUGIN_BLURB = 'A simple Geany plugin using Free Pascal bindings to GTK3';
  PLUGIN_MSG_TEXT = 'Hello, World!';
  PLUGIN_TB_TOOLTIP = 'Say "Hello"';
  PLUGIN_TB_ICON = {$ifdef Unix}GTK_STOCK_DIALOG_INFO{$else}'gtk3-demo'{$endif};

{%region 'GLib macro polyfill'}
{$ifdef MsWindows}
function dgettext(domain: Pgchar; msgid: Pgchar): Pgchar; cdecl; external 'libintl-8.dll' name 'dgettext';
{$endif}

function _(msgid: Pgchar): Pgchar; cdecl;
begin
  Result := {$ifdef Unix}g_dgettext{$else}dgettext{$endif}(GETTEXT_PACKAGE, msgid);
end;
{%endregion}

{%region 'Function definitions'}
function fpgeany_plugin_init(var plugin: TGeanyPlugin; {%H-}pdata: gpointer): gboolean; cdecl;
var
  toolbar_button: PGtkToolButton;

procedure on_toolbar_btn_click({%H-}widget: PGtkWidget; {%H-}pdata: gpointer); cdecl;
begin
  dialogs_show_msgbox(TGtkMessageType.GTK_MESSAGE_INFO, _(PLUGIN_MSG_TEXT));
end;

begin
  (* Create a new toolbar button *)
  toolbar_button := gtk_tool_button_new(nil, _(PLUGIN_TB_TOOLTIP));

  if not Assigned(toolbar_button) then
    Exit(False);

  gtk_tool_button_set_icon_name(toolbar_button, PLUGIN_TB_ICON);
  gtk_widget_set_tooltip_text(toolbar_button, _(PLUGIN_TB_TOOLTIP));

  (* Connect the button with click handler *)
  g_signal_connect_data(toolbar_button, 'clicked',
    TGCallback(@on_toolbar_btn_click), nil, nil, G_CONNECT_DEFAULT);

  (* Set the plugin's data pointer to the button *)
  geany_plugin_set_data(plugin, toolbar_button, nil);

  (* Show the button *)
  plugin_add_toolbar_item(plugin, toolbar_button^);
  gtk_widget_show(toolbar_button);

  Result := True;
end;

procedure fpgeany_plugin_help(var {%H-}plugin: TGeanyPlugin; {%H-}pdata: gpointer); cdecl;
begin
  utils_open_browser('https://plugins.geany.org/');
end;

procedure fpgeany_plugin_cleanup(var {%H-}plugin: TGeanyPlugin; pdata: gpointer); cdecl;
var
  toolbar_button: PGtkToolButton;
begin
  toolbar_button := PGtkToolButton(pdata);
  if Assigned(toolbar_button) then
    gtk_widget_destroy(toolbar_button);
end;
{%endregion}

{%region 'Initialization'}
procedure geany_load_module(var plugin: TGeanyPlugin); cdecl;
const
  MIN_API_VERSION = 240;
begin
  main_locale_init(LOCALEDIR, GETTEXT_PACKAGE);

  (*  Set metadata *)
  with plugin.info^ do
  begin
    name := PLUGIN_NAME;
    version := PLUGIN_VERSION;
    description := _(PLUGIN_BLURB);
    author := PLUGIN_AUTHOR;
  end;

  (* Set functions *)
  with PGeanyPluginFuncs(plugin.funcs)^ do
  begin
    init := @fpgeany_plugin_init;
    cleanup := @fpgeany_plugin_cleanup;
    help := @fpgeany_plugin_help;
    configure := nil;
    callbacks := nil;
  end;

  (* Register *)
  geany_plugin_register(plugin, FPGEANY_API_VERSION, MIN_API_VERSION, FPGEANY_ABI_VERSION);
end;
{%endregion}

exports
geany_load_module;

begin
end.
