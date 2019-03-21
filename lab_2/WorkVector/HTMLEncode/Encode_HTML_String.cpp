#include "pch.h"
#include "Encode_HTML_String.h"

std::string HtmlEncode(std::string const& text)
{
	std::string resultLine = "";
	for (size_t i = 0; i < text.size(); i++)
	{
		switch (text[i]) {
		case QUOT: resultLine += QUOT_ENCODE; break;
		case APOS: resultLine += APOS_ENCODE; break;
		case LT: resultLine += LT_ENCODE; break;
		case GT: resultLine += GT_ENCODE; break;
		case AMP: resultLine += AMP_ENCODE; break;
		default: resultLine += text[i];
		}
	}

	return resultLine;
}