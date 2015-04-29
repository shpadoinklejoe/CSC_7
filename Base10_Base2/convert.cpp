
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Prints vector backwards
void print(const vector<int>& v)
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
    
    

    return 0;
}

