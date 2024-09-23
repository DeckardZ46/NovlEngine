#include <pch.h>
#include "NovlEditor.h"

namespace Novl{
    NovlEditor::NovlEditor(){

    }

    NovlEditor::~NovlEditor(){

    }

    void NovlEditor::init(){
        // init runtime
        NovlRuntime::Get().init();
        EDITOR_ASSERT(NovlRuntime::Get().getWindow().getNativeWindow() != nullptr, "Native window init failed!");

        // init Editor GUI
        m_GUI = make_unique<EditorUI>();
    }

    void NovlEditor::close(){
        // clear Editor GUI
        m_GUI->clear();

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