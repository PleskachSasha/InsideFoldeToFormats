#include <iostream>
#include <filesystem>
#include <exception>
#include <windows.h>

#include "DirectoryObject.h"
#include "ICreator.h"
#include "IPrinter.h"
#include "JSONCreator.h"
#include "JSONPrinter.h"
#include "TXTCreator.h"
#include "TXTPrinter.h"
#include "boost/property_tree/json_parser.hpp"


void ClientCode(const ICreator& creator, std::vector<DirectoryObjects> directoryObjects) {
    creator.CreateAndMakeReport(directoryObjects);
}

enum Formats
{
    AllAvailableFormats = 0,
    TXT = 1,
    JSON = 2,
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    std::cout << "Enter path: ";
    std::string pathstring;
    getline(std::cin, pathstring);
    std::filesystem::path path(pathstring);

    try
    {
        TXTCreator TXTObject;
        JSONCreator JSONObject;

        if (std::filesystem::exists(path)) {

            int format;
            std::cout << "Chouse what format do you want: \n\t0. All available formats\n\t1. txt\n\t2. json\n\t";
            std::cin >> format;

            switch (format)
            {
            case AllAvailableFormats:
                ClientCode(TXTObject, TakeObjectInformation(pathstring));
                ClientCode(JSONObject, TakeObjectInformation(pathstring));
                break;
            case TXT:
                ClientCode(TXTObject, TakeObjectInformation(pathstring));
                break;
            case JSON:
                ClientCode(JSONObject, TakeObjectInformation(pathstring));
                break;
            default:
                std::cout << "You have chosen the wrong format";
                break;
            }
            
        }
        else {
            throw std::runtime_error("path not exist");
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }    
    catch (...) {
        std::cout << "You have exception" << '\n';
    }
}
