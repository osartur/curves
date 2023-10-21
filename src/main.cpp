#include "anut.h"
#include "curves.h"

int main()
{
	Engine* andronaut = new Engine;
	Curves* chaikin_method = new Curves;
	int output = andronaut->Start(chaikin_method);
	
	delete andronaut;
	delete chaikin_method;
	
	return output;
}

