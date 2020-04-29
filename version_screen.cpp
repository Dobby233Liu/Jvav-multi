void version_screen(string language, int intro = TRUE){
	cout << "--------------------------------------------\n";
    cout << "| Jvav REPL              Runtime "+RUNTIME_VERSION+" |\n";
    cout << "| By Dr. HaoYang Zhang         REPL "+REPL_VERSION+" |\n";
    cout << "| programmed by "+AUTHOR+"                      |\n";
if (intro){ // srry for the indent. it was intended
	cout << "| Type '.help' to get info                 |\n";
	cout << "| WHAT'S NEW:                              |\n";
	cout << "| Better i18n for REPL; 10888              |\n";
	cout << "|                     multiplatform port   |\n";
}
    cout << "--------------------------------------------\n";
}