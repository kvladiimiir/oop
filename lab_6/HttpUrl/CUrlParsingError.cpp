#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(const std::string& invalid_message)
	: std::invalid_argument(invalid_message)
{
}

CUrlParsingError::~CUrlParsingError()
{
}