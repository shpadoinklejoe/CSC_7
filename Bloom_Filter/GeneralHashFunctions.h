
#ifndef INCLUDE_GENERALHASHFUNCTION_CPP_H
#define INCLUDE_GENERALHASHFUNCTION_CPP_H

#include <cstdlib>
#include <iostream>

using namespace std;


typedef unsigned int (*HashFunction)(const string&);


unsigned int RSHash  (const string& str);
unsigned int JSHash  (const string& str);
unsigned int PJWHash (const string& str);
unsigned int ELFHash (const string& str);
unsigned int BKDRHash(const string& str);
unsigned int SDBMHash(const string& str);
unsigned int DJBHash (const string& str);
unsigned int DEKHash (const string& str);
unsigned int BPHash  (const string& str);
unsigned int FNVHash (const string& str);
unsigned int APHash  (const string& str);
unsigned int joeHash (const string& s);


#endif