#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
public:
    Settings();

    static Settings *instanse();

    int getWIDTH() const;
    void setWIDTH(int WIDTH);

    int getDEPTH() const;
    void setDEPTH(int DEPTH);

    std::string getADDRESS_RADIX() const;
    void setADDRESS_RADIX(std::string ADDRESS_RADIX);

    std::string getDATA_RADIX() const;
    void setDATA_RADIX(std::string DATA_RADIX);

    std::string getDATA_RADIX_START() const;
    void setDATA_RADIX_START(std::string DATA_RADIX_START);

    int getWIDTH_GENERATE() const;
    void setWIDTH_GENERATE(int WIDTH_GENERATE);

    int getDEPTH_GENERATE() const;
    void setDEPTH_GENERATE(int DEPTH_GENERATE);

    std::string getADDRESS_RADIX_GENERATE() const;
    void setADDRESS_RADIX_GENERATE(std::string ADDRESS_RADIX_GENERATE);

    std::string getDATA_RADIX_GENERATE() const;
    void setDATA_RADIX_GENERATE(std::string DATA_RADIX_GENERATE);

    int getMIN();
    void setMIN(int MIN);

    int getMAX();
    void setMAX(int MAX);

    int getNUMBER();
    void setNUMBER(int NUMBER);

    std::string getOPERATION() const;
    void setOPERATION(std::string OPERTAION);

    int getNUMBER_2();
    void setNUMBER_2(int NUMBER_2);

private:
    int _WIDTH;
    int _DEPTH;
    std::string _ADDRESS_RADIX;
    std::string _DATA_RADIX;
    std::string _DATA_RADIX_START;

    int _WIDTH_GENERATE;
    int _DEPTH_GENERATE;
    std::string _ADDRESS_RADIX_GENERATE;
    std::string _DATA_RADIX_GENERATE;

    int _MIN = 0;
    int _MAX = 0;
    int _NUMBER = 0;
    int _NUMBER_2 = 0;
    std::string _OPERATION;
};

#endif // SETTINGS_H
