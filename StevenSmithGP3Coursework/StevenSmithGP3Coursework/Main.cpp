#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY 

#include"Constants.h"
#include "cWNDManager.h"
#include "windowOGL.h"


int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR cmdLine,
				   int cmdShow)
{
	//Create window settings
	const int windowWidth = 1024;
	const int windowHeight = 768;
	const int windowBPP = 16;

	//Initialise the window
	static cWNDManager* pgmWNDMgr = cWNDManager::getInstance();

	//OpenGL
	windowOGL theOGLWnd;

	//Attach OpenGL to window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	//Attempt to create the window
	if (!pgmWNDMgr->createWND(windowWidth, windowHeight, windowBPP))
	{
		//If it fails

		MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}

	if (!theOGLWnd.initOGL(windowWidth, windowHeight)) //Initialize our example
	{
		MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}

	//This is the mainloop, we render frames until isRunning returns false
	while (pgmWNDMgr->isWNDRunning())
	{
		//Carry out any windows events
		pgmWNDMgr->processWNDEvents(); 
		//We get the time that passed since the last frame
		float elapsedTime = pgmWNDMgr->getElapsedSeconds();
		//Clear the buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Initialise OpenGL to draw
		theOGLWnd.initOGL(windowWidth, windowHeight);

		pgmWNDMgr->swapBuffers();
	}

	//Free the OpenGL storage
	theOGLWnd.shutdown();
	//Destroy the window
	pgmWNDMgr->destroyWND();
	//Return a 0 for success
	return 0; 
}