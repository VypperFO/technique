#include <string>
#include <iostream>
#include <cstdio>
#include "PriorityQueue.hpp"
#include "HuffmanNode.hpp"
#include <queue>

using namespace std;

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
		HuffmanNode *firstNode = huffQueue.front();
		priorityFirstNode = huffQueue.frontPriority();
		huffQueue.pop();
		HuffmanNode *secondNode = huffQueue.front();
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

// Print the array
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i];

	cout << "\n";
}

int isLeaf(HuffmanNode *root)
{
	return !(root->left) && !(root->right);
}

void printHCodes(HuffmanNode *root, int arr[], int top, queue<int> *encodingQueue)
{
	if (root->left)
	{
		arr[top] = 0;
		encodingQueue->push(0);
		printHCodes(root->left, arr, top + 1, encodingQueue);
	}

	if (root->right)
	{
		arr[top] = 1;
		encodingQueue->push(1);
		printHCodes(root->right, arr, top + 1, encodingQueue);
	}
	if (isLeaf(root))
	{
		cout << root->data << "  | ";
		printArray(arr, top);
	}
}

queue<int> *encode(HuffmanNode *root)
{
	queue<int> *encodingQueue = new queue<int>();
	int arr[50];
	printHCodes(root, arr, 0, encodingQueue);

	return encodingQueue;
}

int main(int argc, char *argv[])
{
	PriorityQueue<HuffmanNode *> myQueue = PriorityQueue<HuffmanNode *>();
	HuffmanNode *root;
	queue<int> *myEncodingQueue = new queue<int>();

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

	myEncodingQueue = encode(root);

	for (size_t i = 0; i < myEncodingQueue->size(); i++)
	{
		cout << myEncodingQueue->front() << endl;
		myEncodingQueue->pop();
	}

	delete huffA;
	delete huffC;
	delete huffE;
	delete huffH;
	delete huffR;
	delete huffS;
	return 0;
}