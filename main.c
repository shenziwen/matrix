#include "matrix.h"

#define TEST_ROW (2)
#define TEST_COL (3)

int main(int argc, char *argv[])
{
    float TEST_data1[TEST_ROW][TEST_COL]={
                                    {1.0,1.0,0.0},
                                    {0.0,1.0,2.0}};

    float TEST_data2[TEST_ROW][TEST_COL]={
                                    {200.0,100.1,150.2},
                                    {300.0,500.1,200.2}};
    float TEST_data3[TEST_COL][TEST_ROW]={
                                    {1.0,0.0},
                                    {0.0,1.0},
									{1.0,0.0}};


    Matrix_s *pstMatrix_A = CreatMatrix(TEST_ROW, TEST_COL, &TEST_data1[0][0]);
    Matrix_s *pstMatrix_B = CreatMatrix(TEST_ROW, TEST_COL, &TEST_data2[0][0]);
	Matrix_s *pstMatrix_C = CreatMatrix(TEST_COL, TEST_ROW, &TEST_data3[0][0]);

    if(NULL == pstMatrix_A || NULL == pstMatrix_B || NULL == pstMatrix_C)
    {
        return -1;
    }
	printf("The matrix A is:\r\n");
    DisplayMatrix(pstMatrix_A);
	printf("The matrix B is:\r\n");
    DisplayMatrix(pstMatrix_B);
	printf("The matrix C is:\r\n");
    DisplayMatrix(pstMatrix_C);
//test! only one 
	//Matrix_s *pstMatrix_Result = TransposeMatrix(pstMatrix_A);
	//Matrix_s *pstMatrix_Result = AddMatrix(pstMatrix_A,pstMatrix_B);
    //Matrix_s *pstMatrix_Result = SubtractMatrix(pstMatrix_A,pstMatrix_B);
	//Matrix_s *pstMatrix_Result = MultiplyMatrix_shucheng(pstMatrix_A,pstMatrix_C);
	Matrix_s *pstMatrix_Result = MultiplyMatrix_diancheng(pstMatrix_A,5);
    if (pstMatrix_Result == NULL)
    {
        printf("pstMatrix_Result fault!\n");
        return -1;
    }
	printf("The matrix_Result is:\r\n");
    DisplayMatrix(pstMatrix_Result);

    DestoryMatrix(pstMatrix_A);
    DestoryMatrix(pstMatrix_B);
	DestoryMatrix(pstMatrix_C);
    DestoryMatrix(pstMatrix_Result);

    return 0;
}

