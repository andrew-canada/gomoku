#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>

// #define LOCAL

using namespace std;

typedef vector<int> vi;

int cases;
string in;
string vals[1000000];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &cases);
    getline(cin, in);
    for (int i = 0; i < cases; i++)
    {
        vi index;

        getline(cin, in);
        getline(cin, in);
        stringstream ss(in);
        int ind;
        while (ss >> ind)
        {
            index.push_back(ind - 1);
        }

        getline(cin, in);
        stringstream ss2(in);
        string val;
        int insert = 0;
        while (ss2 >> val)
        {
            vals[index[insert++]] = val;
        }

        for (int i = 0; i < index.size(); i++)
        {
            printf("%s\n", vals[i].c_str());
        }

        if (i != cases - 1)
        {
            printf("\n");
        }
    }
}