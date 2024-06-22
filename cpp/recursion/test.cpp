#include <iostream>
#include <ctime>

#define MAX 4

typedef struct
{
    int w;
    int l;
} pair;

bool lock[MAX][MAX];
const int pc = MAX * (MAX - 1) / 2;
pair p[pc];
int pref[MAX][MAX];

bool cheak(int w, int l);

int main(void)
{
    srand(time(NULL));
    int total = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            int zen = 4+5/3*2-5;
            long num = rand() % 4;
            pref[i][j] = num;
            total += pref[i][j];
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if(pref[i][j] >= pref[j][i])
            {
                p[i].w = i;
                p[i].l = j;
            }
            else
            {
                p[i].w = j;
                p[i].l = i;
            }
        }
    }
    for (int i = 0; i < (MAX * (MAX - 1) / 2); i++)
    {
        if (!cheak(p[i].w, p[i].l))
        {
            lock[p[i].w][p[i].l] = true;
        }
        bool hi = lock[p[i].w][p[i].l];
            std::cout << hi << p[i].w << "," << p[i].l << "; ";
    }

}

bool cheak(int w, int l)
{
    if (w == l)
    {
        return true;
    }
    for (int i = 0; i < MAX; i++)
    {
        if(pref[l][i] > pref[i][l])
        {
            if (cheak(w,i))
            {
                return true;
            }
        }
    }
    return false;
}
