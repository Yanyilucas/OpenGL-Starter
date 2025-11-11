#pragma once
#include<vector>
#include<memory>
#include"camera.h"
#include"irenderable.h"



class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer() = default;

    void Init();
    void Update(float dt);
    void Render();

    int SCR_WIDTH;
    int SCR_HEIGHT;
private:
    std::unique_ptr<Camera> camera;
    std::vector<std::shared_ptr<IRenderable>> renderModules;
};