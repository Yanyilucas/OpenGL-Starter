#include "camera.h"


Camera::Camera()
    : position(glm::vec3(0.0f, 0.0f, 0.0f)),
    front(glm::vec3(0.0f, 0.0f, -1.0f)),
    up(glm::vec3(0.0f, 1.0f, 0.0f)),
    yaw(-90.0f),
    pitch(0.0f),
    fov(45.0f) {
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::GetProjectionMatrix(float aspect) const
{
    return glm::perspective(glm::radians(fov), aspect, 0.1f, 100.0f);
}

void Camera::RotateAroundY(float angularSpeed, float deltaTime)
{
    // // 更新角度
    yaw += angularSpeed * deltaTime;

    // 保持相机位置在原点
    position = glm::vec3(0.0f, 0.0f, 0.0f);

    // // 计算front向量绕Y轴旋转
    front.x = sin(glm::radians(yaw));
    front.y = 0.0f;
    front.z = -cos(glm::radians(yaw));
    front = glm::normalize(front);
}
