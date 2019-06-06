#pragma once
#include "pch.h"
#include "Protocol.h"
#include "CUrlParsingError.h"

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol);
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		int port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	std::string GetProtocol() const;
	int GetPort() const;

private:
	void ParseURL(const std::string& url);
	void ValidateDomain(const std::string& domain) const;
	void ValidateDocument(const std::string& domain) const;
	void ValidatePort(const int& port) const;
	int GetPortDef(Protocol protocol) const;
	void DivisionDomainPort(const std::string& str);
	Protocol GetProtocolEnum(const std::string& protocol);

	Protocol m_protocol;
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	int m_port;
};

