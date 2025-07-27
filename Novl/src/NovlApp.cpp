#include <pch.h>
#include <NovlApp.h>

namespace Novl{
NovlApp::NovlApp(n_string name): m_name(name){
    // init runtime
    NovlRuntime::Get();
}

NovlApp::~NovlApp(){
    // close runtime
    NovlRuntime::Get().shutdown();
}

void NovlApp::update(){
    // runtime tick logic & render
    NovlRuntime::Get().tick();
}

void NovlApp::flush(){
    // swap window buffer
    NovlRuntime::Get().flush();
}
} // namespace Novl