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
int checkDigit(const vector<int>& v);
void flipDig(vector<int>& v);
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
    
    // error checking
    char c = tolower(conglomerate[0]);

    while(c!='v' && c!='m' && c!='a' && c!='e' && c!='d'){
        cout << "\nNot a valid conglomerate!\nEnter a valid company: ";
        cin >> conglomerate;
        c = tolower(conglomerate[0]);
    }
 
    switch( c ){
        case 'v':
            ccType = Visa;
            break;    
        case 'm':
            ccType = Mastercard;
            break;
        case 'a':
            ccType = Amex;
            break;
        case 'd':
             ccType = Discover;
        break;
        case 'e':
            ccType = EITHER;
            break;
    }
    
    genCC(crdCard, ccType);
    
    //Output credit card
    cout<<"\nHere's your new Credit Card number: \n";
    coutNum(crdCard);
    
    //Impliment Flip Digit Function
    cout<< "Now let's randomly replace a digit with a random number: \n";
    flipDig(crdCard);
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

// randomly replace a CC digit with a random number
void flipDig(vector<int>& v)
{
    int flipDig = rand()%v.size();
    int randDig = rand()%10;
    

    v[flipDig] = randDig;
    
}




// fill Credit Card with numbers
void genCC(vector<int>&v, crdCardType c)
{
    // VISA
    if (c==Visa)
    {
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
    else if (c==Mastercard)
    {
        for(int i=0; i<15; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));
    }
    //American Express
    else if (c==Amex)
    {
        for(int i=0; i<14; i++)
        {
                v.push_back(rand()%10);
        }
        v.push_back(checkDigit(v));
    }
    //Discover Card
    else if (c==Discover)
    {
        for(int i=0; i<15; i++)
        {
                v.push_back(rand()%10);
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
