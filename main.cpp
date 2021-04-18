#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;
using namespace type_phrases;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Incorrect command line! " << "Waited: command infile outfile" << endl;
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