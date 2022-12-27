#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//#define LOCAL

int main()
{
    ios_base::sync_with_stdio(false);
    int r = 0, c = 0, numBrushes = 0;
    char rowOrCol;
    int number;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    cin >> r >> c >> numBrushes;
    map<int, bool> parityOfRowsMap;
    map<int, bool> parityOfColumnsMap;
    for (int i = 0; i < numBrushes; i++)
    {
        cin >> rowOrCol >> number;
        if (rowOrCol == 'R')
        {
            map<int, bool>::iterator it = parityOfRowsMap.find(number);
            if (it == parityOfRowsMap.end())
            {
                parityOfRowsMap.insert({number, true});
            }
            else
            {
                it->second = !it->second;
            }
        }
        else
        {
            map<int, bool>::iterator it = parityOfColumnsMap.find(number);
            if (it == parityOfColumnsMap.end())
            {
                parityOfColumnsMap.insert({number, true});
            }
            else
            {
                it->second = !it->second;
            }
        }
    }
    int numPaintedRows = count_if(begin(parityOfRowsMap), end(parityOfRowsMap),
                                  [](const pair<int, bool> &p)
                                  { return p.second; });
    int numPaintedColumns = count_if(begin(parityOfColumnsMap), end(parityOfColumnsMap),
                                     [](const pair<int, bool> &p)
                                     { return p.second; });
    cout << numPaintedRows * c + numPaintedColumns * r - 2 * numPaintedRows * numPaintedColumns;
}