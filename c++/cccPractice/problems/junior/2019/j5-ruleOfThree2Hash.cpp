#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

// #define LOCAL

using namespace std;

char word1[51];
char word2[51];
string rro[3]; // rro replacement rule origin
string rrr[3]; // rrr replacement rule result
vector<int> visited;
stack<string> nums;
stack<string> ns; // node stack
// string cs;        // current sequence
string ts; // target sequence
int steps;
int currentSteps;
string tempSequence;
int numPushed = 0;
bool nnf; // new node found
vector<string> results;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
#endif

    // visited.resize(1000000);
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
    // nums.push("filler");
    ts = s2;

    while (true)
    {
        // printf("top\n");
        // printf("%d\n", ns.size());
        // printf("%d\n", nums.size());
        string cs = ns.top();
        // printf("%d\n", visited.size());
        // printf("%d\n", ns.size());
        if (cs == ts)
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
            return 0;
        }
        visited.push_back(hash<std::string>{}(cs));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < cs.size(); j++)
            {
                int index = cs.find(rro[i], j);
                if (index != string::npos && ns.size() <= steps)
                {
                    // printf("current seq: %s | %d %d %s %s\n", cs.c_str(), i, index, rro[i].c_str(), rrr[i].c_str());
                    tempSequence = cs.substr(0, index) + rrr[i] + cs.substr(index + rro[i].size());
                    int hashedTempSeq = hash<std::string>{}(tempSequence);
                    // printf("tempseq: %s\n", tempSequence.c_str());
                    if (find(visited.begin(), visited.end(), hashedTempSeq) == visited.end())
                    {
                        // printf("never visited\n");
                        ns.push(tempSequence);
                        nums.push(to_string(i + 1) + " " + to_string(index + 1));
                        currentSteps++;
                        visited.push_back(hashedTempSeq);
                        nnf = true;
                        break;
                    }
                    // printf("after if\n");
                }
            }
        }
        if (!nnf)
        {
            // printf("before\n");
            // printf("%d\n", ns.size());
            // printf("%d\n", nums.size());
            ns.pop();
            nums.pop();
            currentSteps--;
            // printf("end\n");
        }
        nnf = false;
    }
}