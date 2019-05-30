#include "CHttpUrl.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Empty url\n");
	}

	ParcingURL(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
	, m_document(Validation(document))
	, m_domain(Validation(domain))
{
	m_port = GetPortDef(protocol);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, int port)
	: m_protocol(protocol)
	, m_port(port)
	, m_document(Validation(document))
	, m_domain(Validation(domain))
{
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

std::string CHttpUrl::GetProtocol() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	else
	{
		return "https";
	}
}

int CHttpUrl::GetPortDef(Protocol protocol)
{
	if (m_protocol == Protocol::HTTP)
	{
		return HTTP_DEF_PORT;
	}
	else
	{
		return HTTPS_DEF_PORT;
	}
}

int CHttpUrl::ValidPort(const std::string& port)
{
	int portNum = std::stoi(port);

	if ((portNum > MAX_NUM_PORT) || (portNum < MIN_NUM_PORT))
	{
		throw CUrlParsingError("Port error\n");
	}
	else
	{
		return portNum;
	}
}

int CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::Validation(const std::string& str)
{
	for (char ch : str)
	{
		if (!((ch == '/') || (ch == ':') || (ch == '=') || (ch == '#') || (ch == '&') || (ch == '?') || (ch == '[') || (ch == ']') || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '+') || (ch == '(') || (ch == ')') || (ch == '!') || (ch == '$') || (ch == ',') || isalpha(ch) || isdigit(ch)))
		{
			throw CUrlParsingError("Error validation\n");
		}
	}

	return str;
}

Protocol CHttpUrl::GetProtocolEnum(const std::string& protocol)
{
	if ((protocol == "HTTP") || (protocol == "http"))
	{
		return Protocol::HTTP;
	}
	else if ((protocol == "HTTPS") || (protocol == "https"))
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Error protocol\n");
	}
}

void CHttpUrl::DivisionDomainPort(const std::string& str)
{
	if (str.empty())
	{
		m_domain = "/";
		m_port = GetPortDef(m_protocol);
		return;
	}

	auto position = str.find(':');

	if (position == std::string::npos)
	{
		m_domain = str;
		m_port = GetPortDef(m_protocol);
	}
	else
	{
		auto const firstPos = str.find_last_of(':');
		m_port = ValidPort(str.substr(firstPos + 1, (str.length() - firstPos - 1)));
		m_domain = str.substr(0, firstPos);
	}
}

void CHttpUrl::ParcingURL(const std::string& url)
{
	std::string validateUrl = Validation(url);

	std::regex urlValidRegex(R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)");

	std::smatch urlMatch;

	if (!std::regex_match(validateUrl, urlMatch, urlValidRegex))
	{
		throw CUrlParsingError("Error input url-string");
	}

	m_url = std::string(urlMatch[0]);
	m_protocol = GetProtocolEnum(urlMatch[2]);
	std::string domain_port = std::string(urlMatch[4]);
	DivisionDomainPort(domain_port);
	m_document = std::string(urlMatch[5]);
}