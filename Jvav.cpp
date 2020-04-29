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
int main()
{
    string language = "English";
	string command, type, inputcharacter;
    #include "init_repl.cpp"
	while(true){
		cout << "Jvav > ";
		cin >> command;
		if (command == ".help") {
			#include "commands/repl/help.cpp"
		}
		else if (command == ".exit") {
			break;
		}
		else if (command == "output") {
			#include "commands/output.cpp" // echo
		}
		else if (command == ".ver") {
			#include "commands/repl/version.cpp"
		}
		else if (command == "input") {
			#include "commands/input.cpp"
		}
		else if (command == ".upgrade") {
			#include "commands/repl/upgrade.cpp"
		}
		else if (command == ".language") {
			#include "commands/repl/switch_language.cpp"
		}
		else {
			#include "commands/default.cpp"
		}
	}
	return 0;
}