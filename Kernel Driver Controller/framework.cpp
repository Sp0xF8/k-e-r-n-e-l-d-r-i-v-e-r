#include "framework.h"
#include "RepeatableData.h"


bool Framework::run() {

	// Run the game loop



	return true;
}


bool Framework::init() {

	// Get setup info from krnl

	if(!Data::init()) return false;


	//setup overlay





	// Read the config file


	return true;
}


void Framework::shutdown() {

	// Shutdown the renderer
	
	// Shutdown the window

	// shutdown device

}


