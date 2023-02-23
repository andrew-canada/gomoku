#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <iterator>

using namespace std;

class TextResponse
{
public:
    int waitTime;
    int friendNum;
    bool isReplied = false;
    bool isNewMsg = false;
    TextResponse(int waitTime, int friendNum)
    {
        this->waitTime = waitTime;
        this->friendNum = friendNum;
    }
    void print()
    {
        cout << "friendNum: " << friendNum << " waitTime: " << waitTime << " isReplied: " << isReplied << " isNewMsg: " << isNewMsg << endl;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    map<int, TextResponse> waitTimes;

    char recieveSentOrWait;
    bool isPreviousW = false;
    int friendNum, numLines;

    cin >> numLines;

    for (int i = 0; i < numLines; i++)
    {
        cin >> recieveSentOrWait >> friendNum;
        if (recieveSentOrWait == 'R')
        {

            if (waitTimes.count(friendNum) <= 0)
            {
                waitTimes.insert(make_pair(friendNum, TextResponse(isPreviousW ? 0 : -1, friendNum)));
            }
            else if (waitTimes.find(friendNum)->second.isReplied)
            {
                waitTimes.find(friendNum)->second.isReplied = false;
            }
        }
        if (recieveSentOrWait == 'S')
        {
            waitTimes.find(friendNum)->second.isReplied = true;

            waitTimes.find(friendNum)->second.isNewMsg = true;
            if (!isPreviousW)
            {
                waitTimes.find(friendNum)->second.waitTime += 1;
            }
        }

        for_each(begin(waitTimes), end(waitTimes),
                 [&waitTimes, &recieveSentOrWait, &friendNum, &isPreviousW](auto &element)
                 {
                     int addTime = 1;
                     if (recieveSentOrWait == 'W')
                     {
                         addTime = friendNum;
                     }
                     if (element.second.isNewMsg && recieveSentOrWait == 'R')
                     {
                         addTime = 0;
                         element.second.isNewMsg = false;
                     }
                     element.second.waitTime = element.second.waitTime + addTime;
                     if (isPreviousW || element.second.isReplied)
                     {
                         element.second.waitTime = element.second.waitTime - addTime;
                     }
                 });
        if (recieveSentOrWait == 'W')
        {
            isPreviousW = true;
        }
        else
        {
            isPreviousW = false;
        }
    }
    for_each(begin(waitTimes), end(waitTimes),
             [&waitTimes](auto &element)
             {
                 if (!element.second.isReplied)
                 {
                     element.second.waitTime = -1;
                 }
                 cout << element.first << " " << element.second.waitTime << endl;
             });
}