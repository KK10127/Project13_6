/*
 * CHAPTER 13, PROJECT 6
 * CS 151
 * Tu 5:30-9:20 with Porto
 * Programmer: Jay Montoya
 *
 * PROBLEM STATEMENT:
 *      A program that processes an input file and produces an output file is called a filter.
 *      Write a program that asks the user for two filenames. The first file will be opened for input,
 *      and the second file will be opened for output. (It will be assumed that the first file contains
 *      sentences that end with a period.) The program will read the contents of the first file and change
 *      all the letters other than the first letter of sentences to lowercase. The first letter of
 *      sentences should be made uppercase. The revised contents should be stored in the second file.
 *
 *
 *
 *
 */
#include <iostream>
#include <fstream>
using namespace std;


int main() {

    string inputFileName, outputFileName, line;
    bool toUpper = true;
    char ch;

    cout << "Welcome to the demo of project 6!" << endl;
    cout << "Please enter an input file name: ";

    cin >> inputFileName;

    cout << "Please enteer an output file name: ";

    cin >> outputFileName;

    // opening file streams
    ifstream inFile;
    ofstream outFile;

    inFile.open(inputFileName, ios::in);
    outFile.open(outputFileName, ios::out);

    if (!inFile || !outFile) {
        cout << "Error opening file streams!" << endl;
        return 0;
    }

    // read the file one char at a time, if toUpper is flagged to true,
    // convert the char to uppercase. After each period, set toUpper to true.
    // after converting to uppercase, set toUpper to false;
    while(!inFile.eof()) {
       // get the next char
       inFile.get(ch);
       if(isalpha(ch) == 0 && (ch != '.')) {
           outFile.put(ch);
           continue;
       }
       if (toUpper) {
           ch = toupper(ch);
           toUpper = false;
       } else {
           ch = tolower(ch);
       }

       // if its a period then set toUpper
       if (ch == '.') {
           toUpper = true;
       }

       // put the char in the next file
       outFile.put(ch);
    }


    // housekeeping
    inFile.close();
    outFile.close();
    return 0;
}