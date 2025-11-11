#pragma once
#include "stb_image.h"
#include "shader.h"
#include "irenderable.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <string>
#include <memory>

class Skybox : public IRenderable {
public:
    void Init() override;
    void Update(float dt) override;
    void Render(const glm::mat4& view, const glm::mat4& projection) override;

private:
    unsigned int skyboxVAO = 0;
    unsigned int skyboxVBO = 0;
    unsigned int cubemapTexture = 0;
    std::unique_ptr<Shader> shader;
};

