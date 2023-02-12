#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>

class DirectoryObjects
{
public:

	void SetName(const std::string& name) {
		m_name = name;
	}
	std::string GetName() {
		return m_name;
	}

	void SetExtension(const std::string& extension) {
		m_extension = extension;
	}
	std::string GetExtension() {
		return m_extension;
	}

	void SetType(const std::string& type) {
		m_type = type;
	}
	std::string GetType() {
		return m_type;
	}

	void SetRootPath(const std::string& root_path) {
		m_root_path = root_path;
	}
	std::string GetRootPath() {
		return m_root_path;
	}

	void SetRelativePath(const std::string& relative_path) {
		m_relative_path = relative_path;
	}
	std::string GetRelativePath() {
		return m_relative_path;
	}

private:
	std::string m_name;
	std::string m_extension;
	std::string m_type;
	std::string m_root_path;
	std::string m_relative_path;
};

std::vector<DirectoryObjects> TakeObjectInformation(const std::string& path) {

	std::vector<DirectoryObjects> objectVector;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		DirectoryObjects object;

		object.SetName(entry.path().filename().string());
		object.SetExtension(entry.path().extension().string());
		object.SetRootPath(entry.path().root_path().string());
		object.SetRelativePath(entry.path().relative_path().string());
		
		if (std::filesystem::is_regular_file(entry))
			object.SetType("regular file");
		else if (std::filesystem::is_directory(entry))
			object.SetType("directory");
		else if (std::filesystem::is_block_file(entry))
			object.SetType("block device");
		else if (std::filesystem::is_character_file(entry))
			object.SetType("character device");
		else if (std::filesystem::is_fifo(entry))
			object.SetType("IPC pipe");
		else if (std::filesystem::is_socket(entry))
			object.SetType("IPC socket");
		else if (std::filesystem::is_symlink(entry))
			object.SetType("symlink");
		else if (!std::filesystem::exists(entry))
			object.SetType("does not exist");

		objectVector.emplace_back(object);
	}
	objectVector.shrink_to_fit();

	return objectVector;
}