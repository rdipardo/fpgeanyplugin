# Source: https://www.msys2.org/docs/ci/#docker
#
# SPDX-FileCopyrightText: (c) Christoph Reiter <https://github.com/lazka> et al.
# SPDX-License-Identifier: CC-BY-SA-4.0 OR CC0-1.0
#
if ((Test-Path 'C:\msys64')) { exit 0 }
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12;
Invoke-WebRequest -UseBasicParsing -uri 'https://github.com/msys2/msys2-installer/releases/download/nightly-x86_64/msys2-base-x86_64-latest.sfx.exe' -OutFile msys2.exe;
.\msys2.exe -y -oC:\;;
Remove-Item msys2.exe;
function msys() { C:\msys64\usr\bin\bash.exe @('-lc') + @Args; }
msys ' ';
msys 'pacman --noconfirm -Syuu';
msys 'pacman --noconfirm -Syuu';
msys 'pacman --noconfirm -Scc';
msys 'pacman --noconfirm -Syuu \
  git-core \
  intltool \
  base-devel \
  gettext \
  mingw-w64-x86_64-gcc \
  mingw-w64-x86_64-autotools \
  mingw-w64-x86_64-ccache \
  mingw-w64-x86_64-libtool \
  mingw-w64-x86_64-gtk3';
