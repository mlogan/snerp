﻿// snerp.cpp : Defines the entry point for the application.
//

#include "common.h"
#include "console.h"
#include "snerp.h"
#include "SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
  initConsole();
	cout << "Hello CMake." << endl;
	CHECK(SDL_Init(SDL_INIT_VIDEO) == 0);
	return 0;
}
