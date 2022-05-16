#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <Windows.h>
#include <thread>

#pragma comment(lib , "opengl32")
class openobject {
public:
    openobject() {}
    virtual ~openobject() {}
};


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float b = 0.7f;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.6f, 0.6f, 0.6f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        float f = 0.0f;

        if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
        {
            f = 0.1f;
        }
        else
        {
            f = 0.0f;
            if (b <= -0.9f)
            {
                b = 0.8f;
            }
        }
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(b, 0.0f);
        glVertex2f(b + 0.05f, 0.1f);
        glVertex2f(b + 0.1f, 0.0f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.7f, f + 0.1f);
        glVertex2f(-0.7f, f);
        glVertex2f(-0.8f, f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.7f, f + 0.1f);
        glVertex2f(-0.8f, f + 0.1);
        glVertex2f(-0.8f, f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
        b = b - 0.1f;
        if (b <= -1.0f)
        {
            b = 0.7f;
        }
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}