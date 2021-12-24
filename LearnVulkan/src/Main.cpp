#include<iostream>
#include "Window.h"
#include "VulkanSetup.h"
int main() {
	Window window;
	VulkanInit vulkan(window.GetWindow());

	while (glfwWindowShouldClose(window.GetWindow()) ==false) {
		window.Update();
		vulkan.DrawFrame();
	}
}