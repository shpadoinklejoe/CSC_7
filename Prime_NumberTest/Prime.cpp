
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// Test if a given number is prime
// If 'composite' then factors printed out
void primeTest(double n)
{
    int count = 0;
    
    for( int i=2; i<=sqrt(n); i++)
    {
        if ( fmod(n,i) == 0 )
        {
            cout << "Composite: " << i << " x "<< n/i << " = "<< n << endl;
            count++;
        }
    }
    
    if (count == 0){
        cout << n << " IS a prime number!\n";
    }
    cout << endl;
}

// Boolean Prime function
bool isPrime(double n)
{
    for( int i=2; i<=sqrt(n); i++)
    {
        if ( fmod(n,i) == 0 )
        {
            return false;
        }
    }  
    return true;
}

// Prints out all prime numbers to n
void primePrint(int n)
{
    vector<int>primeArray;
    
    for( double i=1; i<=n; i++)
    {   
        if ( isPrime(i) )
        {
            primeArray.push_back(i);
        }
    }
    
    for(int i=0; i<primeArray.size(); i++)
    {
        cout << setw(2)<< primeArray[i] << " ";
        if( (i+1)%9 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

// Main
int main(int argc, char** argv) {
    
    // Test if given number is prime
    double prime = 27;
    cout << "sqrt("<< prime << ") = "<< sqrt(prime) << endl;
    primeTest(prime);
    
    
    // Prints all prime numbers to a given n
    int primeNums = 100;
    cout << "Here are the prime numbers up to "<< primeNums << ":\n";
    primePrint(primeNums);
    

    return 0;
}

