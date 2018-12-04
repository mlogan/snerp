// window.h : Window creation and manipulation code.

#include <memory>

class Window {
public:
  virtual ~Window() {}
  static std::unique_ptr<Window> New();

protected:
  Window() = default;
};

