/* 
 * Due Monday, March 09th
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Global Constants

//Function Prototypes
void prpLuhn(vector<int>&v);
void coutNum(const vector<int>&v);
void coutCC(const vector<int>&v);
int luhnSum(const vector<int>&v);
int checkDigit(const vector<int>& v);
bool luhnTest(const vector<int>& v);

int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(time(0));
    
    //Prepare for Luhn encoding
    const int CCSIZE= 15; // initial credit card size (-1 digit of actual size)
    vector<int> crdCard(CCSIZE);
    prpLuhn(crdCard);
    
    //Output the preLuhn credit card
    cout<<"A random number created in Prep for Luhn Digit: \n";
    coutNum(crdCard);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!\n";
    crdCard.push_back(checkDigit(crdCard));
    coutNum(crdCard);
    
    
    //Test credit card number using Luhn method
    coutCC(crdCard);
    if (luhnTest(crdCard))
    {
        cout << "is a valid credit card number!\n\n";
    }
    else{
        cout << "is NOT a valid credit card number :(\n\n";
    }
    
    
    
    //Exit Stage Right
    return 0;
}

//Fill credit card with numbers
void prpLuhn(vector<int>& v)
{
    //Create a random cc in prep for Luhn checksum
    for(int i=0; i<v.size(); i++)
    {
        v[i]=rand()%10;
    }

}

//Output vector of integers
void coutNum(const vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout <<"\n\n";
}

//Output vector of integers (without spaces or return statement)
void coutCC(const vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i];
        if( (i+1)%4==0 ){
            cout << " ";
        }
        
    }
}

// does the Luhn math
int luhnSum(const vector<int>&v)
{
    vector<int> vLuhn( v.size() );
    
    // Calculate Luhn credit card number
    for(int i=0; i<v.size(); i++)
    {
        //if odd digit multiply by 2
        if ( (i%2 == 1) && (i!=v.size()-1) ) // does not double luhn number when 
        {                                // testing luhn algorithm
            if( (v[i]*2) > 9)
            {
                vLuhn[i]= (v[i]*2)-9;
            }
            else{
                vLuhn[i]= v[i]*2;
            }
        }
        else{
            vLuhn[i]= v[i];
        }
    }
    
    int sum =0;
    for(int i=0; i<vLuhn.size(); i++)
    {
        sum += vLuhn[i];
    }
    
    return sum;
}

// calculate check digit
int checkDigit(const vector<int>& v)
{
    int checkDigit= luhnSum(v);
    
    checkDigit= (checkDigit*9)%10;
    
    return checkDigit;
    
}


//Test CC number
bool luhnTest(const vector<int>& v)
{
   
    int sum = luhnSum(v);  
    
    if (sum%10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
