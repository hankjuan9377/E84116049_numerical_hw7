#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int maxiter = 1000;
const double maxerror = 1e-6;

int main() {
    vector<double> x(6, 0.0);
    vector<double> x_new(6, 0.0);

    for (int iter = 0; iter < maxiter; ++iter) {

        x_new[0] = (1.0 / 4) * (0 + x[1] + x[3]);                      // x1
        x_new[1] = (1.0 / 4) * (-1 + x[0] + x[2] + x[4]);              // x2
        x_new[2] = (1.0 / 4) * (9 + x[1] - x[4] + x[5]);               // x3
        x_new[3] = (1.0 / 4) * (4 + x[0] + x[4] + x[5]);               // x4
        x_new[4] = (1.0 / 4) * (8 + x[1] + x[3] + x[5]);               // x5
        x_new[5] = (1.0 / 4) * (6 + x[2] + x[4]);                      // x6

        double error = 0.0;
        for (int i = 0; i < 6; ++i) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        if (error < maxerror) {
            break;
        }
    }
    
	//output
    for (int i = 0; i < 6; ++i) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}

