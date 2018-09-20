#pragma once
#ifndef _VEC3_H
#define _VEC3_H

using namespace std;

template <class Type>

class vec3 {

public:

	Type x, y, z;

	//Constructors

	vec3() {} //general constructor

	vec3(Type x, Type y, Type z) :x(x), y(y), z(z) {}

	vec3(const vec3& parameter) {

		this->x = parameter.x;
		this->y = parameter.y;
		this->z = parameter.z;
	}

	vec3(const vec3 &copy) :x(copy.x), y(copy.y), z(copy.z) {}

	//Destructor

	~vec3() {} //General destructor, not needed in this case

	//Operators

	bool operator==(const vec3& other)const {
		
		return (this->x == other.x && this->y == other.y && this->z == other.z);
	}

	void operator+=(const vec3& other) {

		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	void operator-=(const vec3& other) {

		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	void operator+(const vec3& other)const {

		return vec3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	void operator-(const vec3& other)const {

		return vec3(this->x - other.x, this->y - other.y, this->z - other.z);

	}

	Type normalize() {

		Type modulo = sqrtf(x*x + y*y + z*z);

		x = x / modulo;
		y = y / modulo;
		z = z / modulo;
	}

	vec3 zero() {

		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	
	bool is_zero() const {

		return this->x == 0 && this->y == 0 && this->z == 0;
	}

	Type distance_to(const vec3& other)const {

		Type distance = sqrtf((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y) + (other.z - z)*(other.z - z));

		return distance;
	}
};
	
#endif // !_VEC3_H