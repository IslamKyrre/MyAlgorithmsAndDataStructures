#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
 
using namespace std;
 
 
int main() {
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    int n;
    fin >> n;
    fout << n / 5 + n / 25 + n / 125 + n / 625;
    fout.close();
    return 0;
}