#pragma once
#include <glm/glm.hpp>

class IRenderable {
public:
    virtual ~IRenderable() = default;
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render(const glm::mat4& view, const glm::mat4& projection) = 0;
};