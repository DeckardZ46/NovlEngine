#include "NovlEditor.h"

namespace Novl{
    NovlEditor::NovlEditor(){

    }

    NovlEditor::~NovlEditor(){

    }

    void NovlEditor::init(){
        NovlRuntime::Get().init();
    }

    void NovlEditor::close(){

    }

    void NovlEditor::update(){
        NovlRuntime::Get().tick();
    }
}