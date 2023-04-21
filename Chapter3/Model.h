//
// Created by 后藤一里 on 2023/4/20.
//

#ifndef LEARNOPENGL_CH3_MODEL_H
#define LEARNOPENGL_CH3_MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "shader_m.h"
#include "Mesh.h"

class Model
{
public:
	Model(char *path);
	void Draw(Shader shader);

private:
	vector<Mesh> meshes;
	string directory;
	vector<Texture> textures_loaded;

	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
			string typeName);
};

#endif //LEARNOPENGL_CH3_MODEL_H
