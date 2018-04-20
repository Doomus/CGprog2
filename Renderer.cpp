#include "Renderer.h"

namespace {
	double currentFrame = glfwGetTime();
	double lastFrame = currentFrame;
	double deltaTime;

	auto quadpos = glm::vec3(1, 0, 0);

	glm::mat4 TransformQuad() {

		//keyboard input handle here

		int state = glfwGetKey(window, GLFW_KEY_RIGHT);
		if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
			quadpos += glm::vec3(1 * deltaTime, 0, 0);
		}
		else if (glfwGetKey(window, GLFW_KEY_LEFT)) {
			quadpos -= glm::vec3(1 * deltaTime, 0, 0);
		}
		else if (glfwGetKey(window, GLFW_KEY_UP)) {
			quadpos += glm::vec3(0, 1 * deltaTime, 0);
		}
		else if (glfwGetKey(window, GLFW_KEY_DOWN)) {
			quadpos -= glm::vec3(0, 1 * deltaTime, 0);
		}
		else if (glfwGetKey(window, GLFW_KEY_BACKSPACE)) {
			quadpos -= glm::vec3(0, 0, 1);
		}
		else {
			quadpos = glm::vec3(0, 0, 0);
		}
		//matrix math here

		glm::mat4 model;  //identity matrix...
		model = glm::translate(model, quadpos);

		return model;

		//
		//if (state == GLFW_PRESS)
		// activate_airship();
		
	}

	
	
	
}


void BeginRendering()
{
	
	GLuint vertexArrayID = 0;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//Create and compile glsl program from shaders...
	GLuint programID = LoadShaders("BasicVertexShader.vertexshader", "BasicFragmentShader.fragmentshader");

	GLuint triangleID = LoadTriangle();
	GLuint quadID = LoadQuad();

	


	do {
		
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		

		//RenderTriangle(triangleID);
		RenderQuad(quadID, programID, TransformQuad());

		//Update();
		//Render();
		glfwSwapBuffers(window);
		glfwPollEvents();

		
		//set Deltatime
		

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}

void RenderVertex(GLuint vertexBuffer, GLuint programID /*shader program id*/, glm::mat4 model) {

	glUseProgram(programID);

	GLuint uniformModel = glGetUniformLocation(programID, "model");
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glVertexAttribPointer(
		0,			//attribute layout
		3,			//Elements in array
		GL_FLOAT,	//Each element is of type float
		GL_FALSE,	//Normalized?
		0,			//Stride...
		(void*)0	//Array buffer offset...
	);
}

void RenderQuad(GLuint vertexBuffer, GLuint programID, glm::mat4 model) {
	RenderVertex(vertexBuffer, programID, model);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
}

void RenderTriangle(GLuint vertexBuffer, GLuint programID, glm::mat4 model) {
	RenderVertex(vertexBuffer, programID, model);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}