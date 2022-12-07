#include "FileSystem.h"

FileSystem::FileSystem()
{
	currentDir = new Node();
	this->size = 0;
	directory = "/";
	rootDir = nullptr;
}


FileSystem::~FileSystem()
{
}

void FileSystem::CD(std::string _cmd) {
	// cd to root
	if (_cmd == "/")
	{
		currentDir = rootDir;
		return;
	}
	// cd up
	if (_cmd == ".." && currentDir->parent != nullptr)
	{
		currentDir = currentDir->parent;
		return;
	}
	// cd down to new directory
	for (auto n : currentDir->children)
	{
		// Check if there is any 
	}
}


void FileSystem::LS()
{
	std::cout << "File Tree: \n";

	if (rootDir != nullptr) {
		LS_Recursive(rootDir);
	}
	else
	{
		std::cout << "Null Tree! \n";
		return;
	}

}

void FileSystem::LS_Recursive(Node* _node)
{
    std::cout << _node->directory << " " << _node->size << std::endl;
    for (int i = 0; i < _node->children.size(); i++)
    {
        LS_Recursive(_node->children[i]);
    }
}

void FileSystem::DIR(std::string _directory)
{
	Node* newNode = new Node();
	newNode->directory = _directory;
	newNode->parent = currentDir;
	currentDir->children.push_back(newNode);
}

void FileSystem::SetSize(int _newSize)
{
	currentDir->size += _newSize;
}
