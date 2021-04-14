#include <stdio.h>
#include <stdlib.h>

int row, column;
int i, j;
int matrix[10][10];
int trans[10][10];


//行列を生成する。
void generate_matrix();
//転置行列を生成する。
void answer_transposed_matrix();
//逆行列を求める
void answer_inverse_matrix();
//対称行列を求める
void answer_symmetric_matrix();
//ToDo
//行列の要素をファイルから読み込む関数を作る。
void file_read_matrix();

int main(void)
{
 
    printf("行数 = ");
    scanf("%d", &row);
    printf("列数 = ");
    scanf("%d", &column);

    /* 行列の入力 */
    printf("\n行列を入力してください\n");
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            printf("行列の要素 A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    generate_matrix();
    answer_transposed_matrix();
    file_read_matrix();

    return 0;
}

void generate_matrix()
{

    /* 入力した行列の表示 */
    printf("\nA = \n");
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            printf("%d  ", matrix[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

void answer_transposed_matrix()
{

    /* 転置行列 */
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            trans[j][i] = matrix[i][j];
        }
    }

    /* 転置行列の表示 */
    printf("\n転置行列 = \n");
    for (i = 0; i < column; ++i)
    {
        for (j = 0; j < row; ++j)
        {
            printf("%d  ", trans[i][j]);
            if (j == row - 1)
                printf("\n");
        }
    }
}

void file_read_matrix(){

    FILE *fp; // 
	char fname[] = "test.txt";
    int chr;

	fp = fopen(fname, "r"); //read
	if(fp == NULL) {
		printf("%s ファイルの読み込みに失敗しました\n", fname);
	} else {
		printf("%s ファイルの読み込みに成功しました。\n", fname);
	}

    while((chr = fgetc(fp)) != EOF) {
		putchar(chr);
	}
 
	fclose(fp); // ファイルを閉じる
}