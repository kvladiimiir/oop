#include "CHttpUrl.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Empty url\n");
	}

	ParseURL(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	: m_protocol(protocol)
	, m_document(document)
	, m_domain(domain)
{
	m_port = GetPortDef(protocol);
	ValidateDocument(document);
	ValidateDomain(domain);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, int port)
	: m_protocol(protocol)
	, m_port(port)
	, m_document(document)
	, m_domain(domain)
{
	ValidatePort(port);
	ValidateDocument(document);
	ValidateDomain(domain);
}

std::string CHttpUrl::GetURL() const
{
	std::string stringUrl;
	stringUrl += GetProtocol();
	stringUrl += "://";
	stringUrl += m_domain;

	if ((m_port != HTTP_DEF_PORT) && (m_port != HTTPS_DEF_PORT))
	{
		stringUrl += ":";
		stringUrl += std::to_string(m_port);
	}

	stringUrl += m_document;

	return stringUrl;
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

int CHttpUrl::GetPortDef(Protocol protocol) const
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

void CHttpUrl::ValidatePort(const int& port) const
{
	if ((port > MAX_NUM_PORT) || (port < MIN_NUM_PORT))
	{
		throw CUrlParsingError("Port error\n");
	}
}

int CHttpUrl::GetPort() const
{
	return m_port;
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
		m_port = std::stoi(str.substr(firstPos + 1, (str.length() - firstPos - 1)));
		ValidatePort(m_port);
		m_domain = str.substr(0, firstPos);
	}
}

void CHttpUrl::ValidateDomain(const std::string& domain) const
{
	if (domain.empty())
	{
		throw CUrlParsingError("Error validation domain\n");
	}

	for (char ch : domain)
	{
		if (!((ch == '/') || (ch == ':') || (ch == '=') || (ch == '#') || (ch == '&') || (ch == '[') || (ch == ']') || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '+') || (ch == '(') || (ch == ')') || (ch == '!') || (ch == '$') || (ch == ',') || isalpha(ch) || isdigit(ch)))
		{
			throw CUrlParsingError("Error validation domain\n");
		}
	}
}

void CHttpUrl::ValidateDocument(const std::string& document) const
{
	for (char ch : document)
	{
		if (!((ch == '/') || (ch == ':') || (ch == '=') || (ch == '%') || (ch == '#') || (ch == '&') || (ch == '?') || (ch == '[') || (ch == ']') || (ch == '-') || (ch == '.') || (ch == '_') || (ch == '+') || (ch == '(') || (ch == ')') || (ch == '!') || (ch == '$') || (ch == ',') || isalpha(ch) || isdigit(ch)))
		{
			throw CUrlParsingError("Error validation document\n");
		}
	}
}


void CHttpUrl::ParseURL(const std::string& url)
{
	std::regex urlValidRegex(R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)");

	std::smatch urlMatch;

	if (!std::regex_match(url, urlMatch, urlValidRegex))
	{
		throw CUrlParsingError("Error input url-string");
	}
	m_protocol = GetProtocolEnum(urlMatch[2]);
	std::string domain_port = std::string(urlMatch[4]);
	DivisionDomainPort(domain_port);
	m_document = std::string(urlMatch[5]);
	ValidateDocument(m_document);
	ValidateDomain(m_domain);
}