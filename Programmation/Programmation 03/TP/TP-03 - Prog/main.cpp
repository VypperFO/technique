#include <string>
#include <iostream>
#include <cstdio>
#include "PriorityQueue.hpp"
#include "HuffmanNode.hpp"

using namespace std;

void encode()
{
}

void decode()
{
}

void importing()
{
}

void exporting()
{
}

void treeMaker()
{
}

void seedPlanter()
{
}

void encryption()
{
}

int countChar(string str, char searchChar)
{
	int count = 0;

	for (unsigned char i = 0; i < 255; i++)
	{
		if (str.at(i) == searchChar)
		{
			count++;
		}
	}

	return count;
}

void census(string str)
{
	int count = 0;
	// for (int i = 0; (i = str.find(, i)) != string::npos; i++)
	//{
	// count++;
	//}
}
int main(int argc, char *argv[])
{
	PriorityQueue<HuffmanNode *> myQueue = PriorityQueue<HuffmanNode *>();

	HuffmanNode *huff01 = new HuffmanNode('p');

	myQueue.push(huff01, 1);

	cout << myQueue.front()->data << endl;
	cout << myQueue.frontPriority() << endl;

	delete huff01;
	return 0;
}