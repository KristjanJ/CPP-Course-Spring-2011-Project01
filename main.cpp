#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

#include "functions.h"

bool isNumeric(const char* input);
void calculate(long a, long b);
bool process(const char* arg1, const char* arg2);

int main(int argc, char** argv)
{
    int errorCode  = EXIT_FAILURE;

    if (argc == 3)
    {
        bool result = process(argv[1], argv[2]);

        if (result)
        {
            errorCode = EXIT_SUCCESS;
        }
    }
    else if (argc == 2)
    {
        std::ifstream inputFileStream;
        inputFileStream.open(argv[1]);

        if (inputFileStream.is_open())
        {
            std::string str1;
            std::string str2;

            inputFileStream >> str1;
            inputFileStream >> str2;

            inputFileStream.close();

            if (!inputFileStream.fail())
            {
                bool result = process(str1.c_str(), str2.c_str());

                if (result)
                {
                    errorCode = EXIT_SUCCESS;
                }
            }
            else
            {
                std::cout << "ERROR: Failed to read from file " << argv[1] << std::endl;
            }
        }
        else
        {
            std::cout << "ERROR: Unable to open file " << argv[1] << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Invalid number of arguments." << std::endl;
    }

    //std::cout << "ERRORCODE: " << errorCode << std::endl;
    return errorCode;
}

bool process(const char* arg1, const char* arg2)
{
    if (isNumeric(arg1) && isNumeric(arg2))
    {
        long number1 = atol(arg1);
        long number2 = atol(arg2);

        calculate(number1, number2);

        return true;
    }
    else
    {
        std::cout << "ERROR: Invalid number format. Expected two integers." << std::endl;

        return false;
    }
}

void calculate(long a, long b)
{
    std::cout << a << " " << b << std::endl;
    std::cout << minimum(a, b) << std::endl;
    std::cout << maximum(a, b) << std::endl;
    std::cout << sum(a, b) << std::endl;
    std::cout << product(a, b) << std::endl;
    std::cout << gcd(a, b) << std::endl;
}

bool isNumeric(const char* input)
{
    bool result = true;

    size_t length = strlen(input);

    for (unsigned int i = 0; i < length; i++)
    {
        bool validChar = false;

        if (i == 0 && (input[i] == '-' || input[i] == '+'))
        {
            continue;
        }

        for (char j = '0'; j <= '9'; j++)
        {
            if (input[i] == j)
            {
                validChar = true;
                break;
            }
        }

        if (!validChar)
        {
            result = false;
            break;
        }
    }

    return result;
}
