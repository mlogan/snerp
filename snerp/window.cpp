#include "common.h"
#include "window.h"

#include "SDL.h"

#include <memory>
#include <vector>

bool modesEqual(const SDL_DisplayMode& a, const SDL_DisplayMode& b) {
  return (a.w == b.w) && (a.h == b.h) && (a.format == b.format)
    && (a.refresh_rate == b.refresh_rate);
}

struct VideoMode {
  int displayIndex;
  SDL_DisplayMode mode;
  bool native;
};

struct Display {
  std::string name;
  SDL_DisplayMode nativeMode;
  SDL_Rect displayRect;

  float ddpi;
  float hdpi;
  float vdpi;

  std::vector<VideoMode> videoModes;
};

class WindowImpl : public Window {
public:
  explicit WindowImpl(SDL_Window* w) : sdl_window_(w) {}

private:

  std::vector<Display> displays_;
  SDL_Window* sdl_window_;
};

std::vector<Display> getDisplayInfo() {
  std::vector<Display> ret;
  auto totalModes = 0;
  auto numDisplays = SDL_GetNumVideoDisplays();
  for (int i = 0; i < numDisplays; i++) {
    Display display = {};
    auto modes = SDL_GetNumDisplayModes(i);
    totalModes += modes;
    display.videoModes.reserve(modes);

    auto name = SDL_GetDisplayName(i);
    if (name == nullptr) {
      display.name = "unknown display";
    } else {
      display.name = name;
    }

    TRACE(TRACE_INFO, "Found display %s", display.name.c_str());

    if (SDL_GetDesktopDisplayMode(i, &display.nativeMode) != 0) {
      TRACE(TRACE_ERROR, "Couldn't get native mode for %s: %s", display.name.c_str(), SDL_GetError());
    }

    if (SDL_GetDisplayBounds(i, &display.displayRect) != 0) {
      TRACE(TRACE_ERROR, "Couldn't get display bounds for %s: %s", display.name.c_str(), SDL_GetError());

      // Make a guess.
      display.displayRect.w = 1280;
      display.displayRect.h = 1024;

      // 0, 0 should hopefully always be a valid position.
      display.displayRect.x = 0;
      display.displayRect.y = 0;
    }

    for (int j = 0; j < modes; j++) {
      VideoMode mode;
      mode.displayIndex = i;

      SDL_GetDisplayMode(i, j, &mode.mode);
      mode.native = modesEqual(mode.mode, display.nativeMode);
      TRACE(TRACE_INFO, "-- mode (%i) %ix%i@%iHz %s",
        j, mode.mode.w, mode.mode.h, mode.mode.refresh_rate,
        SDL_GetPixelFormatName(mode.mode.format));
      display.videoModes.push_back(mode);
    }
    ret.push_back(display);
  }
  return ret;
}

std::unique_ptr<Window> Window::New() {

  auto displayInfo = getDisplayInfo();

  int w = 1280;
  int h = 1024;
  auto window = SDL_CreateWindow(
    "SNERP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
	return std::unique_ptr<Window>(nullptr);

  return std::make_unique<WindowImpl>(window);
}