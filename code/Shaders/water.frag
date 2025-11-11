#version 410 core
out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D dudvMap;
uniform sampler2D normalMap;
uniform float time;

void main()
{
    // 基于 DuDv map 生成动态扰动
    vec2 distorted = texture(dudvMap, TexCoords + vec2(time * 0.05, 0)).rg * 2.0 - 1.0;
    vec2 offsetCoords = TexCoords + distorted * 0.02;

    // 法线贴图调光
    vec3 normal = normalize(texture(normalMap, offsetCoords).rgb * 2.0 - 1.0);
    float lighting = dot(normal, normalize(vec3(0.0, 1.0, 1.0))) * 0.5 + 0.5;

    // 模拟水的浅蓝渐变
    vec3 color = mix(vec3(0.0, 0.2, 0.5), vec3(0.1, 0.5, 0.8), lighting);
    FragColor = vec4(color, 1.0);
}