#include <fstream>

using namespace std;

int main()
{
    // choose source file - represented by ifstream object
    ifstream source("fileInput.txt");
    // choose output file - represented by ofstream object
    ofstream destination("fileOutput.txt");
    int x;
    for (int i = 0; i < 5; i++)
    {
        // reads one int from source file
        source >> x;
        // writes to destination file
        destination << x;
    }
    // automatically closed by destructor, but close ASAP is best practice
    source.close();
}