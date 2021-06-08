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

    return 0;

}

