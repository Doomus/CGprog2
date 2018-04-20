#include "Renderer.h"

int main(){

	if(InitWindowFailed() | InitGlewFailed()){
		return EXIT_WITH_ERROR;
	}

	BeginRendering();

	return EXIT_WITH_SUCCESS;
}