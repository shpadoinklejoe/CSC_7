/* 
 * Due Monday, March 30
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Global Constants//
//Creating data type 
enum crdCardType {Visa, Mastercard, Amex, Discover, EITHER};

//Function Prototypes
void genCC(vector<int>&v, crdCardType);
int luhnSum(const vector<int>&v);
int checkDigit(const vector<int>& v);
bool validCC(const vector<int>& v);
void coutNum(const vector<int>&v);
void coutCC(const vector<int>&v);

int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(time(0));
    
    //Prepare for Luhn encoding
    vector<int> crdCard;
    crdCardType ccType = EITHER;
    string conglomerate;
   
    cout << "Enter which conglomerate you want a credit card number from\n"
            "Visa, Mastercard, Discover, Amex, or EITHER(if it doesn't matter which company): ";
    cin >> conglomerate;
    
    switch( tolower(conglomerate[0]) ){
        case 'v':
            ccType = Visa;
            break;    
        case 'm':
            ccType = Mastercard;
            break;
        case 'a':
            ccType = Amex;
            break;
        case 'e':
            ccType = EITHER;
            break;
        default:
            cout << "Not a valid conglomerate\n";
    }
    
    cout << ccType << endl;
    
    genCC(crdCard, ccType);
    
    //Output credit card
    cout<<"Here's your new Credit Card number: \n";
    coutNum(crdCard);
    
    
    //Test credit card number using Luhn method
    coutCC(crdCard);
    if (validCC(crdCard))
    {
        cout << "is a valid credit card number!\n\n";
    }
    else{
        cout << "is NOT a valid credit card number :(\n\n";
    }
    
    
    
    //Exit Stage Right
    return 0;
}
/////////////////////

// fill Credit Card with numbers
void genCC(vector<int>&v, crdCardType)
{
    cout << "entering function ";
    // VISA
    if (Visa)
    {
        cout << "visa ";
        int size = rand()%2;
        // length of CC can be 13digits or 16digits
        if (size==0)
        {
            size=12;
        }
        else if (size==1)
        {
            size=15;
        }
        
        for(int i=0; i<size; i++) 
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));
    }
    //MasterCard
    else if (Mastercard)
    {
        cout << "mastercard ";
        for(int i=0; i<15; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));
    }
    //American Express
    else if (Amex)
    {
        cout << "amex ";
        for(int i=0; i<14; i++)
        {
                v.push_back(rand()%10);
        }
        cout << "test ";
        v.push_back(checkDigit(v));
        cout << "test ";
    }
    //Discover Card
    else if (Discover)
    {
        cout << "discover ";
        for(int i=0; i<15; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));
    }
    // Recurse if type not specified
    else if (EITHER)
    {
        int rand = rand()%4;
        if(rand == 0)
        {
                genCC(v, Visa);
        }
        else if(rand == 1)
        {
                genCC(v, Mastercard);
        }
        else if(rand == 2)
        {
                genCC(v, Amex);
        }
        else if(rand == 3)
        {
                genCC(v, Discover);
        }
    }
    
    cout << "leaving function ";
    
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
        {                                    // testing luhn algorithm
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
bool validCC(const vector<int>& v)
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
