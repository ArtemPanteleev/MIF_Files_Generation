#include "file.h"

File::File(const std::string &fileName, const std::string &fileNameresult,char sep): _fileName(fileName), _fileNameresult(fileNameresult), _sep(sep)
{
    int WIDTH = Settings::instanse()->getWIDTH();
    unsigned int DEPTH = Settings::instanse()->getDEPTH();
    std::string ADDRESS_RADIX = Settings::instanse()->getADDRESS_RADIX();
    std::string DATA_RADIX = Settings::instanse()->getDATA_RADIX();
    std::string DATA_RADIX_START = Settings::instanse()->getDATA_RADIX_START();

    std::fstream file;
    file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
    std::ofstream out;
    out.open(fileNameresult, std::ofstream::out | std::ofstream::trunc);

    unsigned int counter = 0;
    unsigned int n = 0;
    unsigned int bits = std::pow(2, WIDTH) - 1;
    unsigned int res = 0;

    if(!file)
    {
        throw std::runtime_error("open: Invalid File, try another File");
    }
    else
    {
        file.seekg(0);
        std::string line = "";

        out << "WIDTH = " << WIDTH << ";" << std::endl;
        out << "DEPTH = " << DEPTH << ";" << std::endl;
        out << "ADDRESS_RADIX = " << ADDRESS_RADIX << ";" << std::endl;
        out << "DATA_RADIX = " << DATA_RADIX << ";" << std::endl;

        out << "" << std::endl;
        out << "CONTENT BEGIN" << std::endl;
        while(getline(file, line, sep))
        {
            if (out.is_open())
            {
                std::istringstream del(line);
                std::string new_string = "";
                while(getline(del, new_string))
                {
                    if(DATA_RADIX_START == "UNS")
                    {
                        std::istringstream(new_string) >> std::dec >> n;
                    }
                    else if(DATA_RADIX_START== "HEX")
                    {
                        std::istringstream(new_string) >> std::hex >> n;
                    }
                    else if(DATA_RADIX_START == "OCT")
                    {
                        std::istringstream(new_string) >> std::oct >> n;
                    }
                    else if(DATA_RADIX_START == "BIN")
                    {
                        std::istringstream(new_string) >> std::dec >> n;
                        std::bitset<8>(n);
                    }

                    res = n & bits;

                    if(ADDRESS_RADIX == "UNS")
                    {
                        out << std::dec << counter << "    " << ":" << "    ";
                    }
                    else if(ADDRESS_RADIX == "HEX")
                    {
                        out << std::hex << counter << "    " << ":" << "    ";
                    }
                    else if(ADDRESS_RADIX == "OCT")
                    {
                        out << std::oct << counter << "    " << ":" << "    ";
                    }
                    else if(ADDRESS_RADIX == "BIN")
                    {
                        out << std::bitset<8>(counter) << "    " << ":" << "    ";
                    }


                    if(DATA_RADIX == "UNS")
                    {
                        out << std::dec << res << ";" << std::endl;
                    }
                    else if(DATA_RADIX == "HEX")
                    {
                        out << std::hex << res << ";" << std::endl;
                    }
                    else if(DATA_RADIX == "OCT")
                    {
                        out << std::oct << res << ";" << std::endl;
                    }
                    else if(DATA_RADIX == "BIN")
                    {
                        std::string temp = "";
                        for(int i = 0; i < WIDTH; i++)
                        {
                            temp += std::to_string(res % 2);
                            res /= 2;
                        }
                        reverse(temp.begin(), temp.end());
                        out << temp << ";" << std::endl;
                    }

                    counter++;
                    if(counter > DEPTH - 1)
                    {
                        break;
                    }
                }
            }
        }
    }

    file.close();
    out << "END;" << std::endl;
    out.close();
}

