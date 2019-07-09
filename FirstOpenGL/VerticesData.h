#pragma once
#ifndef _VERTICESDATA_H
#define _VERTICESDATA_H

#include <glfw3.h>

class VerticesData {
public:
	// sizes of area
	GLfloat areaWidth = 12.0f;
	GLfloat areaLong = 12.0f;
	GLfloat areaHeight = 6.0f;
	// sizes of tank
	GLfloat gunHeight = 0.45f;
	GLfloat towerHeight = 0.5f;
	GLfloat chassisHeight = 0.3f;
	GLfloat trackHeight = 0.225f;
	GLfloat elevationHeight = 0.01f;

	GLfloat gunWidth = 0.1f;
	GLfloat towerWidth = 0.6f;
	GLfloat chassisWidth = 0.9f;
	GLfloat trackWidth = 0.2f;

	GLfloat gunLong = 1.5f;
	GLfloat towerLong = 1.0f;
	GLfloat chassisLong = 1.7f;

	GLfloat deltaHeightGun = 0.1f;
	GLfloat deltaHeightUpperChassis = 0.2f;
	GLfloat deltaHeightFrontPartPartition = 0.15f;

	GLfloat deltaLongPartsOfTrack = 0.05f;
	GLfloat deltaLongFrontChassis = 0.15f;
	GLfloat deltaLongTowerOffset = 0.0f; // need to change rotate center for tower
	///////////////////////////////////////////////////////////////////////
	GLfloat bottomArea[20] = {
	-areaWidth / 2, 0.0f, -areaLong / 2, 0.0f, 1.0f, // left top
	-areaWidth / 2, 0.0f, areaLong / 2, 0.0f, 0.0f, // left bottom
	areaWidth / 2, 0.0f, areaLong / 2, 1.0f, 0.0f, // right bottom
	areaWidth / 2, 0.0f, -areaLong / 2, 1.0f, 1.0f // right top
	};

	GLuint bottomAreaI[6] = {
	0, 1, 2,
	0, 2, 3
	};

	GLfloat areaWalls[100] = {
	// roof;
	-areaWidth / 2, areaHeight, -areaLong / 2, 0.0f, 1.0f, // left top
	-areaWidth / 2, areaHeight, areaLong / 2, 0.0f, 0.0f, // left bottom
	areaWidth / 2, areaHeight, areaLong / 2, 1.0f, 0.0f, // right bottom
	areaWidth / 2, areaHeight, -areaLong / 2, 1.0f, 1.0f, // right top
	// left
	-areaWidth / 2, areaHeight, -areaLong / 2, 0.0f, 1.0f,
	-areaWidth / 2, 0.0f, -areaLong / 2, 0.0f, 0.0f,
	-areaWidth / 2, 0.0f, areaLong / 2, 1.0f, 0.0f,
	-areaWidth / 2, areaHeight, areaLong / 2, 1.0f, 1.0f,
	// right
	areaWidth / 2, areaHeight, -areaLong / 2, 0.0f, 1.0f,
	areaWidth / 2, 0.0f, -areaLong / 2, 0.0f, 0.0f,
	areaWidth / 2, 0.0f, areaLong / 2, 1.0f, 0.0f,
	areaWidth / 2, areaHeight, areaLong / 2 , 1.0f, 1.0f,
	// front
	-areaWidth / 2, areaHeight, -areaLong / 2, 0.0f, 1.0f,
	-areaWidth / 2, 0.0f, -areaLong / 2, 0.0f, 0.0f,
	areaWidth / 2, 0.0f, -areaLong / 2, 1.0f, 0.0f,
	areaWidth / 2, areaHeight, -areaLong / 2, 1.0f, 1.0f,
	// back
	-areaWidth / 2, areaHeight, areaLong / 2, 0.0f, 1.0f,
	-areaWidth / 2, 0.0f, areaLong / 2, 0.0f, 0.0f,
	areaWidth / 2, 0.0f, areaLong / 2, 1.0f, 0.0f,
	areaWidth / 2, areaHeight, areaLong / 2, 1.0f, 1.0f
	};

