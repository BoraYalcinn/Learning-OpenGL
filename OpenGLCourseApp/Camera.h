#pragma once

#include <GL\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera
{

public:
	Camera();
	Camera(glm::vec3 position,glm::vec3 up, GLfloat startYaw,GLfloat startPitch,GLfloat startMoveSpeed,GLfloat startTurnSpeed);	

	void keyControl(bool* keys,GLfloat deltaTime); // passing the array of keys from the Window class to the Camera class to control the camera movement
	void mouseControl(GLfloat xChange,GLfloat yChange);
	
	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();

	glm::mat4 calculateViewMatrix(); // calculates the view matrix using the position, front and up vectors of the camera


	~Camera();


private:

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat movementSpeed;
	GLfloat turnSpeed;

	void Update();

};

