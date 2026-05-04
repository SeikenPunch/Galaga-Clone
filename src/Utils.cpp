#include "Utils.hpp"
#include <cmath>

Vector2 normalize(Vector2 vector){
	if(vector.x == 0 && vector.y == 0) {return {0,0};}

	float mag = 0;
	mag = sqrt((vector.x * vector.x) + (vector.y * vector.y));

	return {vector.x / mag, vector.y / mag};
}

Vector2 normalize(float x, float y){
	if(x == 0 && y == 0) {return {0,0};}

	float mag = 0;
	mag = sqrt((x * x) + (y * y));

	return {x/mag, y/mag};
}