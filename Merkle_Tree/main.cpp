
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
#include <sstream>

using namespace std;

// converts unsigned integers to string data type
string convert(unsigned int n)
{
    string s;
    stringstream convert;
    convert << n;
    convert >> s;
    
    return s;
}

// combines 2 hashes into 1 string
string combine(unsigned int n0, unsigned int n1)
{
    string s0 = convert(n0);
    string s1 = convert(n1);
    
    string combined = s0 + s1;
    
    return combined;
}

// combines two hash nodes to return hash node root
unsigned int root(unsigned int H1, unsigned int H2)
{
    unsigned int rootHash = joeHash(combine(H1,H2));
    return rootHash;
}

// takes in L1 - L4 and returns the Top Hash
unsigned int topHash(unsigned int L1, unsigned int L2, unsigned int L3, unsigned int L4)
{
    unsigned int hashZero = root(L1,L2);
    unsigned int hashOne = root(L3,L4);
    unsigned int hashTop = root(hashZero,hashOne);
    
    return hashTop;
}

void isComplete(unsigned int a, unsigned int b)
{
    if (a == b)
    {
        cout << "FILE IS COMPLETE!\n\n";
    }
    else{
        cout << "FILE INCOMPLETE...\n\n";
    }
}

int main(int argc, char** argv) {
    
      //////////////////////
     ////  HEIGHT = 0  ////
    //////////////////////
    
    // original parsed data
    string L1 = "Then out spake brave Horatius, The Captain of the Gate:";
    string L2 = "To every man upon this earth Death cometh soon or late.";
    string L3 = "And how can man die better Than facing fearful odds,";
    string L4 = "For the ashes of his fathers, And the temples of his Gods.\n";
    cout << "Key:\n"<< L1 <<"\n" << L2 <<"\n"<< L3 <<"\n"<< L4 << endl;
    
    // hash the parsed data for height = 0
    unsigned int hash00 = joeHash(L1);
    unsigned int hash01 = joeHash(L2);
    unsigned int hash10 = joeHash(L3);
    unsigned int hash11 = joeHash(L4);
    cout << "Hash 0-0: " << hash00 << "\nHash 0-1: " << hash01 << endl;
    cout << "Hash 1-0: " << hash10 << "\nHash 1-1: " << hash11 << endl << endl;
    
      //////////////////////
     ////  HEIGHT = 1  ////
    //////////////////////
    
    // hash combined strings for tree height = 1
    unsigned int hash0 = root(hash00,hash01);
    unsigned int hash1 = root(hash10,hash11);
    cout << "Hash 0: " << hash0 << "\nHash 1: " << hash1 << endl << endl;

      //////////////////////
     ////  TOP HEIGHT  ////
    //////////////////////
    
    // hash combined strings for tree height = 2 (top)
    unsigned int hashTop = root(hash0,hash1);
    cout << "Top Hash: " << hashTop << endl << endl;
    

    cout << "Let's say a network of computers is seeding arbitrarily chosen yet\n"
            "specific verses.  We will check to see if their data + ours = the total data.\n";
    unsigned int verse2 = 3935862746;
    unsigned int verse4 = 4186718316;
    cout << "CPU-A provides verse 2: " << verse2 << endl;
    cout << "CPU-B provides verse 4: " << verse4 << endl; 

    unsigned int checkHash = topHash(hash00,verse2,hash10,verse4);
    
    cout << "\nComputing...\n";
    isComplete(checkHash, hashTop);
    
    
    
    
    

    return 0;
}

