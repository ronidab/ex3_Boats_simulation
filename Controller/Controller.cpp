#include "./Controller.h"
#include "./FileParser.h"
#include "./Terminal.h"
/***************************/
void Controller::load_data(const char * filename)	{
	try	{
		FileParser file_parser = FileParser(filename); // this call generates all port's at Model component.
	}
	catch( exception& e )	{
	    cerr << e.what() << endl;
	    exit(1);}
}
/***************************/
void Controller::run()	{ terminal.run(); }
/***************************/
