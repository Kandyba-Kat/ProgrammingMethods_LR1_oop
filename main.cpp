﻿#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;
using namespace type_phrases;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Incorrect command line!\n" << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);
    if (!ifst.is_open()) {
        cout << "File is not open!" << endl;
        exit(1);
    }
    ofstream ofst(argv[2]);
    cout << "Start" << endl;
    container c;
    c.container_Fill(ifst);
    cout << "Filled container" << endl;
    c.container_Output(ofst);
    c.container_Clear();
    cout << "Empty container" << endl;
    c.container_Output(ofst);
    cout << "Stop" << endl;

    system("pause");
    return 0;
}

/*int main()
{
    ifstream ifst("In.txt");
    if (!ifst.is_open()) {
        cout << "File is not open!" << endl;
        exit(1);
    }
    else {
        /*string buff1 = "";

        while (true)
        {
            buff1 = "";
            ifst >> buff1;
            cout << buff1 << endl;
            if (ifst.eof()) break;
        }
    }
    ofstream ofst("Out.txt");

    cout << "Start" << endl;
    container c;
    c.container_Fill(ifst);
    cout << "Filled container" << endl;
    c.container_Output(ofst);
    c.container_Clear();
    cout << "Empty container" << endl;
    c.container_Output(ofst);
    cout << "Stop" << endl;
    ifst.close();

    system("pause");
    return 0;
}*/