#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

int main() {
    const int N = 1024;
    const double fs = 1000; // sampling frequency
    const double f0 = 100; // frequency of the sine wave
    vector<cd> x(N); // input signal

    // Generate a sine wave with frequency f0
    for (int n = 0; n < N; n++) {
        x[n] = sin(2 * PI * f0 * n / fs);
    }

    // Compute the FFT of the input signal
    fft(x, false);

    // Compute the magnitude spectrum of the FFT
    vector<double> mag(N/2+1);
    for (int k = 0; k < N/2+1; k++) {
        mag[k] = abs(x[k]);
    }

    // Plot the magnitude spectrum
    for (int k = 0; k < N/2+1; k++) {
        double f = k * fs / N;
        cout << f << " " << mag[k] << endl;
    }
int vv;
cin>>vv;
    return 0;
}
