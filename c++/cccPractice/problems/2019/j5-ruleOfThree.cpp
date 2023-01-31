#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

char word1[51];
char word2[51];
std::string start[3];
std::string end[3];
std::vector<std::string> visited;
std::stack<std::string> positions;
std::string currentPos;
int steps;
int currentSteps;
std::string tmpPos;

int main()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%s %s", &word1, &word2);
        std::string s1(word1);
        std::string s2(word2);
        start[i] = s1;
        end[i] = s2;
    }

    scanf("%d %s %s", &steps, &word1, &word2);
    std::string startPos = word1;
    std::string endPos = word2;
    int stepDepth = steps;

    std::stack<std::string> positions;
    positions.push(startPos);

    while (true)
    {
        while (currentSteps < steps)
        {
            currentPos = positions.top();
            if (currentPos == endPos)
            {
                while (!positions.empty())
                {
                    printf("%s\n", positions.top().c_str());
                    positions.pop();
                }
                return 0;
            }

            for (int i = 0; i < 3; i++)
            {
                if (currentPos.find(start[i]) != std::string::npos)
                {
                    int index = currentPos.find(start[i]);
                    tmpPos = currentPos.substr(0, index) + end[i] + currentPos.substr(index + start[i].size());
                    if (std::find(visited.begin(), visited.end(), tmpPos) == visited.end())
                    {
                        positions.push(tmpPos);
                        if (positions.top() == endPos)
                        {
                            while (!positions.empty())
                            {
                                printf("%s\n", positions.top().c_str());
                                positions.pop();
                            }
                            return 0;
                        }
                        break;
                    }
                }
            }
            visited.push_back(currentPos);
            currentSteps += 1;
        }
        positions.pop();
        currentSteps -= 1;
        stepDepth -= 1;
        visited.erase(visited.begin() + stepDepth);
        visited.push_back(tmpPos);
    }
}
