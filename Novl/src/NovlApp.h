/**
 * < Novl Engine > NovlApp.h
 * Author: DeckardZ46
 * Date: 2024/11/13
 * Note: Novl application base class, game & editor should both inherited from this class.
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once
#include <Novl.h>

namespace Novl{
class NovlApp {
public:
    NovlApp(n_string name = "Novl App");
    virtual ~NovlApp();

    virtual void update();
    virtual void flush();

protected:
    n_string m_name;
};
} // namespace Novl