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

HuffmanNode *treeMaker(PriorityQueue<HuffmanNode *> huffQueue)
{
	int priorityFirstNode = 0;
	int prioritySecondNode = 0;
	int sumPriority = 0;

	while (huffQueue.size() > 1)
	{
		HuffmanNode *firstNode = new HuffmanNode(huffQueue.front()->data);
		priorityFirstNode = huffQueue.frontPriority();
		huffQueue.pop();
		HuffmanNode *secondNode = new HuffmanNode(huffQueue.front()->data);
		prioritySecondNode = huffQueue.frontPriority();
		huffQueue.pop();
		sumPriority = priorityFirstNode + prioritySecondNode;

		HuffmanNode *newNode = new HuffmanNode(firstNode, secondNode);

		huffQueue.push(newNode, sumPriority);
	}

	return huffQueue.front();
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
	HuffmanNode *root;

	HuffmanNode *huffA = new HuffmanNode('a');
	HuffmanNode *huffC = new HuffmanNode('c');
	HuffmanNode *huffE = new HuffmanNode('e');
	HuffmanNode *huffH = new HuffmanNode('h');
	HuffmanNode *huffR = new HuffmanNode('r');
	HuffmanNode *huffS = new HuffmanNode('s');
	HuffmanNode *huffNothing = new HuffmanNode(' ');

	myQueue.push(huffA, 1);
	myQueue.push(huffC, 2);
	myQueue.push(huffE, 4);
	myQueue.push(huffH, 1);
	myQueue.push(huffR, 1);
	myQueue.push(huffS, 6);
	myQueue.push(huffNothing, 1);

	root = treeMaker(myQueue);

	delete huffA;
	delete huffC;
	delete huffE;
	delete huffH;
	delete huffR;
	delete huffS;
	return 0;
}