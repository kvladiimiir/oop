#include "pch.h"
#include "Encode_HTML_String.h"

int main()
{
	std::string inputLine;
	std::getline(std::cin, inputLine);
	std::string encodeLine = HtmlEncode(inputLine);

	std::cout << encodeLine << '\n';
	return 0;
}