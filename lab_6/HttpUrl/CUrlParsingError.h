#pragma once
#include "pch.h"

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(std::string const& invalid_message);
	~CUrlParsingError();
};

