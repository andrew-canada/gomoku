#include <stdio.h>
#include <vector>

using namespace std;

struct edge
{
    int from, to, cap, flow;
    edge *resid;
    edge(int f, int t, int c)
    {
        from = f;
        to = t;
        cap = c;
        flow = 0;
    };
};

vector<edge> EL[20];

int main()
{
    edge e1(1, 1, 1);
    edge e2(2, 2, 2);
    edge e3(3, 3, 3);
    edge e4(4, 4, 4);
    e2.resid = &e1;
    e1.resid = &e2;
    e3.resid = &e4;
    e4.resid = &e3;
    EL[1].push_back(e1);
    EL[2].push_back(e2);
    EL[3].push_back(e3);
    EL[4].push_back(e4);
    printf("d");
}