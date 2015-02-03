#include <QtCore/QCoreApplication>
#include "missingobjects.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

    missingObjects(argc, argv);
	
	return 0;
}
