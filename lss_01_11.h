#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int debug_print;
int errors_print;
int matrix_print;
int time_print;

void swap(double *a, double *b);

size_t lss_memsize_01_11(int n);

void display_matrix(int n, double *A);

void display_X(int n, double *X);

int lss_01_11(int n, double *A, double*B, double *X, double*tmp);


