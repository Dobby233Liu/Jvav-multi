string language = "English";
cout << get_language_noncommand(language, "REPL_INIT");
language = DEFAULT_LANGUAGE;
string command, type, inputcharacter;
bool exiting = false;
unisleep(10); // variable take short
#ifndef NO_NETWORKING
cout << get_language_noncommand(language, "UPDATE_SERVICE_INIT");
unisleep(30); // curl is big
#endif
version_screen(language);