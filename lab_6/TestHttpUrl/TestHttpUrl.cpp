#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "lab_6\HttpUrl\CHttpUrl.h"
#include "lab_6\HttpUrl\CUrlParsingError.h"
#include "lab_6\HttpUrl\Protocol.h"

void CheckUrlString(const std::string& urlStr, const std::string& urlProtocol, const std::string& urlDomain, int urlPort, const std::string& urlDocument)
{
	CHttpUrl url(urlStr);
	CHECK(url.GetURL() == urlStr);
	CHECK(url.GetProtocol() == urlProtocol);
	CHECK(url.GetDomain() == urlDomain);
	CHECK(url.GetPort() == urlPort);
	CHECK(url.GetDocument() == urlDocument);
}

void CheckUrlWithoutPort(Protocol urlProtocol, const std::string& urlDomain, const std::string& urlDocument)
{
	int urlPort;
	CHttpUrl url(urlDomain, urlDocument, urlProtocol);
	CHECK(url.GetDomain() == urlDomain);
	(urlProtocol == Protocol::HTTP) ? urlPort = 80 : urlPort = 443;
	CHECK(url.GetPort() == urlPort);
	CHECK(url.GetDocument() == urlDocument);
}

void CheckUrlWithPort(Protocol urlProtocol, const std::string& urlDomain, int urlPort, const std::string& urlDocument)
{
	CHttpUrl url(urlDomain, urlDocument, urlProtocol, urlPort);
	CHECK(url.GetDomain() == urlDomain);
	CHECK(url.GetPort() == urlPort);
	CHECK(url.GetDocument() == urlDocument);
}

TEST_CASE("Check Url String")
{
	SECTION("Port default HTTPS")
	{
		std::string urlStr = "HTTPS://drive.google.com/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk";
		CheckUrlString("https://drive.google.com/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk", "https", "drive.google.com", HTTPS_DEF_PORT, "/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk");
	}

	SECTION("Port default HTTP")
	{
		std::string urlStr = "HTTP://lks.volgatech.net/ExamList";
		CheckUrlString("http://lks.volgatech.net/ExamList", "http", "lks.volgatech.net", HTTP_DEF_PORT, "/ExamList");
	}

	SECTION("Port 73 HTTPS")
	{
		std::string urlStr = "HTTP://lks.volgatech.net:73/ExamList";
		CheckUrlString("http://lks.volgatech.net:73/ExamList", "http", "lks.volgatech.net", 73, "/ExamList");
	}

	SECTION("Valide document 1")
	{
		std::string urlStr = "https://www.youtube.com/";
		CheckUrlString(urlStr, "https", "www.youtube.com", HTTPS_DEF_PORT, "/");
	}

	SECTION("Valide document 2")
	{
		std::string urlStr = "https://www.youtube.com:34/doc";
		CheckUrlString(urlStr, "https", "www.youtube.com", 34, "/doc");
	}

	SECTION("Port installed HTTP port MIN_NUMBER_PORT")
	{
		std::string urlStr = "HTTP://www.my-site-time.com:0/docs/document1.html";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("Port installed HTTP port MAX_NUMBER_PORT")
	{
		std::string urlStr = "HTTP://www.mysite-time.com:65536/docs/document1.html";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("Url empty")
	{
		std::string urlStr = "";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("Invalid URL port")
	{
		std::string urlStr = "https://www.google.com:-1/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("Invalid URL domain 1")
	{
		std::string urlStr = "https://www.googl^e.com/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("Invalid URL domain 2")
	{
		std::string urlStr = "https://www google.com/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}
}

TEST_CASE("Check Url Without Port")
{
	SECTION("HTTP not empty document")
	{
		std::string urlStr = "http://mathhelpplanet.com/static.php?p=onlain-reshit-treugolnik";
		CheckUrlWithoutPort(Protocol::HTTP, "mathhelpplanet.com", "/static.php?p=onlain-reshit-treugolnik");
	}

	SECTION("HTTP empty document")
	{
		std::string urlStr = "http://mathhelpplanet.com/";
		CheckUrlWithoutPort(Protocol::HTTP, "mathhelpplanet.com", "/");
	}
}

TEST_CASE("Check Url With Port")
{
	SECTION("HTTP not empty document")
	{
		std::string urlStr = "http://vk.com:832/audios62352g721709";
		CheckUrlWithPort(Protocol::HTTP, "vk.com", 832, "/audios62352g721709");
	}

	SECTION("HTTP empty document")
	{
		std::string urlStr = "http://vk.com:214/";
		CheckUrlWithPort(Protocol::HTTP, "vk.com", 214, "/");
	}
}