void File::Generate(const std::string fileNamegenerate)
{
    const int WIDTH_GENERATE = Settings::instanse()->getWIDTH_GENERATE();
    unsigned int DEPTH_GENERATE = Settings::instanse()->getDEPTH_GENERATE();
    std::string ADDRESS_RADIX_GENERATE = Settings::instanse()->getADDRESS_RADIX_GENERATE();
    std::string DATA_RADIX_GENERATE = Settings::instanse()->getDATA_RADIX_GENERATE();
    int MIN = Settings::instanse()->getMIN();
    int MAX = Settings::instanse()->getMAX();
    int NUMBER = Settings::instanse()->getNUMBER();
    std::string OPERATION = Settings::instanse()->getOPERATION();
    int NUMBER_2 = Settings::instanse()->getNUMBER_2();

    std::ofstream out;
    out.open(fileNamegenerate, std::ofstream::out | std::ofstream::trunc);

    unsigned int counter = 0;
    unsigned int n = 0;
    unsigned int result = 0;
    unsigned int bits = std::pow(2, WIDTH_GENERATE) - 1;
    int res = 0;

    out << "WIDTH = " << WIDTH_GENERATE << ";" << std::endl;
    out << "DEPTH = " << DEPTH_GENERATE << ";" << std::endl;
    out << "ADDRESS_RADIX = " << ADDRESS_RADIX_GENERATE << ";" << std::endl;
    out << "DATA_RADIX = " << DATA_RADIX_GENERATE << ";" << std::endl;

    out << "" << std::endl;
    out << "CONTENT BEGIN" << std::endl;
    while(counter < DEPTH_GENERATE)
    {
        n += ((MIN + MAX) / DEPTH_GENERATE);

        if(OPERATION == "ADDITION")
        {
            result = (n + NUMBER) * NUMBER_2;
        }
        else if(OPERATION == "SUBTRACTION")
        {
            result = (n - NUMBER) * NUMBER_2;
        }
        else if(OPERATION == "MULTIPLICATION")
        {
            result = (n * NUMBER) * NUMBER_2;
        }
        else if(OPERATION == "DIVISION")
        {
            result = (n / NUMBER) * NUMBER_2;
        }
        else if(OPERATION == "DEGREE")
        {
            result = std::pow(n, NUMBER) * NUMBER_2;
        }
        else if(OPERATION == "RADICAL")
        {
            result = std::sqrt(n) * NUMBER_2;
        }
        else if(OPERATION == "COSINE")
        {
            result = std::cos(n) * NUMBER_2;
        }
        else if(OPERATION == "SINUS")
        {
            result = std::sin(n) * NUMBER_2;
        }
        else if(OPERATION == "ZERO")
        {
            result = 0;
        }

        res = result & bits;

        if(ADDRESS_RADIX_GENERATE == "UNS")
        {
            out << std::dec << counter << "    " << ":" << "    ";
        }
        else if(ADDRESS_RADIX_GENERATE == "HEX")
        {
            out << std::hex << counter << "    " << ":" << "    ";
        }
        else if(ADDRESS_RADIX_GENERATE == "OCT")
        {
            out << std::oct << counter << "    " << ":" << "    ";
        }
        else if(ADDRESS_RADIX_GENERATE == "BIN")
        {
            out << std::bitset<8>(counter) << "    " << ":" << "    ";
        }


        if(DATA_RADIX_GENERATE == "UNS")
        {
            out << std::dec << res << ";" << std::endl;
        }
        else if(DATA_RADIX_GENERATE == "HEX")
        {
            out << std::hex << res << ";" << std::endl;
        }
        else if(DATA_RADIX_GENERATE == "OCT")
        {
            out << std::oct << res << ";" << std::endl;
        }
        else if(DATA_RADIX_GENERATE == "BIN")
        {
            std::string temp = "";
            for(int i = 0; i < WIDTH_GENERATE; i++)
            {
                temp += std::to_string(res % 2);
                res /= 2;
            }
            reverse(temp.begin(), temp.end());
            out << temp << ";" << std::endl;
        }

        counter++;

    }
    out << "END;" << std::endl;
    out.close();
}

File::~File()
{

}
