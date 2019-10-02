/*
 * Scene.cpp
 *
 *  Created on: Sep 10, 2018
 *  Author: John Hall
 */

#include "Scene.h"

#include <iostream>

#include "RenderingEngine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

//**Must include glad and GLFW in this order or it breaks**
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<string>
#include "texture.h"
int sceneNum = 0; //monkey scene (1)
int rotationIt = 0; //right side up

Scene::Scene(RenderingEngine* renderer) : renderer(renderer) {
	selectScene();
	/*MyTexture texture;
	std::string sceneImg = selectScene("image1-mandrill.png");
	//Shaders need to be active to load uniforms
		glUseProgram(renderer->shaderProgram);

		//TODO: assign correct texture here based on scene selection
		InitializeTexture(&texture, "image1-mandrill.png", GL_TEXTURE_RECTANGLE);

		glm::mat4 baseMatrix = glm::mat4(1.0f);
		glm::mat4 rotationMatrix = glm::rotate(baseMatrix, glm::radians(60.0f), glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 scaleMatrix = glm::scale(baseMatrix, glm::vec3(0.5, 0.5, 1.0));

		//Get identifiers for uniforms
		GLuint uniformLocation = glGetUniformLocation(renderer->shaderProgram, "imageTexture");
		GLuint rotationLoc = glGetUniformLocation(renderer->shaderProgram, "rotationMatrix");
		GLuint scaleLoc = glGetUniformLocation(renderer->shaderProgram, "scaleMatrix");
		//std::cout<<"\n"<<rotationLoc<<"\n";
		//Load texture uniform



		//Set which texture unit the texture is bound to
		glActiveTexture(GL_TEXTURE0);
		//Bind the texture to GL_TEXTURE0
		glBindTexture(GL_TEXTURE_RECTANGLE, texture.textureID);


		//Load texture unit number into uniform
		glUniform1i(uniformLocation, 0);
		glUniformMatrix4fv(rotationLoc, 1, GL_FALSE, glm::value_ptr(rotationMatrix));



		if(renderer->CheckGLErrors()) {
			std::cout << "Texture creation faileeeed" << std::endl;
		}
		// three vertex positions and associated colours of a triangle
	rectangle.verts.push_back(glm::vec3( -0.9f, -0.9f, 1.0f));
	rectangle.verts.push_back(glm::vec3( 0.9f,  -0.9f, 1.0f));
	rectangle.verts.push_back(glm::vec3( 0.9f, 0.9f, 1.0f));
	rectangle.verts.push_back(glm::vec3( -0.9f, -0.9f, 1.0f));
	rectangle.verts.push_back(glm::vec3( 0.9f, 0.9f, 1.0f));
	rectangle.verts.push_back(glm::vec3( -0.9f, 0.9f, -1.0f));

	rectangle.drawMode = GL_TRIANGLES;

	rectangle.uvs.push_back(glm::vec2( 0.0f, 0.0f));
	rectangle.uvs.push_back(glm::vec2( float(texture.width), 0.f));
	rectangle.uvs.push_back(glm::vec2( float(texture.width), float(texture.height)));
	rectangle.uvs.push_back(glm::vec2( 0.0f, 0.0f));
	rectangle.uvs.push_back(glm::vec2( float(texture.width), float(texture.height)));
	rectangle.uvs.push_back(glm::vec2(0.0f, float(texture.height)));

	//Construct vao and vbos for the triangle
	RenderingEngine::assignBuffers(rectangle);

	//Send the triangle data to the GPU
	//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
	RenderingEngine::setBufferData(rectangle);

	//Add the triangle to the scene objects
	objects.push_back(rectangle);*/

}



