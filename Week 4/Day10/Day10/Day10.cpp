// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string fileName = "pg2_2501.csv";
    std::string path = "C:\\temp\\2501\\";
    std::string fullPath = path + fileName;

    char delimiter = '!';
    
    //1. open the file
    std::ofstream outFile(fullPath);
    if (outFile.is_open())
    {
        //2. write to the file
        // << insertion operator
        outFile << "Batman is the best.";
        outFile << delimiter << "F5";
        outFile << delimiter << true << delimiter << 420.12;
        outFile << delimiter << "Aquaman smells like fish.";
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }


    //3. close the file
    outFile.close();

    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */

    //1. Open the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2. read the file
        std::string input;
        std::getline(inFile, input);//reads 1 line from the file. looks for '\n'
        std::cout << input << "\n";
        
        std::string data;
        std::stringstream inputStream(input);
        std::getline(inputStream, data, delimiter);
        std::cout << data << "\n";

        try
        {
            std::getline(inputStream, data, delimiter);
            int iData = std::stoi(data);
            std::cout << iData << "\n";
        }
        catch (const std::exception&ex)
        {
            std::cout << ex.what() << "\n";
        }
        std::getline(inputStream, data, delimiter);
        bool bData = std::stoi(data) == 1;
        std::cout << bData << "\n";


        std::getline(inputStream, data, delimiter);
        double dData = std::stod(data);
        std::cout << dData << "\n";

        std::getline(inputStream, data, delimiter);
        std::cout << data << "\n";
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3. close the file
    inFile.close();





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}