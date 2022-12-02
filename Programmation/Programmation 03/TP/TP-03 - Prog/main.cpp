#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

void encode()
{
}

void decode()
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
	for (int i = 0; (i = str.find(ch, i)) != string::npos; i++)
	{
		count++;
	}
}
int main(int argc, char *argv[])
{

	return 0;
}