#include <iostream>
using namespace std;

const int N = 3;
int main()
{
    double array[N][N], det = 1;

    // initialise
    cout << "Enter " << N << "*" << N << " matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < N; ++i) 
    {
        bool flag = false; // flag := are all entries below a[i][i] including it zero?
        if (array[i][i] == 0) // If a[i][i] is zero then check rows below and swap
        {
            flag = true;
            for (int j = i; j < N; ++j)
            {
                if (array[j][i] != 0) {
                    det *= -1;
                    for (int k = 0; k < N; ++k) { 
                        double t = array[i][k]; // swapping
                        array[i][k] = array[j][k];
                        array[j][k] = t;
                        flag = false;
                    }
                }
            }
        }

        if (flag == true) {
            det = 0;
            break;
        }

        else {

            for (int j = i+1; j < N; ++j)
            {
                double store = array[j][i];
                for (int k = i; k < N; ++k) {
                    array[j][k] -= (array[i][k]*store)/array[i][i];

                } 
            }
            det *= array[i][i];
        }
    }

    cout << "Determinant: " << det;
    return 0;
}