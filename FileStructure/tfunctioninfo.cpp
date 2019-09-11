#include "tfunctioninfo.h"

TFunctionInfo::TFunctionInfo(const std::wstring inFunctionName) :
    name_(inFunctionName)
{

}

TFunctionInfo::TFunctionInfo(const TFunctionInfo &other) :
    name_(other.name_)
{

}

void TFunctionInfo::setName(const std::wstring inName)
{
    name_ = inName;
}

std::wstring TFunctionInfo::name() const
{
    return name_;
}

bool TFunctionInfo::isValid() const
{
    return name_.size() != 0;
}

bool TFunctionInfo::operator<(const TFunctionInfo &other) const
{
    return name_ < other.name_;
}

bool TFunctionInfo::operator>(const TFunctionInfo &other) const
{
    return  name_ > other.name_;
}

bool TFunctionInfo::operator==(const TFunctionInfo &other) const
{
    return name_ == other.name_;
}
