#include "lss_01_11.h"
#include <time.h>

#pragma warning(disable:4996)

int main(int argc, char *argv[]) {

    int res;
    char *input_name = "lss_01_11_in.txt";
    char *output_name = "lss_01_11_out.txt";

    for (int i = 1; i < argc; ++i)
        switch (argv[i][1]) {
            case 'd':
                debug_print = 1;
                break;
            case 'e':
                errors_print = 1;
                break;
            case 'p':
                matrix_print = 1;
                break;
            case 't':
                time_print = 1;
                break;
            case 'h':
                printf("Usage: lss [input_file_name] [output_file_name] [options]\n"
                       "Where options include:\n"
                       "  -d        print debug messages [default OFF]\n"
                       "  -e        print errors [default OFF]\n"
                       "  -p        print matrix [default OFF]\n"
                       "  -t        print execution time [default OFF]\n"
                       "  -h, -?    print this and exit\n"
                       "Default input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.");
                break;
            case '?':
                printf("Usage: lss [input_file_name] [output_file_name] [options]\n"
                       "Where options include:\n"
                       "  -d        print debug messages [default OFF]\n"
                       "  -e        print errors [default OFF]\n"
                       "  -p        print matrix [default OFF]\n"
                       "  -t        print execution time [default OFF]\n"
                       "  -h, -?    print this and exit\n"
                       "Default input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.");
                break;

            default:
                printf("Bad console arguments!\n", argv[i][1]);
                return -4;
        }
    if (argc > 1 && argv[1][0] != '-')
        input_name = argv[1];
    if (argc > 2 && argv[2][0] != '-')
        output_name = argv[2];

    FILE *input = fopen(input_name, "r"),
            *output = fopen(output_name, "w");

    if (input == NULL) {
        if (errors_print == 1)
            printf("Error reading file\n");
        return -3;
    } else {
        int n;
        if (fscanf(input, "%d", &n) == EOF) {
            if (errors_print == 1)
                printf("Empty file\n");
            return -5;
        }
//        double *A = (double *) malloc((n * n + n) * sizeof(double));
//        double *X = (double *) malloc(n * sizeof(double));

        double *A = (double *) malloc(lss_memsize_01_11(n * n + n));
        double *X = (double *) malloc(lss_memsize_01_11(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                fscanf(input, "%lf", &A[i * (n + 1) + j]);

        for (int i = 0; i < n; i++)
            fscanf(input, "%lf", &A[i * (n + 1) + n]);


        if (matrix_print == 1)
            display_matrix(n, A);

        clock_t start = clock();

        res = lss_01_11(n, A, NULL, X, NULL);
        clock_t end = clock();
        if (res == 1)
            fprintf(output, "0\n");

        else {
            fprintf(output, "%d\n", n);
            for (int i = 0; i < n; i++)
                fprintf(output, "%1.9lf\n", X[i]);
        }

        if (time_print == 1)
            printf("TIME: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);

        if (matrix_print == 1)
            display_matrix(n, A);

        if (errors_print == 1)
            printf("%d", res);

        free(A);
        free(X);
        A = NULL;
        X = NULL;

        fclose(input);
        fclose(output);

        return res;

    }
}