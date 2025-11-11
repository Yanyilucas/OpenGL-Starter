#include "app.h"
#include <iostream>

App::App(int width, int height, const char* title) : SCR_WIDTH(width), SCR_HEIGHT(height)
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(
        window, [](GLFWwindow* window, int w, int h) { glViewport(0, 0, w, h); });

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    // Enable depth testing for proper 3D rendering
    glEnable(GL_DEPTH_TEST);

    //renderer initialization
    renderer = std::make_unique<Renderer>(width, height);
    renderer->Init();

    // print versions
    // --------------
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "GLFW Version: " << glfwGetVersionString() << std::endl;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void App::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

App::~App()
{
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}

//render loop
//-----------
void App::run()
{
    float lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window))
    {
        // delta time calculation
        float currentFrame = static_cast<float>(glfwGetTime());
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // update
        // ------
        renderer->Update(deltaTime);

        // render
        // ------
        render();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // --------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}

// render function
//----------------
void App::render()
{
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //Renderer here
    renderer->Render();
}