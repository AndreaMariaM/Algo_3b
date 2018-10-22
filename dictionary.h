/*dictionary.h, Project 3a.
Andrea Matellian and Nathan Newbury
ID: MATNEW
this file contains the dictionary class, which reads
words from the dictionary file and stores them in a vector.
*/

#include <iostream>
#include <vector>
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
	friend ostream& operator<< (ostream &ostr, dictionary& result);
	
	//funtion that sorts the words using selection sort
	void selectionSort();
	
	//funtion to handle word lookups using binary search
//	string binarySearch(string grid& candidate);

	//destructor
//	~dictionary();

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
	string fileName = "dictionary.txt";
	fin.open(fileName.c_str());
	if (!fin)
	{
		//error handling
		cout << "The file can't be opened.\n\n";
		system("pause");
		exit(1);
	}
	
	string word;

	//push words into the vector d and also print to screen for testing
	cout << "Unsorted dictionary: \n\n";
	while (!fin.eof())
	{
		fin >> word;
		d.push_back(word);
		cout << word << endl;
	}
	//system("pause");

	//close the file
	cout << "\nThe size of the vector is: " << d.size() << endl << endl;
	//system("pause");

	fin.close();
}

//overloaded operator to print the final word list
ostream& operator<< (ostream &ostr, dictionary& dict)
{
	cout<<"sorted"<<endl;
	for (int j = 0; j < dict.sorted.size(); j++)
		cout << dict.sorted[j] << endl;	
			
	cout<<"results"<<endl;
	for (int j = 0; j < dict.result.size(); j++)
		cout << dict.result[j] << endl;

	return ostr;
}

void dictionary::selectionSort()
{
	string compare;
	int index;
	for (int l = 0; l < d.size(); l++)
	{
		compare = d[l];
		for (int m = 1; m < d.size(); m++)
		{
			if (compare < d[m])
			{
				continue;
			}
			else
			{ 
				compare = d[m];
				index = m;
			}
			
		}
	
		d.erase(d.begin() + index);
		sorted.push_back(compare);
		cout << compare << endl;
	}
	cout << endl;
}

