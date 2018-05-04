#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    char test[] = "The string to be rotated." ;

    // circular right shift 'test' by 6
    std::rotate( test, test+6, test+sizeof(test)-1 ) ;
    cout<< test<<endl;

    return 0;
}
