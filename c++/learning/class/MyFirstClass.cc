#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
public:
    string name;
    string ownerName;
    int subscribers;
    list<string> publishedVideos;

    YouTubeChannel(string name, string ownerName, int subscribers)
    {
        this->name = name;
        this->ownerName = ownerName;
        this->subscribers = subscribers;
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Subscribers: " << subscribers << endl;
        cout << "Published videos: " << endl;
        for (string video : publishedVideos)
        {
            cout << video << endl;
        }
    }
};

int main()
{
    YouTubeChannel johnChannel("UCI", "John", 100);
    johnChannel.publishedVideos.push_back("Video 1");
    johnChannel.publishedVideos.push_back("Video 2");
    johnChannel.publishedVideos.push_back("Video 3");
    johnChannel.getInfo();
    return 0;
}