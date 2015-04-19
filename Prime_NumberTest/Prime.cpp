
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//
void primeTest(double n)
{
    int count = 0;
    
    for( int i=2; i<=sqrt(n); i++)
    {
        if ( fmod(n,i) == 0 )
        {
            cout << "Not prime: " << i << " x "<< n/i << " = "<< n << endl;
            count++;
        }
    }
    
    if (count == 0){
        cout << n << " IS a prime number!\n";
    }    
}

//
int main(int argc, char** argv) {
    
    double prime = 7917;
    
    cout << "sqrt("<< prime << ") = "<< sqrt(prime) << endl;
    
    primeTest(prime);
    
    

    return 0;
}

