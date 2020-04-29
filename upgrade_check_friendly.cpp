void upgrade_check_friendly(string language, string command){
	cout << get_language(language, "UPGRADE_REQUESTING_VERSION", command);
	int ret = check_version();
	int showVersion = FALSE;
	if (ret < 0) { // -1002: server say error, < 0 == can't obtain
		cout << get_language(language, "UPGRADE_ERROR_CURL", command);
		showVersion = TRUE; // this should be safe?
	}
	else if (ret > REPL_VERSION_ID) {
		cout << get_language(language, "UPGRADE_NEW_VERSION", command);
		cout << DL_ADDR;
		cout << get_language_noncommand(language, "UPGRADE_NEW_VERSION_SUFFIX");
		showVersion = TRUE;
	}
	else if (ret == REPL_VERSION_ID) {
		cout << get_language(language, "UPGRADE_LATEST_VERSION", command);
	}
	else if (ret < REPL_VERSION_ID && ret > -1){
		cout << get_language(language, "UPGRADE_ERROR_FUTURE", command);
		showVersion = TRUE;
	} else { // did this ended up be used?
		cout << get_language(language, "UPGRADE_ERROR_UNKNOWN", command);
		showVersion = TRUE;
	}
	if (showVersion) {
		cout << get_language_noncommand(language, "UPGRADE_ERROR_UNKNOWN_PREFIX");
		cout << ret;
		cout << get_language_noncommand(language, "UPGRADE_ERROR_UNKNOWN_PREFIX_SECONDARY");
		cout << REPL_VERSION_ID;
		cout << get_language_noncommand(language, "UPGRADE_ERROR_UNKNOWN_SUFFIX");
	}
}