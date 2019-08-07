
#include "main.h"
#include "logger.h"

using namespace std;
using namespace SharedLib;

int main()
{
	cout << "Main App uses shared library" << endl;

	Logger logger("main");

	logger.debug("log messages");

	getchar();

	return 0;

}
