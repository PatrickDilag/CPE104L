#include "fileHandling.h"
#include <string>
#include <iostream>
#include <fstream>
#include "linkedStackType.h"

template <typename Type>
fileHandling<Type>::fileHandling(string data, Type* songInfo)
{
    ifstream ifs;
    char x[50];

    ifs.open(data);

    while(!ifs.eof()){
        ifs.getline(x, 50, ';');
        songInfo->singer = x;
        ifs.getline(x, 50, ';');
        songInfo->song = x;
        ifs.getline(x, 50, ';');
        songInfo->album = x;
        ifs.getline(x, 50);
        songInfo->year = atoi(x);

    }
}


template <typename Type>
fileHandling<Type>::~fileHandling()
{
    //dtor
}
