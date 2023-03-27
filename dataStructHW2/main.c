#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define  MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;

}SparseMatrix;

SparseMatrix matrix_transpose(SparseMatrix a)
{
	SparseMatrix b;
	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;

	if (a.terms > 0)
	{
		bindex = 0;
		for (int c = 0; c < a.cols; c++)
		{
			for (int i = 0; i < a.terms; i++)
			{
				if (a.data[i].col == c)
				{
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;

				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++)
	{
		printf("(%d, %d, %d)   \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}


int main()
{
	SparseMatrix* m;

	m = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	printf("Enter the size of rows and columns. the number of non-zero terms : ");
	scanf_s("%d", &m->cols, sizeof(int));
	scanf_s("%d", &m->rows, sizeof(int));
	scanf_s("%d", &m->terms, sizeof(int));

	printf("Enter row, column, and value pairs in order : \n");
	for (int i = 0; i < m->terms; i++)
	{
		scanf_s("%d", &m->data[i].row, sizeof(int));
		scanf_s("%d", &m->data[i].col, sizeof(int));
		scanf_s("%d", &m->data[i].value, sizeof(int));

	}
	printf("The transposed matrix is : \n");
	SparseMatrix trans = matrix_transpose(*m);
	matrix_print(trans);
	printf("\n-------------------------------------\n");

	free(m);

	return 0;
}