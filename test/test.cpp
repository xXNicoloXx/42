#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream ofs( "myfile.txt" );
    ofs << "line 1\n";
    ofs << char(26);
    ofs << "line 2\n";
}
