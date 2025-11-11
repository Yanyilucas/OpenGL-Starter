#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
};