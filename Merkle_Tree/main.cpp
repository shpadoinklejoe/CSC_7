
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"
#include <sstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
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
    
    // convert original 4 hashes to string data type
    stringstream convert1, convert2, convert3, convert4;
    string h00, h01, h10, h11;
    convert1 << hash00; 
    convert1 >> h00;  
    convert2 << hash01;
    convert2 >> h01;        
    convert3 << hash10; 
    convert3 >>h10;
    convert4 << hash11; 
    convert4 >> h11;
    
    // combine tree height = 0 hashes
    // assign to new variables for tree height = 1
    string hashZero = h00 + h01;
    string hashOne = h10 + h11;
    //cout << hashZero << endl;
    //cout << hashOne << endl << endl;
    
    // hash combined strings for tree height = 1
    unsigned int hash0 = joeHash(hashZero);
    unsigned int hash1 = joeHash(hashOne);
    cout << "Hash 0: " << hash0 << "\nHash 1: " << hash1 << endl << endl;
    
    // convert tree height = 1 hashes to string data types
    stringstream convert5, convert6;
    string h0, h1;
    convert5 << hash0; 
    convert5 >> h0;  
    convert6 << hash1;
    convert6 >> h1;  
    
    // combine tree height = 1 hashes
    // assign to new variable for tree height = 2 (top)
    string hashTop = h0 + h1;
    //cout << hashTop << endl << endl;
    
    // hash combined strings for tree height = 2 (top)
    unsigned int topHash = joeHash(hashTop);
    cout << "Top Hash: " << topHash << endl;
    

    
    
    
    

    return 0;
}

