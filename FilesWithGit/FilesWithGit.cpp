// FilesWithGit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Jackets {
    string brand;
    string material;
    string color;
    string size;
    float price;
    Jackets(string br = "Supreme", string mt = "Leather", string clr = "Black", string sz = "L", float pr = 149.99) {
        brand = br;
        material = mt;
        color = clr;
        size = sz;
        price = pr;
        }
};

// Member 2 [
struct Jackets* InputJacket(struct Jackets* p_jacket){
    for (int i = 0; i < 5; i++) {
        cout << "\n[Jacket No. " << i + 1 << "]\n" << endl;
        cout << "Enter the Jacket Brand: ";
        cin >> (p_jacket + i)->brand;
        cout << "Enter the Jacket Material: ";
        cin >> (p_jacket + i)->material;
        cout << "Enter the Jacket Color: ";
        cin >> (p_jacket + i)->color;
        cout << "Enter the Jacket Size: ";
        cin >> (p_jacket + i)->size;
        cout << "Enter the Jacket Price: ";
        cin >> (p_jacket + i)->price;
    }

    return p_jacket;
}
// ] Member 2

int main()
{
    // Member 2 [
    struct Jackets jacket[5]; // Structure Array
    struct Jackets* p_jacket; // Structure Pointer
    p_jacket = jacket; // Assigning Pointer to Array
    fstream outfile; // Output file identifier
    ifstream infile;
    
    // Heading
    cout << "FilesWithGit - Jacket System" << endl;
    cout << "----------------------------\n" << endl;

    // Input Function
    p_jacket = InputJacket(p_jacket);

    

    outfile.open("jacket.txt", ios::out); // Opening File for outputting the user's input into a text file.

    // Loop for output.
    for (int i = 0; i < 5; i++) {
        outfile << "\n[Jacket No. " << i + 1 << "]\n" << endl;
        outfile << "Brand: " << (p_jacket + i)->brand << endl;
        outfile << "Material: " << (p_jacket + i)->material << endl;
        outfile << "Color: " << (p_jacket + i)->color << endl;
        outfile << "Size: " << (p_jacket + i)->size << endl;
        outfile << "Price: $" << (p_jacket + i)->price << endl;
    }

    outfile.close(); // Closing File

    // ] Member 2

    // Member 1 [

    infile.open("jacket.txt", ios::in); // Opening file for input.
    string str; // String to assign with getline
    while (getline(infile, str)) { // File input loop
        cout << str << endl;
    }

    string insize; // Size search input
    cout << "\nSearch by Size: ";
    cin >> insize;
    
    bool resultsFound = false; // Results Found checker
    int results = 0; // Counter for amount of results found

    // Loop for searching the data.
    for (int i = 0; i < 5; i++) {
        cout << "\nSearching..." << endl;
        if (insize == (p_jacket + i)->size) {
            cout << "\nFound!: " << endl;
            cout << "\n[Jacket No. " << i + 1 << "]\n" << endl;
            cout << "Brand: " << (p_jacket + i)->brand << endl;
            cout << "Material: " << (p_jacket + i)->material << endl;
            cout << "Color: " << (p_jacket + i)->color << endl;
            cout << "Size: " << (p_jacket + i)->size << endl;
            cout << "Price: $" << (p_jacket + i)->price << endl;
            resultsFound = true;
            results = results + 1;
        }
    }
    // Conditional to check if any results were found in the search and to print out a different closing text based on the result.
    if (resultsFound == true) {
        cout << "\nFound " << results << " results!" << endl;
    }
    else {
        cout << "\nNo results were found!" << endl;
    }

    infile.close(); // Closing File

    // ] Member 1

    return 0;

}

