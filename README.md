# Picat-win32
Picat for Windows (no dependencies, C11 support)

/!\ WIP AS OF 190617

This repository holds the original picat-lang (2.6#2, March 3, 2019) found at http://picat-lang.org/download.html

The aim is to agressively update the source code in order to :
- Make it compile on Windows with no dependencies (no Cygwin, no Msys)
- Use a free and lightweight C11 compiler such as Pelles C 9.0
- C11 support (function prototype format, structure initialization, ...)
- Remove all those GOTO (seriously, even though it's generated code...)
- Reformat the source code (remove the FF, get something homogeneous)
- Add more modules and compilers ( https://github.com/slhGit/Picat )
- Use makeit as make engine (https://github.com/Kochise/makeit )

Currently there are several limitations, mostly due to __stdcall vs. __cdecl from JNI inclusion.

Future will be OpenGL support for a self hosted IDE/debugger.
Further will be network support for process distribution.

But right now, let's clean a bit this project :)

Some include files from https://github.com/pilight/windows-cli/tree/master/include and https://github.com/schanur/libplatform/tree/master/src/platform

