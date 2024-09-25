#include "EditorDataManager.h"
#include "Core/Log/Sink/gui_sink.h"
#include <pch.h>

namespace Novl {
EditorDataManager::EditorDataManager() {
    m_logMsgs = make_shared<n_vector<log_item>>();
    m_logMsgs->reserve(MAX_LOG_MSG);

    // construct ui sink for editor
    auto ui_sink = gui_sink_mt(m_logMsgs);
    NOVL_ASSERT(ui_sink, "ConsolePanel: init failed because log container is null!");
    Log::AddSink(std::move(ui_sink));
}

EditorDataManager::~EditorDataManager() {
    m_logMsgs.reset();
}
} // namespace Novl