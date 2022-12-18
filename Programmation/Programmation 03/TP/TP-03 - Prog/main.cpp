#include <string>
#include <iostream>
#include <cstdio>
#include "PriorityQueue.hpp"
#include "HuffmanNode.hpp"
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;

void decode()
{
}

string importing(string nomFichier)
{
	string stringToEncode = "";
	ifstream file(nomFichier, ios::binary);

	if (file.is_open())
	{
		unsigned char byte;
		while (file.read((char *)&byte, sizeof(byte)))
		{
			stringToEncode += byte;
		}
	}
	file.close();

	return stringToEncode;
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

void compression()
{
}

/// @brief Recensement des char dans un string donnee
/// @param myString le string
/// @param pq la priority queue a ajouter le recensement
void census(string myString, PriorityQueue<HuffmanNode *> *pq)
{
	// create an array to store the frequency of each character
	int freq[256] = {0};

	// iterate through the string and count the frequency of each character
	for (char ch : myString)
	{
		freq[ch]++;
	}

	// print the frequency of each character
	for (int i = 0; i < 256; i++)
	{
		if (freq[i] > 0)
		{
			cout << char(i) << ": " << freq[i] << endl;
			HuffmanNode *node = new HuffmanNode(char(i));
			pq->push(node, freq[i]);
		}
	}
}

/// @brief Ajoute un binaire
/// @param arr table a ajouter binaire
/// @param n top de la serie de binaire
/// @param encodingQueue
void addBinary(int arr[], int n, queue<string> *encodingQueue)
{
	string binaryChar;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		binaryChar = binaryChar + to_string(arr[i]);
	}
	encodingQueue->push(binaryChar);
	cout << "\n";
}

/// @brief Savoir si noeud est une feuille
/// @param root la racine huffmannode
/// @return le huffmannode gauche ou droite
int isLeaf(HuffmanNode *root)
{
	return !(root->left) && !(root->right);
}

/// @brief Fonction recursive permettant d'assigner un 0 ou 1 a chaque char
/// @param root la racine huffmannode
/// @param arr table des 1 et 0 pour chaque char
/// @param top top de la serie de binaire
/// @param encodingQueue la file pour ajouter les binaires
void binaryTraversal(HuffmanNode *root, int arr[], int top, queue<string> *encodingQueue)
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

/// @brief Encode tout les char avec un binaire unique a l'aide d'une racine huffmannode
/// @param root la racine huffmannode
/// @return une queue de binaire
queue<string> *encode(HuffmanNode *root)
{
	queue<string> *encodingQueue = new queue<string>();
	int arr[256];
	binaryTraversal(root, arr, 0, encodingQueue);

	return encodingQueue;
}

int main(int argc, char *argv[])
{
	PriorityQueue<HuffmanNode *> *myQueue = new PriorityQueue<HuffmanNode *>();
	queue<string> *myEncodingQueue = new queue<string>();
	HuffmanNode *root;
	string stringToEncode;

	if (strcmp(argv[0], "huffman") && argc == 3)
	{
		cout << "huffman encoding....." << endl;
		stringToEncode = importing(argv[2]);
	}
	else if (strcmp(argv[0], "huffman") && argc == 4)
	{
		cout << "huffman decoding....." << endl;
	}
	else
	{
		// cout << "nothing found" << endl;
	}

	// cout << stringToEncode << endl;

	/*census("ces chasseresses", myQueue);
	root = treeMaker(myQueue);
	myEncodingQueue = encode(root);

	for (size_t i = 0; i < myEncodingQueue->size(); i++)
	{
		cout << myEncodingQueue->front();
		myEncodingQueue->pop();
	}*/

	delete root;
	delete myEncodingQueue;
	delete myQueue;

	return 0;
}