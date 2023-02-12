#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "IPrinter.h"
#include <vector>
#include <boost/property_tree/json_parser/detail/standard_callbacks.hpp>

class JSONPrinter : public IPrinter {
public:
	void MakeReport(std::vector<DirectoryObjects> directoryObjects) override {
		boost::property_tree::ptree root;
		for (auto it = directoryObjects.begin(); it != directoryObjects.end(); ++it)
		{
			boost::property_tree::ptree tree;
			tree.add("Root path", it->GetRootPath());
			tree.add("Relative path", it->GetRelativePath());
			tree.add("Type", it->GetType());
			if (it->GetType() != "directory")
			{
				tree.add("Extension", it->GetExtension());
			}

			root.add_child(it->GetName(), tree);
		}
		boost::property_tree::write_json("json_report.json", root);
	}
};
