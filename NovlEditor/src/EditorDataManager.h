/**
 * < Novl Engine > EditorDataManager.h
 * Author: DeckardZ46
 * Date: 2024/09/24
 * Note: Data manager for Novl Engine Editor, transferring data between Editor & Runtime
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once

namespace Novl{
    class EditorDataManager {
    private:
        EditorDataManager();
        EditorDataManager(const EditorDataManager&) = delete;
        EditorDataManager(EditorDataManager&&) = delete;
        EditorDataManager &operator=(const EditorDataManager&) = delete;
        EditorDataManager &operator=(EditorDataManager&&) = delete;
    
    public:
        ~EditorDataManager();
    
    inline static EditorDataManager& Get() {
        static EditorDataManager s_Instance;
        return s_Instance;
    }
    
    private:
        
    };
}