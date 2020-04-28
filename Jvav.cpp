/*
    @description Jvav REPL Multiplatform
	@version 20w06a Snapshot
    @author 30266 / Dobby233Liu
    @time 2020-04-16 21:00
*/
#include <stdlib.h> // FIXME
#include <stdio.h>
#include <string>
#include <iostream>
#include <cpr/cpr.h>
using namespace std; // FIXME end
#define REPL_VERSION (string)"20w06a"
#define RUNTIME_VERSION (string)"1.2.10889"
#define VERSION_API "https://30266-Official.github.io/updates" // no trailing slash
int str2int(const string &str) { // unsafe
	stringstream ss(str);
	int num;
	if((ss >> num).fail()) num = -1;
	return num;
}
int check_version(string endpoint = VERSION_API){
    auto r = cpr::Get(cpr::Url{(string)VERSION_API+(string)"/version.txt"});
    int ret = str2int(r.header["content-length"]);
	if(r.status_code<200||r.status_code>299||ret<0) ret = 0;
	return ret;
}
string get_string_not_found_replacement(string language, string tag){
	return (language=="简体中文"?"<字符串不存在：":"<string not found: ")+tag+">";
}
string get_language(string language, string tag, string command = "<parser>"){//std::string
	return "Jvav > "+command+" > "+get_string_not_found_replacement(language, tag);
}
string get_language_noncommand(string language, string tag){//std::string
	if (tag == "REPL_INIT"){
		return (string)(language=="简体中文"?"REPL 正在初始化":"Initializing REPL")+(string)"...\n";
	}
	if (tag == "UPDATE_SERVICE_INIT"){
		return (string)(language=="简体中文"?"配置在线更新服务中":"Configuring update service")+(string)"...\n";
	}
	return get_string_not_found_replacement(language, tag);
}
int main()
{
    string language;
    language = "English";
    cout << get_language_noncommand(language, "REPL_INIT");
    string command, type, inputcharacter;
    cout << get_language_noncommand(language, "UPDATE_SERVICE_INIT");
    cout << "--------------------------------------------\n";
    cout << "| Jvav REPL              Runtime "+RUNTIME_VERSION+" |\n";
    cout << "| By Dr. HaoYang Zhang       REPL "+REPL_VERSION+" |\n";
    cout << "| Type 'help' to get info                  |\n";
    cout << "| WHAT'S NEW:                              |\n";
	cout << "| Better i18n for REPL; 10888              |\n";
	cout << "|                     multiplatform port   |\n";
    cout << "--------------------------------------------\n";
	while(true){
		cout << "Jvav > ";
		cin >> command;
		if (command == "help") {
			cout << "----help------Page(1/1)---\n";
			cout << "  help [page]: Get help\n  exit: Exit REPL\n  output: Output characters\n  input: Input characters\n  upgrade: Check-out updates\n  language: Language selector\n  ver: REPL version and info\n";
			cout << "----help------Page(1/1)---\n";
		}
		else if (command == "exit") {
			cout << "Are you sure: exit the REPL? (y/n) ";
			string L;
			cin >> L;
			if (L == "y") {
				return 0;
			}
		}
		else if (command == "output") {
			cout << "Jvav > output > ";
			cin >> type;
			cout << type << endl;
		}
		else if (command == "info") {
			cout << "Jvav REPL "+REPL_VERSION+"\nIt's just a joke, but we still made it. This joke was originally brought by Zhang Haoyang.\nThis version supports running without JDK.\nProgram written by 30266.\n";
		}
		else if (command == "input") {
			cout << "Jvav > input > ";
			cin >> inputcharacter;
		}
		else if (command == "upgrade") {
			cout << "Jvav > upgrade > Getting version list...\n";
			int ret = check_version();
			if (ret == -1) {
				cout << "Jvav > upgrade > Error! Version list cannot be obtained on the authentication server!\n";
			}
			else if (ret > 6) {
				if (language == "English") {
					cout << "Jvav > upgrade > Update available, please go to https://30266-official.github.io/updates/Jvav.zip to download.\n";
				}
				else if (language == "简体中文") {
					cout << "Jvav > upgrade > 有更新版本可供升级，请前往 https://30266-official.github.io/updates/Jvav.zip 下载！\n";
				}
			}
			else if (ret == 6) {
				cout << "Jvav > upgrade > Congratulations! You've upgraded to the latest version!\n";
			}
			else {
				cout << "Jvav > upgrade > Error! We can't get a version list because your version is a future version, which we don't support.\n";
			}
		}
		else if (command == "language") {
			cout << "Jvav > language > Enter language you want to select (English/简体中文):";
			cin >> language;
			if (language != "English" && language != "简体中文") {
				cout << "Jvav > language > Unknown language.\n";
			}
		}
		else {
			cout << "Jvav > <parser> > Unknown command.\n";
		}
	}
}