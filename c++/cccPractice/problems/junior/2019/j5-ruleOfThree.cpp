#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

#define LOCAL

char word1[51];
char word2[51];
std::string start[3];
std::string end[3];
std::vector<std::string> visited;
std::deque<std::pair<int, int>> nums;
std::string currentSequence;
int steps;
int currentSteps;
std::string tempSequence;
int numPushed = 0;
bool notFound;

int main()
{
#ifdef LOCAL:
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int i = 0; i < 3; i++)
    {
        scanf("%s %s", &word1, &word2);
        std::string s1(word1);
        std::string s2(word2);
        start[i] = s1;
        end[i] = s2;
    }

    scanf("%d %s %s", &steps, &word1, &word2);
    std::string startSequence = word1;
    std::string endSequence = word2;
    int stepDepth = steps;

    std::deque<std::string> sequenceQueue;
    sequenceQueue.push_back(startSequence);

    while (true)
    {
        while (currentSteps < steps)
        {
            currentSequence = sequenceQueue.back();

            if (currentSequence == endSequence)
            {
                sequenceQueue.pop_front();
                while (!sequenceQueue.empty())
                {
                    printf("%d %d %s\n", nums.front().first, nums.front().second, sequenceQueue.front().c_str());
                    sequenceQueue.pop_front();
                    nums.pop_front();
                }
                return 0;
            }

            for (int i = 0; i < 3; i++)
            {
                if (currentSequence.find(start[i]) != std::string::npos)
                {
                    int index = currentSequence.find(start[i]);
                    tempSequence = currentSequence.substr(0, index) + end[i] + currentSequence.substr(index + start[i].size());
                    if ((std::find(visited.begin(), visited.end(), tempSequence) == visited.end()))
                    {
                        numPushed += 1;
                        currentSteps += 1;
                        sequenceQueue.push_back(tempSequence);
                        visited.push_back(currentSequence);
                        nums.push_back(std::make_pair(i + 1, index + 1));
                        if (sequenceQueue.back() == endSequence)
                        {
                            sequenceQueue.pop_front();
                            while (!sequenceQueue.empty())
                            {
                                printf("%d %d %s\n", nums.front().first, nums.front().second, sequenceQueue.front().c_str());
                                sequenceQueue.pop_front();
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
                    sequenceQueue.push_back(tempSequence);
                    visited.push_back(currentSequence);
                    // dummy value
                    nums.push_back(std::make_pair(1, 1));
                    notFound = true;
                    break;
                }
            }
        }

        if (sequenceQueue.size() > steps)
        {
            sequenceQueue.pop_back();
            nums.pop_back();
        }
        currentSteps -= 1;

        if (!notFound)
        {
            visited.erase(visited.end());
        }
        visited.push_back(tempSequence);
        if (numPushed < sequenceQueue.size() && notFound)
        {
            sequenceQueue.erase(sequenceQueue.begin() + numPushed);
        }

        notFound = false;
        numPushed = 0;
    }
}