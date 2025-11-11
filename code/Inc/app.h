#pragma once
#include "renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<memory>

class App
{
public:
  App(int width, int height, const char* title);
  ~App();
  void run();

private:
  void processInput(GLFWwindow* window);
  void render();

  GLFWwindow* window;
  unsigned int SCR_WIDTH;
  unsigned int SCR_HEIGHT;

  std::unique_ptr<Renderer> renderer; //RAII for Renderer
};