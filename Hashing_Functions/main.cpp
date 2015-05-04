
#include <cstdlib>
#include <iostream>
#include "GeneralHashFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
   string key = "Then out spake brave Horatius,"
                "\n     The Captain of the Gate:"
                "\n     To every man upon this earth"
                "\n     Death cometh soon or late."
                "\n     And how can man die better"
                "\n     Than facing fearful odds,"
                "\n     For the ashes of his fathers,"
                "\n     And the temples of his gods.\n";

   cout << "General Purpose Hash Function Algorithms Test\n" << endl;
   cout << "Key: "                          << key           << endl;
   cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << endl;
   cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << endl;
   cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << endl;
   cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << endl;
   cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << endl;
   cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << endl;
   cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << endl;
   cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << endl;
   cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << endl;
   cout << "10. BP-Hash Function Value:   " << BPHash(key)   << endl;
   cout << "11. AP-Hash Function Value:   " << APHash(key)   << endl;
   cout << "12. joe-Hash Function Value:   " << joeHash(key)   << endl;
   

   return 0;
}