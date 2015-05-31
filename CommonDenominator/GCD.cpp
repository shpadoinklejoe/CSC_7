
#include <cstdlib>
#include <iostream>

using namespace std;

// greatest common denominator (RECURSION)
int gcd(int n,int d)
{
    if(n==0){
        return d;
    }
    if(n>=d){
        return gcd(n%d,d);
    }
    
    return gcd(d%n,n);
}

// lowest common multiple (GCD) loop
int lcm (int n, int d)
{
    int r = n%d;
    
    while (r != 0)
    {
        n = d;
        d = r;
        r = n%d; 
    }
    
    return d;
    
}


int main(int argc, char** argv) {
    
    
   //Test out the Greatest Common Denominator
   int num=8145;
   int den=99999;
   int gcdval=gcd(num,den);
    
   cout << num << "/"<< den << " gcd = " << gcdval << endl;

   int snum=num/gcdval;
   int sden=den/gcdval;
   cout << "\n" << num << "/" << den << " = " << snum << "/" << sden << endl;
   


   return 0;
}

