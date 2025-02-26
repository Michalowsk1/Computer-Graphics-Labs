#pragma once

#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
using namespace glm;
//Maths class
class Maths
{
public:
	//transformation matrices
	static mat4 translate(const vec3 &v);

	static mat4 scale(const vec3& v);
};
