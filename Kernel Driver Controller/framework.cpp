#include "framework.h"
#include "visualiser.h"
#include "RepeatableData.h"


bool Framework::run() {

	// Run the game loop

	Visualiser::RenderFrame();




	return true;
}


bool Framework::init() {

	// Get setup info from krnl

	if(!Data::init()) return false;


	//setup overlay

	if(!Visualiser::Init()) return false;





	// Read the config file


	return true;
}


void Framework::shutdown() {

	//shutdown the overlay

	Visualiser::Shutdown();



}


