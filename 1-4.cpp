#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> Vec;
typedef vector< Vec > Mat;

// Vt*V
double dot(const Vec& a, const Vec& b) {
    double result = 0.0;
    for (int i = 0; i < a.size(); ++i)
        result += a[i] * b[i];
    return result;
}

// 矩陣乘向量
Vec matvec(const Mat& A, const Vec& x) {
    Vec result(x.size(), 0.0);
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < x.size(); ++j)
            result[i] += A[i][j] * x[j];
    return result;
}

// 向量相減 a - b
Vec vec_sub(const Vec& a, const Vec& b) {
    Vec result(a.size());
    for (int i = 0; i < a.size(); ++i)
        result[i] = a[i] - b[i];
    return result;
}

// 算新X 
Vec vec_add(const Vec& a, const Vec& b, double alpha) {
    Vec result(a.size());
    for (int i = 0; i < a.size(); ++i)
        result[i] = a[i] + alpha * b[i];
    return result;
}

int main() {
    int n = 6;

    Mat A(n, Vec(n, 0.0));
    A[0][0] = 4;   A[0][1] = -1;  A[0][3] = -1;
    A[1][0] = -1;  A[1][1] = 4;   A[1][2] = -1;  A[1][4] = -1;
    A[2][1] = -1;  A[2][2] = 4;   A[2][4] = 1;   A[2][5] = -1;
    A[3][0] = -1;  A[3][3] = 4;   A[3][4] = -1;  A[3][5] = -1;
    A[4][1] = -1;  A[4][3] = -1;  A[4][4] = 4;  A[4][5] = -1;
    A[5][2] = -1;  A[5][4] = -1;  A[5][5] = 4;

    Vec b;
    b.push_back(0);
    b.push_back(-1);
    b.push_back(9);
    b.push_back(4);
    b.push_back(8);
    b.push_back(6);

    Vec x(n, 0.0); // 初始猜測 x=[0, 0, ..., 0]
    Vec Ax(n), v(n);
    double tol = 1e-6;
    int max_iter = 100;

    for (int k = 0; k < max_iter; ++k) {
        Ax = matvec(A, x);           // A * x
        v = vec_sub(b, Ax);          // v(k) = b - A*x(k)

        Vec Av = matvec(A, v);
        double t_num = dot(v, v);
        double t_den = dot(v, Av);
        
        if (t_den == 0.0) break;
        
        double t = t_num / t_den;

        Vec x_new = vec_add(x, v, t);

        double error = sqrt(dot(vec_sub(x_new, x), vec_sub(x_new, x)));

        x = x_new;

        if (error < tol) {
            break;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << "x[" << i + 1 << "] = " << x[i] << endl;

    return 0;
}

