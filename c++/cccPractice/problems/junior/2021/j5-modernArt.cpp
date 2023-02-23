#include <iostream>
#include <algorithm>

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
    bool *canvas = new bool[r * c]{false};
    for (int i = 0; i < numBrushes; i++)
    {
        cin >> rowOrCol >> number;
        if (rowOrCol == 'R')
        {
            for (int j = 0; j < c; j++)
            {
                canvas[(number - 1) * c + j] = !canvas[(number - 1) * c + j];
            }
        }
        else
        {
            for (int j = 0; j < r; j++)
            {
                canvas[(number - 1) + c * j] = !canvas[(number - 1) + c * j];
            }
        }
    }
    cout << count_if(canvas, canvas + r * c, [](bool element)
                     { return element; });
}