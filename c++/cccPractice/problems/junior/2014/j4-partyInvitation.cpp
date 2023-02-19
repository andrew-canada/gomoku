#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename P>
vector<T> filter(const vector<T> &v, P predicate);

int main()
{
    int numFriends, numRounds, removalFactor;

    vector<int> friendVector;

    scanf("%d%d", &numFriends, &numRounds);

    for (int i = 1; i <= numFriends; i++)
    {
        friendVector.push_back(i);
    }
    vector<int> filteredVector = friendVector;

    for (int i = 0; i < numRounds; i++)
    {
        scanf("%d", &removalFactor);

        filteredVector = filter(filteredVector, [&removalFactor, &filteredVector](int element)
                                {   auto it = find(filteredVector.begin(), filteredVector.end(), element);
                                    int position = it - filteredVector.begin() + 1;
                                    return position % removalFactor == 0; });
    }

    for_each(begin(filteredVector), end(filteredVector), [](int element)
             { printf("%d\n", element); });
}

template <typename T, typename P>
vector<T> filter(const vector<T> &v, P predicate)
{
    vector<T> tempVector;
    remove_copy_if(begin(v), end(v), back_inserter(tempVector), predicate);
    return tempVector;
}