	GLuint areaWallsI[30] = {
	0, 1, 2,
	0, 2, 3,
	4, 5, 6,
	4, 6, 7,
	8, 9, 10,
	8, 10, 11,
	12, 13, 14,
	12, 14, 15,
	16, 17, 18,
	16, 18, 19
	};
	///////////////////////////////////////////////////////////////////////
	GLfloat chassisPart[180] = {
		// view from the positive value of axis Oy on plane xOz
		// upper side
		(-chassisWidth) / 2, chassisHeight, (-chassisLong) / 2, 0.0f, 1.0f, // left top
		(-chassisWidth) / 2, chassisHeight, chassisLong / 2, 0.0f, 0.0f, // left bottom
		chassisWidth / 2, chassisHeight, chassisLong / 2, 1.0f, 0.0f,// right bottom
		chassisWidth / 2, chassisHeight, (-chassisLong) / 2, 1.0f, 1.0f, // right top
		// right side (upper part)
		chassisWidth / 2, chassisHeight, -chassisLong / 2, 0.0f, 0.2f,
		chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, chassisLong / 2, 1.0f, 0.0f,
		chassisWidth / 2, chassisHeight, chassisLong / 2, 1.0f, 0.2f,
		// left side (upper part)
		-chassisWidth / 2, chassisHeight, -chassisLong / 2, 0.0f, 0.2f,
		-chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 0.0f, 0.0f,
		-chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, chassisLong / 2, 1.0f, 0.0f,
		-chassisWidth / 2, chassisHeight, chassisLong / 2, 1.0f, 0.2f,
		// back part
		-chassisWidth / 2, chassisHeight, chassisLong / 2, 0.0f, 0.4f,
		-chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, chassisLong / 2, 1.0f, 0.0f,
		chassisWidth / 2, chassisHeight, chassisLong / 2, 1.0f, 0.4f,
		// front upper part
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.0f, 0.2f,
		-chassisWidth / 2, chassisHeight, -chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight, -chassisLong / 2, 1.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 1.0f, 0.2f,
		// front bottom part
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.0f, 0.1f,
		-chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 1.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 1.0f, 0.1f,
		// side particles in front part
		// upper left
		-chassisWidth / 2, chassisHeight, -chassisLong / 2, 0.0f, 0.1f,
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2, 0.0f, 0.0f,
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.1f, 0.0f,
		// upper rigth
		chassisWidth / 2, chassisHeight, -chassisLong / 2, 0.0f, 0.1f,
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.1f, 0.0f,
		// bottom left
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2, 0.1f, 0.0f,
		-chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 0.0f, 0.0f,
		-chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.1f, 0.1f,
		// bottom rigth
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2, 0.1f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightUpperChassis, -chassisLong / 2, 0.0f, 0.0f,
		chassisWidth / 2, chassisHeight - deltaHeightFrontPartPartition, -chassisLong / 2 - deltaLongFrontChassis, 0.1f, 0.1f
	};

	GLuint chassisI[48] = {
	0, 1, 2,
	0, 2, 3,
	4, 5, 6,
	4, 6, 7,
	8, 9, 10,
	8, 10, 11,
	12, 13, 14,
	12, 14, 15,
	16, 17, 18,
	16, 18, 19,
	20, 21, 22,
	20, 22, 23,
	// triangles (side particles in front part)
	24, 25, 26,
	27, 28, 29,
	30, 31, 32,
	33, 34, 35
	};

