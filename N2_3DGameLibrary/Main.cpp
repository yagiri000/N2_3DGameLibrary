#include <iostream>
#include "Vector3.h"
#include "MathUtil.h"
int main() {
	Vector3 v[3];
	v[0] = Vector3(6.0f, 10.0f, -2.0f);
	v[1] = Vector3(3.0f, -1.0f, 17.0f);
	v[2] = Vector3(-9.0f, 8.0f, 0.0f);

	Vector3 hoge(3, 4, 5);

	Vector3 n = crossProduct(v[1] - v[0], v[2] - v[1]);
	n.normalize();

	Vector3 zero;
	zero.zero();

	float d = v[0] * n;

	float a = hoge * n - d;

	float test = Vector3(-3.3f, 12.4f, 33.2f) * n;
	

	return 1;
}