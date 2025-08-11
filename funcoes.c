#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int** data;
};

Matrix* create_matrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;

    m->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
    }
    return m;
}

Matrix *sum(Matrix* Ma, Matrix* Mb) {
    if ((Ma->rows != Mb->rows) || (Ma->cols != Mb->cols)) {
        erro("As Matrizes possuem dimensoes diferentes");
        return NULL;
    }

    for (int i = 0; i < Ma->rows; i++) {
        for (int j = 0; j < Ma->cols; j++) {
            Ma->data[i][j] = Ma->data[i][j] + Mb->data[i][j];
        }
    }

    return Ma;
}

Matrix *sub(Matrix *Ma, Matrix *Mb){
    if ((Ma->rows != Mb->rows) || (Ma->cols != Mb->cols)) {
        erro("As Matrizes possuem dimensoes diferentes");
        return NULL;
    }

    for (int i = 0; i < Ma->rows; i++) {
        for (int j = 0; j < Ma->cols; j++) {
            Ma->data[i][j] = Ma->data[i][j] - Mb->data[i][j];
        }
    }

    return Ma;    
}

Matrix *scalar_multiply(int k, Matrix *M){

    for (int i = 0; i < M->rows; i++) {
        for (int j = 0; j < M->cols; j++) {
            M->data[i][j] = M->data[i][j] * k;
        }
    }

    return M;    
}

Matrix *multiply(Matrix *Ma, Matrix *Mb){
    if (Ma->cols != Mb->rows){
        erro("As Matrizes nao podem ser multiplicadas");
        return NULL;
    }

Matrix* product  = create_matrix(Ma->rows, Mb->cols);
    for(int i=0; i<product->rows; i++){
        for(int j=0; j<product->cols; j++){
            product->data[i][j] = 0;
            for(int k=0; k < Ma->cols; k++){
                product->data[i][j] += Ma->data[i][k]*Mb->data[k][j];
            }
        }
    }
    return product;
}

Matrix *transpose(Matrix* M){
    Matrix *MT = create_matrix(M->cols, M->rows);
    for(int i=0; i<MT->rows; i++){
        for(int j=0; j<MT->cols; j++){
            MT->data[i][j] = M->data[j][i];
        }
    }
    return MT;
}

bool  is_simetric(Matrix *M){
    Matrix *MT = transpose(M);
    for(int i=0; i<MT->rows; i++){
        for(int j=0; j<MT->cols; j++){
            if(MT->data[i][j] != M->data[j][i]){
                free(MT->data);
                free(MT);
                return false;
            }
        }
    }
    free(MT->data);
    free(MT);
    return true;
}

bool is_quadratic(Matrix *M){
    return M->rows == M->cols;
}

void fill_matrix(Matrix *M){
    printf("Digite os elementos da matriz A, uma matriz %dx%d.\n", M->rows,M->cols);
    for (int i = 0; i < M->rows; i++) {
        printf("%d entradas para a linha %d:\n", M->cols,i+1);
        for (int j = 0; j < M->cols; j++) {
            scanf("%d",&M->data[i][j]);
        }
    }   
    printf("Matriz preenchida: \n");
    matrix_print(M);
}

void matrix_print(Matrix *M){
    for (int i = 0; i < M->rows; i++) {
        for (int j = 0; j < M->cols; j++) {
            printf("%d ",M->data[i][j]);
        }
        printf("\n");
    }   
}

void erro(char *mensagem){
    printf("Não foi possivel realizar a operacao. Motivo: %s\n",mensagem);
}

void free_matrix(Matrix *M) {
    if (!M) return;
    for (int i = 0; i < M->rows; i++) {
        free(M->data[i]);
    }
    free(M->data);
    free(M);
}