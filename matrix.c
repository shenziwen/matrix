#include <stdio.h>
#include <stdlib.h>
#include"./matrix.h"

void DisplayMatrix(IN const Matrix_s *pstMatrix)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < pstMatrix->ucHang;i++)
    {
        for(j = 0;j < pstMatrix->ucLie;j++)
        {
            printf(" %8.2f",(pstMatrix->pfDataAddr)[i][j]);
        }
        printf("\r\n");		
    }
}

Matrix_s *CreatMatrix(IN unsigned int ucHang, 
        IN unsigned int ucLie, 
        IN float *pvData)
{
    int i = 0;
    int j = 0;
    Matrix_s *pstMatrix = (Matrix_s*)malloc(sizeof(Matrix_s));
    if (pvData == NULL || pstMatrix == NULL)
    {
        printf("Creat matrix fault.\r\n");
        return NULL;
    }

    memset(pstMatrix, 0, sizeof(Matrix_s));
    pstMatrix->ucHang = ucHang;
    pstMatrix->ucLie = ucLie;
    pstMatrix->pfDataAddr = (float**)malloc((sizeof(float) * ucHang));

    if(pstMatrix->pfDataAddr == NULL)
    {
     	printf("Creat matrix fault.\r\n");
        return NULL;
    }
    else
    {
        for(i = 0;i < pstMatrix->ucHang;i++)
        {
            (pstMatrix->pfDataAddr)[i] = (float*)malloc((sizeof(float) * ucLie));
			if((pstMatrix->pfDataAddr)[i] == NULL)
    		{
     			printf("Creat matrix fault.\r\n");
       			return NULL;
   			}
            for(j = 0;j < pstMatrix->ucLie;j++)
            {
                (pstMatrix->pfDataAddr)[i][j] = pvData[i*ucLie + j];
            }				
        }	
    }

    return pstMatrix;
}

BOOL DestoryMatrix(IN Matrix_s *pstMatrix)
{
    int tmp = pstMatrix->ucHang;
    while( tmp > 0 )
    {
        if ((pstMatrix->pfDataAddr)[tmp-1] != NULL)
        {
            free((pstMatrix->pfDataAddr)[tmp-1]);
            (pstMatrix->pfDataAddr)[tmp-1] = NULL;
        }
        tmp--;
    }

    free(pstMatrix->pfDataAddr);

    if(pstMatrix != NULL)
    {
        free(pstMatrix);
        pstMatrix = NULL;
    }
}

unsigned int GetMatrixRow(IN const Matrix_s *pstMatrix)
{
    return pstMatrix->ucHang;
}

unsigned int GetMatrixCol(IN const Matrix_s *pstMatrix)
{
    return pstMatrix->ucLie;
}

Matrix_s *TransposeMatrix(IN const Matrix_s *pstMatrixA)//转置
{
	int i;
	int j;
	Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));
	if(NULL == pstMatrixResult)
	{
		printf("Malloc Matrix_Result fault.\r\n");
		return NULL;
	}
		
	pstMatrixResult->ucHang = pstMatrixA->ucLie;
	pstMatrixResult->ucLie = pstMatrixA->ucHang;
	
	pstMatrixResult->pfDataAddr = (float **)malloc(sizeof(float) * (pstMatrixResult->ucHang));
	if(NULL == pstMatrixResult->pfDataAddr)
	{
		printf("Malloc Matrix_Result->pfDataAddr fault.\r\n");
		return NULL;
	}
	
	for(i = 0;i < pstMatrixResult->ucHang;i++)
	{
		(pstMatrixResult->pfDataAddr)[i] = (float *)malloc(sizeof(float)*(pstMatrixResult->ucLie));
		if(NULL == (pstMatrixResult->pfDataAddr)[i])
		{
			printf("Malloc Matrix_Result->pfDataAddr[%d] fault.\r\n",i+1);
			return NULL;
		}
		for(j = 0;j < pstMatrixResult->ucLie;j++)
		{
			(pstMatrixResult->pfDataAddr)[i][j] = (pstMatrixA->pfDataAddr)[j][i];
		}			  
	}
	
	return pstMatrixResult;
}

Matrix_s *AddMatrix(IN const Matrix_s *pstMatrixA,
        IN const Matrix_s *pstMatrixB)
{
    int i;
    int j;
    Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));
	if(NULL == pstMatrixResult)
    {
    	printf("Malloc Matrix_Result fault.\r\n");
        return NULL;
    }

    if((pstMatrixA->ucHang != pstMatrixB->ucHang)||(pstMatrixA->ucLie != pstMatrixB->ucLie))
    {
        printf("相加的两个矩阵的行或列不满足矩阵相减条件！\r\n");
        return NULL;
    }

    pstMatrixResult->ucHang = pstMatrixA->ucHang;
    pstMatrixResult->ucLie = pstMatrixA->ucLie;

    pstMatrixResult->pfDataAddr = (float **)malloc(sizeof(float)*(pstMatrixResult->ucHang));
	if(NULL == pstMatrixResult->pfDataAddr)
    {
    	printf("Malloc Matrix_Result->pfDataAddr fault.\r\n");
        return NULL;
    }

    for(i = 0;i < pstMatrixResult->ucHang;i++)
    {
        (pstMatrixResult->pfDataAddr)[i] = (float *)malloc(sizeof(float)*(pstMatrixResult->ucLie));
		if(NULL == (pstMatrixResult->pfDataAddr)[i])
		{
			printf("Malloc Matrix_Result->pfDataAddr[%d] fault.\r\n",i+1);
			return NULL;
		}
		for(j = 0;j < pstMatrixResult->ucLie;j++)
        {
            (pstMatrixResult->pfDataAddr)[i][j] = (pstMatrixA->pfDataAddr)[i][j] + (pstMatrixB->pfDataAddr)[i][j];
        } 			  
    }

    return pstMatrixResult;
}


