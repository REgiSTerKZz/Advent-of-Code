#include <vector>
#include <string>
#include <iostream>

struct Node
{
	int size;
	std::string directory;
	Node* parent;
	std::vector<Node*> children;
};