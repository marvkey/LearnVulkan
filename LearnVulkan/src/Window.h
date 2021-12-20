#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include<iostream>
class Window {
public:
    Window() {
        this->createWindow();
    }
    ~Window() {
        this->WindowEnd();
    }
    GLFWwindow* GetWindow() {
        return m_Window;
    }
    void Update() {
        glfwSwapBuffers((GLFWwindow*)m_Window);
        glfwPollEvents();
    }
private:

    int createWindow() {
        if (!glfwInit()) {
            std::cout << "Could Not Initilize GLFW" << std::endl;
            return -1;
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // so we do not set an api as open gl
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        m_Window = glfwCreateWindow(Width, Height, "Learn VUlkan", nullptr, NULL);
        if (m_Window == nullptr) {
            glfwTerminate();
        }
        std::cout << "Window created widht " << Width << "Height " << Height << std::endl;
        return 0;
    }
    int WindowEnd() {
        glfwDestroyWindow((GLFWwindow*)m_Window);
        glfwTerminate();
        return 0;
    }
    uint32_t Width = 800, Height = 500;
    GLFWwindow* m_Window;
};