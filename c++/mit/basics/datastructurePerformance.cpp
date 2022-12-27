#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>

#include <stdio.h>

// rand() function
#include <stdlib.h>

// time functions
#include <chrono>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

using namespace std;

typedef long long ll;

template <typename Func>
long long getTime(Func f)
{
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

void buildVector(vector<int> &v, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        bool isInserted = false;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            if (*it > val)
            {
                v.insert(it, val);
                isInserted = true;
                break;
            }
        }
        if (isInserted == false)
        {
            v.push_back(val);
        }
    }
}

void buildQueue(queue<int> &q, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        q.push(val);
    }
}

void buildStack(stack<int> &s, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        s.push(val);
    }
}

void buildSet(set<int> &s, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        bool isInserted = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it > val)
            {
                s.insert(it, val);
                isInserted = true;
                break;
            }
        }
        if (isInserted == false)
        {
            s.insert(val);
        }
    }
}

void buildUnorderedSet(unordered_set<int> &s, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        bool isInserted = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it > val)
            {
                s.insert(it, val);
                isInserted = true;
                break;
            }
        }
        if (isInserted == false)
        {
            s.insert(val);
        }
    }
}

void buildMap(map<int, int> &s, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        bool isInserted = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (it->second > val)
            {
                s[it->first] = val;
                isInserted = true;
                break;
            }
        }
        if (isInserted == false)
        {
            s[i] = val;
        }
    }
}

void buildUMap(unordered_map<int, int> &s, int const size)
{
    for (int i = 0; i < size; i++)
    {
        int val = (int)rand();
        bool isInserted = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (it->second > val)
            {
                s[it->first] = val;
                isInserted = true;
                break;
            }
        }
        if (isInserted == false)
        {
            s[i] = val;
        }
    }
}

int main()
{
    const int size = 10'000;
    ll time = getTime(
        [&]()
        {
            std::vector<int> v1;
            buildVector(v1, size);
        });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::queue<int> q1;buildQueue(q1, size); });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::stack<int> s1;buildStack(s1, size); });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::set<int> s1;buildSet(s1, size); });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::unordered_set<int> s1;buildUnorderedSet(s1, size); });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::map<int, int> s1;buildMap(s1, size); });
    printf("%lld\n", time);

    time = getTime([&]()
                   {std::unordered_map<int, int> s1;buildUMap(s1, size); });
    printf("%lld\n", time);
}
