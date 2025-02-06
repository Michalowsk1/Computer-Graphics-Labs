#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/shader.hpp>

// Function prototypes
void keyboardInput(GLFWwindow *window);

int main( void )
{
    // =========================================================================
    // Window creation - you shouldn't need to change this code
    // -------------------------------------------------------------------------
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Lab02 Basic Shapes", NULL, NULL);
    


    if( window == NULL ){
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    // -------------------------------------------------------------------------
    // End of window creation
    // =========================================================================
    
        //defining vertices
    const float vertices[] =
    {
        //  x   y   z
        0.0f, 0.0f, 0.0f,  //white triangles
        -0.2f, 0.6f, 0.0f,
        0.2f,  0.6f, 0.0f,

        0.0f, 0.0f, 0.0f,  
        -0.2f, -0.6f, 0.0f,
        0.2f,  -0.6f, 0.0f,

        0.0f, 0.0f, 0.0f,
        -0.6f, 0.2f, 0.0f,
        -0.6f,  -0.2f, 0.0f,

        0.0f, 0.0f, 0.0f,
        0.6f, 0.2f, 0.0f,
        0.6f,  -0.2f, 0.0f,

        
        0.0f, 0.0f, 0.0f, //red triangles
        0.2f, 0.6f, 0.0f,
        0.6f, 0.2f, 0.0f,

        0.0f, 0.0f, 0.0f,
        0.2f, -0.6f, 0.0f,
        0.6f, -0.2f, 0.0f,

        0.0f, 0.0f, 0.0f,
        -0.2f, 0.6f, 0.0f,
        -0.6f, 0.2f, 0.0f,

        0.0f, 0.0f, 0.0f,
        -0.2f, -0.6f, 0.0f,
        -0.6f, -0.2f, 0.0f,
    };

    //define vertex colours
    const float colours[] =
    {
       //R     G     B
        1.0f, 0.0f, 0.0f, //red
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f, //red
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f, //red
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f, //red
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 1.0f, 1.0f, //white
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, //white
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, //white
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, //white
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f
    }; 

    //create the Vertex Array Object (VAO)
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //create vertex buffer object (VBO)
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Create colour buffer
    unsigned int colourBuffer;
    glGenBuffers(1, &colourBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);

    //Compile shader program
    unsigned int shaderID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");

    //Use the shader program
    glUseProgram(shaderID);

	// Ensure we can capture keyboard inputs
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Render loop
	while (!glfwWindowShouldClose(window))
    {
        // Get inputs
        keyboardInput(window);
        
        // Clear the window
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //send VBO to shaders
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer
        (
            0,              //attribute
            3,              //size
            GL_FLOAT,       //type
            GL_FALSE,       //normalise?
            0,              //stride
            (void*)0        //offset
        );
        //Send colour buffer to shader
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        //Draw the triangle
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / (3 * sizeof(float)));
        glDisableVertexAttribArray(0);
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
    
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;

    ////Cleanup
    //glDeleteBuffers(1, &VBO);
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteProgram(shaderID);

}

void keyboardInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
