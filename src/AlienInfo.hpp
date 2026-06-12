#pragma once

#include <raylib.h>

enum class ALIEN_TYPE{ 
   NORMAL,
   SHOOTER,
   CAPTURE,
};

typedef struct{
   ALIEN_TYPE alienType;
   Vector2 position;
} GridInfo;