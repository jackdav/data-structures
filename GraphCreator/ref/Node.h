#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
	public:
		int value;
		std::vector<Node*> neighbors;

		Node();
};

#endif