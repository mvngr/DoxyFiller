#include "tclassinfo.h"

#include <algorithm>

TClassInfo::TClassInfo(const std::wstring inClassName) :
    name_(inClassName),
    functions_(std::set<TFunctionInfo>())
{

}

TClassInfo::TClassInfo(const std::wstring inClassName, std::set<TFunctionInfo> inFunctions) :
    name_(inClassName),
    functions_(std::move(inFunctions))
{

}

void TClassInfo::insertFunction(TFunctionInfo inValue)
{
    functions_.insert(std::move(inValue));
}

const TFunctionInfo &TClassInfo::findFunction(const std::wstring inName) const
{
    const std::set<TFunctionInfo>::const_iterator &iterator = std::find_if(functions_.cbegin(), functions_.cend(), [&inName](const TFunctionInfo &value){
        return value.name() == inName;
    });

    return *iterator;
}
