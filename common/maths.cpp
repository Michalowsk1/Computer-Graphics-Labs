
#include <common/maths.hpp>

using namespace glm;
mat4 Maths::translate(const vec3 &v) //moving image
{
	mat4 translate(1.0f);
	translate[3][0] = v.x, translate[3][1] = v.y, translate[3][2] = v.z;
	return translate;
}

mat4 Maths::scale(const vec3& v) //inc-decreasing size
{
	mat4 scale(1.0f);
	scale[0][0] = v.x;; scale[1][1] = v.y; scale[2][2] = v.z;
	return scale;
}

float Maths::radians(float angle)
{
	return angle * 3.1416f / 180.0f;
}

mat4 Maths::rotate(const float& angle, vec3 v)
{
	v = normalize(v);
	float c = cos(angle);
	float s = sin(angle);
	float x2 = v.x * v.x, y2 = v.y * v.y, z2 = v.z * v.z;
	float xy = v.x * v.y, xz = v.x * v.z, yz = v.y * v.z;
	float xs = v.x * s, ys = v.y * s, zs = v.z * s;


	mat4 rotate;
	rotate[0][0] = (1 - c) * x2 + c;
	rotate[0][1] = (1 - c) * xy + zs;
	rotate[0][2] = (1 - c) * xz - ys;
	rotate[1][0] = (1 - c) * xy - zs;
	rotate[1][1] = (1 - c) * y2 + c;
	rotate[1][2] = (1 - c) * yz + xs;
	rotate[2][0] = (1 - c) * xz + ys;
	rotate[2][1] = (1 - c) * yz - xs;
	rotate[2][2] = (1 - c) * z2 + c;

	return rotate;
}


