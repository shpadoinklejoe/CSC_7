
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
#include <vector>
#include <fstream>

using namespace std;

// create a file with a sentence.
void createFile()
{
    ofstream outfile;
    outfile.open("sentence.dat");
    
    outfile << "one two three four five six seven eight nine ten eleven";
    outfile.close();
}

// random word generator
void createSet(vector<string>& v, int elements)
{
    ifstream infile;
    string read;
    int counter = 0;
    
    // write Strings from file into a vector
    infile.open("sentence.txt");
    while(infile >> read && counter<elements)
    {
        v.push_back(read);
        counter++;
    }
    
    infile.close();
}

// bloom filter
void bloomSearch (vector<bool>& bitMap, string searchWord, int m)
{
    int count = 0;
    for(int i=0; i<bitMap.size(); i++)
    {
        if ( bitMap[RSHash(searchWord)%m] && bitMap[JSHash(searchWord)%m] )
        {
            count++;
        }
    }
    
    if (count > 0){
        cout << "yes\n\n";
    }
    else {
        cout << "no\n\n";
    }
}

//Output vector of strings
void print(const vector<string>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout <<"\n\n";
}

//Output vector of boolean values
void print(const vector<bool>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout <<"\n\n";
}

int main(int argc, char* argv[])
{
    //createFile();
    
    // n (elements in set)
    int elements = 50; 
    vector<string> set;
    
    createSet(set, elements);
    print(set);
    
    
    // k (number of hashes used)
    // RSHash & JSHash
    int k = 2;
    
    // m (size of Bloom Filter to use)
    int m = static_cast<int>( (k*elements)/.69 ); 

    // bit vector (actual Bloom Filter)
    // k = 2
    vector<bool> bitMap (m);
    
    for(int i=0; i<set.size(); i++)
    {
        bitMap[RSHash(set[i])%m] = true;
        bitMap[JSHash(set[i])%m] = true;
    }
    
    print(bitMap);
    
    string searchWord;
    
    // search for word not inside set
    searchWord = "cardiac";
    bloomSearch(bitMap, searchWord, m);
    
    // search for word inside of set
    searchWord = "eight";
    bloomSearch(bitMap, searchWord, m);
    
    
    
    
    



//    RSHash(key);
//    JSHash(key);
//    PJWHash(key);
//    ELFHash(key);
//    BKDRHash(key);
//    SDBMHash(key);
//    DJBHash(key);
//    DEKHash(key);
//    FNVHash(key);
//    BPHash(key);
//    APHash(key);

   return 0;
}