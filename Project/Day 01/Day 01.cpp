// Day 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>                                 // I / O with Files
#include <fstream>                                  // I / O with Files
#include <string>


/// <summary>
/// Reads the Input from the ..\Resources and saves the data
/// </summary>
int ReadInput() {

    std::string mFileString;
    std::ifstream mFile;
    int sum = 0;
    int nElfMax = 0;
    int totalElves = 0;
    int topOne = 0;


    mFile.open("Input.txt");

    while (getline(mFile, mFileString)) {
        // Try to parse the String to int

        if (mFileString != "") {                                // Add Calorioes to the Number
            sum += std::stoi(mFileString);
        }
        else                                                    // Save the number if bigger
        {
            if (totalElves == 230) {

				std::cout << "\n";
            }
            if (sum > topOne) {
                topOne = sum;                            // Save the new Value of Calories
                nElfMax = totalElves;                           // Store the # of Elf that has the grater Calorie value
            }
            sum = 0;                                            // Reset to 0
            totalElves++;                                       // Increase the number of Elves
        }
    }
	totalElves++;
    std::cout << "Total Elves:  ---  " << totalElves << "\n";
    std::cout << "Bigger Elf:   ---  " << nElfMax << "\n";
    mFile.close();                                  // Closes the file in case we want to use it again.
    return topOne;
}

int main()
{
    int a = ReadInput();

    std::cout << "Calories:     ---  " << a << "\n";
}