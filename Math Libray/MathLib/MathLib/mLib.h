#ifdef DLL 
 #define DLLEXPORT __declspec(dllexport) 
#else 
 #define DLLEXPORT __declspec(dllimport) 
#endif

//Math Lib
#ifndef _MLIB_H__
#define _MLIB_H__

#include <cmath>

using namespace std;

const float M_PI = 3.14159f;

class Vector3
{
public:
	float x, y, z;

	DLLEXPORT Vector3();
	
	DLLEXPORT Vector3(float a_fX, float a_fY, float a_fZ);

	DLLEXPORT Vector3 operator - (Vector3& v);

	DLLEXPORT Vector3 operator + (Vector3& v);

	DLLEXPORT Vector3& operator += (Vector3& v);

	DLLEXPORT Vector3& operator -= (Vector3& v);

	DLLEXPORT Vector3 operator * (int i);

	DLLEXPORT Vector3 operator * (float f);
	
	DLLEXPORT Vector3 operator / (float f);
	
	DLLEXPORT Vector3 operator * (Vector3 v);

	DLLEXPORT Vector3& operator = (Vector3& v);
	
	DLLEXPORT Vector3 GetReflected(Vector3 a_vNormal);

	DLLEXPORT Vector3 CrossProduct(Vector3& v);

	DLLEXPORT float Magnitude();
	
	DLLEXPORT float GetDistance(Vector3 v);

	DLLEXPORT float DotProduct(Vector3& v);

	DLLEXPORT float GetAngle(Vector3& v);

	DLLEXPORT Vector3 GetNorm();

	DLLEXPORT Vector3& Normalize();
};

class Matrix
{
public:
	float data[3][3];
	int m_iRows;
	int m_iColumns;

	DLLEXPORT Matrix();
	DLLEXPORT ~Matrix();

	DLLEXPORT static Matrix Rotate(float a_fRadians);

	DLLEXPORT static Matrix Scale(Vector3 a_Scale);

	DLLEXPORT static Matrix Translate(Vector3 a_Translate);

	DLLEXPORT void initMatrix();

	DLLEXPORT void setIdentity();

	DLLEXPORT void setTranslation(float x, float y);

	DLLEXPORT void setScale(float x, float y);

	DLLEXPORT void setRotation(float r);

 	DLLEXPORT Matrix Transpose();

	DLLEXPORT Matrix operator * (Matrix m);
	
	DLLEXPORT Vector3 operator * (Vector3 v);

	DLLEXPORT void operator = (Matrix m);

	DLLEXPORT void operator = (Vector3 v);

};

//

#endif