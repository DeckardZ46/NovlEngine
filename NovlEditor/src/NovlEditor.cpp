#include <pch.h>
#include "NovlEditor.h"
#include "EditorDataManager.h"

namespace Novl{
    NovlEditor::NovlEditor(): NovlApp("Novl Editor"){
        
    }

    NovlEditor::~NovlEditor(){
        
    }

    /*
       Process below are mostly order sensitive in their implementations, for example: do not init Editor-GUI before init Runtime
       Manually order-controlling is needed for now
    */
    void NovlEditor::init(){
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
    }   


    void NovlEditor::update(){
        NovlApp::update();

        // update & draw Editor GUI
        m_GUI->update();
        m_GUI->draw();

        NovlApp::flush();
    }
}