void Scene::selectScene(){
	rotationIt=0;
	objects.clear();
	rectangle.verts.clear();
	rectangle.uvs.clear();
	++sceneNum;
	//if (sceneNum<=1){sceneNum=1;} //cap scene changes once start is reached
	//if (sceneNum>=6){sceneNum=6;} //cap scene changes once end is reached
	sceneNum = sceneNum%6;
	MyTexture texture;
	//select texture for current scene
	switch (sceneNum)
	{
	    case 1: InitializeTexture(&texture, "image1.png", GL_TEXTURE_RECTANGLE);
	        break;
	    case 2: InitializeTexture(&texture, "image2.png", GL_TEXTURE_RECTANGLE);
	        break;
	    case 3: InitializeTexture(&texture, "image3.jpg", GL_TEXTURE_RECTANGLE);
	    		break;
	    case 4:InitializeTexture(&texture, "image4.jpg", GL_TEXTURE_RECTANGLE);
	    		break;
	    case 5: InitializeTexture(&texture, "image5.png", GL_TEXTURE_RECTANGLE);
	    	    		break;
	    	case 0: InitializeTexture(&texture, "image6.png", GL_TEXTURE_RECTANGLE);
	    	    		break;
	    default: std::cout<<"\n no image selected.\n";
	}

		//Shaders need to be active to load uniforms
			glUseProgram(renderer->shaderProgram);

		//Get identifiers for uniforms
		GLuint uniformLocation = glGetUniformLocation(renderer->shaderProgram, "imageTexture");

			//Set which texture unit the texture is bound to
			glActiveTexture(GL_TEXTURE0);
			//Bind the texture to GL_TEXTURE0
			glBindTexture(GL_TEXTURE_RECTANGLE, texture.textureID);

			//Load texture unit number into uniform
			glUniform1i(uniformLocation, 0);


				glm::mat4 idMatrix = glm::mat4(1.0f);
				GLuint rotationLoc = glGetUniformLocation(renderer->shaderProgram, "rotationMatrix");
				glUniformMatrix4fv(rotationLoc, 1, GL_FALSE, glm::value_ptr(idMatrix));
				GLuint translationLoc = glGetUniformLocation(renderer->shaderProgram, "translationMatrix");
				glUniformMatrix4fv(translationLoc, 1, GL_FALSE, glm::value_ptr(idMatrix));
				GLuint offsetLoc = glGetUniformLocation(renderer->shaderProgram, "translateToCenter");
				glUniformMatrix4fv(offsetLoc, 1, GL_FALSE, glm::value_ptr(idMatrix));
				GLuint scaleLoc = glGetUniformLocation(renderer->shaderProgram, "scaleMatrix");
				glUniformMatrix4fv(scaleLoc, 1, GL_FALSE, glm::value_ptr(idMatrix));

			//glUniformMatrix4fv(rotationLoc, 1, GL_FALSE, glm::value_ptr(rotationMatrix));

			//rotate();
			//scale();
			//translate();

			if(renderer->CheckGLErrors()) {
				std::cout << "Texture creation faileeeed" << std::endl;
			}
			//maintain aspect ratios
			float longerSide = std::max(texture.width, texture.height);
			float shorterSide = std::min(texture.width, texture.height);
			float aspectRatio = shorterSide/longerSide;
			// three vertex positions and associated colours of a triangle
			if (longerSide == texture.height){
				rectangle.verts.push_back(glm::vec3( -aspectRatio, -1.0f, 1.0f));
				rectangle.verts.push_back(glm::vec3( aspectRatio,  -1.0f, 1.0f));
				rectangle.verts.push_back(glm::vec3( aspectRatio, 1.0f, 1.0f));
				rectangle.verts.push_back(glm::vec3( -aspectRatio, -1.0f, 1.0f));
				rectangle.verts.push_back(glm::vec3( aspectRatio, 1.0f, 1.0f));
				rectangle.verts.push_back(glm::vec3( -aspectRatio, 1.0f, -1.0f));
			}
			else {
				rectangle.verts.push_back(glm::vec3( -1.0f, -aspectRatio, 1.0f));
				rectangle.verts.push_back(glm::vec3( 1.0f,  -aspectRatio, 1.0f));
				rectangle.verts.push_back(glm::vec3( 1.0f, aspectRatio, 1.0f));
				rectangle.verts.push_back(glm::vec3( -1.0f, -aspectRatio, 1.0f));
				rectangle.verts.push_back(glm::vec3( 1.0f, aspectRatio, 1.0f));
				rectangle.verts.push_back(glm::vec3( -1.0f, aspectRatio, -1.0f));
			}
				rectangle.drawMode = GL_TRIANGLES;

				rectangle.uvs.push_back(glm::vec2( 0.0f, 0.0f));
				rectangle.uvs.push_back(glm::vec2( float(texture.width), 0.f));
				rectangle.uvs.push_back(glm::vec2( float(texture.width), float(texture.height)));
				rectangle.uvs.push_back(glm::vec2( 0.0f, 0.0f));
				rectangle.uvs.push_back(glm::vec2( float(texture.width), float(texture.height)));
				rectangle.uvs.push_back(glm::vec2(0.0f, float(texture.height)));
		//Construct vao and vbos for the triangle
		RenderingEngine::assignBuffers(rectangle);
		//Send the triangle data to the GPU
		//Must be done every time the triangle is modified in any way, ex. verts, colors, normals, uvs, etc.
		RenderingEngine::setBufferData(rectangle);
		//Add the triangle to the scene objects
		objects.push_back(rectangle);
}


