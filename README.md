# Jvav-multi

###### Jvav-Windows Readme
> 注意：这是一个梗，并非真实存在的编程语言。未经TZG-official允许，禁止在其他项目上使用此代码或修改署名后重新编译分发。

*not with the CC-BY-4.0*

*license pending, I wanna submit this repo to TZG-official/Jvav#47*

###### Original README by 30266, 2020-04-16 11:00 (UTC), Engrish fixed
>It's just a joke, but we still made it. The joke was originally brought by Zhang Haoyang.
>
>Copies will comply with the CC-3.0 protocol. (Dobby233Liu: idk about this, but I upgraded the license to CC-BY-4.0)

###### real README
This is a try to make Jvav REPL have a fragmented i18n system, wonderfully split, no Chinese commands, and make upgrading JRE-less.

If you're PR-ing this into the Jvav-Windows repo, your PR probably will be rejected by TZG-Offical - the changes are too big.

The code is also, slightly, a mess (maybe messier than the 30266/TZG branch), because files are `#include`'d, thus they can merge to a messier `Jvav.cpp` after the preprocessing. Don't learn to do this.

# TODO
	* upgrade program, like in Jvav-Windows

# Building
## Linux (Ubuntu)
Bring a pack of build essentials (make, g++ is the requirement), then run `make`. Run `make install` to install Jvav to `/usr/bin`.
## Windows x-compile on Linux (Ubuntu)
**WARNING:** Jvav-multi might not work correctly on Windows, often without a right charset and curl failing to do SSL. Always use `chcp 65001`.

Also get a Windows build toolchain, ensure libcurl includes is installed \[if doing in windows, take some hacks to global libs\], make `make` run the correct CXX, then run `make`. Copy DLL(s) if needed.

# Prebuilts
There is 2 builder that builds Jvav in each commits, `build` (Linux) and `build-mingw-x86_64` (Windows, MinGW). Currently, only the Linux build will work.