#ifndef STEPMANIA_STRINGUTIL_H
#define STEPMANIA_STRINGUTIL_H

#include <string>

namespace StringUtil
{
	bool StartsWith(const std::string &s, const std::string &prefix);
	bool StartsWith(const std::string &s, char targetChar);
	bool EndsWith(const std::string &s, const std::string &suffix);
	bool EndsWith(const std::string &s, char targetChar);
	int CompareNoCase(const std::string &s, const std::string &sOther);
	void MakeUpper(std::string &s);
	void MakeLower(std::string &s);
	int Replace(std::string &s, char chOld, char chNew);
	int Replace(std::string &s, const std::string& sOld, const std::string& sNew);
	bool EqualsNoCase(const std::string &s, const std::string &sOther);
}

#endif //STEPMANIA_STRINGUTIL_H
