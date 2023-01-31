#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

char word1[51];
char word2[51];
std::string start[3];
std::string end[3];
std::vector<std::string> visited;
std::stack<std::string> positions;
std::string currentPos;
int steps;
int currentSteps = 0;

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

    positions.push(startPos);
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
        }
        if (std::find(visited.begin(), visited.end(), currentPos) == visited.end())
        {
            for (int i = 0; i < 3; i++)
            {
                if (currentPos.find(visited[i]) != std::string::npos)
                {
                    int index = currentPos.find(visited[i]);
                    positions.push(currentPos.substr(0, index) + end[i] + currentPos.substr(index + 1));
                }
            }
            visited.push_back(currentPos);
        }
    }
}