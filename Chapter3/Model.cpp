//
// Created by 后藤一里 on 2023/4/20.
//
#include <iostream>

#include "Model.h"
#include "stb_image.h"

unsigned int TextureFromFile(const char *filename, string &dic)
{
	string m_filename = string(filename);
	m_filename = dic + '/' + m_filename;

	unsigned int ret_id;
	glGenTextures(1, &ret_id);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(m_filename.c_str(), &width, &height,
			&nrComponents, 0);

	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, ret_id);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << m_filename << std::endl;
		stbi_image_free(data);
	}

	return ret_id;
}

Model::Model(char* path)
{
	loadModel(path);
}

void Model::Draw(Shader shader)
{
	for (auto &mesh : meshes)
	{
		mesh.Draw(shader);
	}
}

void Model::loadModel(std::string path)
{
	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	for(unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}

	for(unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;

	for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
	{
		Vertex vertex;

		vertex.Position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
		vertex.Normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

		if (mesh->mTextureCoords[0])
			vertex.TexCoords = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
	{
		const aiFace &face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
		vector<Texture> diffuseMap = loadMaterialTextures(material,
				aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMap.begin(), diffuseMap.end());

		vector<Texture> specularMap = loadMaterialTextures(material,
				aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMap.begin(), specularMap.end());
	}

	return {vertices, indices, textures};
}

vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
	vector<Texture> textures;
	for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString filename;
		mat->GetTexture(type, i, &filename);
		Texture texture;
		texture.id = TextureFromFile(filename.C_Str(), directory);
		texture.type = typeName;
		texture.path = filename;
		textures.push_back(texture);
	}
	return textures;
}