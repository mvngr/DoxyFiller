#include "advancedstringfunctions.h"
#include <algorithm>

using namespace StringFunctions;

std::wstring clearSpaces(const std::wstring inString)
{
    std::wstring resultString;
    std::remove_copy(inString.begin(), inString.end(), std::back_inserter(resultString), L' ');
    return resultString;
}
