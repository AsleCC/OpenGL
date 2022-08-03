#include <stdio.h>
//OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma region WindowConfig
//Tamaño pantalla
const GLint WIDTH = 800, HEIGHT = 600;
#pragma endregion Constantes de configuración de la pantalla


int main() {
	//Inicialización GLFW
	if (!glfwInit()) {
		printf("GLFW Initialisation failed!");
		glfwTerminate();
		return 1;
	}

#pragma region Compatibility
	//Versión de OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core profile  = Detecta si esta obsoleto algo que ponga
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#pragma endregion Errores de compatibilidad y versiones


#pragma region WindowInit
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test", NULL, NULL);
	if (!mainWindow) {
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	//Tamaño del buffer
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
	//Establecer contexto al GLEW
	glfwMakeContextCurrent(mainWindow);
	//Permite extensiones modernas de GL
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW init failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Tamaño del visulizador
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Bucle para el refresco
	while (!glfwWindowShouldClose(mainWindow)) {
		//Eventos dentro de la pantalla
		glfwPollEvents();

		//Limpiar la ventana
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}
#pragma endregion Inicialización de la ventana
	return 0;
}