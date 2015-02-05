#include <vector>

using namespace std;

class Matrix
{
public:
	float** data;
	int m_iRows;
	int m_iColumns;

	Matrix()
	{
		data = new float*[m_iRows];
		for(int i = 0; i < m_iRows; i++)
		{
			data[i] = new float[m_iColumns];
		}
	}

	Matrix(int a_iRows, int a_iColumns)
	{
		m_iRows = a_iRows;
		m_iColumns = a_iColumns;
		data = new float*[a_iRows];
		for(int i = 0; i < a_iRows; i++)
		{
			data[i] = new float[a_iColumns];
		}

	}

	void initMatrix()
	{
		for(int i = 0; i < m_iRows; i++)
		{
			for(int j = 0; j < m_iColumns; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	
	void setIdentity(float x, float y)
	{
		if(m_iRows == 3 && m_iColumns == 3)
		{
			data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
			data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
			data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
		}
	}

	void setTranslation(float x, float y)
	{
		if(m_iRows == 3 && m_iColumns == 3)
		{
			data[0][0] = 1; data[0][1] = 0; data[0][2] = x;
			data[1][0] = 0; data[1][1] = 1; data[1][2] = y;
			data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
		}
	}

	void setScale(float x, float y)
	{		
		if(m_iRows == 3 && m_iColumns == 3)
		{
			data[0][0] = x; data[0][1] = 0; data[0][2] = 0;
			data[1][0] = 0; data[1][1] = y; data[1][2] = 0;
			data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
		}
	}

	void setRotation(float r)
	{
		if(m_iRows == 3 && m_iColumns == 3)
		{
			data[0][0] = cosf(r); data[0][1] = sinf(r); data[0][2] = 0;
			data[1][0] = sinf(r); data[1][1] = cosf(r); data[1][2] = 0;
			data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
		}
	}

	Matrix Transpose()
	{
		Matrix result(m_iColumns, m_iRows);
		result.initMatrix();

		for(int i = 0; i < m_iRows; i++)
		{
			for(int j = 0; j < m_iColumns; j++)
			{
				result.data[j][i] = data[i][j];
			}

		}
		
		return result;
		
	}

	Matrix operator * (Matrix m)
	{		
		int rows = m_iRows;
		
		int columns = m.m_iColumns;

		Matrix result(rows, columns);
		result.initMatrix();
		
		if(m_iColumns == m.m_iRows)
		{
			for(int i = 0; i < rows; i++)
			{
				for(int j = 0; j < columns; j++)
				{
					float* v1 = new float[m_iColumns];
					for(int v = 0; v < m_iColumns; v++)
					{
						v1[v] = data[i][v];
					}
				
					float* v2 = new float[m.m_iRows];
					for(int v = 0; v < m.m_iRows; v++)
					{
						v2[v] = m.data[v][j];
					
						float tempNum = (v1[v] * v2[v]);
						result.data[i][j] += tempNum;
					}
				
				}
			
			}

			return result;
		}
		return Matrix();
	}

	void operator = (Matrix m)
	{
		for(int i = 0; i < m_iRows; i++)
		{
			for(int j = 0; j < m_iColumns; j++)
			{
				data[i][j] = m.data[i][j]; 
			}
		}
	}

};