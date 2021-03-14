#include <GLFW/glfw3.h>
#include "example.c"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    
    /* Set the anti-aliasing */
    if(antiAliasing){
        glfwWindowHint(GLFW_SAMPLES, antiAliasingLevel);
    }
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Gilbert GL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Config the blend */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* Configure the anti-aliasing */
    if(antiAliasing){
        glEnable(GL_MULTISAMPLE);
    }

    
    /* Set background color */
    glClearColor(1,1,1,1);
    
    /* Initialize the example */
    printf("Initializing Gilbert Example...\n");
    exinit();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    	/* Put all the nice code stuff here */
    	exloop();	

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
