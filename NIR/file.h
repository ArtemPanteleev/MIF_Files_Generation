#ifndef FILE_H
#define FILE_H

#include <QFileDialog>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>

#include "settings.h"

class File
{
    std::string _fileName;
    std::string _fileNameresult;
    const char _sep;
public:
    File(const std::string &fileName, const std::string &fileNameresult, char sep = ',');
    void Generate(const std::string fileNamegenerate);
    ~File();
};

#endif // FILE_H
