#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

#define LOCAL

using namespace std;

char word1[51];
char word2[51];
string rro[3]; // rro replacement rule origin
string rrr[3]; // rrr replacement rule result
stack<string> nums;
stack<string> ns; // node stack
string ts;        // target sequence
int steps;
string tempSequence;
int numPushed = 0;
bool nnf; // new node found
vector<string> results;

bool solve(int currentSteps, string cs)
{
    if (currentSteps == steps)
    {
        return cs == ts;
    }
    for (int i = 0; i < 3; i++)
    {
        int index = cs.find(rro[i]);
        while (index != string::npos)
        {
            printf("current seq: %s | %d %d %s %s\n", cs.c_str(), i, index, rro[i].c_str(), rrr[i].c_str());
            cs = cs.substr(0, index) + rrr[i] + cs.substr(index + rro[i].size());
            printf("tempseq: %s\n", tempSequence.c_str());

            ns.push(cs);
            if (solve(currentSteps + 1, cs))
            {
                return true;
            }
            // nums.push(to_string(i + 1) + " " + to_string(index + 1));
            ns.pop();
            index = cs.find(rro[i]);
        }
    }
    if (!nnf)
    {
        ns.pop();
        nums.pop();
        currentSteps--;
    }
    nnf = false;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
#endif

    for (int i = 0; i < 3; i++)
    {
        scanf("%s %s", &word1, &word2);
        string s1(word1);
        string s2(word2);
        rro[i] = s1;
        rrr[i] = s2;
    }

    scanf("%d %s %s", &steps, &word1, &word2);
    string s1(word1);
    string s2(word2);
    ns.push(s1);
    ts = s2;

    int currentSteps = 0;
    string cs; // current sequence

    if (solve(0, cs))
    {
        while (!nums.empty())
        {
            results.push_back(nums.top() + " " + ns.top());
            ns.pop();
            nums.pop();
        }
        reverse(results.begin(), results.end());
        for (string s : results)
        {
            printf("%s\n", s.c_str());
        }
    }
}