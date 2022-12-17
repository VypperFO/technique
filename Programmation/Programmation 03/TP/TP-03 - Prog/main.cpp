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

HuffmanNode *treeMaker(PriorityQueue<HuffmanNode *> *huffQueue)
{
	int priorityFirstNode = 0;
	int prioritySecondNode = 0;
	int sumPriority = 0;

	while (huffQueue->size() > 1)
	{
		HuffmanNode *firstNode = huffQueue->front();
		priorityFirstNode = huffQueue->frontPriority();
		huffQueue->pop();
		HuffmanNode *secondNode = huffQueue->front();
		prioritySecondNode = huffQueue->frontPriority();
		huffQueue->pop();

		sumPriority = priorityFirstNode + prioritySecondNode;

		HuffmanNode *newNode = new HuffmanNode(firstNode, secondNode);

		huffQueue->push(newNode, sumPriority);
	}

	return huffQueue->front();
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

void census(string myString, PriorityQueue<HuffmanNode *> *pq)
{
	string s = "hello, world!";

	// create an array to store the frequency of each character
	int freq[256] = {0};

	// iterate through the string and count the frequency of each character
	for (char ch : s)
	{
		freq[ch]++;
	}

	// print the frequency of each character
	for (int i = 0; i < 256; i++)
	{
		if (freq[i] > 0)
		{
			cout << char(i) << ": " << freq[i] << endl;
		}
	}
}

// Print the array
void addBinary(int arr[], int n, queue<int> *encodingQueue)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		encodingQueue->push(arr[i]);
	}
	cout << "\n";
}

int isLeaf(HuffmanNode *root)
{
	return !(root->left) && !(root->right);
}

void binaryTraversal(HuffmanNode *root, int arr[], int top, queue<int> *encodingQueue)
{
	if (root->left)
	{
		arr[top] = 0;
		binaryTraversal(root->left, arr, top + 1, encodingQueue);
	}

	if (root->right)
	{
		arr[top] = 1;
		binaryTraversal(root->right, arr, top + 1, encodingQueue);
	}
	if (isLeaf(root))
	{
		cout << root->data << " | ";
		addBinary(arr, top, encodingQueue);
	}
}

queue<int> *encode(HuffmanNode *root)
{
	queue<int> *encodingQueue = new queue<int>();
	int arr[255];
	binaryTraversal(root, arr, 0, encodingQueue);

	return encodingQueue;
}

int main(int argc, char *argv[])
{
	PriorityQueue<HuffmanNode *> *myQueue = new PriorityQueue<HuffmanNode *>();
	HuffmanNode *root;
	queue<int> *myEncodingQueue = new queue<int>();

	HuffmanNode *huffA = new HuffmanNode('a');
	HuffmanNode *huffC = new HuffmanNode('c');
	HuffmanNode *huffE = new HuffmanNode('e');
	HuffmanNode *huffH = new HuffmanNode('h');
	HuffmanNode *huffR = new HuffmanNode('r');
	HuffmanNode *huffS = new HuffmanNode('s');
	HuffmanNode *huffNothing = new HuffmanNode(' ');

	myQueue->push(huffNothing, 1);
	myQueue->push(huffH, 1);
	myQueue->push(huffA, 1);
	myQueue->push(huffR, 1);
	myQueue->push(huffC, 2);
	myQueue->push(huffE, 4);
	myQueue->push(huffS, 6);

	root = treeMaker(myQueue);

	myEncodingQueue = encode(root);

	for (int i = 0; i < 21; i++)
	{
		cout << myEncodingQueue->front();
		myEncodingQueue->pop();
	}

	delete huffA;
	delete huffC;
	delete huffE;
	delete huffH;
	delete huffR;
	delete huffS;
	delete huffNothing;
	delete root;
	delete myEncodingQueue;
	delete myQueue;

	return 0;
}