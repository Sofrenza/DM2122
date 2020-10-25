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
	m_programID = LoadShaders("Shader//SimpleVertexShader.vertexshader", "Shader//SimpleFragmentShader.fragmentshader");
	glUseProgram(m_programID);

	//Switch background colour to dark blue
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//generating a default VAO
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//generate buffers
	glGenBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glGenBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);

	//An Array of 3 vectors which represents 3 vertices
	static const GLfloat vertex_buffer_data[] = {
		-0.7f, 0.0f, 0.0f, //Vertice 0
		0.0f, 1.0f, 0.0f, //Vertice 1
		1.0f, 0.0f, 0.0f, //Vertice 2
	};

	//second triangle
	static const GLfloat vertex_buffer_data_2[] = {
		0.0f, 0.7f, 0.0f, //Vertice 0
		-1.0f, 0.0f, 0.0f, //Vertice 1
		1.0f, 0.0f, 0.0f, //Vertice 2
	};

	//set the current active buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	//Transfer vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_2), vertex_buffer_data_2, GL_STATIC_DRAW);

	// An array of 3 vectors which represents the colors of the 3 vertices
		static const GLfloat color_buffer_data[] = {
		1.0f, 1.0f, 0.0f, //color of vertex 0
		1.0f, 1.0f, 0.0f, //color of vertex 1
		1.0f, 1.0f, 0.0f, //color of vertex 2
		};

		static const GLfloat color_buffer_data_2[] = {
		1.0f, 0.0f, 0.0f, //color of vertex 0
		1.0f, 0.0f, 0.0f, //color of vertex 1
		1.0f, 0.0f, 0.0f, //color of vertex 2
		};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data),
		color_buffer_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_2),
		color_buffer_data_2, GL_STATIC_DRAW);





}

void Scene1::Update(double dt)
{
}

void Scene1::Render()
{
	//Clear colour buffer every frame (Updating per frame?)
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0); //1st attribute buffer : vertices
	glEnableVertexAttribArray(1); //2nd attribute buffer : colors
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(
		0, //attribute 0.Must match layout in the shader. Usually 0 is for vertex
		3, //size
		GL_FLOAT, //Type
		GL_FALSE, //normalised?
		0, //Stride
		0 //array buffer offset
	);


	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//to draw triangle
	glDrawArrays(GL_TRIANGLES, 0, 3); //Starting from vertex 0; 3 vertices would make 1 traingele
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(
		0, //attribute 0.Must match layout in the shader. Usually 0 is for vertex
		3, //size
		GL_FLOAT, //Type
		GL_FALSE, //normalised?
		0, //Stride
		0 //array buffer offset
	);


	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//to draw triangle
	glDrawArrays(GL_TRIANGLES, 0, 3); //Starting from vertex 0; 3 vertices would make 1 traingele

	glDisableVertexAttribArray(1);

	glDisableVertexAttribArray(0);
}

void Scene1::Exit()
{
	// Cleanup VBO here
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
		
}
//PLEASE