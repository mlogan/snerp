// snerp.cpp : Defines the entry point for the application.
//

#include "common.h"
#include "console.h"
#include "snerp.h"
#include "window.h"

#include "SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
  initConsole();
  cout << "Hello CMake." << endl;
  CHECK(SDL_Init(SDL_INIT_VIDEO) == 0);

  int w = 1280;
  int h = 1024;

  // TODO: query current display mode
  auto window = Window::New();
  _sleep(20000);

  return 0;
}
