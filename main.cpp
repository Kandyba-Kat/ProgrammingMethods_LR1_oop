#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;
using namespace type_phrases;

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        cout << "Incorrect command line!\n" << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);
    if (!ifst.is_open()) {
        cout << "Input file is not open!" << endl;
    }
    else {
        ofstream ofst(argv[2]);
        if (!ofst.is_open()) {
            cout << "Output file is not open!" << endl;
        }
        else {
            cout << "Start" << endl;
            container c;
            c.Cont_Fill(ifst);
            cout << "Filled container" << endl;
            c.Cont_Output(ofst);          
            cout << "Output container" << endl;
            ofst << "\n" << endl;

            c.MultiMethod(ofst);
            cout << "Multimethod worked" << endl;
            ofst << "\n" << endl;

            c.Sort();
            cout << "Sorted container" << endl;
            c.Cont_Output(ofst);
            ofst << "\n" << endl;
            c.Cont_Output_Aphos(ofst);
            cout << "Output only aphorism" << endl;
            c.Cont_Clear();
            cout << "Empty container" << endl;
            c.Cont_Output(ofst);
            cout << "Stop" << endl;

            ifst.close();
            ofst.close();
        }
    }
    system("pause");
    return 0;
}