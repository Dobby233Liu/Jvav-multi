# Jvav-multi

###### Jvav-windows Readme
> 注意：这是一个梗，并非真实存在的编程语言。未经TZG-official允许，禁止在其他项目上使用此代码或修改署名后重新编译分发。

*licensing pending*

###### Original README by 30266, 2020-04-16 11:00 (UTC)
It's just a joke, but we still made it. The joke was originally brought by Zhang Haoyang.
It's reprints comply with the CC3.0 protocol. (Dobby233Liu: upgraded to CC-4.0-BY)

This is a try to make Jvav REPL have a fragmented i18n system, wonderfully split, no Chinese commands, and make upgrading JRE-less.

If you're PR-ing this into the Jvav-windows repo, your PR probably will be rejected by TZG-Offical - the changes are too big.

# Building
## Linux (Ubuntu)
Bring a pack of build essentials (make, g++ is the requirement), then run `make`.
## Windows x-compile on Linux (Ubuntu) \[unsure. Jvav-multi might not work on Windows\]
Also get a Windows build toolchain, ensure libcurl includes is installed \[if doing in windows, take some hacks to global libs\], make `make` run the correct CXX, then run `make`. Copy DLL(s) if needed.