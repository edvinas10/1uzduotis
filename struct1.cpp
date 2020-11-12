#include "struct1.h"

//rikiuoti(Eil.paz);
//rikiuoti(Eil.egz);
void rikiuoti(std::vector<int> masyvas, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int k = i;
        for (j = i + 1; j < n; j++)
            if (masyvas[i] > masyvas[j])
                k = j;
        std::swap(masyvas[i], masyvas[k]);
    }
}

double rastiMediana(std::vector<int> masyvas, int n)
{
    rikiuoti(masyvas, n);
    if (n % 2 != 0) {
        return (double)masyvas[n / 2];
    }
    else return (double)(masyvas[(n - 1) / 2] + masyvas[n / 2]) / 2.0;
}

int randomSk() {
    std::random_device rd;//random seed
    std::mt19937 gen(rd());//random number generator
    std::uniform_int_distribution<> dis(1, 10);//range
    return dis(gen);//put generator in range
    //srand((unsigned)time(0)); //susigeneruoju seed'as
}