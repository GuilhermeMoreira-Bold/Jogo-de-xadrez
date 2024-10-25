//
// Created by guilherme on 16/10/24.
//

#include "Renderer.h"
#include <SDL_image.h>

SDL_Renderer* Renderer::renderer = nullptr;
std::unique_ptr<Renderer> Renderer::instance = nullptr;

void  Renderer::init(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);

    if (renderer == nullptr) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }
}

void Renderer::draw(SDL_Rect* rect, SDL_Texture* texture) {
    SDL_RenderCopy(renderer,texture,NULL,rect);
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}


void Renderer::render() {
    SDL_RenderPresent(renderer);
}

void Renderer::shutdown() {

}

Renderer& Renderer::getInstance() {
    if(instance == nullptr) {
        instance = std::unique_ptr<Renderer>(new Renderer());
    }
    return *instance;
}


SDL_Texture*  Renderer::createTexture (std::string* path) {
    SDL_Surface* surface = IMG_Load(path->c_str());
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == nullptr) {
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    }
    return texture;
}

Renderer::Renderer() {

}



