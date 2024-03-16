#include "global.h"
#include <algorithm>
#include "StringUtil.h"

// -----------------------------------------------------------------------------
// sstolower/sstoupper -- convert characters to upper/lower case
// -----------------------------------------------------------------------------
/* Our strings are UTF-8; instead of having to play around with locales,
 * let's just manually toupper ASCII only.  If we really want to play with
 * Unicode cases, we can do it ourself in RageUtil. */
/**
 * @brief Turn the character into its uppercase equivalent.
 * @param ch the character to convert.
 * @return the converted character.
 */
inline char sstoupper(char ch)
{
	return (ch >= 'a' && ch <= 'z') ? char(ch + 'A' - 'a') : ch;
}

/**
 * @brief Turn the character into its lowercase equivalent.
 * @param ch the character to convert.
 * @return the converted character.
 */
inline char sstolower(char ch)
{
	return (ch >= 'A' && ch <= 'Z') ? char(ch + 'a' - 'A') : ch;
}

// -----------------------------------------------------------------------------
// ssicmp: comparison (case insensitive )
// -----------------------------------------------------------------------------
/**
 * @brief Perform a case insensitive comparison of the two strings.
 * @param pA1 the first string.
 * @param pA2 the second string.
 * @return >0 if pA1 > pA2, <0 if pA1 < pA2, or 0 otherwise.
 */
inline int ssicmp(const char* pA1, const char* pA2)
{
	char f;
	char l;

	do
	{
		f = sstolower(*(pA1++));
		l = sstolower(*(pA2++));
	} while ( (f) && (f == l) );

	return (int)(f - l);
}

// TODO: Use std::string::starts_with() as soon as we depend on C++20
bool StringUtil::StartsWith(const std::string &s, const std::string &prefix)
{
	return s.substr(0, prefix.size()) == prefix;
}

// TODO: Use std::string::ends_with() as soon as we depend on C++20
bool StringUtil::EndsWith(const std::string &s, const std::string &suffix)
{
	if (s.size() < suffix.size())
		return false;

	return s.substr(s.size() - suffix.size()) == suffix;
}

bool StringUtil::StartsWith(const std::string &s, const char targetChar)
{
	if (s.empty())
		return false;

	return s.front() == targetChar;
}

bool StringUtil::EndsWith(const std::string &s, const char targetChar)
{
	if (s.empty())
		return false;

	return s.back() == targetChar;
}

int StringUtil::CompareNoCase(const std::string &s, const std::string &sOther)
{
	return ssicmp(s.c_str(), sOther.c_str());
}

void StringUtil::MakeUpper(std::string &s)
{
	if ( !s.empty() )
	{
		for (char& i : s)
		{
			i = sstoupper(i);
		}
	}
}

void StringUtil::MakeLower(std::string &s)
{
	if ( !s.empty() )
	{
		for (char& i : s)
		{
			i = sstolower(i);
		}
	}
}

int StringUtil::Replace(std::string &s, char chOld, char chNew)
{
	int nReplaced = 0;

	for (char& i : s)
	{
		if ( i == chOld )
		{
			i = chNew;
			nReplaced++;
		}
	}

	return nReplaced;
}

int StringUtil::Replace(std::string &s, const std::string& sOld, const std::string& sNew)
{
	int nReplaced = 0;
	std::string::size_type nIdx = 0;
	std::string::size_type nOldLen = std::string::traits_type::length(sOld.c_str());

	if ( 0 == nOldLen )
		return 0;

	static const char defaultChar = char(0);
	std::string::size_type nNewLen = std::string::traits_type::length(sNew.c_str());
	std::string szRealNew = sNew.c_str() == nullptr ? &defaultChar : sNew;

	while ( (nIdx=s.find(sOld, nIdx)) != std::string::npos )
	{
		s.replace(s.begin()+nIdx, s.begin()+nIdx+nOldLen, szRealNew);
		nReplaced++;
		nIdx += nNewLen;
	}

	return nReplaced;
}

bool StringUtil::EqualsNoCase(const std::string &s, const std::string &sOther)
{
	return CompareNoCase(s, sOther) == 0;
}
