#ifndef MATH_h
#define MATH_h
#include <cmath>
#include <vector>

const float PI = 3.14159f;
const float TWO_PI = 2*PI;
const double TAU = 2*PI;

struct Vector
{
	float x;
	float y;
	
	Vector operator - (Vector &v)
	{
		Vector result;
		result.x = x - v.x;
		result.y = y - v.y;
		return result;
	}

	Vector operator + (Vector &v)
	{
		Vector result;
		result.x = x + v.x;
		result.y = y + v.y;
		return result;
	}

	inline float magnitude()
	{
		float length = sqrt(pow(x,2) + pow(y,2));
		return length; 
	}
};

class Matrix
{
	float data[9];
	void setTranslation(float x, float y)
	{
		data[0] = 1; data[1] = 0; data[2] = x;
		data[3] = 0; data[4] = 1; data[5] = y;
		data[6] = 0; data[7] = 0; data[8] = 1;
	}

	void setScale(float x, float y)
	{
		data[0] = x; data[1] = 0; data[2] = 0;
		data[3] = 0; data[4] = y; data[5] = 0;
		data[6] = 0; data[7] = 0; data[8] = 1;
	}

	void setRotation(float r)
	{
		data[0] = cosf(r); data[1] = sinf(r); data[2] = 0;
		data[3] = -sinf(r); data[4] = cosf(r); data[5] = 0;
		data[6] = 0; data[7] = 0; data[8] = 1;
	}

	void setRandMatrix()
	{
		data[0] = rand() % 100 + 1; data[1] = rand() % 100 + 1; data[2] = rand() % 100 + 1;
		data[3] = rand() % 100 + 1; data[4] = rand() % 100 + 1; data[5] = rand() % 100 + 1;
		data[6] = rand() % 100 + 1; data[7] = rand() % 100 + 1; data[8] = rand() % 100 + 1;
	}

	Matrix operator * (Matrix &m)
	{
		Matrix result;

		result.data[0] = (data[0] * m.data[0] + data[1] * m.data[3] + data[2] * m.data[6]);
		result.data[1] = (data[0] * m.data[1] + data[1] * m.data[4] + data[2] * m.data[7]);
		result.data[2] = (data[0] * m.data[2] + data[1] * m.data[5] + data[2] * m.data[8]);

		result.data[3] = (data[3] * m.data[0] + data[4] * m.data[3] + data[5] * m.data[6]);
		result.data[4] = (data[3] * m.data[1] + data[4] * m.data[4] + data[5] * m.data[7]);
		result.data[5] = (data[3] * m.data[2] + data[4] * m.data[5] + data[5] * m.data[8]);

		result.data[6] = (data[6] * m.data[0] + data[7] * m.data[3] + data[8] * m.data[6]);
		result.data[7] = (data[6] * m.data[1] + data[7] * m.data[4] + data[8] * m.data[7]);
		result.data[8] = (data[6] * m.data[2] + data[7] * m.data[5] + data[8] * m.data[8]);

		return result;
	}
};

#endif

