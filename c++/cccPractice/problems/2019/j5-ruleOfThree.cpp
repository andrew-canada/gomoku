#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

char word1[51];
char word2[51];
std::string start[3];
std::string end[3];
std::vector<std::string> visited;
std::deque<std::pair<int, int>> nums;
std::string currentPos;
int steps;
int currentSteps;
std::string tmpPos;
bool first = true;
int numPushed = 0;
bool notFound;

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
    // int stepDepth = 0;

    std::deque<std::string> positions;
    positions.push_back(startPos);

    while (true)
    {
        while (currentSteps < steps)
        {
            stepDepth = positions.size();
            if (first)
            {
                currentPos = startPos;
            }
            else
            {
                // if (tmpPos == visited.back())
                // {
                //     currentPos = startPos;
                // }
                // else
                // {
                currentPos = positions.back();
                //}
            }
            first = false;
            if (currentPos == endPos)
            {
                // positions.erase(positions.begin());
                positions.pop_front();
                while (!positions.empty())
                {
                    printf("%d %d %s\n", nums.front().first, nums.front().second, positions.front().c_str());
                    positions.pop_front();
                    nums.pop_front();
                }
                return 0;
            }

            for (int i = 0; i < 3; i++)
            {
                if (currentPos.find(start[i]) != std::string::npos)
                {
                    int index = currentPos.find(start[i]);
                    tmpPos = currentPos.substr(0, index) + end[i] + currentPos.substr(index + start[i].size());
                    if ((visited.size() == 0) || /*(tmpPos == visited.at(0)) ||*/ (std::find(visited.begin(), visited.end(), tmpPos) == visited.end()))
                    {
                        numPushed += 1;
                        currentSteps += 1;
                        positions.push_back(tmpPos);
                        // visited.push_back(currentPos);
                        visited.push_back(currentPos);
                        nums.push_back(std::make_pair(i + 1, index + 1));
                        if (positions.back() == endPos)
                        {
                            // positions.erase(positions.begin());
                            positions.pop_front();
                            while (!positions.empty())
                            {
                                printf("%d %d %s\n", nums.front().first, nums.front().second, positions.front().c_str());
                                positions.pop_front();
                                nums.pop_front();
                            }
                            return 0;
                        }
                        break;
                    }
                }
                if (i == 2)
                {
                    numPushed += 1;
                    currentSteps += 1;
                    positions.push_back(tmpPos);
                    // visited.push_back(currentPos);
                    visited.push_back(currentPos);
                    // dummy value
                    nums.push_back(std::make_pair(1, 1));
                    notFound = true;
                    break;
                }
            }
        }

        if (positions.size() > steps)
        {
            positions.pop_back();
            nums.pop_back();
        }
        currentSteps -= 1;

        // visited.erase(visited.begin() + stepDepth);
        // stepDepth += 1;
        if (!notFound)
        {
            visited.erase(visited.end());
        }
        stepDepth -= 1;
        visited.push_back(tmpPos);
        if (numPushed < positions.size() && notFound)
        {
            positions.erase(positions.begin() + numPushed);
        }

        notFound = false;
        numPushed = 0;
    }
}