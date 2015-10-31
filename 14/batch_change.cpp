#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
using std::string;

std::vector<string> read_directory(const string& path = string(), const string& extension = string()) {
	std::vector<string> result;
	dirent* de;
	DIR* dp;
	errno = 0;
	dp = opendir( path.empty() ? "." : path.c_str());
	if (dp) {
		while(true) {
			errno = 0;
			de = readdir(dp);
			if (de == NULL) break;
			if(std::strstr(de->d_name,extension.c_str())) result.push_back(string(de->d_name));
		}
	closedir(dp);
	std::sort(result.begin(),result.end());
	}
	return result;
}

void batch_change(string dir, std::vector<string>files, string to_change, string change) {
	for(string s : files) {
		s = dir + s;
		std::vector<string> buffer;
		std::ifstream ifs {s};
		string str;
		while(std::getline(ifs,str)) {
			if (str == to_change) {
				buffer.push_back(change);
			} 
			else buffer.push_back(str);
		}
		std::ofstream ofs {s};
		for (string x : buffer) {
			ofs << x << std::endl;
		}
	}
}

int main() {
	std::vector<string>files = read_directory("../13", ".cpp");
	batch_change("../13/", files, "#include \"Classes.h\"", "#include \"13.h\"");
}