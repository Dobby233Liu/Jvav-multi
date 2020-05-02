exiting = false;
switch (switch_translator(command.c_str())){
	case switch_translator("input"): {
		#include "input.cpp"
		break;
	}
	case switch_translator("output"): {
		#include "output.cpp"
		break;
	}
	case switch_translator("void"): { // internal command, does nothing
		break;
	}
	case switch_translator(".__repl__"): { // hope you didn't believe in this
		break;
	}
	
	case switch_translator(".help"): {
		#include "repl/help.cpp"
		break;
	}

	case switch_translator(".ver"): {
		#include "repl/version.cpp"
		break;
	}
	case switch_translator(".upgrade"): {
		#include "repl/upgrade.cpp"
		break;
	}
	case switch_translator(".language"): {
		#include "repl/switch_language.cpp"
		break;
	}
	case switch_translator(".exit"): {
		exiting = true;
		break;
	}

	default: {
		#include "default.cpp"
		break;
	}
}
if (exiting) break;