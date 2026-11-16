#include <iostream>
#include "tinyxml2.h"
using namespace tinyxml2;
using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
    	cout << "Usage: ./books catalog.xml" << endl;
    	return 1;
	}
	XMLDocument doc;
	if (doc.LoadFile(argv[1]) != XML_SUCCESS)
	{
    	cout << "Unable to load XML file." << endl;
    	return 1;
	}
	XMLElement* catalog = doc.FirstChildElement("catalog");
	if (catalog == nullptr)
	{
    	cout << "Catalog not found." << endl;
    	return 1;
	}
	XMLElement* book = catalog->FirstChildElement("book");
	while (book != nullptr)
	{
    	XMLElement* title = book->FirstChildElement("title");
    	if (title && title->GetText())
    	{
        	cout << title->GetText() << endl;
    	}
    	book = book->NextSiblingElement("book");
	}
	return 0;
}
