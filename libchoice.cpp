/* int choicer(string language, string question, string prefix = "[[[[[[default]]]]]]"){
	if (prefix == "[[[[[[default]]]]]]") prefix = get_language_noncommand(language, "ARE_YOU_SURE");
	cout << prefix+get_language_noncommand(language,"COLON_SPACE_CONNECTER")+question+get_language_noncommand(language, "CHOICER_QMARK_ENDING")+"(y/*) ";
	char L = getchar();
	char yesLower{'y'};
	char yesUpper{'Y'};
	if (L == yesLower || L == yesUpper) return 0;
	return 1;
} */