// ==========================================================================
// Modified vertex shader 
//
// Author:  Shanty
// Date:    Oct 2018
// ==========================================================================
#version 410

// location indices for these attributes correspond to those specified in the
// InitializeGeometry() function of the main program
layout(location = 0) in vec3 VertexPosition; //vertex position
layout(location = 1) in vec2 VertexUV; //texture coords


uniform mat4 rotationMatrix; 
uniform mat4 scaleMatrix;
uniform mat4 translationMatrix; 
uniform mat4 centreMatrix;


// output to be interpolated between vertices and passed to the fragment stage
out vec2 uv;

void main()
{vec4 newPoint;
	//first translate to the center of the screen 
	mat4x4 centreMatrix = mat4x4(1.0,0.0,0.0,0.0,  0.0,1.0,0.0,0.0,  0.0,0.0,1.0,0.0,  0.00005, 0.00005,1.0,1.0);
	newPoint =  centreMatrix  *rotationMatrix * scaleMatrix *  translationMatrix *vec4(VertexPosition, 1.0f);
	
	//vec3 newnewPoint = VertexPosition * transMatrix ;
	//vec3 newPoint = scalingMatrix * rotationMatrixFromRenderingEngine * VertexPosition; 
	
    // assign vertex position WITH modification
    gl_Position = vec4(newPoint.xy, 0.0, 1.0); //z=0, w=1... why set z to 0?

    // assign output colour to be interpolated
    uv = VertexUV;
}
