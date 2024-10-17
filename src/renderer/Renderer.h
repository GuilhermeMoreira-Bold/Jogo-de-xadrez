//
// Created by guilherme on 16/10/24.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <memory>
#include <SDL_render.h>

class Renderer {
    public:
    static Renderer& getInstance();
    static SDL_Renderer* renderer;
    static void init(SDL_Window* window);
    static void draw(SDL_Rect* rect, SDL_Texture* texture);
    static void render();
    static void shutdown();
    static SDL_Texture* createTexture(std::string* texturePath);
    private:
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    static std::unique_ptr<Renderer> instance;
    Renderer();
};
#endif //RENDERER_H
