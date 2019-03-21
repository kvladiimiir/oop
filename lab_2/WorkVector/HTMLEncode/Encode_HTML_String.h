#pragma once

#include "pch.h"
#include <iostream>
#include <string>

const char QUOT = '"';
const char APOS = '’';
const char LT = '<';
const char GT = '>';
const char AMP = '&';
const std::string QUOT_ENCODE = "&quot;";
const std::string APOS_ENCODE = "&apos;";
const std::string LT_ENCODE = "&lt;";
const std::string GT_ENCODE = "&gt;";
const std::string AMP_ENCODE = "&amp;";

std::string HtmlEncode(std::string const& text);