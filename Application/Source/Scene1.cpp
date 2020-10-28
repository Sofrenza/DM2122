#include "Scene1.h"
#include "GL\glew.h"

#include "shader.hpp"


Scene1::Scene1()
{
}

Scene1::~Scene1()
{
}

void Scene1::Init()
{

	//Load vertex and fragment shaders
	m_programID = LoadShaders(
		"Shader//SimpleVertexShader.vertexshader",
		"Shader//SimpleFragmentShader.fragmentshader");
	glUseProgram(m_programID);

	//set background colour to dark blue
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//Generate Buffers
	glGenBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glGenBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);

	//An Array of 3 vectors which represents 3 vertices
	//static const GLfloat vertex_buffer_data_1[] = {
	//	-1.0f, 0.0f, 0.0f, // Vertex 0
	//	0.0f, 1.0f, 0.0f, // Vertex 1
	//	1.0f, 0.0f, 0.0f, // Vertex 2
	//};

	//CHECK POINT 4, BLANKING OUT THE PREVIOUS COLOR/ BUFFER ARRAYS

	static const GLfloat vertex_buffer_data_1[] = {
		-0.5f, 0.7f, 0.0f,
		0.5f, 0.7f, 0.0f,
		-0.7f, 0.3f, 0.0f,
		0.7f, 0.3f, 0.0f,
		-0.7f, -0.2f, 0.0f,
		0.7f, -0.2f, 0.0f,
		-0.5f, -0.7f, 0.0f,
		0.5f, -0.7f, 0.0f
	};

	//set the current active buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	//Transfer Vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_1), vertex_buffer_data_1, GL_STATIC_DRAW);

	//An array of 3 vectors which represents the colors of the 3 vertices
	//static const GLfloat color_buffer_data_1[] = {
	//	1.0f, 0.0f, 0.0f, // Color for Vertex 0
	//	0.0f, 1.0f, 0.0f, // Color for Vertex 1
	//	0.0f, 1.0f, 1.0f, // Color for Vertex 2
	//};

	static const GLfloat color_buffer_data_1[] = {
		0.4f, 1.0f, 0.6f,
		1.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
		1.0f, 0.1f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 1.0f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_1), color_buffer_data_1, GL_STATIC_DRAW);



	//An Array of 3 vectors which represents 3 vertices
	static const GLfloat vertex_buffer_data_2[] = {
		0.5f, 0.7f, 0.0f, // Vertex 0
		-0.7f, -0.2f, 0.0f, // Vertex 1
		0.5f, -0.2f, -0.5f, // Vertex 2
		-0.1f, -0.2f, 0.7f, // Vertex 3
		-0.7f, 0.3f, 0.0f, // Vertex 4
		0.7f, 0.3f, 0.0f, // Vertex 5
		0.5f, -0.7f, 0.0f, // Vertex 6
		-0.1f, -0.2f, 0.7f, // Vertex 7
		0.5f, -0.2f, -0.5f, // Vertex 8
	};

	//set the current active buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	//Transfer Vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_2), vertex_buffer_data_2, GL_STATIC_DRAW);

	//An array of 3 vectors which represents the colors of the 3 vertices
	static const GLfloat color_buffer_data_2[] = {
		-1.0f, 0.0f, 0.5f, // Color for Vertex 0
		0.0f, 0.0f, 0.0f, // Color for Vertex 1
		1.0f, 1.0f, 1.0f, // Color for Vertex 2
		-1.0f, 0.0f, 0.5f, // Color for Vertex 3
		0.0f, 0.0f, 0.0f, // Color for Vertex 4
		1.0f, 1.0f, 1.0f, //Color for Vertex 5
		-1.0f, 0.0f, 0.5f, // Color for Vertex 6
		0.0f, 0.0f, 0.0f, // Color for Vertex 7
		1.0f, 1.0f, 1.0f, //color for Vertex 8
	};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_2), color_buffer_data_2, GL_STATIC_DRAW);

	//DEPTH TESTING
	//enable Depth Test
	glEnable(GL_DEPTH_TEST);
}

void Scene1::Update(double dt)
{
}

void Scene1::Render()
{
	//clear color buffer every frame
	//glClear(GL_COLOR_BUFFER_BIT); (Check point 4, currently getting replaced)
	//New clear command! Clears color and depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnableVertexAttribArray(0); //1st attribute buffer : Vertices
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(
		0, // attribute 0. Must match the layout in the shader.Usually 0 is for vertex
		3, //size
		GL_FLOAT, //type
		GL_FALSE, //normalized?
		0, //Stride
		0 //array buffer offset
	);

	glEnableVertexAttribArray(1); //2nd attribute buffer : colors

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);



	//Draw the triangle
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 8); //starting from vertex 0; 3 vertices - 1 triangle

	glEnableVertexAttribArray(0); //1st attribute buffer : Vertices
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(
		0, // attribute 0. Must match the layout in the shader.Usually 0 is for vertex
		3, //size
		GL_FLOAT, //type
		GL_FALSE, //normalized?
		0, //Stride
		0 //array buffer offset
	);

	glEnableVertexAttribArray(1); //2nd attribute buffer : colors
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 9); //starting from vertex 0; 3 vertices - 1 triangle


	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

}

void Scene1::Exit()
{
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);

}
