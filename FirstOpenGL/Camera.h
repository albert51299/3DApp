#pragma once

#include <vector>

#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SENSITIVTY = 0.1f;
const GLfloat ZOOM = 45.0f;

class Camera {
public:
	glm::vec3 cameraUp;
	glm::vec3 worldUp;
	glm::vec3 tankPos;
	glm::vec3 cameraPos;
	glm::vec3 startCameraPos;
	glm::vec3 startTankPos;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat mouseSensitivity;
	GLfloat zoom;

	Camera(glm::vec3 cameraPos, glm::vec3 cameraTarget, glm::vec3 up){
		startCameraPos = cameraPos;
		startTankPos = cameraTarget; // in this case we suppose that cameraTarger is a tank position
		this->cameraPos = cameraPos;
		this->tankPos = cameraTarget;
		worldUp = up;
		yaw = YAW;
		pitch = PITCH;
		mouseSensitivity = SENSITIVTY;
		zoom = ZOOM;
		UpdateCameraUp();
	}

	void UpdateCameraUp() {
		glm::vec3 cameraFront = tankPos - cameraPos;
		glm::vec3 cameraRight = glm::cross(worldUp, cameraFront);
		cameraUp = glm::cross(cameraFront, cameraRight);
		cameraUp = glm::normalize(cameraUp);
	}

	glm::mat4 GetViewMatrix() {
		return glm::lookAt(this->cameraPos, this->tankPos, this->cameraUp);
	}

	void GoToFreeCamera() {
	

		UpdateCameraUp();
	}

	void GoToFixedCamera(GLfloat towerAngle, glm::vec3 tankMoved) {
		yaw = YAW;
		pitch = PITCH;
        
		// it will be used in computing camera position 
		GLfloat length = glm::distance(cameraPos, tankPos);
		 
	    // rotate gun front which equaled 0 0 -1 at the begin
		glm::vec3 gun = startTankPos - startCameraPos;
		gun = glm::rotateY(gun, towerAngle);
		gun = glm::normalize(gun);
		gun = gun * length;
		// move camera position
		glm::mat4 translateMat;
		translateMat = glm::translate(translateMat, tankMoved);

		glm::vec4 localVec = glm::vec4(startTankPos.x, startTankPos.y, startTankPos.z, 1.0f);
		glm::vec4 result = translateMat * localVec;
		
		cameraPos.x = result.x - gun.x;
		cameraPos.y = result.y - gun.y;
		cameraPos.z = result.z - gun.z;

		UpdateCameraUp();
	}

	void UpdateCamera(glm::vec3 delta) {
		glm::mat4 translateMat; 
		translateMat = glm::translate(translateMat, delta);
		glm::vec4 localVec = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::vec4 result = translateMat * localVec;
		cameraPos.x = result.x;
		cameraPos.y = result.y;
		cameraPos.z = result.z;

		localVec = glm::vec4(tankPos.x, tankPos.y, tankPos.z, 1.0f);
		result = translateMat * localVec;
		tankPos.x = result.x;
		tankPos.y = result.y;
		tankPos.z = result.z;

		UpdateCameraUp();
	}

	void TankRotate(GLfloat angle) {
		glm::vec3 cameraFront = tankPos - cameraPos;
		cameraFront = glm::rotateY(cameraFront, angle);
		cameraPos = tankPos - cameraFront;
		UpdateCameraUp();
	}

	void MouseMove(GLfloat xOffset, GLfloat yOffset) {
		xOffset *= this->mouseSensitivity;
		yOffset *= this->mouseSensitivity;

		yaw += xOffset;
		pitch += yOffset;

		if (this->pitch > 89.0f)
			this->pitch = 89.0f;
		if (this->pitch < -89.0f)
			this->pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		front.y = sin(glm::radians(this->pitch));
		front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

		GLfloat length = glm::distance(tankPos, cameraPos);
		front = glm::normalize(front) * length;
		
		if (front.y > (tankPos.y - 0.05f)) {
			front.y = tankPos.y - 0.05f;
			pitch -= yOffset;
		}

		front = glm::normalize(front) * length;

		cameraPos = tankPos - front;

		UpdateCameraUp();
	}

	void ProcessMouseScroll(GLfloat yoffset) {
		if (this->zoom >= 1.0f && this->zoom <= 45.0f)
			this->zoom -= yoffset;
		if (this->zoom <= 1.0f)
			this->zoom = 1.0f;
		if (this->zoom >= 45.0f)
			this->zoom = 45.0f;
	}
};
