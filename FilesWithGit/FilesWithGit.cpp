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

int main()
{

}

