/* 
 * Due Monday, April 06
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
int checkDigit(const vector<int>& v);
void transpose(vector<int>& v);
void flip2dig(vector<int>& v);
bool validCC(const vector<int>& v);
void isValidCC(const vector<int>& v);
void isValidCCtype(const vector<int>& v, crdCardType);
void coutNum(const vector<int>&v);
void coutCC(const vector<int>&v);

int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(time(0));
    
    //Prepare for Luhn encoding
    vector<int> crdCard;
    crdCardType ccType = EITHER; //initializing enum
   
    int randomCC = rand()%4;
 
    switch( randomCC ){
        case 0:
            ccType = Visa;
            break;    
        case 1:
            ccType = Mastercard;
            break;
        case 2:
            ccType = Amex;
            break;
        case 3:
             ccType = Discover;
             break;
    }
    
    genCC(crdCard, ccType);
    
    //Output credit card
    cout<<"\nHere's your new Credit Card number: \n";
    coutNum(crdCard);
    //Test credit card number using Luhn method
    coutCC(crdCard);
    isValidCCtype(crdCard, ccType);
    
    
    //Implement Swap Digit Function
    cout<< "Now let's randomly swap 2 of the numbers in the credit card: \n";
    transpose(crdCard);
    //Test
    coutCC(crdCard);
    isValidCC(crdCard);
    
    
    //Implement 2 Flip function
    cout<< "Now let's randomly replace 2 digits with random numbers: \n";
    flip2dig(crdCard);
    //Test
    coutCC(crdCard);
    isValidCC(crdCard);
    
    
    // Test TRANSPOSE 10,000 times
    cout<< "OK now i will create, transpose, & test 10,000 credit card numbers...\n";
    int validTrans =0;
    int nonValidTrans= 0;
    
    for (int i=0; i<10000; i++)
    {
        vector<int> crdCardTranspose;
        crdCardType ccTransTest = EITHER;
        genCC(crdCardTranspose, ccTransTest);
        
        transpose(crdCardTranspose);
        
        if (validCC(crdCardTranspose))
        {
            validTrans++;
        }
        else{
            nonValidTrans++;
        }
    }
    cout << "There were "<< nonValidTrans<< " NON-valid credit card numbers,\n";
    cout << "and there were " << validTrans << " valid credit card numbers\n\n";
    
    
    // Test FLIPPING 10,000 times
    cout<< "For my next analysis i will create, flip, & test 10,000 credit card numbers...\n";
    int validFlip =0;
    int nonValidFlip= 0;
    
    for (int i=0; i<10000; i++)
    {
        vector<int> crdCardFlip;
        crdCardType ccFlipTest = EITHER;
        genCC(crdCardFlip, ccFlipTest);
        
        transpose(crdCardFlip);
        
        if (validCC(crdCardFlip))
        {
            validFlip++;
        }
        else{
            nonValidFlip++;
        }
    }
    cout << "There were "<< nonValidFlip<< " NON-valid credit card numbers,\n";
    cout << "and there were " << validFlip << " valid credit card numbers\n";
    
    
    
    //Exit Stage Right
    return 0;
}
/////////////////////

// fill Credit Card with numbers
void genCC(vector<int>&v, crdCardType c)
{
    // VISA (13 or 16 digits)
    if (c==Visa)
    {
        int size = rand()%2;
        // length of CC can be 13digits or 16digits
        if (size==0)
        {
            size=11;
        }
        else if (size==1)
        {
            size=14;
        }
        
        v.push_back(4);
        for(int i=0; i<size; i++) 
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));

    }
    //MasterCard (16 digits)
    else if (c==Mastercard)
    {
        v.push_back(5);
        v.push_back( (rand()%5)+1 );
        for(int i=0; i<13; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));

    }
    //American Express (15 digits)
    else if (c==Amex)
    {
        v.push_back(3);
        int iin = rand()%2;
        if(iin==0)
        {
            v.push_back(4);
        }
        else if(iin==1)
        {
            v.push_back(7);
        }
        for(int i=0; i<12; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));

    }
    //Discover Card (16 digits)
    else if (c==Discover)
    {
        int iin = rand()%2;
        if(iin==0)
        {
            v.push_back(6);
            v.push_back(0);
            v.push_back(5);
            v.push_back(5);
            for(int i=0; i<11; i++)
            {
                v.push_back(rand()%10);
            }
        }
        else if(iin==1)
        {
            v.push_back(6);
            v.push_back(5);
            for(int i=0; i<13; i++)
            {
                v.push_back(rand()%10);
            }
        }
             
        v.push_back(checkDigit(v));
  
    }
    // Recurse if type not specified
    else if (c==EITHER)
    {
        int r = rand()%4;
        if(r == 0)
        {
                genCC(v, Visa);
        }
        else if(r == 1)
        {
                genCC(v, Mastercard);
        }
        else if(r == 2)
        {
                genCC(v, Amex);
        }
        else if(r == 3)
        {
                genCC(v, Discover);
        }
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

//Output vector of integers in respective CC format
void coutCC(const vector<int>& v)
{
    if (v.size()==16)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i];
            if( (i+1)%4==0 ){
                cout << " ";
            }
        }
    }
    else if (v.size()==15)
    {
        for(int i=0; i<4; i++)
        {
            cout << v[i];
        }
        cout << " ";
        for(int i=4; i<10; i++)
        {
            cout << v[i];
        }
        cout << " ";
        for(int i=10; i<15; i++)
        {
            cout << v[i];
        }
        cout << " ";
    }
    else if (v.size()==13)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i];
        }
        cout << " ";
    }
}

// calculate check digit
int checkDigit(const vector<int>& v)
{
    vector<int> vLuhn( v.size() );
    
    // Calculate Luhn credit card number
    for(int i=0; i<v.size(); i++)
    {
        //if odd digit multiply by 2
        if ( i%2 == 1 ) 
        {                                 
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
    
    sum= (sum*9)%10;
    
    return sum;
    
}


//Test CC number
bool validCC(const vector<int>& v)
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
    
    if (sum%10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// function that uses bool value to cout result
void isValidCCtype(const vector<int>& v, crdCardType c)
{
    string s;
    switch( c ){
        case 0:
            s = "VISA";
            break;    
        case 1:
            s = "MASTERCARD";
            break;
        case 2:
            s = "AMERICAN EXPRESS";
            break;
        case 3:
            s = "DISCOVER";
            break;
    }
    
    if ( validCC(v) )
    {
        cout << "IS a valid "<< s << " credit card number!\n\n";
    }
    else{
        cout << "is NOT a valid credit card number :(\n\n";
    }
}


// function that uses bool value to cout result
void isValidCC(const vector<int>& v)
{
    if ( validCC(v) )
    {
        cout << "is STILL a valid credit card number!\n\n";
    }
    else{
        cout << "is NOT a valid credit card number :(\n\n";
    }
}

// randomly swaps 2 digits of the credit card number
void transpose(vector<int>& v)
{
    int flipDig = rand()%v.size();
    int flipDig2;
    // ensures that 2 separate digits are chosen to swap
    do{
        flipDig2 = rand()%v.size();
    }
    while(flipDig==flipDig2);
    
    swap(v[flipDig],v[flipDig2]);   
}

// randomly replace 2 CC digits with 2 random numbers
void flip2dig(vector<int>& v)
{
    int flipDig = rand()%v.size();
    int flipDig2;
    // ensures that 2 separate digits are chosen to flip
    do{
        flipDig2 = rand()%v.size();
    }
    while(flipDig==flipDig2);
    
    // ensures that flipDigits are replaced by different numbers
    int randDig;
    do{
    randDig = rand()%10;
    }
    while(randDig==v[flipDig]);
  
    int randDig2;
    do{
    randDig2 = rand()%10;
    }
    while(randDig2==v[flipDig2]);

    v[flipDig] = randDig;
    v[flipDig2] = randDig2; 
}