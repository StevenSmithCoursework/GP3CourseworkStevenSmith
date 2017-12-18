#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define GLM_FORCE_RADIANS
//Define the string that will become the window title
#define WINDOW_TITLE "Steven Smith GP3 Coursework"

//Windows & OpenGL Libraries
#include <stdlib.h>
#include <Windows.h>
#include "GL/glut.h"
#include <iostream>
#include <string>
#include <ctime>

//Image & Texture Loading Libraries
#include "IL\il.h"
#include "IL\ilu.h"
#include "IL\ilut.h"

//Model/Mesh Loading Library
#include "glm-0.3.2\glm\glm.h"

//Font Library
#include "FTGL\ftgl.h"

//Audio Libraries
#include "OpenAL\al.h"
#include "OpenAL\alc.h"
#include "OpenAL\alut.h"

//Math Functions
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\geometric.hpp"
#include "glm\gtc\quaternion.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtx\quaternion.hpp"

//STL Containers & Algorithms
#include <vector>
#include <map>
#include <algorithm>

struct lightColour4
{
	lightColour4(float _r = 0.0f, float _g = 0.0f, float _b = 0.0f, float _a = 0.0f) : r(_r), g(_g), b(_b), a(_a) {}

	float r; //Red
	float g; //Green
	float b; //Blue
	float a; //Alpha
};

#endif