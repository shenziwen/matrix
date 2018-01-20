#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 
#define OUT 

#define TRUE    (0)
#define FALSE   (1)

typedef int BOOL; 

typedef struct tagMatrix 
{  
	unsigned int ucHang;  //行Row
	unsigned int ucLie;  //列Col
	float **pfDataAddr; //二维数组的指针
}Matrix_s;


Matrix_s *CreatMatrix(IN unsigned int ucHang, IN unsigned int ucLie, IN float *pvData);
BOOL DestoryMatrix(IN Matrix_s *pstMatrix);
unsigned int GetMatrixRow(const Matrix_s *pstMatrixA);
unsigned int GetMatrixCol(const Matrix_s *pstMatrixA);
Matrix_s *TransposeMatrix(IN const Matrix_s *pstMatrixA);
Matrix_s *AddMatrix(IN const Matrix_s *pstMatrixA,IN const Matrix_s *pstMatrixB);
Matrix_s *SubtractMatrix(IN const Matrix_s *pstMatrixA,IN const Matrix_s *pstMatrixB);
Matrix_s *MultiplyMatrix_shucheng(IN const Matrix_s *pstMatrixA,	IN const Matrix_s *pstMatrixB);
Matrix_s *MultiplyMatrix_diancheng(IN const Matrix_s *pstMatrixA,IN const float tmp);

void DisplayMatrix(IN const Matrix_s *pstMatrix);
#endif

