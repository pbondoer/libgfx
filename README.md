# libgfx
A simple library to make miniLibX better :tada:

This is my small library for `miniLibX`. I started getting tired of reusing the
same functions in most of my projects so I built a more streamlined version that
contains my most usually used functions.

It is meant to be quite minimal and only contain the most essential functions to
be reused in multiple projects later.

## Features
* Multiple double-buffered windows
* Draw lines!

### Planned features
* Rectangles (filled and outlined)
* Circles (filled and outlined)
* Polygons (filled and outlined)

## Compiling
Make sure to edit the `Makefile` to point to
[libft](https://github.com/pbondoer/42-libft) and
[miniLibX](https://github.com/pbondoer/miniLibX). Run `make` to compile the
library.

## Demo project
There is a demo project in the `demo` folder. Feel free to mess with the code
in there. It should display how to open up more than one window, and how to draw
within windows.

## License
`libgfx` is under the GNU General Public License 3.0
