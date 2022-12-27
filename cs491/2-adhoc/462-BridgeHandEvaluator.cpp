#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

// #define LOCAL

int c = 0;
std::map<char, std::vector<char>> cards;
// int s[13], h[13], d[13], cl[13];
char suit;
char val;
char cardarr[3] = {'K', 'Q', 'J'};
char suits[4] = {'S', 'H', 'D', 'C'};
int stopped = 0;
int highest;

void sub(char &card);
void countStopped(char &suit);
void add(char &s);
bool comp(int a, int b);
void upd();
void clr();

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cards.insert({'S', std::vector<char>()});
    cards.insert({'H', std::vector<char>()});
    cards.insert({'D', std::vector<char>()});
    cards.insert({'C', std::vector<char>()});

    while (scanf("%c%c ", &val, &suit) != EOF)
    {
        upd();
        for (int i = 0; i < 12; i++)
        {
            scanf("%c%c ", &val, &suit);

            upd();
        }

        for (char &chr : cardarr)
        {
            sub(chr);
        }
        for (char &chr : suits)
        {
            countStopped(chr);
        }
        if (stopped == 4 && c >= 16)
            printf("BID NO-TRUMP\n");
        else
        {
            // 5, 6, 7
            for (char &chr : suits)
            {
                add(chr);
            }

            if (c >= 14)
            {
                highest = std::max({cards.at('S').size(), cards.at('H').size(), cards.at('D').size(),
                                    cards.at('C').size()},
                                   comp);
                for (char &card : suits)
                {
                    if (cards.at(card).size() == highest)
                    {
                        printf("BID %c\n", card);
                        break;
                    }
                }
            }
            else
            {
                printf("PASS\n");
            }
        }
        clr();
    }
}

void sub(char &card)
{
    int n;
    if (card == 'K')
        n = 1;
    else if (card == 'Q')
        n = 2;
    else
        n = 3;
    if (find(cards.at('S').begin(), cards.at('S').end(), card) != cards.at('S').end() &&
        cards.at('S').size() <= n)
    {
        c -= 1;
    }
    if (find(cards.at('H').begin(), cards.at('H').end(), card) != cards.at('H').end() &&
        cards.at('H').size() <= n)
    {
        c -= 1;
    }
    if (find(cards.at('D').begin(), cards.at('D').end(), card) != cards.at('D').end() &&
        cards.at('D').size() <= n)
    {
        c -= 1;
    }
    if (find(cards.at('C').begin(), cards.at('C').end(), card) != cards.at('C').end() &&
        cards.at('C').size() <= n)
    {
        c -= 1;
    }
}

void countStopped(char &suit)
{
    if (find(cards.at(suit).begin(), cards.at(suit).end(), 'A') != cards.at(suit).end() ||
        (find(cards.at(suit).begin(), cards.at(suit).end(), 'K') != cards.at(suit).end() &&
         cards.at(suit).size() >= 2) ||
        (find(cards.at(suit).begin(), cards.at(suit).end(), 'Q') != cards.at(suit).end() &&
         cards.at(suit).size() >= 3))
        stopped += 1;
}

void add(char &s)
{
    if (cards.at(s).size() == 2)
        c += 1;
    if (cards.at(s).size() <= 1)
        c += 2;
}

bool comp(int a, int b)
{
    return a < b;
}

void upd()
{
    switch (val)
    {
    case 'A':
        c += 4;
        break;
    case 'K':
        c += 3;
        break;
    case 'Q':
        c += 2;
        break;
    case 'J':
        c += 1;
        break;
    }

    cards.at(suit).push_back(val);
}

void clr()
{
    cards.at('S').clear();
    cards.at('H').clear();
    cards.at('D').clear();
    cards.at('C').clear();
    c = 0;
    stopped = 0;
}
