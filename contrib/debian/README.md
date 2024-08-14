
Debian
====================
This directory contains files used to package blocx_testnetd/blocx_testnet-qt
for Debian-based Linux systems. If you compile blocx_testnetd/blocx_testnet-qt yourself, there are some useful files here.

## blocx_testnet: URI support ##


blocx_testnet-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install blocx_testnet-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your blocx_testnet-qt binary to `/usr/bin`
and the `../../share/pixmaps/blocx_testnet128.png` to `/usr/share/pixmaps`

blocx_testnet-qt.protocol (KDE)

