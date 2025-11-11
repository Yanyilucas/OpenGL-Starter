#include "renderer.h"
#include"skybox.h"

Renderer::Renderer(int width, int height) : SCR_WIDTH(width), SCR_HEIGHT(height) {
    camera = std::make_unique<Camera>();
    renderModules.push_back(std::make_shared<Skybox>());
    /*more render modules can be added here*/
}

void Renderer::Init() {
    for (auto& module : renderModules) {
        module->Init();
    }
}

void Renderer::Update(float dt) {
    camera->RotateAroundY(20.0f, dt);  // 20度/秒
    for (auto& module : renderModules) {
        module->Update(dt);
    }
}

void Renderer::Render() {
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = camera->GetProjectionMatrix(static_cast<float>(SCR_WIDTH) / SCR_HEIGHT);
    for (auto& module : renderModules) {
        module->Render(view, projection);
    }
}