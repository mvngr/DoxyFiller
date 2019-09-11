#include "tclassinfo.h"

#include <algorithm>

TClassInfo::TClassInfo(const std::wstring inClassName) :
    name_(inClassName),
    functions_(std::set<std::shared_ptr<TFunctionInfo>>())
{

}

TClassInfo::TClassInfo(const std::wstring inClassName, std::set<std::shared_ptr<TFunctionInfo>> inFunctions) :
    name_(inClassName),
    functions_(std::move(inFunctions))
{

}

/*!
 * \brief TClassInfo::insertFunction вставляет новую функцию в класс
 * \param inValue объект функции
 */
void TClassInfo::insertFunction(TFunctionInfo inValue)
{
    functions_.insert(std::make_shared<TFunctionInfo>(inValue));
}

/*!
 * \brief TClassInfo::findFunction найдет экземпляр функции или вернет nullptr
 * \param inName название функции, которую нужно найти
 * \return указатель на объект функции
 *
 * \warning может вернуть nullptr
 */
const std::shared_ptr<TFunctionInfo> TClassInfo::findFunction(const std::wstring inName) const
{
    const std::set<std::shared_ptr<TFunctionInfo>>::const_iterator iterator = std::find_if(functions_.cbegin(), functions_.cend(), [&inName](const std::shared_ptr<TFunctionInfo> value){
        return value && ( value->name() == inName );
    });

    return ( iterator == functions_.cend() ? nullptr : *iterator );
}
