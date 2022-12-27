#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Message
{
public:
    int waitTime;
    int friendNum;
    bool isReplied = false;
    bool isNewMsg = false;
    Message(int waitTime, int friendNum)
    {
        this->waitTime = waitTime;
        this->friendNum = friendNum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    map<int, Message> waitTimes;
    char msgType;
    int numLines, friendNum;
    bool isPreviousW = false;
    cin >> numLines;

    for (int i = 0; i < numLines; i++)
    {
        cin >> msgType >> friendNum;

        if (msgType == 'R')
        {
            if (waitTimes.count(friendNum) <= 0)
            {
                waitTimes.insert(make_pair(friendNum, Message((isPreviousW ? 0 : -1), friendNum)));
            }
            else if (waitTimes.find(friendNum)->second.isReplied)
            {
                waitTimes.find(friendNum)->second.isReplied = false;
            }
        }
        if (msgType == 'S')
        {
            waitTimes.find(friendNum)->second.isReplied = true;
            waitTimes.find(friendNum)->second.isNewMsg = true;
            if (!isPreviousW)
            {
                waitTimes.find(friendNum)->second.waitTime += 1;
            }
        }
        for_each(begin(waitTimes), end(waitTimes),
                 [&waitTimes, &friendNum, &msgType, &isPreviousW](auto &elem)
                 {
                     int addTime = 1;
                     if (msgType == 'W')
                     {
                         addTime = friendNum;
                     }
                     if (elem.second.isNewMsg && msgType == 'R')
                     {
                         addTime = 0;
                         elem.second.isNewMsg = false;
                     }
                     elem.second.waitTime += addTime;
                     if (isPreviousW || elem.second.isReplied)
                     {
                         elem.second.waitTime -= addTime;
                     }
                 });
        if (msgType == 'W')
        {
            isPreviousW = true;
        }
        else
        {
            isPreviousW = false;
        }
    }

    for_each(begin(waitTimes), end(waitTimes),
             [&waitTimes](auto &elem)
             {
                 if (!elem.second.isReplied)
                 {
                     elem.second.waitTime = -1;
                 }
                 cout << elem.first << " " << elem.second.waitTime << endl;
             });
}