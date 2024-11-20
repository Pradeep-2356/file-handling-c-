#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int i;

    ofstream outfile("data.txt");
    if (!outfile.is_open()) {
        cout << "Error! File cannot be opened!" << endl;
        return 1;
    }
    for (i = 200; i <= 500; i++) {
        outfile << i << endl;
    }
    outfile.close();
    cout << "File data.txt created successfully." << endl;

   
    ifstream infile("data.txt");
    ofstream oddFile("odd.txt");
    ofstream evenFile("even.txt");
    ofstream primeFile("prime.txt");

    if (!infile.is_open() || !oddFile.is_open() || !evenFile.is_open() || !primeFile.is_open()) {
        cout << "Error! File cannot be opened!" << endl;
        return 1;
    }

    int n;
   
    while (infile >> n) {
        if (n % 2 != 0) {
            oddFile << n << endl;
        } else {
            evenFile << n << endl;
        }
    }

   
    infile.clear();
    infile.seekg(0, ios::beg);
   
    ifstream read_odd("odd.txt");

   
    while (read_odd >> n) {
        int f = 1;
        if (n <= 1) {
            f=0;
        } else {
            for (int j = 2; j * j <= n; ++j) {
                if (n % j == 0) {
                    f=0;
                    break;
                }
            }
        }

        if (f==1) {
            primeFile << n << endl;
        }
    }

    infile.close();
    oddFile.close();
    evenFile.close();
    primeFile.close();

    cout << "Files odd.txt, even.txt, and prime.txt created successfully." << endl;

    return 0;
}