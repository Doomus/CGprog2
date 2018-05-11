#include "ObjData.h"
#include <iostream>
#include <string>


static int RecursiveLoad(const char *fileName, ObjLoader::ObjData &data) {



	std::ifstream file(fileName);
	std::string nextLine;

	while (std::getline(file, nextLine)) {

		if (nextLine.length() > 2) {
			switch (nextLine[0])
			{
			case 'v':
				switch (nextLine[1]) {

				case 32: //vertex data
					if (data.vertices == nullptr) {
						++data.numVerts;
						continue;
					}
					break;
				case 't':
					if (data.uvs == nullptr) {
						++data.numUvs;
						continue;
					}
					break;

				case 'n': // normals data
					if (data.normals == nullptr) {
						++data.numNormals;
						continue;
					}
					break;
				}
				break;
			case 'f':
				if (nextLine[1] == 32 && data.faces == nullptr) {
					++data.numFaces;
				}
				break;
			}
		}

		if (data.faces == nullptr) {

			data.faces = (unsigned int*)malloc(data.numFaces);
			data.vertices = (float*)malloc(data.numVerts);
			data.normals = (float*)malloc(data.numNormals);
			data.uvs = (float*)malloc(data.numUvs);


			return RecursiveLoad(fileName, data);
		}

	}

		//if faces != nullptr, we simply counted the faces, not set them.
	return data.faces != nullptr ? 0 :
		RecursiveLoad(fileName, data);
	
};

int ObjLoader::Load(const char* fileName, ObjData &data) {
	RecursiveLoad(fileName, data);

	return 0;

};


