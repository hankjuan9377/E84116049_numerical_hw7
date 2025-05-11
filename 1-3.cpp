#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int maxiter = 1000;
const double maxerror = 1e-6;
const double omega = 1.25;

int main() {
    vector<double> x(6, 0.0);
    vector<double> x_old(6, 0.0);

    for (int iter = 0; iter < maxiter; ++iter) {
        x_old = x;

        x[0] = (1 - omega) * x[0] + omega * (1.0 / 4) * (0 + x[1] + x[3]);
        x[1] = (1 - omega) * x[1] + omega * (1.0 / 4) * (-1 + x[0] + x[2] + x[4]);
        x[2] = (1 - omega) * x[2] + omega * (1.0 / 4) * (9 + x[1] - x[4] + x[5]);
        x[3] = (1 - omega) * x[3] + omega * (1.0 / 4) * (4 + x[0] + x[4] + x[5]);
        x[4] = (1 - omega) * x[4] + omega * (1.0 / 4) * (8 + x[1] + x[3] + x[5]);
        x[5] = (1 - omega) * x[5] + omega * (1.0 / 4) * (6 + x[2] + x[4]);
		
		double error = 0;
        for (int i = 0; i < 6; ++i) {
            error += fabs(x[i] - x_old[i]);
        }

        if (error < maxerror) break;
    }

    for (int i = 0; i < 6; ++i) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}

