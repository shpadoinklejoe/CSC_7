
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <sstream>



using namespace std;

// Prints vector backwards
void print(const vector<int>& v)
{
    for(int i=v.size()-1; i>=0; i--)
    {
        cout << v[i];
    }
}

// Prints vector backwards
void print(const vector<string>& v)
{
    for(int i=v.size()-1; i>=0; i--)
    {
        cout << v[i];
    }
}

// Converts Base(10) => Base(2)
void toBinary (unsigned int n)
{
    vector<int>v;
    
    if(n==0){
        v.push_back(0);
    }
    
    while ( n > 0 )
    {
        v.push_back(n%2);
        n = n/2;
    }
    
    print(v); 
}

// Convert Base(10) => Base(16)
void toHexadecimal(int numerator)
{
    vector<string>v;
    
    if(numerator==0){
        v.push_back("0");
    }
    
    while ( numerator > 0 )
    {
        int num = numerator%16;
        
        if (num < 10){
        string number;
        ostringstream convert;
        convert << num;
        number = convert.str();
            v.push_back(number);
        }
        else if (num == 10){
            v.push_back("A");
        }
        else if (num == 11){
            v.push_back("B");
        }
        else if (num == 12){
            v.push_back("C");
        }
        else if (num == 13){
            v.push_back("D");
        }
        else if (num == 14){
            v.push_back("E");
        }
        else if (num == 15){
            v.push_back("F");
        }
        
        
        numerator = numerator/16;
    }
    
    print(v);
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    srand(time(0));
    
    //unsigned int toConvert = INT_MAX + INT_MAX+1;
    int toConvert = rand()%256;
    
    cout << toConvert <<" = ";
    toBinary(toConvert);
    cout << " in Binary\n";
    
    
    int base10 = 287;
    
    cout << base10 <<" = ";
    toHexadecimal(base10);
    cout << " in Hexadecimal\n";

    return 0;
}

