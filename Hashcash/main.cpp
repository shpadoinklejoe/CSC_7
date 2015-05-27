
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

int main(int argc, char* argv[])
{
    
    // n (elements in set)
    int elements = 43; 
    vector<string> set;
    createSet(set, elements);   
    
    cout << "Here is a vector of "<< elements << " elements:\n";
    print(set);
    
    int stat1 = 0;
    int stat2 = 0;
    int stat3 = 0;
    
    for(int i=0; i<set.size(); i++)
    {      
        int hash1 = RSHash(set[i]);
        int hash2 = JSHash(set[i]);
        int hash3 = PJWHash(set[i]);
        int hash4 = ELFHash(set[i]);
        int hash5 = BKDRHash(set[i]);
        int hash6 = SDBMHash(set[i]);
        int hash7 = DJBHash(set[i]);
        int hash8 = DEKHash(set[i]);
        int hash9 = FNVHash(set[i]);
        int hash10 = BPHash(set[i]);
        int hash11 = APHash(set[i]); 
        int hash12 = joeHash(set[i]);
        
        int range = 1*pow(10,9);
        
        if(hash1>range){stat1++;}
        if(hash2>range){stat1++;}
        if(hash3>range){stat1++;}
        if(hash4>range){stat1++;} 
        if(hash5>range){stat1++;}
        if(hash6>range){stat1++;}
        if(hash7>range){stat1++;}
        if(hash8>range){stat1++;} 
        if(hash9>range){stat1++;}
        if(hash10>range){stat1++;}
        if(hash11>range){stat1++;}
        if(hash12>range){stat1++;}

        
        int range2 = 1*pow(10,6);
        if(hash1<range && hash1>range2){stat2++;}
        if(hash2<range && hash2>range2){stat2++;}
        if(hash3<range && hash3>range2){stat2++;}
        if(hash4<range && hash4>range2){stat2++;}
        if(hash5<range && hash5>range2){stat2++;}
        if(hash6<range && hash6>range2){stat2++;}
        if(hash7<range && hash7>range2){stat2++;}
        if(hash8<range && hash8>range2){stat2++;}
        if(hash9<range && hash9>range2){stat2++;}
        if(hash10<range && hash10>range2){stat2++;}
        if(hash11<range && hash11>range2){stat2++;}
        if(hash12<range && hash12>range2){stat2++;}

        
        if(hash1<range2){stat3++;}
        if(hash2<range2){stat3++;}
        if(hash3<range2){stat3++;}
        if(hash4<range2){stat3++;} 
        if(hash5<range2){stat3++;}
        if(hash6<range2){stat3++;}
        if(hash7<range2){stat3++;}
        if(hash8<range2){stat3++;} 
        if(hash9<range2){stat3++;}
        if(hash10<range2){stat3++;}
        if(hash11<range2){stat3++;}
        if(hash12<range2){stat3++;}
        
    }
    
    cout << "number of hashes over 1 billion: " << stat1 << endl;
    cout << "number of hashes from 1 million - 1 billion: " << stat2 << endl;
    cout << "number of hashes under 1 million: " << stat3 << endl;
    
    
    
    
    
    
    
    
    
    

   return 0;
}