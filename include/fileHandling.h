#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <string>
#include <fstream>
#include "linkedStackType.h"

template <typename Type>
class fileHandling
{
    public:
        fileHandling(string data, Type* songInfo);
        virtual ~fileHandling();

    protected:

    private:
};

#endif // FILEHANDLING_H
