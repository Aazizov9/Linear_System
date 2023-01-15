#include "lss_01_11.h"


const double EPS = 1e-8;

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

size_t lss_memsize_01_11(int n) {
    return n * sizeof(double);
}

void display_matrix(int n, double *A) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%lf  ", A[i * (n + 1) + j]);
        }
        printf("\n");
    }
    printf("\n");

}

void display_X(int n, double *X) {

    printf("X: \n");
    for (int i = 0; i < n; i++)
        printf("X%d: %lf\n", i, X[i]);

}

int lss_01_11(int n, double *A, double *B, double *X, double *tmp) {

    double c, s, temp1, temp2;
    int m = n + 1;

    if (debug_print == 1) {
        printf("START MATRIX:\n");
        display_matrix(n, A);
    }

    for (int i = 0; i < n; i++) {

        int ind = -1;
        for (int j = i; j < n; j++) {
            if (fabs(A[j * m + i]) > EPS) {
                ind = j;
                break;
            }
        }


        if (ind != -1)
            for (int j = 0; j < n + 1; j++)
                swap(&A[i * m + j], &A[ind * m + j]);



        for (int j = i + 1; j < n; j++) {
            double z = sqrt(A[i * m + i] * A[i * m + i] + A[j * m + i] * A[j * m + i]);
            if (fabs(z) < EPS) return -1;
            c = A[i * m + i] / z;
            s = A[j * m + i] / z;

            for (int k = i; k < n + 1; k++) {
                temp1 = A[i * m + k];
                temp2 = A[j * m + k];
                A[i * m + k] = c * temp1 + s * temp2;
                A[j * m + k] = -s * temp1 + c * temp2;

            }
            if (debug_print == 1) {
                printf("STEPS:\n");
                display_matrix(n, A);
            }
        }

    }
    if (debug_print == 1) {
        printf("FINAL MATRIX:\n");
        display_matrix(n, A);
    }


    for (int i = n - 1; i >= 0; i--) {
        X[i] = A[i * m + n];

        for (int j = n - 1; j > i; j--)
            X[i] -= A[i * m + j] * X[j];
//
        if (fabs(A[i * m + i]) < EPS && fabs(A[i * m + n]) > EPS)
            return 1;

        else if (fabs(A[i * m + i]) < EPS && fabs(A[i * m + n]) < EPS) {
            X[i] = 0;
            continue;
        }

        X[i] /= A[i * m + i];

    }

    return 0;
}
