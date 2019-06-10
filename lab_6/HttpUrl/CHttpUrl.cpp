#include "CHttpUrl.h"
#include "ValidateUrlComponents.h"

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

int CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocolEnum(const std::string& protocol)
{
	auto upperProtocol = protocol;
	std::transform(upperProtocol.begin(), upperProtocol.end(), upperProtocol.begin(), ::tolower);

	if (upperProtocol == "http")
	{
		return Protocol::HTTP;
	}
	else if (upperProtocol == "https")
	{
		return Protocol::HTTPS;
	}
	else
	{
		throw CUrlParsingError("Error protocol\n");
	}
}

void CHttpUrl::ParseURL(const std::string& url)
{
	std::regex urlValidRegex(R"(^((?:(https?):\/\/)?((?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\.(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\.)(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9])\.)(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[0-9][0-9]|[0-9]))|(?:(?:(?:\w+\.){1,2}[\w]{2,3})))(?::(\d+))?((?:\/[\w]*)*)(?:\/|(\/[\w]+\.[\w]{3,4})|(\?(?:([\w]+=[\w]+)&)*([\w]+=[\w]+))?|\?(?:(wsdl|wadl))))$)", std::regex_constants::icase);
	std::smatch urlMatch;

	if (!std::regex_match(url, urlMatch, urlValidRegex))
	{
		throw CUrlParsingError("Error input url-string");
	}

	m_protocol = GetProtocolEnum(urlMatch[2]);

	m_domain = urlMatch[3];
	ValidateDomain(m_domain);

	std::string portInput = urlMatch[4];
	if (portInput.empty())
	{
		m_port = GetPortDef(m_protocol);
	}
	else
	{
		m_port = std::stoi(portInput);
		ValidatePort(m_port);
	}

	std::string documentInput = urlMatch[5];
	if (documentInput.empty())
	{
		m_document = "/";
	}
	else
	{
		m_document = documentInput;
		ValidateDocument(m_document);
	}

}