#include <string>
#include <iostream>
#include <cstdio>
#include "PriorityQueue.hpp"
#include "HuffmanNode.hpp"
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;

string fileName = "";
string stringToEncode = "";
string encodedString = "";

void decode()
{
}

string importing(string nomFichier)
{
	string stringToImport = "";
	ifstream file(nomFichier, ios::binary);

	if (file.is_open())
	{
		unsigned char byte;
		while (file.read((char *)&byte, sizeof(byte)))
		{
			stringToImport += byte;
		}
	}
	file.close();

	return stringToImport;
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

/// @brief Recensement des char dans un string donnee
/// @param myString le string
/// @param pq la priority queue a ajouter le recensement
void census(string myString, PriorityQueue<HuffmanNode *> *pq)
{
	int freq[255] = {0};
	ofstream file(fileName + ".hk");

	for (char ch : myString)
	{
		freq[ch]++;
	}

	for (int i = 0; i < 255; i++)
	{
		if (freq[i] > 0 && file.is_open())
		{
			HuffmanNode *node = new HuffmanNode(char(i));
			pq->push(node, freq[i]);
			file << char(i) << ':' << freq[i] << endl;
		}
	}
	file.close();
}
void addBinary(int arr[], int n, queue<string> *encodingQueue, unsigned char letter)
{
	string binaryString = "";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		binaryString += to_string(arr[i]);
	}

	cout << "\n";

	size_t pos = stringToEncode.find(letter);
	while (pos != std::string::npos)
	{
		encodedString = stringToEncode.replace(pos, 1, binaryString);
		pos = stringToEncode.find(letter);
	}
	cout << encodedString << endl;
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
		addBinary(arr, top, encodingQueue, root->data);
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

void huffmanEncode(string stringToEncode)
{
	PriorityQueue<HuffmanNode *> *myQueue = new PriorityQueue<HuffmanNode *>();
	queue<string> *myEncodingQueue = new queue<string>();
	HuffmanNode *root;
	census(stringToEncode, myQueue);

	root = treeMaker(myQueue);
	myEncodingQueue = encode(root);

	for (size_t i = 0; i < myEncodingQueue->size(); i++)
	{
		cout << myEncodingQueue->front() << endl;
		myEncodingQueue->pop();
	}

	delete root;
	delete myEncodingQueue;
	delete myQueue;
}

int main(int argc, char *argv[])
{
	string stringToEncode;

	if (1 == 1 /*strcmp(argv[0], "huffman") && argc == 3*/)
	{
		cout << "huffman encoding....." << endl;
		// fileName = argv[2];
		fileName = "monFichier.ext";
		stringToEncode = importing(fileName);
		huffmanEncode(stringToEncode);
	}
	else if (strcmp(argv[0], "huffman") && argc == 4)
	{
		cout << "huffman decoding....." << endl;
	}
	else
	{
		// cout << "nothing found" << endl;
	}

	cout << encodedString << endl;
	return 0;
}