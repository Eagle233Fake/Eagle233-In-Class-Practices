/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]) {
    if (M == 32) {
        int i, j, k, l;
        int temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
        for (k = 0; k < M; k += 8) {
            for (l = 0; l < M; l += 8) {
                if (k == l) {
                    for (i = k; i < k + 8; i++) {
                        temp1 = A[i][l];
                        temp2 = A[i][l + 1];
                        temp3 = A[i][l + 2];
                        temp4 = A[i][l + 3];
                        temp5 = A[i][l + 4];
                        temp6 = A[i][l + 5];
                        temp7 = A[i][l + 6];
                        temp8 = A[i][l + 7];

                        B[l][i] = temp1;
                        B[l + 1][i] = temp2;
                        B[l + 2][i] = temp3;
                        B[l + 3][i] = temp4;
                        B[l + 4][i] = temp5;
                        B[l + 5][i] = temp6;
                        B[l + 6][i] = temp7;
                        B[l + 7][i] = temp8;
                    }
                } else {
                    for (i = k; i < k + 8; i++) {
                        for (j = l; j < l + 8; j++) {
                            B[j][i] = A[i][j];
                        }
                    }
                }
            }
        }
    }

    if (M == 64) {
        for (int i = 0; i < N; i += 8) {
            for (int j = 0; j < M; j += 8) {
                for (int k = i; k < i + 4; ++k) {
                    int temp0 = A[k][j];
                    int temp1 = A[k][j + 1];
                    int temp2 = A[k][j + 2];
                    int temp3 = A[k][j + 3];
                    int temp4 = A[k][j + 4];
                    int temp5 = A[k][j + 5];
                    int temp6 = A[k][j + 6];
                    int temp7 = A[k][j + 7];
    
                    B[j][k]     = temp0;
                    B[j + 1][k] = temp1;
                    B[j + 2][k] = temp2;
                    B[j + 3][k] = temp3;
    
                    B[j][k + 4]     = temp7;
                    B[j + 1][k + 4] = temp6;
                    B[j + 2][k + 4] = temp5;
                    B[j + 3][k + 4] = temp4;
                }
    
                for (int l = 0; l < 4; ++l) {
                    int temp0 = A[i + 4][j + 3 - l];
                    int temp1 = A[i + 5][j + 3 - l];
                    int temp2 = A[i + 6][j + 3 - l];
                    int temp3 = A[i + 7][j + 3 - l];
                    int temp4 = A[i + 4][j + 4 + l];
                    int temp5 = A[i + 5][j + 4 + l];
                    int temp6 = A[i + 6][j + 4 + l];
                    int temp7 = A[i + 7][j + 4 + l];
    
                    B[j + 4 + l][i]     = B[j + 3 - l][i + 4];
                    B[j + 4 + l][i + 1] = B[j + 3 - l][i + 5];
                    B[j + 4 + l][i + 2] = B[j + 3 - l][i + 6];
                    B[j + 4 + l][i + 3] = B[j + 3 - l][i + 7];
    
                    B[j + 3 - l][i + 4] = temp0;
                    B[j + 3 - l][i + 5] = temp1;
                    B[j + 3 - l][i + 6] = temp2;
                    B[j + 3 - l][i + 7] = temp3;
    
                    B[j + 4 + l][i + 4] = temp4;
                    B[j + 4 + l][i + 5] = temp5;
                    B[j + 4 + l][i + 6] = temp6;
                    B[j + 4 + l][i + 7] = temp7;
                }
            }
        }
    }    

    if (M == 61) {
        for (int i = 0; i < N; i += 16) {
            for (int j = 0; j < M; j += 16) {
                for (int k = i; k < i + 16 && k < N; k++) {
                    for (int l = j; l < j + 16 && l < M; l++) {
                        B[l][k] = A[k][l];
                    }
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

