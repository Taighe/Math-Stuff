#include "mLib.h"

Vector3::Vector3() 
{
	x = 0;
	y = 0;
	z = 0;
}
	
Vector3::Vector3(float a_fX, float a_fY, float a_fZ)
{
	x = a_fX;
	y = a_fY;
	z = a_fZ;
}
	
Vector3 Vector3::operator - (Vector3& v)
{
	Vector3 temp;
	temp.x = x - v.x;
	temp.y = y - v.y;
	return temp;
}
	
Vector3 Vector3::operator + (Vector3& v)
{
	Vector3 temp;
	temp.x = x + v.x;
	temp.y = y + v.y;
	return temp;
}


Vector3& Vector3::operator += (Vector3& v)
{
	x = x + v.x;
	y = y + v.y;
	return *this;
}

Vector3& Vector3::operator -= (Vector3& v)
{
	x = x - v.x;
	y = y - v.y;
	return *this;
}

Vector3 Vector3::operator * (int i)
{
	Vector3 temp;
	temp.x = x * i;
	temp.y = y * i;
	return temp;
}

Vector3 Vector3::operator * (float f)
{
	Vector3 temp;
	temp.x = x * f;
	temp.y = y * f;
	return temp;
}

Vector3 Vector3::operator / (float f)
{
	Vector3 temp;
	temp.x = x / f;
	temp.y = y / f;
	return temp;
}
	
Vector3 Vector3::operator * (Vector3 v)
{
	Vector3 temp;
	temp.x = x * v.x;
	temp.y = y * v.y;
	return temp;
}

Vector3& Vector3::operator = (Vector3& v)
{	
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector3 Vector3::GetReflected(Vector3 a_vNormal)
{
	Vector3 Vi = *this; 
	
	//Find P
	Vector3 P = a_vNormal * (-Vi.DotProduct(a_vNormal));

	//Math Burns
	Vector3 Vf =  Vi + P * 2;

	return Vf; 
}

float Vector3::GetDistance(Vector3 v)
{
	return abs( (x - v.x) + (y - v.y) );
}

float Vector3::Magnitude()
{
	return sqrt((x*x) + (y*y));
}

float Vector3::DotProduct(Vector3& v)
{
	return (x * v.x) + (y * v.y);
}

float Vector3::GetAngle(Vector3& v)
{
	float deltaX = v.x - x;
	float deltaY = v.y - y;
	
	float angle = atan2f(deltaX, deltaY);
	return angle;
}

Vector3 Vector3::GetNorm()
{
	Vector3 result;
	result.x = x / Magnitude();
	result.y = y / Magnitude();
		
	return result;
}

Vector3& Vector3::Normalize()
{
	float mag = Magnitude();
	x = x / mag;
	y = y / mag;
	return *this;
}

Matrix::Matrix()
{
	m_iRows = 3;
	m_iColumns = 3;
}

Matrix::~Matrix()
{

}

Matrix Matrix::Rotate(float a_fRadians)
{
	Matrix result;
	result.data[0][0] = cosf(a_fRadians); result.data[0][1] = -sinf(a_fRadians); result.data[0][2] = 0;
	result.data[1][0] = sinf(a_fRadians); result.data[1][1] = cosf(a_fRadians);  result.data[1][2] = 0;
	result.data[2][0] = 0;                result.data[2][1] = 0;                 result.data[2][2] = 1;

	return result;
}

Matrix Matrix::Scale(Vector3 a_Scale)
{
	Matrix result;
	result.data[0][0] = a_Scale.x; result.data[0][1] = 0;           result.data[0][2] = 0;
	result.data[1][0] = 0;         result.data[1][1] = a_Scale.y;   result.data[1][2] = 0;
	result.data[2][0] = 0;         result.data[2][1] = 0;           result.data[2][2] = 1;
		
	return result;
}

Matrix Matrix::Translate(Vector3 a_Translate)
{
	Matrix result;
	result.data[0][0] = 1;		   result.data[0][1] = 0;           result.data[0][2] = a_Translate.x;
	result.data[1][0] = 0;         result.data[1][1] = 1;           result.data[1][2] = a_Translate.y;
	result.data[2][0] = 0;         result.data[2][1] = 0;           result.data[2][2] = 1;
		
	return result;
}

void Matrix::initMatrix()
{
	for(int i = 0; i < m_iRows; i++)
	{
		for(int j = 0; j < m_iColumns; j++)
		{
			data[i][j] = 0;
		}
	}
}
	
void Matrix::setIdentity()
{
	if(m_iRows == 3 && m_iColumns == 3)
	{
		data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
		data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
		data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
	}
}

void Matrix::setTranslation(float x, float y)
{
	if(m_iRows == 3 && m_iColumns == 3)
	{
		data[0][0] = 1; data[0][1] = 0; data[0][2] = x;
		data[1][0] = 0; data[1][1] = 1; data[1][2] = y;
		data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
	}
}

void Matrix::setScale(float x, float y)
{		
	if(m_iRows == 3 && m_iColumns == 3)
	{
		data[0][0] = x; data[0][1] = 0; data[0][2] = 0;
		data[1][0] = 0; data[1][1] = y; data[1][2] = 0;
		data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
	}
}

void Matrix::setRotation(float r)
{
	if(m_iRows == 3 && m_iColumns == 3)
	{
		data[0][0] = cosf(r); data[0][1] = -sinf(r); data[0][2] = 0;
		data[1][0] = sinf(r); data[1][1] = cosf(r); data[1][2] = 0;
		data[2][0] = 0;       data[2][1] = 0;       data[2][2] = 1;
	}
}

Matrix Matrix::Transpose()
{
	Matrix result;
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

Matrix Matrix::operator * (Matrix m)
{		
	int rows = m_iRows;
		
	int columns = m.m_iColumns;

	Matrix result;
	result.initMatrix();
		
	if(m_iColumns == m.m_iRows)
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				float v1[3];
				for(int v = 0; v < m_iColumns; v++)
				{
					v1[v] = data[i][v];
				}
				
				float v2[3];
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
	
Vector3 Matrix::operator * (Vector3 v)
{		
	int rows = 3;
	int columns = 1;
	Matrix result;

	Matrix mVector;
	mVector.initMatrix();
	mVector = v;

	result.initMatrix();
		
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			float v1[3];
			for(int v = 0; v < m_iColumns; v++)
			{
				v1[v] = data[i][v];
			}
				
			float v2[3];
			for(int v = 0; v < mVector.m_iRows; v++)
			{
				v2[v] = mVector.data[v][j];
					
				float tempNum = (v1[v] * v2[v]);
				result.data[i][j] += tempNum;
			}
			
		}
	}

	Vector3 v_Result;
	v_Result.x = result.data[0][0];
	v_Result.y = result.data[1][0];
	v_Result.z = result.data[2][0];
		
	return v_Result;

}

void Matrix::operator = (Matrix m)
{
	for(int i = 0; i < m_iRows; i++)
	{
		for(int j = 0; j < m_iColumns; j++)
		{
			data[i][j] = m.data[i][j]; 
		}
	}
}

void Matrix::operator = (Vector3 v)
{	
	m_iRows = 3;
	m_iColumns = 1;
	data[0][0] = v.x;
	data[1][0] = v.y;
	data[2][0] = v.z;
}