#include "tbriefcppfilder.h"
#include "tkeywords.h"
#include "advancedstringfunctions.h"

/*!
 * \brief TBriefCppFilder::TBriefCppFilder конструктор класса
 * \param inPathToFile путь до cpp файла
 */
TBriefCppFilder::TBriefCppFilder(const std::wstring inPathToFile)
{
    path_ = inPathToFile;
    data_ = std::make_shared<CppData>();
}

/*!
 * \brief TBriefCppFilder::calculate возвращает структуру классов с функциями и их комментариями
 * \return структура классов с функциями и их комментариями
 */
std::shared_ptr<CppData> TBriefCppFilder::calculate()
{
    readFile();
    return data_;
}

void TBriefCppFilder::readFile()
{
    try {
        std::wifstream stream( std::string(path_.begin(), path_.end()) );
        stream.imbue(std::locale("ru_RU.UTF-8"));

        std::wstring line;
        while( std::getline(stream, line) )
        {
            parseLine(line);
        }

        stream.close();
    }
    catch (...)
    {

    }
}
/*!
 * \brief TBriefCppFilder::parseLine парсит строку, и если в ней есть комментарий к функции - добавляет в data_
 * \param inLine строка
 */
void TBriefCppFilder::parseLine(const std::wstring inLine)
{
    // * \brief TBriefCppFilder::parseLine парсит строку, и если в ней есть комментарий к функции - добавляет в data_
    //    ^ - briefPos
    size_t briefPos = inLine.find(Keywords::brief);
    if(briefPos != std::wstring::npos)
    {
        // * \brief TBriefCppFilder::parseLine парсит строку, и если в ней есть комментарий к функции - добавляет в data_
        //         ^ - spaceAndClassPos
        size_t spaceAndClassPos = inLine.find(L' ', briefPos);
        if(spaceAndClassPos != std::wstring::npos)
        {
            // * \brief TBriefCppFilder::parseLine парсит строку, и если в ней есть комментарий к функции - добавляет в data_
            //                         ^ - firstColonPos
            size_t firstColonPos = inLine.find(L"::", spaceAndClassPos);
            if(firstColonPos != std::wstring::npos)
            {
                std::wstring className = inLine.substr(spaceAndClassPos + 1, firstColonPos - (spaceAndClassPos + 1));
                // * \brief TBriefCppFilder::parseLine парсит строку, и если в ней есть комментарий к функции - добавляет в data_
                //                                    ^
                size_t spaceAfterFunctionPos = inLine.find(L' ', firstColonPos + 2);
                if(spaceAfterFunctionPos != std::wstring::npos)
                {
                    std::wstring functionName = inLine.substr(firstColonPos + 2, spaceAfterFunctionPos - (firstColonPos + 2));

                    std::wstring comment = inLine.substr(spaceAfterFunctionPos + 1);

                    //Теперь проверяю, нет ли комментирования этой строки, так как возможнен случай, как с этим методом, когда строка с брифом
                    //Находится уже в комментарии и ее не надо обрабатывать
                    size_t doubleSlashPos = inLine.substr(0, spaceAfterFunctionPos).find(L"//");
                    if(doubleSlashPos == std::wstring::npos && data_) //Если комментариев не обнаружено
                    {
//                        auto it = data_->find(className);
//                        if(it != data_->end())
//                            (*it).second
                    }
                }
            }
        }

    }
}
