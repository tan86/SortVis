#include "sortvis.hh"

SortVis::SortVis() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(m_scrwidth, m_scrHeight, SDL_WINDOW_INPUT_FOCUS,
                              &m_pwin, &m_pren);
  m_isRunning = true;
}

SortVis::~SortVis() {
  m_colRects.clear();
  SDL_DestroyRenderer(m_pren);
  SDL_DestroyWindow(m_pwin);
  SDL_Quit();
}

void SortVis::close() {
  m_colRects.clear();
  SDL_DestroyRenderer(m_pren);
  SDL_DestroyWindow(m_pwin);
  SDL_Quit();
}

void SortVis::mainloop() {
  while (m_isRunning) {
    handleEvents();
    render({0, 0, 0, 0});
  }
  close();
}

void SortVis::bubbleSort() {
  for (const auto& i : m_colRects) {
    for (auto it = 0; it < m_colRects.size(); ++it) {
      if (m_colRects[it].h > m_colRects[it + 1].h) {
        int temp = m_colRects[it + 1].h;
        m_colRects[it + 1].h = m_colRects[it].h;
        m_colRects[it].h = temp;
      }
      SDL_Delay(15);
      render(m_colRects[it]);
    }
  }
}

void SortVis::render(const SDL_Rect& currRect) {
  SDL_SetRenderDrawColor(m_pren, 0, 0, 0, 0);
  SDL_RenderClear(m_pren);
  SDL_SetRenderDrawColor(m_pren, 255, 255, 255, 255);

  for (const auto& rect : m_colRects) {
    SDL_RenderDrawRect(m_pren, &rect);
  }

  SDL_SetRenderDrawColor(m_pren, 0, 255, 0, 255);
  SDL_RenderFillRect(m_pren, &currRect);

  SDL_RenderPresent(m_pren);
}

void SortVis::handleEvents() {
  while (SDL_PollEvent(&m_event) != 0) {
    if (m_event.type == SDL_KEYDOWN) {
      switch (m_event.key.keysym.sym) {
        case SDLK_ESCAPE:
          m_isRunning = false;
          break;
        case SDLK_r:
          // Generate Random Heights for each colRect
          {
            // temp here
            std::random_device m_rd;
            std::mt19937 m_rng(m_rd());
            std::uniform_int_distribution<int> m_uni(30, 450);

            m_colRects.clear();
            for (int i = 0; i < m_nOfCol; ++i) {
              m_colRects.push_back(
                  {i * m_colWidth, 0, m_colWidth, m_uni(m_rng)});
            }
          }
          break;
        case SDLK_s:
          bubbleSort();
          break;
      }
    }
  }
}
