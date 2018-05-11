#pragma once
#include <fstream>
#include <string>

namespace ObjLoader {

	struct ObjData
	{
		float *vertices = nullptr;
		float *normals = nullptr;
		float *uvs = nullptr;
		unsigned int *faces = nullptr;

	    unsigned int numVerts = 0;
	    unsigned int numNormals = 0;
	    unsigned int numUvs = 0;
	    unsigned int numFaces = 0;

	};
	//make function to clean up model data.
	int Load(const char* fileName, ObjData &data);

};

