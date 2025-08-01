(*********************************************************************
  Free Pascal bindings for Geany 2.0

  Copyright (C) 2023,2025 Robert Di Pardo

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
*********************************************************************)
unit geanyplugin247;

interface

uses
  ctypes, lazglib2, lazgobject2, lazgio2, lazgdk3, lazgtk3;

const
  FPGEANY_API_VERSION = 247;
  FPGEANY_ABI_VERSION = (73 shl 8);

{$ifdef MsWindows}
  {$I 'mingw/2.0.0/geanybindings.inc'}
{$else}
  {$I 'gcc/2.0.0/geanybindings.inc'}
{$endif}
{$I 'sci_537_messages.inc'}

implementation
end.
