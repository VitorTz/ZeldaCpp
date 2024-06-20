#pragma once
#include <raylib.h>
#include <cmath>
#include <stdio.h>
#include "types.h"
#include "components.h"


namespace ze {	

	void normalize_vec(Vector2* v);

	unsigned long hash_f(const char* s);	

}