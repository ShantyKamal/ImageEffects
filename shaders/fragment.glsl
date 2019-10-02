// ==========================================================================
// Modified fragment shader program
//
// Author:  Shanty K
// Date:    Oct 2018
// ==========================================================================
#version 410

// interpolated colour received from vertex stage
in vec2 uv;
///////////////////

// first output is mapped to the framebuffer's colour index by default
out vec4 FragmentColour;
uniform sampler2DRect imageTexture;
//pass in selected greyScaleMatrix
uniform mat4 greyScaleMatrix; 


void main(void)
{
	vec4 myColour = texture(imageTexture, uv );
	vec2 topLeft = (uv[0]-1, uv[1]+1);
	vec4 topLeftColour  = texture(imageTexture, topLeft);
	
	FragmentColour = myColour * greyScaleMatrix;
	//uncomment below lines to convert to greyscale
	float l = dot(FragmentColour, vec4(1));
	FragmentColour = vec4(l);
}