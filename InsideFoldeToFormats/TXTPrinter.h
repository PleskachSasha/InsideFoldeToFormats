#pragma once
#include "IPrinter.h"
#include <vector>
#include <fstream>

class TXTPrinter :  public IPrinter {
public:
	void MakeReport(std::vector<DirectoryObjects> directoryObjects) override {
		std::string path = "txt_report.txt";
	
		std::ofstream file;

		try {
			file.open(path);
			if (!file.is_open())
			{
				std::cout << "Нема файла" << std::endl;
			}
			else {
				for (auto it = directoryObjects.begin(); it != directoryObjects.end(); ++it)
				{
					file << "Name: " << it->GetName() <<
						";\nRoot path: " << it->GetRootPath() <<
						";\nRelative path:" << it->GetRelativePath() <<
						";\nType:" << it->GetType() << ";\n";
					if (it->GetType() != "directory")
					{
						file << "Extension:" << it->GetExtension() << ";\n\n";
					}
					else
						file << "\n";
				}
			}
		}
		catch (const std::ifstream::failure& e) {
			std::cout << "Exception opening/reading file";
		}

		file.close();
	}
};