	GLfloat headPart[180] = {
		// view from the positive value of axis Oy on plane xOz
		//tower (only upper side)
		(-towerWidth) / 2, towerHeight, (-towerLong) / 2 + deltaLongTowerOffset, 0.0f, 1.0f, // left top
		(-towerWidth) / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		towerWidth / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f, // right bottom
		towerWidth / 2, towerHeight, (-towerLong) / 2 + deltaLongTowerOffset, 1.0f, 1.0f, // right top
		// gun (upper side)
		(-gunWidth) / 2, gunHeight, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 1.0f, // left top
		(-gunWidth) / 2, gunHeight, -towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		gunWidth / 2, gunHeight, -towerLong / 2 + deltaLongTowerOffset, 0.1f, 0.0f, // right bottom
		gunWidth / 2, gunHeight, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.1f, 1.0f, // right top
		// gun (down side)
		(-gunWidth) / 2, gunHeight - deltaHeightGun, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 1.0f, // left top
		(-gunWidth) / 2, gunHeight - deltaHeightGun, -towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		gunWidth / 2, gunHeight - deltaHeightGun, -towerLong / 2 + deltaLongTowerOffset, 0.1f, 0.0f, // right bottom
		gunWidth / 2, gunHeight - deltaHeightGun, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.1f, 1.0f, // right top
		// side polygons
		// right gun side
		gunWidth / 2, gunHeight, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.1f,
		gunWidth / 2, gunHeight - deltaHeightGun, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f,
		gunWidth / 2, gunHeight - deltaHeightGun, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f,
		gunWidth / 2, gunHeight, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.1f,
		// left gun side
		-gunWidth / 2, gunHeight, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.1f,
		-gunWidth / 2, gunHeight - deltaHeightGun, -gunLong - towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f,
		-gunWidth / 2, gunHeight - deltaHeightGun, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f,
		-gunWidth / 2, gunHeight, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.1f,
		// right tower side
		towerWidth / 2, towerHeight, (-towerLong) / 2 + deltaLongTowerOffset, 0.0f, 0.4f, // left top
		towerWidth / 2, chassisHeight, (-towerLong) / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		towerWidth / 2, chassisHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f, // right bottom
		towerWidth / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.4f, // right top
		// left tower side
		-towerWidth / 2, towerHeight, (-towerLong) / 2 + deltaLongTowerOffset, 0.0f, 0.4f, // left top
		-towerWidth / 2, chassisHeight, (-towerLong) / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		-towerWidth / 2, chassisHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f, // right bottom
		-towerWidth / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.4f, // right top
		// back tower side
		(-towerWidth) / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.4f, // left top
		(-towerWidth) / 2, chassisHeight, towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		towerWidth / 2, chassisHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f, // right botttom
		towerWidth / 2, towerHeight, towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.4f, // right top
		// front tower side 
		(-towerWidth) / 2, towerHeight, -towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.4f, // left top
		(-towerWidth) / 2, chassisHeight, -towerLong / 2 + deltaLongTowerOffset, 0.0f, 0.0f, // left bottom
		towerWidth / 2, chassisHeight, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.0f, // right botttom
		towerWidth / 2, towerHeight, -towerLong / 2 + deltaLongTowerOffset, 1.0f, 0.4f, // right top
	};

	GLuint headI[60] = {
	0, 1, 2,
	0, 2, 3,
	4, 5, 6,
	4, 6, 7,
	8, 9, 10,
	8, 10, 11,
	12, 13, 14,
	12, 14, 15,
	16, 17, 18,
	16, 18, 19,
	20, 21, 22,
	20, 22, 23,
	24, 25, 26,
	24, 26, 27,
	28, 29, 30,
	28, 30, 31,
	32, 33, 34,
	32, 34, 35,
	36, 37, 38,
	36, 38, 39
	};
	///////////////////////////////////////////////////////////////////////
	GLfloat rightTopTrack[20] = {
	chassisWidth / 2, trackHeight, -chassisLong / 2, 0.0f, 1.5f, //
	chassisWidth / 2, trackHeight, chassisLong / 2, 0.0f, 0.0f, //
	chassisWidth / 2 + trackWidth, trackHeight, chassisLong / 2, 1.0f, 0.0f, //
	chassisWidth / 2 + trackWidth, trackHeight, -chassisLong / 2, 1.0f, 1.5f //
	};

