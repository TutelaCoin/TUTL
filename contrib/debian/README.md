
Debian
====================
This directory contains files used to package tutelad/tutela-qt
for Debian-based Linux systems. If you compile tutelad/tutela-qt yourself, there are some useful files here.

## tutela: URI support ##


tutela-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tutela-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tutela-qt binary to `/usr/bin`
and the `../../share/pixmaps/tutela128.png` to `/usr/share/pixmaps`

tutela-qt.protocol (KDE)

