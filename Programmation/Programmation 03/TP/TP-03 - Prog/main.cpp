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

void replaceAllChar(string binaryString, unsigned char letter)
{
	size_t pos = stringToEncode.find(letter);
	while (pos != std::string::npos)
	{
		encodedString = stringToEncode.replace(pos, 1, binaryString);
		pos = stringToEncode.find(letter);
	}
}

void addBinary(int arr[], int n, unsigned char letter)
{
	string binaryString = "";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		binaryString += to_string(arr[i]);
	}
	cout << endl;

	replaceAllChar(binaryString, letter);
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
void binaryTraversal(HuffmanNode *root, int arr[], int top)
{
	if (root->left)
	{
		arr[top] = 0;
		binaryTraversal(root->left, arr, top + 1);
	}

	if (root->right)
	{
		arr[top] = 1;
		binaryTraversal(root->right, arr, top + 1);
	}
	if (isLeaf(root))
	{
		cout << root->data << " | ";
		addBinary(arr, top, root->data);
	}
}

/// @brief Encode tout les char avec un binaire unique a l'aide d'une racine huffmannode
/// @param root la racine huffmannode
/// @return une queue de binaire
void encode(HuffmanNode *root)
{
	int arr[256];
	binaryTraversal(root, arr, 0);
}

void chiffrement()
{
	ofstream file(fileName + ".hd");

	size_t start = 0;

	while (start < encodedString.length())
	{
		string buffer = encodedString.substr(start, 8);

		while (sizeof(buffer) % 8 != 0)
		{
			encodedString.push_back('0');
		}
		start += 8;

		if (file.is_open())
		{
			file << stoi(buffer, 0, 2) << ' ';
		}
	}

	file.close();
}

void huffmanEncode(string stringToEncode)
{
	PriorityQueue<HuffmanNode *> *myQueue = new PriorityQueue<HuffmanNode *>();
	HuffmanNode *root;

	census(stringToEncode, myQueue);

	root = treeMaker(myQueue);
	encode(root);
	// chiffrement();

	delete root;
	delete myQueue;
}

// Decode the given string using the given Huffman tree
string decode(HuffmanNode *root, string encoded)
{
	string decoded;
	HuffmanNode *current = root;
	for (char c : encoded)
	{
		if (c == '0')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		if (current->left == nullptr && current->right == nullptr)
		{
			decoded += current->data;
			current = root;
		}
	}
	return decoded;
}

int main(int argc, char *argv[])
{
	if (1 == 1 /*strcmp(argv[0], "huffman") && argc == 3*/)
	{
		cout << "huffman encoding....." << endl;
		// fileName = argv[2];
		fileName = "monFichier.ext";
		// stringToEncode = importing(fileName);
		//  huffmanEncode(stringToEncode);
	}
	else if (strcmp(argv[0], "huffman") && argc == 4)
	{
		cout << "huffman decoding....." << endl;
	}
	else
	{
		// cout << "nothing found" << endl;
	}

	cout << encodedString;

	PriorityQueue<HuffmanNode *> *myQueue = new PriorityQueue<HuffmanNode *>();
	HuffmanNode *root;

	census(stringToEncode, myQueue);

	root = treeMaker(myQueue);
	string str = decode(root, "1010111100110100110001111010000111110111");

	return 0;
}