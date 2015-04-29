
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
#include <vector>

using namespace std;

// random word generator
void words(vector<string>& v, int elements)
{
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for (int i=0; i<elements; i++ )
    {
        string word;
        int avgWordLength = rand()%6;
        for(int j=0; j<=avgWordLength; j++)
        {
            word += letters[rand()%26];
        }
        
        v.push_back(word);
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
    srand(time(0));
    
    // n
    int elements = 10; 
    vector<string> set;
    words(set, elements);
    print(set);
    
    // k
    int k = 2;
    
    // m
    int m = static_cast<int>( (k*elements)/.69 ); 

    // bit vector
    vector<bool> bitMap (m);
    print(bitMap);
    
    for(int i=0; i<set.size(); i++)
    {
        bitMap[RSHash(set[i])%m] = true;
        bitMap[JSHash(set[i])%m] = true;
    }
    
    print(bitMap);
    
   string key = "Then out spake brave Horatius,"
                "\n     The Captain of the Gate:"
                "\n     To every man upon this earth"
                "\n     Death cometh soon or late."
                "\n     And how can man die better"
                "\n     Than facing fearful odds,"
                "\n     For the ashes of his fathers,"
                "\n     And the temples of his gods.\n";

   cout << "General Purpose Hash Function Algorithms Test\n" << endl;
   cout << "Key: "                          << key           << endl;
   cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << endl;
   cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << endl;
   cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << endl;
   cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << endl;
   cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << endl;
   cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << endl;
   cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << endl;
   cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << endl;
   cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << endl;
   cout << "10. BP-Hash Function Value:   " << BPHash(key)   << endl;
   cout << "11. AP-Hash Function Value:   " << APHash(key)   << endl;

   return 0;
}