Matrix_s *SubtractMatrix(IN const Matrix_s *pstMatrixA,
        IN const Matrix_s *pstMatrixB)
{
    int i;
    int j;
    Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));
	if(NULL == pstMatrixResult)
    {
    	printf("Malloc Matrix_Result fault.\r\n");
        return NULL;
    }

    if((pstMatrixA->ucHang != pstMatrixB->ucHang)||(pstMatrixA->ucLie != pstMatrixB->ucLie))
    {
        printf("相减的两个矩阵的行或列不满足矩阵相减条件！\r\n");
        return NULL;
    }

    pstMatrixResult->ucHang = pstMatrixA->ucHang;
    pstMatrixResult->ucLie = pstMatrixA->ucLie;

    pstMatrixResult->pfDataAddr = (float **)malloc(sizeof(float) * (pstMatrixResult->ucHang));
	if(NULL == pstMatrixResult->pfDataAddr)
    {
    	printf("Malloc Matrix_Result->pfDataAddr fault.\r\n");
        return NULL;
    }

    for(i = 0;i < pstMatrixResult->ucHang;i++)
    {
        (pstMatrixResult->pfDataAddr)[i] = (float *)malloc(sizeof(float)*(pstMatrixResult->ucLie));
		if(NULL == (pstMatrixResult->pfDataAddr)[i])
		{
			printf("Malloc Matrix_Result->pfDataAddr[%d] fault.\r\n",i+1);
			return NULL;
		}
		for(j = 0;j < pstMatrixResult->ucLie;j++)
        {
            (pstMatrixResult->pfDataAddr)[i][j] = (pstMatrixA->pfDataAddr)[i][j] - (pstMatrixB->pfDataAddr)[i][j];
        } 			  
    }

    return pstMatrixResult;
}
		
Matrix_s *MultiplyMatrix_shucheng(IN const Matrix_s *pstMatrixA,
        IN const Matrix_s *pstMatrixB)//矩阵乘矩阵
 {
 	int i;
    int j;
	int k;
    Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));
	if(NULL == pstMatrixResult)
    {
    	printf("Malloc Matrix_Result fault.\r\n");
        return NULL;
    }

    if(pstMatrixA->ucLie != pstMatrixB->ucHang)
    {
        printf("相乘的两个矩阵的行或列不满足矩阵相乘条件！\r\n");
        return NULL;
    }

    pstMatrixResult->ucHang = pstMatrixA->ucHang;
    pstMatrixResult->ucLie = pstMatrixB->ucLie;

    pstMatrixResult->pfDataAddr = (float **)malloc(sizeof(float) * (pstMatrixResult->ucHang));
	if(NULL == pstMatrixResult->pfDataAddr)
    {
    	printf("Malloc Matrix_Result->pfDataAddr fault.\r\n");
        return NULL;
    }

    for(i = 0;i < pstMatrixResult->ucHang;i++)
    {
        (pstMatrixResult->pfDataAddr)[i] = (float *)malloc(sizeof(float)*(pstMatrixResult->ucLie));
		if(NULL == (pstMatrixResult->pfDataAddr)[i])
		{
			printf("Malloc Matrix_Result->pfDataAddr[%d] fault.\r\n",i+1);
			return NULL;
		}
		for(j = 0;j < pstMatrixResult->ucLie;j++)
        {
        	(pstMatrixResult->pfDataAddr)[i][j] = 0.0;
        	for(k = 0;k < pstMatrixA->ucLie;k++)
        	{
            	(pstMatrixResult->pfDataAddr)[i][j] += (pstMatrixA->pfDataAddr)[i][k] * (pstMatrixB->pfDataAddr)[k][j];
        	}
        } 			  
    }

    return pstMatrixResult;
 }

Matrix_s *MultiplyMatrix_diancheng(IN const Matrix_s *pstMatrixA,
			IN const float tmp)//数字乘矩阵
{
	int i;
	int j;
	
	Matrix_s *pstMatrixResult = (Matrix_s*)malloc(sizeof(Matrix_s));
	if(NULL == pstMatrixResult)
	{
		printf("Malloc Matrix_Result fault.\r\n");
		return NULL;
	}
			
	pstMatrixResult->ucHang = pstMatrixA->ucHang;
	pstMatrixResult->ucLie = pstMatrixA->ucLie;
		
	pstMatrixResult->pfDataAddr = (float **)malloc(sizeof(float) * (pstMatrixResult->ucHang));
	if(NULL == pstMatrixResult->pfDataAddr)
	{
		printf("Malloc Matrix_Result->pfDataAddr fault.\r\n");
		return NULL;
	}
		
	for(i = 0;i < pstMatrixResult->ucHang;i++)
	{
		(pstMatrixResult->pfDataAddr)[i] = (float *)malloc(sizeof(float)*(pstMatrixResult->ucLie));
		if(NULL == (pstMatrixResult->pfDataAddr)[i])
		{
			printf("Malloc Matrix_Result->pfDataAddr[%d] fault.\r\n",i+1);
			return NULL;
		}
		for(j = 0;j < pstMatrixResult->ucLie;j++)
		{
			(pstMatrixResult->pfDataAddr)[i][j] = (pstMatrixA->pfDataAddr)[i][j] * tmp;
		}			  
	}

	return pstMatrixResult;
}







