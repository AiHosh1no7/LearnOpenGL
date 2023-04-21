//
// Created by 后藤一里 on 2023/4/20.
//

#ifndef LEARNOPENGL_CH3_MESH_H
#define LEARNOPENGL_CH3_MESH_H

#include <cstring>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "shader_m.h"

using std::string;
using std::vector;

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	string type;
	aiString path;
};

class Mesh {
public:
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;

	Mesh(vector<Vertex> &vertices, vector<unsigned int> &indices, vector<Texture> &textures);
	void Draw(Shader shader);

private:
	unsigned int VAO, VBO, EBO;

	void setupMesh();
};

#endif //LEARNOPENGL_CH3_MESH_H
