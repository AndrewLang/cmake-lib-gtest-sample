
#include "main.h"
#include "logging/logger.h"

using namespace std;
using namespace Matrix;

int main()
{
	cout << "Main App uses shared library" << endl;

	Logger logger("main");

	logger.debug("log messages").debug("debug messages");

	getchar();

	return 0;

}
