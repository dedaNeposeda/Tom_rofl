#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
private: 
	const glm::mat4 e_mat = glm::mat4(1.0f);
	glm::mat4 translation_mat = glm::mat4(0.0f);
	glm::vec3 position;
	GLFWwindow* window;
public: 
	Transform(GLFWwindow* window,glm::vec3& position)
	{
		this->position = position;
		this->window = window;
	}
	glm::mat4 get_translation_mat()
	{
		return translation_mat;
	}
	void translation()
	{
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			position.x += 0.05f;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			position.x -= 0.05f;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			position.y += 0.05f;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			position.y -= 0.05f;
		translation_mat = e_mat;
		translation_mat = glm::translate(translation_mat, position);
	}
	void spin()
	{
		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		{
			//translation_mat = e_mat;
			translation_mat = glm::rotate(translation_mat, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}
	
};