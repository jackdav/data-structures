#include "Node.h"
#include <string>

using namespace std;

std::vector<Node*> nodes;
std::vector<int> path;	


bool search2(Node* n1, Node* n2, int nextI)
{
	for (int i = 0; i < (n1 -> neighbors.size()); i++)
	{
		if (n1 -> neighbors[i] == n2)
		{
			return true;
		}
	}
	
	for (int i = nextI; i < (n1 -> neighbors.size()); i++)
	{
		path.push_back(n1 -> neighbors[i] -> value);
		
		if (n1 -> neighbors[i] -> neighbors[0] == n1)
		{
			return search2(n1 -> neighbors[i], n2, 1);
		}
		
		else
		{
			return search2(n1 -> neighbors[i], n2, 0);
		}
		path.erase(path.end());
	}
	
	return false;
}

void printPath()
{
	for(int i = 0; i < path.size(); i++)
	{
		cout << path[i] << " -> ";
	}
}

void removeV(Node* n1)
{
	for (int i = 0; i < (n1 -> neighbors.size()); i++)
	{
		for (int j = 0; j < (n1 -> neighbors[i] -> neighbors.size()); j++)
		{
			if (n1 -> neighbors[i] -> neighbors[j] == n1)
			{
				n1 -> neighbors[i] -> neighbors.erase(n1 -> neighbors[i] -> neighbors.begin() + j);
			}
		}
	}
}

void removeE(Node* n1, Node* n2)
{
	for (int i = 0; i < n1 -> neighbors.size(); i++)
	{
		if (n1 -> neighbors[i] == n2)
		{
			n1 -> neighbors.erase(n1 -> neighbors.begin() + i);
		}
	}
	
	for (int i = 0; i < n2 -> neighbors.size(); i++)
	{
		if (n2 -> neighbors[i] == n1)
		{
			n2 -> neighbors.erase(n2 -> neighbors.begin() + i);
		}		
	}
}

int main()
{
	string input;
	while (true)
	{
		cout << "Enter input: "; //Reading input and processing
		cin >> input;
		
		if (input == "add") //Enqueue
		{
			cout << "Vertex(v) or Edge(e): ";
			cin >> input;
			
			if (input == "v")
			{
				Node* temp = new Node();
			
				cout << "Vertex value? ";
				cin >> temp -> value;
				
				nodes.push_back(temp);
			}
			
			else if (input == "e")
			{
				int v1;
				int v2;
				
				cout << "Node 1 value? ";
				cin >> v1;
				
				cout << "Node 2 value? ";
				cin >> v2;
				
				Node* node1;
				Node* node2;
				
				for (int i = 0; i < nodes.size(); i++)
				{
					if (nodes[i] -> value == v1)
					{
						node1 = nodes[i];
					}
					
					else if (nodes[i] -> value == v2)
					{
						node2 = nodes[i];
					}
				}
				
				if (node1 == NULL)
				{
					cout << "n1 null" << endl;
				}
				
				else if (node2 == NULL)
				{
					cout << "n2 null" << endl;
				}
				
				else
				{
					node1 -> neighbors.push_back(node2);
					node2 -> neighbors.push_back(node1);
				}
			}
		}
		
		else if (input == "search")
		{
			path.clear();
			int v1;
			int v2;
			
			Node* node1;
			Node* node2;
			
			cout << "Node 1 value? ";
			cin >> v1;
			
			cout << "Node 2 value? ";
			cin >> v2;		

			for (int i = 0; i < nodes.size(); i++)
			{
				if (nodes[i] -> value == v1)
				{
					node1 = nodes[i];
				}
				
				else if (nodes[i] -> value == v2)
				{
					node2 = nodes[i];
				}
			}
			
			if (node1 == NULL)
			{
				cout << "n1 null" << endl;
			}
			
			else if (node2 == NULL)
			{
				cout << "n2 null" << endl;
			}
			
			else
			{
				bool connected = search2(node1, node2, 0);//, NULL);
				
				if (connected == true)
				{
					cout << "Connection!" << endl;
					cout << node1 -> value << " -> ";
					printPath();
					cout << node2 -> value << endl;
				}
				
				else
				{
					cout << "No Connection!" << endl;
				}
			}
		}
		
		else if (input == "remove")
		{
			cout << "Vertex(v) or Edge(e): ";
			cin >> input;
			
			if (input == "v")
			{
				int v1;
				
				Node* node1;
				
				cout << "Node Value? ";
				cin >> v1;
		
				for (int i = 0; i < nodes.size(); i++)
				{
					if (nodes[i] -> value == v1)
					{
						node1 = nodes[i];
					}
				}
				
				removeV(node1);
			}
			
			else if (input == "e")
			{
				int v1;
				int v2;
				
				cout << "Node 1 value? ";
				cin >> v1;
				
				cout << "Node 2 value? ";
				cin >> v2;
				
				Node* node1;
				Node* node2;
				
				for (int i = 0; i < nodes.size(); i++)
				{
					if (nodes[i] -> value == v1)
					{
						node1 = nodes[i];
					}
					
					else if (nodes[i] -> value == v2)
					{
						node2 = nodes[i];
					}
				}
				
				removeE(node1, node2);
			}
		}
	}
}