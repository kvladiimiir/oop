#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	std::string inputLine;

	while (std::getline(std::cin, inputLine))
	{
		try
		{
			CHttpUrl newURL(inputLine);
			std::cout << "URL: " << newURL.GetURL() << '\n';
			std::cout << "Protocol: " << newURL.GetProtocol() << '\n';
			std::cout << "Domain: " << newURL.GetDomain() << '\n';
			std::cout << "Port: " << newURL.GetPort() << '\n';
			std::cout << "Document: " << newURL.GetDocument() << '\n';
		}
		catch (const CUrlParsingError& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	return 0;
}