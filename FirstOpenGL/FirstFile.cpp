#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Camera.h"
#include "Functions.h"
#include "VerticesData.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void moveTank();

const GLuint WIDTH = 800, HEIGHT = 600; // screen resolution
const int N = 100; // number of VAO, VBO, EBO and textures

Camera camera(glm::vec3(0.0f, 1.0f, 3.0f), glm::vec3(0.0f, 0.3f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
bool keys[1024];
GLfloat delta = 0.0f;
GLfloat lastFrame = 0.0f;
GLfloat lastX = WIDTH / 2;
GLfloat lastY = HEIGHT / 2;
glm::vec3 moveForward = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 tankMoved = glm::vec3(0.0f, 0.0f, 0.0f);
GLfloat chassisAngle = 0.0f;
GLfloat towerAngle = 0.0f;

GLfloat trackOffset = 0.0f;

bool freeCamera = false;

VerticesData vd;

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window, lastX, lastY);

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, WIDTH, HEIGHT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);

	Shader mainShader("shaders/firstVShader.txt", "shaders/firstFShader.txt");

	GLint countOfWallsI = sizeof(vd.areaWallsI) / sizeof(GLuint);
	GLint countOfBottomAreaI = sizeof(vd.bottomAreaI) / sizeof(GLuint);
	GLint countOfChassisI = sizeof(vd.chassisI) / sizeof(GLuint);;
	GLint countOfHeadI = sizeof(vd.headI) / sizeof(GLuint);
	GLint countOfOneTrackPartV = 20;
	GLint countOfOneTrackPartI = sizeof(vd.trackI) / sizeof(GLuint);

	GLuint VBO[N], VAO[N], EBO[N];
	glGenVertexArrays(N, VAO);
	glGenBuffers(N, VBO);
	glGenBuffers(N, EBO);

	PassCoordsToVAO(VAO[0], VBO[0], EBO[0], vd.bottomArea, vd.bottomAreaI, sizeof(vd.bottomArea) / sizeof(GLfloat), countOfBottomAreaI);
	PassCoordsToVAO(VAO[1], VBO[1], EBO[1], vd.chassisPart, vd.chassisI, sizeof(vd.chassisPart) / sizeof(GLfloat), sizeof(vd.chassisI) / sizeof(GLuint));
	PassCoordsToVAO(VAO[2], VBO[2], EBO[2], vd.headPart, vd.headI, sizeof(vd.headPart) / sizeof(GLfloat), sizeof(vd.headI) / sizeof(GLuint));

	PassCoordsToVAO(VAO[3], VBO[3], EBO[3], vd.rightTopTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[4], VBO[4], EBO[4], vd.rightBottomTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[5], VBO[5], EBO[5], vd.leftTopTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[6], VBO[6], EBO[6], vd.leftBottomTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[7], VBO[7], EBO[7], vd.rightUpperBackTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[8], VBO[8], EBO[8], vd.rightDownBackTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[9], VBO[9], EBO[9], vd.rightUpperFrontTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[10], VBO[10], EBO[10], vd.rightDownFrontTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[11], VBO[11], EBO[11], vd.leftUpperBackTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[12], VBO[12], EBO[12], vd.leftDownBackTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[13], VBO[13], EBO[13], vd.leftUpperFrontTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);
	PassCoordsToVAO(VAO[14], VBO[14], EBO[14], vd.leftDownFrontTrack, vd.trackI, countOfOneTrackPartV, countOfOneTrackPartI);

	PassCoordsToVAO(VAO[15], VBO[15], EBO[15], vd.areaWalls, vd.areaWallsI, sizeof(vd.areaWalls) / sizeof(GLfloat), countOfWallsI);

	GLuint textures[N];
	glGenTextures(N, textures);
	LoadTexture(textures[0], "pictures/area1600.jpg");
	LoadTexture(textures[1], "pictures/digitalCamo.jpg");
	LoadTexture(textures[2], "pictures/track.jpg");
	LoadTexture(textures[3], "pictures/bottomTrack.png");
	LoadTexture(textures[4], "pictures/steelWall.jpg");

	while (!glfwWindowShouldClose(window)) {

		GLfloat currentFrame = glfwGetTime();
		delta = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		mainShader.Use();
		moveTank();

		glm::mat4 model = glm::mat4();
		glm::mat4 view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(camera.zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(mainShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(mainShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(mainShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniform1i(glGetUniformLocation(mainShader.Program, "isTrack"), false);

		BindTexture(0, textures[0], mainShader);
		Draw(VAO[0], countOfBottomAreaI);

		BindTexture(4, textures[4], mainShader);
		Draw(VAO[15], countOfWallsI);

		glm::mat4 chassisModel;
		glm::mat4 towerModel;
		chassisModel = glm::translate(chassisModel, tankMoved);
		towerModel = glm::rotate(chassisModel, towerAngle, glm::vec3(0.0f, 1.0f, 0.0f));
		chassisModel = glm::rotate(chassisModel, chassisAngle, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(mainShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(towerModel));

		BindTexture(1, textures[1], mainShader);
		Draw(VAO[2], countOfHeadI);

		glUniformMatrix4fv(glGetUniformLocation(mainShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(chassisModel));

		Draw(VAO[1], countOfChassisI);
	
		if (keys[GLFW_KEY_W] || keys[GLFW_KEY_S]) {
			if (keys[GLFW_KEY_W]) {
				trackOffset = glfwGetTime() / 1.5f;
			}
			else {
				trackOffset = -glfwGetTime() / 1.5f;
			}
		}
		
		glUniform1f(glGetUniformLocation(mainShader.Program, "trackOffset"), trackOffset);
		glUniform1i(glGetUniformLocation(mainShader.Program, "isTrack"), true);

		BindTexture(2, textures[2], mainShader);
		Draw(VAO[3], countOfOneTrackPartI);
		Draw(VAO[5], countOfOneTrackPartI);
		Draw(VAO[7], countOfOneTrackPartI);
		Draw(VAO[8], countOfOneTrackPartI);
		Draw(VAO[9], countOfOneTrackPartI);
		Draw(VAO[11], countOfOneTrackPartI); 
		Draw(VAO[12], countOfOneTrackPartI);
		Draw(VAO[13], countOfOneTrackPartI);

		glUniform1f(glGetUniformLocation(mainShader.Program, "trackOffset"), -trackOffset);

		Draw(VAO[10], countOfOneTrackPartI);
		Draw(VAO[14], countOfOneTrackPartI);

		BindTexture(3, textures[3], mainShader);
		Draw(VAO[4], countOfOneTrackPartI);
		Draw(VAO[6], countOfOneTrackPartI);

		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(N, VAO);
	glDeleteBuffers(N, VBO);
	glDeleteBuffers(N, EBO);
	glDeleteTextures(N, textures);
	glfwTerminate();
	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	GLfloat offsetX = xpos - lastX;
	GLfloat offsetY = lastY - ypos;
	
	lastX = xpos;
	lastY = ypos;

	if (freeCamera) {
		camera.MouseMove(offsetX, offsetY);
	}
}

void moveTank() {
	GLfloat towerRotateSpeed = 40.0f * delta;
	GLfloat moveSpeed = 1.5f * delta;
	GLfloat rotateSpeed = 40.0f * delta;
	if (keys[GLFW_KEY_W]) {
		glm::vec3 deltaVec = moveForward * moveSpeed;
		if (!IsAbroad(vd.areaWidth, vd.areaLong, vd.chassisWidth, vd.chassisLong, tankMoved + deltaVec, chassisAngle)) {
			tankMoved += deltaVec;
			camera.UpdateCamera(deltaVec);
		}
	}
	if (keys[GLFW_KEY_S]) {
		glm::vec3 deltaVec = -moveForward * moveSpeed;
		if (!IsAbroad(vd.areaWidth, vd.areaLong, vd.chassisWidth, vd.chassisLong, tankMoved + deltaVec, chassisAngle)) {
			tankMoved += deltaVec;
			camera.UpdateCamera(deltaVec);
		}
	}
	if (keys[GLFW_KEY_D]) {
		if (!IsAbroad(vd.areaWidth, vd.areaLong, vd.chassisWidth, vd.chassisLong, tankMoved, chassisAngle - rotateSpeed)) {
			chassisAngle -= rotateSpeed;
			towerAngle -= rotateSpeed;
			moveForward = glm::vec3(0.0f, 0.0f, -1.0f);
			moveForward = glm::rotateY(moveForward, chassisAngle);
			if (!freeCamera) {
				camera.TankRotate(-rotateSpeed);
			}
		}
	}
	if (keys[GLFW_KEY_A]) {
		if (!IsAbroad(vd.areaWidth, vd.areaLong, vd.chassisWidth, vd.chassisLong, tankMoved, chassisAngle + rotateSpeed)) {
			chassisAngle += rotateSpeed;
			towerAngle += rotateSpeed;
			moveForward = glm::vec3(0.0f, 0.0f, -1.0f);
			moveForward = glm::rotateY(moveForward, chassisAngle);
			if (!freeCamera) {
				camera.TankRotate(rotateSpeed);
			}
		}
	}
	if (keys[GLFW_KEY_Z]) {
		towerAngle += towerRotateSpeed;
		if (!freeCamera) {
			camera.TankRotate(towerRotateSpeed);
		}
	}
	if (keys[GLFW_KEY_X]) {
		towerAngle -= towerRotateSpeed;
		if (!freeCamera) {
			camera.TankRotate(-towerRotateSpeed);
		}
	}
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	if (freeCamera) {
		camera.ProcessMouseScroll(yoffset);
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_C && action == GLFW_PRESS) {
		if (freeCamera) {
			camera.GoToFixedCamera(towerAngle, tankMoved);
		}
		else {
			camera.GoToFreeCamera();
		}
		freeCamera = !freeCamera;
	}
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
}
