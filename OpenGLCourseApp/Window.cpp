#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
}

Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
}

int Window::initialize()
{
    if (!glfwInit()) {
        printf("GLFW initialization failed! \n");
        glfwTerminate();
        return 1;
    }


    // Setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = No backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    mainWindow = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (!mainWindow) {
        printf("Window creation failed! \n");
        glfwTerminate();
        return 1;
    }


    // Get Buffer size information
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


    // set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);


    // Allow modern extension features
    glewExperimental = GL_TRUE;


    if (glewInit() != GLEW_OK) {
        printf("GLEW initialization failed! \n");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);


    // Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}