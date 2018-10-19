/*dictionary.h, Project 3a.
Andrea Matellian and Nathan Newbury
ID: MATNEW
this file contains the dictionary class, which reads
words from the dictionary file and stores them in a vector.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std; 

#ifndef DICTIONARY_H
#define DICTIONARY_H

class dictionary
{
public:

	//constructor import the dictionary file and read it
	dictionary();

	//overloaded operator to print the final word list
	friend ostream& operator<< (ostream &ostr, vector<string> dictionary& result);
	
	//funtion that sorts the words using selection sort
	void selectionSort();
	
	//funtion to handle word lookups using binary search
	string binarySearch(string grid& candidate);

	//destructor
	~dictionary();

private:

	//vector with all the words from the dictionary file
	vector<string> d;

	//vector with the sorted dictionary
	vector<string> sorted;

	//vector with the results that are grid members that were found in the dictionary
	vector<string> result; 
};
#endif // !D_H
// ***********************************************************

//     dictionary class implementation

// ***********************************************************

dictionary::dictionary()
{	
	//constructor - open dictionary file and read it then push words into vector d as strings 
	ifstream fin;	//object
	string fileName = "dictionary";
	fin.open(fileName.txt);
	if (!fin)
	{
		//error handling
		cout << "The file can't be opened.\n\n";
	}
	
	string word;

	//get number of words in the file
	//istream_iterator<string> in{ fin }, end;
	cout << "Word Count: 88994" << endl;

	//push words into the vector d and also print to screen for testing
	cout << "The dictionary contains the words: \n";
	while (!fin.eof())
	{
		fin >> word;
		d.push_back(word);
	}

	//print to screen for testing purposes
	int size = 88994;
	for (int i = 0; i < size; i++)
		cout << d[i] << endl;
	cout << "\n\n";

	//close the file
	fin.close();
}

//overloaded operator to print the final word list
ostream& operator<< (ostream &ostr, vector<string> dictionary& result)
{
	for (int j = 0; j < result.size(); j++)
		cout << result[j] << endl;
}

void dictionary::selectionSort()
{
	//sort the dictionary vector called d into alphabetical order
	//int k, m;
	/*
	for (k = 1; k < 88994; k++)
	{
		for (m = 1; m < 88994; m++)
		{
			if (strcmp(d[m - 1], d[m]) > 0)
			{
				result[m - 1] = strcpy(d[m - 1], d[m]); //or push_back?
			}
		}
	}*/

	/*
	ATTEMPT 2 LOL
	for (k = 0; k < 88994; k++)
	{
		for (m = 1; m < 88994; m++)
		{
			if (d(m - 1) > d(m))
				result(k) = d(m - 1);
			else
				result(k) = d(m);
				
		}
	}*/

	//I THINK THIS IS SOMEWHAT RIGHT ??!!
	string compare;
	for (int l = 0; l < 88994; l++)
	{
		compare = d(l);
		for (m = 1; m < 88994; m++)
		{
			if (compare > d(m))
				continue;
			else
				compare = d(m);
		}
	sorted(l) = compare;
	}

	//print the sorted vector to the screen
	cout << "The sorted dictionary is: \n";
	cout << sorted << endl;
}

