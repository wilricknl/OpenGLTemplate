// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <iostream>

int main()
{
    // initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    auto* window = glfwCreateWindow(1280, 720, "OpenGL Template", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
        return 1;
    }

    auto lastFrameTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time for current frame
        const auto currentFrameTime = glfwGetTime();
        const auto deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        glClearColor(40.0f / 256.0f, 42.0f / 256.0f, 54.0f / 256.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // finish glfw
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // destroy glfw
    glfwTerminate();
}
