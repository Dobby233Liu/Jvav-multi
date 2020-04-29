int str2int(const string &str) { // unsafe
	stringstream ss(str);
	int num;
	if((ss >> num).fail()) num = -1001;
	return num;
}
int check_version(string endpoint = VERSION_API){ // logic based on a decompiled version of upgrade.jar
    auto r = cpr::Get(cpr::Url{(string)VERSION_API+(string)"/version.txt"});
    int ret = str2int(r.header["content-length"]);
	// this is complex
	// if r has error (code > 0 || code < 0), return with -code
	// else if server says in the http status smth gone wrong return -1002
	if((bool)r.error/**acrooding to src code, should run code != OK**/) {ret = -(int)r.error.code/*enum should convert to int*/;}
	else if (r.status_code<200||r.status_code>299||ret<0) {ret = -1002;}
	return ret;
}