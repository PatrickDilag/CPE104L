#include <iostream>
#include <string>

#include "stackADT.h"
#include "linkedStackType.h"
#include "fileHandling.h"

using namespace std;

int main()
{
    linkedStackType<nodeSinger> LST;


    LST.initializeStack();
    LST.pushMulti("data.txt");
    nodeSinger node = LST.top();


    cout << node.singer << endl;
    cout << "End of program" << endl;
    return 0;
}
