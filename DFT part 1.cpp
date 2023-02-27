#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
vector<double> dft(vector<double> input)
{
     vector<double> ans(200);
    for (int i = 1; i < 200; i++)
    {
        vector<double> tempFrSin(200);
        vector<double> tempFrCos(200);
        for (int n = 0; n < 200; n++)
        {
            tempFrSin[n] = sin(2 * PI * i * n / 200);
        }
        for (int n = 0; n < 200; n++)
        {
            tempFrCos[n] = cos(2 * PI * i * n / 200);
        }
        int tempAnsSin = 0;
        int tempAnsCos = 0;
        for(int n = 0; n < 200; n++){
            tempAnsSin += input[n] * tempFrSin[n];
        }
        for(int n = 0; n < 200; n++){
            tempAnsCos += input[n] * tempFrCos[n];
        }
        ans[i] = sqrt(pow(tempAnsSin,2)+pow(tempAnsCos,2));

    }
    return ans;
}

int main()
{
    const int N = 200;
    const double fs = 200; // sampling frequency
    const double f0 = 35;  // frequency of the sine wave
    const double f1  = 80;

    vector<double> x(N);
    for (int n = 0; n < N; n++)
    {
        x[n] = 4*cos(2 * PI * f0 * n / fs)+3*sin(2 * PI * f1 * n / fs)+2*cos((2 * PI * 60 * n / fs)+1.2);
    }

    vector<double> ans = dft(x);

    for(int i = 0; i < N/2; i++){
        cout<<"frequency "<<i<<" value-->  "<<ans[i]<<endl;
    }

    return 0;
}