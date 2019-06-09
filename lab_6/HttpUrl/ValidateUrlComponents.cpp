#include "ValidateUrlComponents.h"

void ValidateDomain(const std::string& domain)
{
	if (domain.empty())
	{
		throw std::logic_error("Error validation domain\n");
	}

	for (char ch : domain)
	{
		if (!((ch == '/') || (ch == ':') || (ch == '=') || (ch == '#') || (ch == '&') || (ch == '[') || (ch == ']') || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '+') || (ch == '(') || (ch == ')') || (ch == '!') || (ch == '$') || (ch == ',') || isalpha(ch) || isdigit(ch)))
		{
			throw std::logic_error("Error validation domain\n");
		}
	}
}

void ValidateDocument(const std::string& document)
{
	for (char ch : document)
	{
		if (!((ch == '/') || (ch == ':') || (ch == '=') || (ch == '%') || (ch == '#') || (ch == '&') || (ch == '?') || (ch == '[') || (ch == ']') || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '+') || (ch == '(') || (ch == ')') || (ch == '!') || (ch == '$') || (ch == ',') || isalpha(ch) || isdigit(ch)))
		{
			throw std::logic_error("Error validation document\n");
		}
	}
}

void ValidatePort(const int& port)
{
	if ((port > MAX_NUM_PORT) || (port < MIN_NUM_PORT))
	{
		throw std::logic_error("Port error\n");
	}
}