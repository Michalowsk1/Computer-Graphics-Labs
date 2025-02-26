
#include <common/maths.hpp>

using namespace glm;
mat4 Maths::translate(const vec3 &v)
{
	mat4 translate(1.0f);
	translate[3][0] = v.x, translate[3][1] = v.y, translate[3][2] = v.z;
	return translate;
}

mat4 Maths::scale(const vec3& v)
{
	mat4 scale(1.0f);
	scale[0][0] = v.x;; scale[1][1] = v.y; scale[2][2] = v.z;
	return scale;
}