	GLfloat rightBottomTrack[20] = {
	chassisWidth / 2, elevationHeight, -chassisLong / 2, 0.0f, 1.5f, //
	chassisWidth / 2, elevationHeight, chassisLong / 2, 0.0f, 0.0f, //
	chassisWidth / 2 + trackWidth, elevationHeight, chassisLong / 2, 1.0f, 0.0f, //
	chassisWidth / 2 + trackWidth, elevationHeight, -chassisLong / 2, 1.0f, 1.5f //
	};

	GLfloat rightUpperBackTrack[20] = {
	chassisWidth / 2, trackHeight, chassisLong / 2, 0.0f, 0.2f,
	chassisWidth / 2, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 0.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 1.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight, chassisLong / 2, 1.0f, 0.2f
	};

	GLfloat rightDownBackTrack[20] = {
	chassisWidth / 2, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 0.0f, 0.2f,
	chassisWidth / 2, elevationHeight, chassisLong / 2, 0.0f, 0.0f,
	chassisWidth / 2 + trackWidth, elevationHeight, chassisLong / 2, 1.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLfloat rightUpperFrontTrack[20] = {
	chassisWidth / 2, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 0.0f, 0.2f,
	chassisWidth / 2, trackHeight, -chassisLong / 2, 0.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight, -chassisLong / 2, 1.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLfloat rightDownFrontTrack[20] = {
	chassisWidth / 2, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 0.0f, 0.2f,
	chassisWidth / 2, elevationHeight, -chassisLong / 2, 0.0f, 0.0f,
	chassisWidth / 2 + trackWidth, elevationHeight, -chassisLong / 2, 1.0f, 0.0f,
	chassisWidth / 2 + trackWidth, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLfloat leftTopTrack[20] = {
	-chassisWidth / 2, trackHeight, -chassisLong / 2, 0.0f, 1.5f, //
	-chassisWidth / 2, trackHeight, chassisLong / 2, 0.0f, 0.0f, //
	-chassisWidth / 2 - trackWidth, trackHeight, chassisLong / 2, 1.0f, 0.0f, //
	-chassisWidth / 2 - trackWidth, trackHeight, -chassisLong / 2, 1.0f, 1.5f //
	};

	GLfloat leftBottomTrack[20] = {
	-chassisWidth / 2, elevationHeight, -chassisLong / 2, 0.0f, 1.5f, //
	-chassisWidth / 2, elevationHeight, chassisLong / 2, 0.0f, 0.0f, //
	-chassisWidth / 2 - trackWidth, elevationHeight, chassisLong / 2, 1.0f, 0.0f, //
	-chassisWidth / 2 - trackWidth, elevationHeight, -chassisLong / 2, 1.0f, 1.5f //
	};

	GLfloat leftUpperFrontTrack[20] = {
	-chassisWidth / 2, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 0.0f, 0.2f,
	-chassisWidth / 2, trackHeight, -chassisLong / 2, 0.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight, -chassisLong / 2, 1.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLfloat leftDownFrontTrack[20] = {
	-chassisWidth / 2, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 0.0f, 0.2f,
	-chassisWidth / 2, elevationHeight, -chassisLong / 2, 0.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, elevationHeight, -chassisLong / 2, 1.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight / 2, -chassisLong / 2 - deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLfloat leftUpperBackTrack[20] = {
	-chassisWidth / 2, trackHeight, chassisLong / 2, 0.0f, 0.2f,
	-chassisWidth / 2, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 0.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 1.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight, chassisLong / 2, 1.0f, 0.2f
	};

	GLfloat leftDownBackTrack[20] = {
	-chassisWidth / 2, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 0.0f, 0.2f,
	-chassisWidth / 2, elevationHeight, chassisLong / 2, 0.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, elevationHeight, chassisLong / 2, 1.0f, 0.0f,
	-chassisWidth / 2 - trackWidth, trackHeight / 2, chassisLong / 2 + deltaLongPartsOfTrack, 1.0f, 0.2f
	};

	GLuint trackI[6] = {
	0, 1, 2,
	0, 2, 3,
	};
	///////////////////////////////////////////////////////////////////////
};

#endif 
