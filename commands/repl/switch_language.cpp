string _bak_language = language;
cout << get_language(language, "CHOOSE_LANG", command);
cin >> language;
if (language == "SChinese") { // shortcut
	language = "简体中文";
}
if (language != "English" && language != "简体中文") {
	language = _bak_language;
	cout << get_language(language, "INVAILD_LANG", command);
}