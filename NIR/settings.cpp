#include "settings.h"
#include <QObject>

Settings::Settings()
{

}

Q_GLOBAL_STATIC(Settings, global_inst)
Settings *Settings::instanse()
{
    return global_inst();
}

int Settings::getWIDTH() const
{
    return _WIDTH;
}

void Settings::setWIDTH(int WIDTH)
{
    _WIDTH = WIDTH;
}

int Settings::getDEPTH() const
{
    return _DEPTH;
}

void Settings::setDEPTH(int DEPTH)
{
    _DEPTH = DEPTH;
}

std::string Settings::getADDRESS_RADIX() const
{
    return _ADDRESS_RADIX;
}

void Settings::setADDRESS_RADIX(std::string ADDRESS_RADIX)
{
    _ADDRESS_RADIX = ADDRESS_RADIX;
}

std::string Settings::getDATA_RADIX() const
{
    return _DATA_RADIX;
}

void Settings::setDATA_RADIX(std::string DATA_RADIX)
{
    _DATA_RADIX = DATA_RADIX;
}

std::string Settings::getDATA_RADIX_START() const
{
    return _DATA_RADIX_START;
}

void Settings::setDATA_RADIX_START(std::string DATA_RADIX_START)
{
    _DATA_RADIX_START = DATA_RADIX_START;
}

int Settings::getWIDTH_GENERATE() const
{
    return _WIDTH_GENERATE;
}

void Settings::setWIDTH_GENERATE(int WIDTH_GENERATE)
{
    _WIDTH_GENERATE = WIDTH_GENERATE;
}

int Settings::getDEPTH_GENERATE() const
{
    return _DEPTH_GENERATE;
}

void Settings::setDEPTH_GENERATE(int DEPTH_GENERATE)
{
    _DEPTH_GENERATE = DEPTH_GENERATE;
}

std::string Settings::getADDRESS_RADIX_GENERATE() const
{
    return _ADDRESS_RADIX_GENERATE;
}

void Settings::setADDRESS_RADIX_GENERATE(std::string ADDRESS_RADIX_GENERATE)
{
    _ADDRESS_RADIX_GENERATE = ADDRESS_RADIX_GENERATE;
}

std::string Settings::getDATA_RADIX_GENERATE() const
{
    return _DATA_RADIX_GENERATE;
}

void Settings::setDATA_RADIX_GENERATE(std::string DATA_RADIX_GENERATE)
{
    _DATA_RADIX_GENERATE = DATA_RADIX_GENERATE;
}

int Settings::getMIN()
{
    return _MIN;
}

void Settings::setMIN(int MIN)
{
    _MIN = MIN;
}

int Settings::getMAX()
{
    return _MAX;
}

void Settings::setMAX(int MAX)
{
    _MAX = MAX;
}

int Settings::getNUMBER()
{
    return _NUMBER;
}

void Settings::setNUMBER(int NUMBER)
{
    _NUMBER = NUMBER;
}

std::string Settings::getOPERATION() const
{
    return _OPERATION;
}

void Settings::setOPERATION(std::string OPERATION)
{
    _OPERATION = OPERATION;
}

int Settings::getNUMBER_2()
{
    return _NUMBER_2;
}

void Settings::setNUMBER_2(int NUMBER_2)
{
    _NUMBER_2 = NUMBER_2;
}
