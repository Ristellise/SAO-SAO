#include <glad\glad.h>
#include <glfw3.h>
#include <iostream>
#include "settings.h"

bool initglsafe();
bool exit_prog = false;
void runtime();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void doRender();
void flush();
void main()
{
    initglsafe();
    runtime();
}
// Coments
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* window = NULL;
// Initialises GLFW Safely.
bool initglsafe()
{
    if (glfwInit() != GLFW_TRUE)
    {
        std::cout << "Failed to initalise GLFW." << std::endl;
        return false;
    }
    // Setup GL Versions.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //GLFW Main Window.
    window = glfwCreateWindow(800, 600, "OpenGLTests", NULL, NULL);
    
    if (window == NULL)
    {
        std::cout << "Cannot create GLFW Magic Window." << std::endl;
        glfwTerminate();
        return false;
    }
    else
    {
        glfwMakeContextCurrent(window);
    }
    // Setup GLAD to allow Real OpenGL Magic
    int res = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!res)
    {
        std::cout << "Failed to initalize GLAD!" << std::endl;
        return false;
    }

    glViewport(0, 0, 800, 600);
    // Callback functions
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    if (VSyncCap)
    {
        glfwSwapInterval(1);
    }
    glGenBuffers(1, &VertBuff);

    glGenVertexArrays(1, &VertArrObj);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VertShader);
    glAttachShader(shaderProgram, FragShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(Vert);
    // Link Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Do Vertex Array Object
    
    glBindVertexArray(VertArrObj);
    glBindBuffer(GL_ARRAY_BUFFER, VertArrObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
unsigned int GenerateProgram(unsigned int VertexShader, unsigned int FragmentShader)
{
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VertShader);
    glAttachShader(shaderProgram, FragShader);
    glLinkProgram(shaderProgram);
    return shaderProgram;
}

unsigned int CompileFragment(char *FragmentSrc)
{
    int success;
    char infoLog[512];
    std::cout << "Compiling Fragment Shader" << std::endl;
    FragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragShader, 1, &FragmentSrc, NULL);
    glCompileShader(FragShader);
    glGetShaderiv(FragShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(FragShader, 512, NULL, infoLog);
        std::cout << "Failed to compile Vertex Shader: " << infoLog << std::endl;
    }
    return FragShader;
}

void CompileVertex(char *VertexSrc)
{
    int success;
    char infoLog[512];
    glBindBuffer(GL_ARRAY_BUFFER, VertBuff);
    std::cout << "Compiling Vertex Shader" << std::endl;
    VertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertShader, 1, &VertShaderSrc, NULL);
    glCompileShader(VertShader);
    glGetShaderiv(VertShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(VertShader, 512, NULL, infoLog);
        std::cout << "Failed to compile Vertex Shader: " << infoLog << std::endl;
    }
}

void runtime()
{
    while (true)
    {
        glfwPollEvents();
        // gametick Update Goes here
        doRender();
        flush();
        if (exit_prog)
        {
            break;
        }
    }
}

void test()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        exit_prog = true;
    }
}

// Flushes The Buffer.
void flush()
{
    if (window == NULL)
    {
        throw std::runtime_error("GLFW Window Became NULL.");
    }
    else
    {
        glfwSwapBuffers(window);
    }
}

void doRender()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}