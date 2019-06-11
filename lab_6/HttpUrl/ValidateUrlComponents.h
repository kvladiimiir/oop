#pragma once
#include "Protocol.h"
#include "pch.h"
#include "CUrlParsingError.h"

void ValidateDomain(const std::string& domain);
void ValidateDocument(const std::string& domain);
void ValidatePort(const int& port);