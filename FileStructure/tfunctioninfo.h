#ifndef TFUNCTIONINFO_H
#define TFUNCTIONINFO_H

#include <string>

class TFunctionInfo
{
public:
    TFunctionInfo(const std::wstring inFunctionName);
    TFunctionInfo(const TFunctionInfo &other);

    void setName(const std::wstring inName);

    std::wstring name() const;

    bool operator < (const TFunctionInfo &other) const;
    bool operator > (const TFunctionInfo &other) const;
    bool operator == (const TFunctionInfo &other) const;

private:
    std::wstring name_;
};

#endif // TFUNCTIONINFO_H
