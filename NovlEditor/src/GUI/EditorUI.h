/**
 * < Novl Engine > EditorUI.h
 * Author: DeckardZ46
 * Date: 2024/09/10
 * Note: GUI manager for Novl Engine Editor, using ImGUi as backend
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

namespace Novl {
class PanelBase;
class EditorUI {
  public:
    EditorUI();
    ~EditorUI();

    void init();
    void clear();
    void update();
    void draw();

  private:
    n_vector<PanelBase *> m_panels;
};
} // namespace Novl
