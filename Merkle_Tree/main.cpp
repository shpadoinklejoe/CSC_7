
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
    
    // combine tree height = 0 hashes
    // assign to new variables for tree height = 1
    string hashZero = combine(hash00,hash01);
    string hashOne = combine(hash10,hash11);
    //cout << hashZero << "\n" << hashOne << endl << endl;
    
    // hash combined strings for tree height = 1
    unsigned int hash0 = joeHash(hashZero);
    unsigned int hash1 = joeHash(hashOne);
    cout << "Hash 0: " << hash0 << "\nHash 1: " << hash1 << endl << endl;

      //////////////////////
     ////  TOP HEIGHT  ////
    //////////////////////
    
    // combine tree height = 1 hashes
    // assign to new variable for tree height = 2 (top)
    string hashTop = combine(hash0,hash1);
    //cout << hashTop << endl << endl;
    
    // hash combined strings for tree height = 2 (top)
    unsigned int topHash = joeHash(hashTop);
    cout << "Top Hash: " << topHash << endl << endl;
    

    cout << "Let's say a network of computers is seeding arbitrarily chosen yet\n"
            "specific verses.  We will check to see if their data + ours = the total data.\n";
    unsigned int verse2 = 3935862746;
    unsigned int verse4 = 4186718316;
    cout << "CPU-A provides verse 2: " << verse2 << endl;
    cout << "CPU-B provides verse 4: " << verse4 << endl; 

    unsigned int hash0new = joeHash(combine(hash00,verse2));
    cout << hash0new << endl;
    unsigned int hash1new = joeHash(combine(hash01,verse4));
    cout << hash1new << endl;
    unsigned int topHashnew = joeHash(combine(hash0new,hash1new));
    cout << topHashnew << endl;
    
    if (topHashnew == topHash)
    {
        cout << "FILE IS COMPLETE!\n\n";
    }
    else{
        cout << "FILE INCOMPLETE...\n\n";
    }
    
    
    
    
    

    return 0;
}

