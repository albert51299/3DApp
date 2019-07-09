#include "Functions.h"

bool IsAbroad(float areaWidth, float areaLong, float tankWidth, float tankLong, glm::vec3 move, float angle) {
	vec3 frontVec = vec3(0.0f, 0.0f, -(tankLong / 2));
	frontVec = rotateY(frontVec, angle);
	
	vec3 frontPos = vec3(frontVec.x + move.x, frontVec.y, frontVec.z + move.z);
	
	frontVec = normalize(frontVec) * tankLong;

	vec3 orthogonal = cross(frontVec, vec3(0.0f, 1.0f, 0.0f));
	orthogonal = normalize(orthogonal) * (tankWidth / 2);
	// getting four dots of tank
	vec3 fTop = frontPos + orthogonal;
	vec3 sTop = frontPos - orthogonal;
	
	frontPos.x -= frontVec.x;
	frontPos.z -= frontVec.z;

	vec3 fBottom = frontPos + orthogonal;
	vec3 sBottom = frontPos - orthogonal;
	// check crossing with z = (-areaLong / 2) border
	if ((fTop.z < (-areaLong / 2)) || (sTop.z < (-areaLong / 2)) || (fBottom.z < (-areaLong / 2)) || (sBottom.z < (-areaLong / 2))) {
		return true;
	}
	// z = areaLong / 2
	if ((fTop.z > (areaLong / 2)) || (sTop.z > (areaLong / 2)) || (fBottom.z > (areaLong / 2)) || (sBottom.z > (areaLong / 2))) {
		return true;
	}
    // x = (-areaWidth / 2)
	if ((fTop.x < (-areaWidth / 2)) || (sTop.x < (-areaWidth / 2)) || (fBottom.x < (-areaWidth / 2)) || (sBottom.x < (-areaWidth / 2))) {
		return true;
	}
	// x = areaWidth / 2
	if ((fTop.x > (areaWidth / 2)) || (sTop.x > (areaWidth / 2)) || (fBottom.x > (areaWidth / 2)) || (sBottom.x > (areaWidth / 2))) {
		return true;
	}
	return false;
}

void PassCoordsToVAO(GLuint VAO, GLuint VBO, GLuint EBO, GLfloat vertices[], GLuint indices[], GLint countOfV, GLint countOfI) {
	std::vector<GLfloat> vecV;
	std::vector<GLuint> vecI;
	for (int i = 0; i < countOfV; i++) {
		vecV.push_back(vertices[i]);
	}
	for (int i = 0; i < countOfI; i++) {
		vecI.push_back(indices[i]);
	}
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vecV.size() * sizeof(GLfloat), vecV.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vecI.size() * sizeof(GLfloat), vecI.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}

void LoadTexture(GLuint texture, const char* path) {
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Draw(GLuint VAO, GLint countV) {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, countV, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void BindTexture(GLint blockOffset, GLuint texture, Shader shader) {
	glActiveTexture(GL_TEXTURE0 + blockOffset);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(shader.Program, "ourTexture"), blockOffset);
}
