
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
#include <vector>
#include <fstream>
#include <cmath>  
#include <iomanip>

using namespace std;

// fill vector with words from a file
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
        cout << "YES, '"<< searchWord<< "' is inside the file\n";
    }
    else {
        cout << "NO, '"<< searchWord<< "' is NOT in the file\n";
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
                 && bitMap[APHash(searchWord)%m] && bitMap[joeHash(searchWord)%m])
        {
            count++;
        }
    }
    
    if (count > 0){
        cout << "YES, '"<< searchWord<< "' is inside the file\n";
    }
    else {
        cout << "NO, '"<< searchWord<< "' is NOT in the file\n";
    }
}


//Output vector of strings
void print(const vector<string>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
        
        if( (i+1)%19 == 0)
        {
            cout << endl;
        }
    }
    cout <<"\n\n";
}

//Output vector of boolean values
void print(const vector<bool>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
        
        if( (i+1)%50 == 0)
        {
            cout << endl;
        }
    }
    cout <<"\n\n";
}

int main(int argc, char* argv[])
{
    const double e = exp(1.0);
    
    // n (elements in set)
    int elements = 10; 
    vector<string> set; 
    createSet(set, elements);
    cout << "Here is a vector of "<< elements << " elements:\n";
    print(set);
    
    
    // k (number of hashes used)
    // RSHash & JSHash
    int k = 2;
    
    // m (size of Bloom Filter to use)
    // optimal size = k*n/ln2 (derived from equation k=(m/n)ln2 )
    int m = static_cast<int>( (k*elements)/.693147 ); 

    // bit vector (actual Bloom Filter)
    vector<bool> bitMap (m);
    
    for(int i=0; i<set.size(); i++)
    {
        bitMap[RSHash(set[i])%m] = true;
        bitMap[JSHash(set[i])%m] = true;
    }
    
    cout << "Here is the bit-vector of size "<< m << ":\n";
    print(bitMap);
    
    string searchWord;
    
    // search for words NOT inside set
    cout << "Let's search for several words we know are NOT in the file:\n";
    searchWord = "hello";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "world";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "thirteen";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "SeVeN";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "threee";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "the";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "end";
    bloomSearch2(bitMap, searchWord, m);
    
    // search for words inside of set
    cout << "\nLet's search for several words we know are inside the file:\n";
    searchWord = "one";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "two";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "three";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "four";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "five";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "six";
    bloomSearch2(bitMap, searchWord, m);
    searchWord = "seven";
    bloomSearch2(bitMap, searchWord, m);
    
    // calculate the rate of false positives
    double knDIVm = static_cast<double>( k*elements )/m;
    double falsePositive = ( pow( (1-(pow(e,-knDIVm))) ,k) )*100;
    cout << "\nWith a false positive rate of "<< setprecision(2)<< fixed << falsePositive << "%\n\n";
    
    
      /////////////////////////////////////////////////////////////
     // again, but with more 'n' elements && 'k' hash functions //
    /////////////////////////////////////////////////////////////
    
    // n (elements in set)
    elements = 55; 
    vector<string> set2;
    createSet(set2, elements);
    
    cout << "\nHere is a vector of "<< elements << " elements:\n";
    print(set2);
    
    
    // k (number of hashes used)
    // RSHash, JSHash, PJWHash, ELFHash, BKDRHash, SDBMHash, 
    // DJBHash, DEKHash, FNVHash, BPHash, & APHash
    k = 12;
    
    // m (size of Bloom Filter to use)
    // optimal size = k*n/ln2 (derived from equation k=(m/n)ln2 )
    m = static_cast<int>( (k*elements)/.693147 ); 

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
        bitMap2[joeHash(set2[i])%m] = true;   
    }
    
    cout << "Here is the bit-vector of size "<< m << ":\n";
    print(bitMap2);

    // search for words NOT inside set
    cout << "Again, let's search for several words we know are NOT in the file:\n";
    searchWord = "cardiac";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "templeton";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "cellar";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "TeMpLeS";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "hello";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "world";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "thirteen";
    bloomSearch11(bitMap2, searchWord, m);
    
    // search for words inside of set
    cout << "\nAgain, let's search for several words we know are inside the file:\n";
    searchWord = "eight";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "his";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "fathers";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "temples";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "fearful";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "Death";
    bloomSearch11(bitMap2, searchWord, m);
    searchWord = "gods";
    bloomSearch11(bitMap2, searchWord, m);
    
    // calculate the rate of false positives
    knDIVm = static_cast<double>( k*elements )/m;
    falsePositive = ( pow( (1-(pow(e,-knDIVm))) ,k) )*100;
    cout << "\nWith a false positive rate of "<< falsePositive << "%\n\n";
    
    
    

   return 0;
}