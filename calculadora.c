#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf(
    " ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ██████╗  ██████╗ ██████╗  █████╗ \n"
    "██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██╔══██╗\n"
    "██║     ███████║██║     ██║     ██║   ██║██║     ███████║██║  ██║██║   ██║██████╔╝███████║\n"
    "██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║██║  ██║██║   ██║██╔══██╗██╔══██║\n"
    "╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║██████╔╝╚██████╔╝██║  ██║██║  ██║\n"
    " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝\n"
    " DE MATRIZES                                                                              \n"
    "                                   1. para adicionar                                      \n"                                    
    "                                   2. para subtrair                                       \n"
    "                                   3. para multiplicação escalar                          \n"
    "                                   4. para multiplicar duas matrizes                      \n"
    "                                   5. para a transposta de uma matriz                     \n"
    "                                   6. para verificar se é quadrada                        \n"
    "                                   7. para verificar se é mmatriz simetrica               \n"
    "                                   8. para imprimir uma matriz                            \n"
    "                                   Digite sua escolha:                                    \n"
    );
    int func = 0;
    scanf("%d",&func);
    if((func==3)||(func==5)||(func==6)||(func==7)||(func==8)){
        printf("Digite as #Linhas e #Colunas da matriz\n");
        int rows = 0;
        int cols = 0;
        scanf("%d",&rows);
        scanf("%d",&cols);
        Matrix *M = create_matrix(rows,cols);
        fill_matrix(M);

        if(func==3){
            int k=0;
            printf("Digite o valor a multiplicar a matriz:");
            scanf("%d",&k);
            M = scalar_multiply(k, M);
            printf("Resultado do produto:\n");
            matrix_print(M);
            free_matrix(M);
        }else if(func==5){
            int k=0;
            Matrix *Mt = transpose(M);
            printf("Transposta da Matriz:\n");
            matrix_print(Mt);
            free_matrix(M);
        } else if(func==6){
            if(is_quadratic(M)){
                printf("a matriz eh quadrada \n");
            }else{
                printf("a matriz nao eh quadrada \n");
            }
            free_matrix(M);
        }else if(func==7){
            if(is_simetric(M)){
                printf("a matriz eh simetrica \n");
            }else{
                printf("a matriz nao eh simetrica \n");
            }
            free_matrix(M);
        }else{
            printf("Matriz:\n");
            matrix_print(M);
            free_matrix(M);
        }
        
    }else if((func==1)||(func==2)||(func==4)){
        printf("Digite as #Linhas e #Colunas da primeira matriz\n");
        int rows = 0;
        int cols = 0;
        scanf("%d",&rows);
        scanf("%d",&cols);
        Matrix *Ma = create_matrix(rows,cols);
        fill_matrix(Ma);

        printf("Digite as #Linhas e #Colunas da segunda matriz\n");
        int rows2 = 0;
        int cols2 = 0;
        scanf("%d",&rows2);
        scanf("%d",&cols2);
        Matrix *Mb = create_matrix(rows,cols);
        fill_matrix(Mb);

        if(func==1){
            Matrix *soma =sum(Ma, Mb);
            printf("Soma das Matrizes:\n");
            matrix_print(soma);
            free_matrix(Ma);
            free_matrix(Mb);
        }else if(func==2){
            Matrix *subtracao =sub(Ma, Mb);
            printf("Subtracao das Matrizes:\n");
            matrix_print(subtracao);
            free_matrix(Ma);
            free_matrix(Mb);
        }else if(func==4){
            Matrix *produto = multiply(Ma,Mb);
            printf("Produto das Matrizes:\n");
            matrix_print(produto);
            free_matrix(Ma);
            free_matrix(Mb);
        }
    }else{
        printf("comando incorreto, tente novamente\n");
    }
    
}