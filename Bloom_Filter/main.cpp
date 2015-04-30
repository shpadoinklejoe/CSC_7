
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

// bloom filter given 2 hashes
void bloomSearch2 (vector<bool>& bitMap, string searchWord, int m)
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

// bloom filter given 11 hashes
void bloomSearch11 (vector<bool>& bitMap, string searchWord, int m)
{
    int count = 0;
    for(int i=0; i<bitMap.size(); i++)
    {
        if ( bitMap[RSHash(searchWord)%m] && bitMap[JSHash(searchWord)%m] 
                && bitMap[PJWHash(searchWord)%m] && bitMap[ELFHash(searchWord)%m]
               && bitMap[BKDRHash(searchWord)%m] && bitMap[SDBMHash(searchWord)%m]
                && bitMap[DJBHash(searchWord)%m] && bitMap[DEKHash(searchWord)%m]
                && bitMap[FNVHash(searchWord)%m] && bitMap[BPHash(searchWord)%m]
                                                 && bitMap[APHash(searchWord)%m] )
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
    int elements = 10; 
    vector<string> set;
    
    createSet(set, elements);
    print(set);
    
    
    // k (number of hashes used)
    // RSHash & JSHash
    int k = 2;
    
    // m (size of Bloom Filter to use)
    int m = static_cast<int>( (k*elements)/.69 ); 

    // bit vector (actual Bloom Filter)
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
    bloomSearch2(bitMap, searchWord, m);
    
    // search for word inside of set
    searchWord = "eight";
    bloomSearch2(bitMap, searchWord, m);
    
    
    ///////////////////////////////////////////////////
    
    // n (elements in set)
    elements = 50; 
    vector<string> set2;
    
    createSet(set2, elements);
    print(set2);
    
    
    // k (number of hashes used)
    // RSHash, JSHash, PJWHash, ELFHash, BKDRHash, SDBMHash, 
    // DJBHash, DEKHash, FNVHash, BPHash, & APHash
    k = 11;
    
    // m (size of Bloom Filter to use)
    m = static_cast<int>( (k*elements)/.69 ); 

    // bit vector (actual Bloom Filter)
    vector<bool> bitMap2 (m);
    
    for(int i=0; i<set2.size(); i++)
    {
        bitMap2[RSHash(set2[i])%m] = true;
        bitMap2[JSHash(set2[i])%m] = true;
        bitMap2[PJWHash(set2[i])%m] = true;
        bitMap2[ELFHash(set2[i])%m] = true;
        bitMap2[BKDRHash(set2[i])%m] = true;
        bitMap2[SDBMHash(set2[i])%m] = true;
        bitMap2[DJBHash(set2[i])%m] = true;
        bitMap2[DEKHash(set2[i])%m] = true;
        bitMap2[FNVHash(set2[i])%m] = true;
        bitMap2[BPHash(set2[i])%m] = true;
        bitMap2[APHash(set2[i])%m] = true;    
    }
    
    print(bitMap2);
    

    // search for word not inside set
    searchWord = "cardiac";
    bloomSearch11(bitMap2, searchWord, m);
    
    // search for word inside of set
    searchWord = "eight";
    bloomSearch11(bitMap2, searchWord, m);
    

    
    
    

   return 0;
}