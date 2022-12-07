#include "Node.cpp"

#pragma once
class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	void CD(std::string _cmd);
	void LS();
	void LS_Recursive(Node* _node);

	void DIR(std::string _directory);
	void SetSize(int _newSize);

private:
	int size;
	std::string directory;
	Node* rootDir;
	Node* currentDir;
};