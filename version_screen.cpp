void version_screen(string language, int intro = TRUE){
	cout << "--------------------------------------------\n";
    cout << get_language_noncommand(language, "VERSION_SCREEN_RUNTIME");
    cout << get_language_noncommand(language, "VERSION_SCREEN_HAOYANG");
    cout << get_language_noncommand(language, "VERSION_SCREEN_AUTHOR");
if (intro){ // srry for the indent. it was intended
	cout << get_language_noncommand(language, "VERSION_SCREEN_HELP");
	cout << get_language_noncommand(language, "VERSION_SCREEN_WHATS_NEW");
	cout << get_language_noncommand(language, "VERSION_SCREEN_LINE_1");
	cout << get_language_noncommand(language, "VERSION_SCREEN_LINE_2");
}
    cout << "--------------------------------------------\n";
}