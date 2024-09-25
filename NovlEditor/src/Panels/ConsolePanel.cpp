#include <pch.h>
#include "ConsolePanel.h"
#include "EditorDataManager.h"
#include "Core/Log/Sink/gui_sink.h"

namespace Novl{
ConsolePanel::ConsolePanel(n_string &&name): PanelBase(std::move(name)){
    // construct ui sink for console panel
    auto ui_sink = gui_sink_mt(EditorDataManager::Get().getLogContainer());
    NOVL_ASSERT(ui_sink,"ConsolePanel: init failed because log container is null!");
    Log::AddSink(ui_sink);
}

ConsolePanel::~ConsolePanel() {
    
}

void ConsolePanel::update() {
    
}

void ConsolePanel::draw() {
    
}

} // namespace Novl