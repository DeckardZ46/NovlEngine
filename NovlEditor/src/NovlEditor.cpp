#include <pch.h>
#include "NovlEditor.h"

namespace Novl{
    NovlEditor::NovlEditor(){

    }

    NovlEditor::~NovlEditor(){

    }

    void NovlEditor::init(){
        NovlRuntime::Get().init();
        m_GUI = make_unique<NovlGUI>();
    }

    void NovlEditor::close(){

    }

    void NovlEditor::update(){
        NovlRuntime::Get().tick();
    }
}