string get_string_not_found_replacement(string language, string tag){
	return (language=="简体中文"?"<字符串不存在：":"<string not found: ")+tag+">";
}
string get_language_noncommand(string language, string tag){//std::string
	if (tag == "REPL_INIT") return (string)(language=="简体中文"?"REPL 正在初始化":"Initializing REPL")+(string)"...\n";
	if (tag == "UPDATE_SERVICE_INIT") return (string)(language=="简体中文"?"配置在线更新服务中":"Configuring update service")+(string)"...\n";
 	if (tag == "COLON_SPACE_CONNECTER") return (language=="简体中文"?"：":": ");
	if (tag == "UPGRADE_ERROR_UNKNOWN_PREFIX") return (language=="简体中文"?"（服务器提供版本：":"(version the server provided: ");
	if (tag == "UPGRADE_ERROR_UNKNOWN_PREFIX_SECONDARY") return (language=="简体中文"?"，你的版本：":", your version: ");
	if (tag == "UPGRADE_ERROR_UNKNOWN_SUFFIX") return (string)(language=="简体中文"?")":"）")+(string)"\n";
	if (tag == "UPGRADE_NEW_VERSION_SUFFIX") return (string)(language=="简体中文"?" 来下载。":" to download.")+(string)"\n";
	if (tag == "INFO_JOKE") {
		return (string)(language=="简体中文"?
		"\n这只是个笑话，但我们仍做了一个 REPL。笑话来源为张浩扬。"
		:"\nIt's just a joke, but we still made it. This joke was originally brought by Zhang Haoyang.");
	}
	if (tag == "INFO_NO_JDK") {
		return (string)(language=="简体中文"?
		"\n该版本支持脱离 JDK 运行。\n"
		:"\nThis version supports running without JDK.\n");
	}
	if (tag == "COMMAND_SHORT_HELP_REPL_HELP"){
		return (string)(language=="简体中文"?"获取帮助":"Get help");
	}
	if (tag == "COMMAND_SHORT_HELP_REPL_EXIT"){
		return (string)(language=="简体中文"?"退出 REPL":"Exit REPL");
	}
	if (tag == "COMMAND_SHORT_HELP_REPL_UPGRADE"){
		return (string)(language=="简体中文"?"检查更新":"Check-out updates");
	}
	if (tag == "COMMAND_SHORT_HELP_REPL_LANGUAGE"){
		return (string)(language=="简体中文"?"选择 REPL 语言":"Select REPL language");
	}
	if (tag == "COMMAND_SHORT_HELP_REPL_VERSION"){
		return (string)(language=="简体中文"?"REPL 的版本和信息":"REPL version and info");
	}
	if (tag == "COMMAND_SHORT_HELP_OUTPUT"){
		return (string)(language=="简体中文"?"输出字符串":"Output a string");
	}
	if (tag == "COMMAND_SHORT_HELP_INPUT"){
		return (string)(language=="简体中文"?"输入字符串":"Input a string");
	}
	if (tag == "VERSION_SCREEN_RUNTIME"){
		return (string)(language=="简体中文"?
		"| Jvav REPL               运行时 "+RUNTIME_VERSION+" |\n":
		"| Jvav REPL              Runtime "+RUNTIME_VERSION+" |\n");
	}
	if (tag == "VERSION_SCREEN_HAOYANG"){
		return (string)(language=="简体中文"?
		"| By 张浩扬博士                REPL 20w06a |\n":
		"| By Dr. HaoYang Zhang         REPL 20w06a |\n");
	}
	if (tag == "VERSION_SCREEN_AUTHOR"){
		return (string)(language=="简体中文"?
		"| 由 "+AUTHOR+" 编写                       |\n":
		"| programmed by "+AUTHOR+"                 |\n");
	}
	if (tag == "VERSION_SCREEN_HELP"){
		return (string)(language=="简体中文"?
		"| 输入 “.help” 以获取帮助                  |\n":
		"| Type '.help' to get help                 |\n");
	}
	if (tag == "VERSION_SCREEN_WHATS_NEW"){
		return (string)(language=="简体中文"?
		"| 新增内容：                               |\n":
		"| WHAT'S NEW:                              |\n");
	}
	if (tag == "VERSION_SCREEN_LINE_1"){
		return (string)(language=="简体中文"?
		"| REPL 更好的 i18n;     10888              |\n":
		"| Better i18n for REPL; 10888              |\n");
	}
	if (tag == "VERSION_SCREEN_LINE_2"){
		return (string)(language=="简体中文"?
		"|                             多平台移植   |\n":
		"|                     multiplatform port   |\n");
	}
/*	if (tag == "CHOICER_QMARK_ENDING") return (language=="简体中文"?"吗？":"? ");
	if (tag == "ARE_YOU_SURE") return (language=="简体中文"?"你确实要":"Are you sure you want to"); */
	return get_string_not_found_replacement(language, tag);
}
string get_language(string language, string tag, string command = "<parser>"){//std::string
	string init = "Jvav > "+command+" > ";
	string ret = get_string_not_found_replacement(language, tag);
	string ending = "\n";
	int doend = TRUE;
	if (tag == "INVAILD_COMMAND") ret = (language=="简体中文"?"未知命令。":"Unknown command.");
	if (tag == "INVAILD_LANG") ret = (language=="简体中文"?"未知语言。":"Unknown language.");
	if (tag == "UPGRADE_ERROR_FUTURE") {
		doend = FALSE;
		ret = (language=="简体中文"?
			"因为你的版本是我们不支持的未来版本，故此我们无法提供版本更新服务。"
			:"Because your version is a future version, which we don't support, so we can't provide version upgrade service. ");
	}
	if (tag == "UPGRADE_ERROR_UNKNOWN") {
		doend = FALSE;
		ret = (language=="简体中文"?
			"未知错误。"
			:"Unknown error.");
	}
	if (tag == "CHOOSE_LANG") {
		doend = FALSE;
		ret = (language=="简体中文"?"输入想要更换到的语言（English/简体中文）":"Enter language you want to select (English/简体中文)");
		ret += get_language_noncommand(language, "COLON_SPACE_CONNECTER");
	}
	if (tag == "INPUT") {
		doend = FALSE;
		ret = "";
	}
	if (tag == "UPGRADE_LATEST_VERSION") {
		doend = FALSE;
		ret = (language=="简体中文"?"恭喜，你已经更新到最新版本了！":"Congratulations! You've upgraded to the latest version!");
	}
	if (tag == "UPGRADE_NEW_VERSION"){
		doend = FALSE;
		ret = (language=="简体中文"?"有更新，请前往 ":"Update available, please go to ");
	}
	if(tag == "UPGRADE_ERROR_CURL"){
		doend = FALSE;
		ret = (language=="简体中文"?"错误：无法从身份验证服务器获取版本列表！":"Error! Version list cannot be obtained on the authentication server! ");
	}
	if (tag=="UPGRADE_REQUESTING_VERSION"){
		ret = (language=="简体中文"?"正在获取版本列表...":"Receiving version list...");
	}
	ret = init+ret;
	if (doend) ret+=ending;
	return ret;
}