void Scene::updateTranslationMatrix(double xpos, double ypos){
	//TODO: screen coords --> opengl vertex coords
	//activate shaders

	glUseProgram(renderer->shaderProgram);

	glm::mat4 idMatrix = glm::mat4(1.0f);
	glm::mat4 translationMatrix = glm::translate(idMatrix, glm::vec3(xpos, ypos, 1.0));
	//glm::mat4 undoTranslationMatrix = glm::translate(idMatrix, glm::vec3(ypos, xpos, 1.0));
	GLuint translationLoc = glGetUniformLocation(renderer->shaderProgram, "translationMatrix");
	//GLuint undoTranslationLoc = glGetUniformLocation(renderer->shaderProgram, "centreMatrix");
	glUniformMatrix4fv(translationLoc, 1, GL_FALSE, glm::value_ptr(translationMatrix));
	//glUniformMatrix4fv(undoTranslationLoc, 1, GL_FALSE, glm::value_ptr(undoTranslationMatrix));


}


void Scene::updateRotationMatrix(float theta){
	//Shaders need to be active to load uniforms
	glUseProgram(renderer->shaderProgram);
	glm::mat4 idMatrix = glm::mat4(1.0f);
	glm::mat4 rotationMatrix = glm::rotate(idMatrix, glm::radians(theta), glm::vec3(0.0, 0.0, 1.0));
	GLuint rotationLoc = glGetUniformLocation(renderer->shaderProgram, "rotationMatrix");
	glUniformMatrix4fv(rotationLoc, 1, GL_FALSE, glm::value_ptr(rotationMatrix));
}

void Scene::rotateRight(){
	rotationIt--;
	std::cout<<"rotateRight() "<<rotationIt;
	float angle = 10.0f * rotationIt;
	updateRotationMatrix(angle);
}

void Scene::rotateLeft(){
	rotationIt++;
	std::cout<<"rotateLeft() "<<rotationIt;
	float angle = 10.0f * rotationIt;
	updateRotationMatrix(angle);
}

void Scene::updateScaleMatrix(double yoffset){
	//scroll down is pos , scroll moving upwards is negative

	glUseProgram(renderer->shaderProgram);
	glm::mat4 idMatrix = glm::mat4(1.0f);
	if (yoffset<0) //zoom in, scale up
	{yoffset = abs(yoffset);
	yoffset+=1.5;}
	else if(yoffset>0) //zoom out, scale down
	{yoffset = abs(yoffset);
	yoffset+=1.5;
	yoffset = 1/yoffset;
	}
	else //yoffset == 0
	{yoffset = 1;}
	glm::mat4 scaleMatrix = glm::scale(idMatrix, glm::vec3(abs(yoffset), abs(yoffset), 1.0));
	GLuint scaleLoc = glGetUniformLocation(renderer->shaderProgram, "scaleMatrix");
	glUniformMatrix4fv(scaleLoc, 1, GL_FALSE, glm::value_ptr(scaleMatrix));


}
Scene::~Scene() {}
//sends geometry objects to renderer
void Scene::displayScene() {renderer->RenderScene(objects);}

