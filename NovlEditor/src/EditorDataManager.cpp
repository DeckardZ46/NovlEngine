#include <pch.h>
#include "EditorDataManager.h"
#include "Core/Log/Sink/gui_sink.h"

namespace Novl{
    EditorDataManager::EditorDataManager(){
        m_logMsgs = make_shared<n_vector<log_item>>();
        m_logMsgs->reserve(MAX_LOG_MSG);
    }

    EditorDataManager::~EditorDataManager(){
        m_logMsgs.reset();
    }
}