# libgfx
A simple library to make miniLibX better :tada:

This is my small library for `miniLibX`. I started getting tired of reusing the
same functions in most of my projects so I built a more streamlined version that
compiles and works on both OS X and Linux.

It is meant to be quite minimal and only contain the most essential functions to
be reused in multiple projects later.

## Features
* Multiple double-buffered windows
* Draw basic shapes (line, rectangle), outlined or filled

## Compiling
Make sure to edit the `Makefile` to point to
[https://github.com/pbondoer/42-libft](libft) and
[https://github.com/pbondoer/miniLibX](miniLibX). Run `make` to compile against
the current OS as a target. Currently only Linux and OS X (Darwin) are
supported.

## License
`miniLibX` (c) Olivier Crouzet

`libgfx` is under the GNU General Public License 3.0
