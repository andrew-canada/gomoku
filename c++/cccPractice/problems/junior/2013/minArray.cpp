#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1, 1, 2, 3};
    cout << "size" << nums.size() << '\n';
    nums.erase(nums.begin());
    cout << "size" << nums.size() << '\n';
    int pos = find(nums.begin(), nums.end(), *min_element(nums.begin(), nums.end())) - nums.begin();
    nums.erase(nums.begin() + pos);
    cout << "size" << nums.size() << '\n';
}