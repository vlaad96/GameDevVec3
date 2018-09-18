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

	//Destructor

	~vec3() {} //General destructor, not needed in this case

	//Operators

	bool operator==(const vec3& other)const {
		
		return (this->x == other.x && this->y == other.y && this->z == other.z);
	}

	void operator+=(const vec3& other) {

		return vec3<Type>(this->x += other.x, this->y += other.y, this->z += other.z);
	}

	void operator-=(const vec3& other) {

		return vec3<Type>(this->x -= other.x, this->y -= other.y, this->z -= other.z);
	}

	void operator+(const vec3& other)const {

		return vec3<Type>(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	void operator-(const vec3& other)const {

		return vec3<Type>(this->x - other.x, this->y - other.y, this->z - other.z);

	}

	Type normalize(Type x, Type y, Type z) const {

		Type modulo = sqrtf<Type>(x*x + y*y + z*z);

		return vec3<Type>(x / modulo, y / modulo, z / modulo);
	}

	vec3 zero() {

		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	
	bool is_zero() {

		return this->x == 0 && this->y == 0 && this->z == 0;
	}

	Type distance_to(const vec3& other)const {

		Type distance = sqrt((other.x - this->x) ^ 2 + (other.y - this->y) ^ 2 + (other.z - this->z));

		return distance;
	}
};
	
#endif // !_VEC3_H