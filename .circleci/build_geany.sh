#
# SPDX-FileCopyrightText: (c) 2023 Robert Di Pardo
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Permitted usage is detailed in the COPYING file.
#
# https://circleci.com/docs/2.0/orbs-best-practices/#check-for-root
if [[ $EUID == 0 ]]; then export SUDO=''; else export SUDO='sudo'; fi
$SUDO apt update && $SUDO apt install -qqy --no-install-recommends \
    build-essential \
    autopoint \
    ccache \
    gettext \
    intltool \
    libtool \
    libgtk-3-dev
NOCONFIGURE=1 ./autogen.sh
mkdir -p _build && cd _build
CFLAGS='-g -O0' \
../configure --prefix=/usr \
    --disable-html-docs \
    --disable-pdf-docs \
    --disable-api-docs \
    --disable-gtkdoc-header \
    --enable-binreloc=no
make -j4 && $SUDO make install && $SUDO ldconfig
