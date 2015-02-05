#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix o_Matrix1(4,2);

	o_Matrix1.data[0][0] = 15; o_Matrix1.data[0][1] = 5;
	o_Matrix1.data[1][0] = -2; o_Matrix1.data[1][1] = 12;
	o_Matrix1.data[2][0] = 3; o_Matrix1.data[2][1] = 8;
	o_Matrix1.data[3][0] = 4; o_Matrix1.data[3][1] = 6;

	Matrix o_Matrix2(2,3);

	o_Matrix2.data[0][0] = 1; o_Matrix2.data[0][1] = 4; o_Matrix2.data[0][2] = 16; 
	o_Matrix2.data[1][0] = 9; o_Matrix2.data[1][1] = 2; o_Matrix2.data[1][2] = 7;
	
	Matrix o_Matrix3(3,3);

	o_Matrix3.data[0][0] = 1; o_Matrix3.data[0][1] = 5; o_Matrix3.data[0][2] = 6; 
	o_Matrix3.data[1][0] = 2; o_Matrix3.data[1][1] = 7; o_Matrix3.data[1][2] = 8;
	o_Matrix3.data[2][0] = 2; o_Matrix3.data[2][1] = 7; o_Matrix3.data[2][2] = 5;

	Matrix test = o_Matrix2 * o_Matrix3;

	for(int i = 0; i < test.m_iRows; i++)
	{
		cout << endl;
		for(int j = 0; j < test.m_iColumns; j++)
		{
			cout << test.data[i][j] << " ";
		}
	}

	system("pause");
	return 0;
}