#include <pch.h>
#include "ConsolePanel.h"
#include "EditorDataManager.h"
#include "Core/Log/Sink/gui_sink.h"

namespace Novl{
ConsolePanel::ConsolePanel(n_string &&name): PanelBase(std::move(name)){
    ELOGD("Initializing console panel...");
    
}

ConsolePanel::~ConsolePanel() {
    
}

void ConsolePanel::update() {
    
}

void ConsolePanel::draw() {
    
}

} // namespace Novl