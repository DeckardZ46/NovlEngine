#include <pch.h>
#include "NovlEditor.h"
#include "EditorDataManager.h"

namespace Novl{
    NovlEditor::NovlEditor(){

    }

    NovlEditor::~NovlEditor(){

    }

    /*
       Process below are mostly order sensitive in their implementations, for example: do not init Editor-GUI before init Runtime
       Manually controlling orders is needed for now
    */
    void NovlEditor::init(){
        // init runtime
        NovlRuntime::Get().init();
        EDITOR_ASSERT(NovlRuntime::Get().getWindow().getNativeWindow() != nullptr, "Native window init failed!");
        
        // init data manager
        EditorDataManager::Get();

        // init Editor GUI
        m_GUI = make_unique<EditorUI>();
        m_GUI->init();
    }

    void NovlEditor::close(){
        // clear Editor GUI
        m_GUI->clear();
        m_GUI.reset();

        // close runtime
        NovlRuntime::Get().shutdown();
    }   


    void NovlEditor::update(){
        // Runtime tick logic & render
        NovlRuntime::Get().tick();

        // update & draw Editor GUI
        m_GUI->update();
        m_GUI->draw();

        // swap window buffer
        NovlRuntime::Get().flush();
    }
}