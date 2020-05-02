/*
    @description Jvav REPL Multiplatform // tokenizer, entrypoint
	@version 20w06a Snapshot
    @author 30266 / Dobby233Liu
    @time 2020-04-29 11:10
*/
#include "entrypoint_libraries.hpp"
#include "macros.hpp"
#include "check_version.cpp"
#include "i18n.cpp"
#include "libchoice.cpp"
#include "version_screen.cpp"
#include "upgrade_check_friendly.cpp"
#include "unisleep.cpp"
#include "trans4switch.cpp"
int main()
{
    #include "init_repl.cpp"
	#include "repl_main.cpp"
	return 0;
}