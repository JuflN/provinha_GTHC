#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdbool.h>

typedef struct Matrix Matrix;
Matrix *create_matrix(int rows, int cols);
Matrix *sum(Matrix *Ma, Matrix *Mb);
Matrix *sub(Matrix *Ma, Matrix *Mb);
Matrix *scalar_multiply(int k, Matrix *M);
Matrix *multiply(Matrix *Ma, Matrix *Mb);
Matrix *transpose(Matrix* M);
bool is_simetric(Matrix *M);
bool is_quadratic(Matrix *M);
void fill_matrix(Matrix *M);
void matrix_print(Matrix* M);
void free_matrix(Matrix *M);
void erro(char *mensagem);


#endif
