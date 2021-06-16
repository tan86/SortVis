#ifndef _SORTVIS_SORTVIS_HH_
#define _SORTVIS_SORTVIS_HH_
#include <SDL2/SDL.h>

#include <random>
#include <vector>

class SortVis {
 public:
  SortVis();
  SortVis(const SortVis&) = delete;
  SortVis(const SortVis&&) = delete;
  ~SortVis();

  void mainloop();

 private:
  const int m_scrwidth = 640;
  const int m_scrHeight = 480;
  bool m_isRunning = false;
  SDL_Event m_event{};
  SDL_Window* m_pwin = nullptr;
  SDL_Renderer* m_pren = nullptr;

  const uint8_t m_colWidth = 10;
  const int m_nOfCol = m_scrwidth / m_colWidth;
  std::vector<SDL_Rect> m_colRects = {};

  void close();
  void bubbleSort();
  void render(const SDL_Rect& currRect);
  void handleEvents();
};
#endif  // !_SORTVIS_SORTVIS_HH_
