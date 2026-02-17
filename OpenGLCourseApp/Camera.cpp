#include "Camera.h"

Camera::Camera(){}

Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	this->position = position;
	this->worldUp = up;
	this->yaw = startYaw;
	this->pitch = startPitch;
	this->front = glm::vec3(0.0f, 0.0f, -1.0f);

	this->movementSpeed = startMoveSpeed;
	this->turnSpeed = startTurnSpeed;

	this->Update();
}	

void Camera::mouseControl(GLfloat xChange, GLfloat yChange) {
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	yaw += xChange;
	pitch += yChange;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}
	Update();
}

void Camera::keyControl(bool* keys,GLfloat deltaTime) {

	GLfloat velocity = movementSpeed * deltaTime;
	if (keys[GLFW_KEY_W]) {
		position += front * velocity;
	}	
	if (keys[GLFW_KEY_S]) {
		position -= front * velocity;
	}
	if (keys[GLFW_KEY_A]) {
		position -= right * velocity;
	}
	if (keys[GLFW_KEY_D]) {
		position += right * velocity;
	}

}

glm::mat4 Camera::calculateViewMatrix() {
	return glm::lookAt(position,position +front,up);
}

glm::vec3 Camera::getCameraPosition() {
	return position;
}

void Camera::Update() {

	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front); // Direction vector from the camera to the world

	right = glm::normalize(glm::cross(front, worldUp)); // Right vector perpendicular to the front and world up (applied Cross Product)
	up = glm::normalize(glm::cross(right,front));


}

Camera::~Camera()
{
}