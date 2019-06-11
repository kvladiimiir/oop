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

TEST_CASE("Check string url")
{
	SECTION("Valid URL without port test")
	{
		std::string urlStr = "https://drive.google.com/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk";
		CheckUrlString("https://drive.google.com/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk", "https", "drive.google.com", HTTPS_DEF_PORT, "/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk");
	}

	SECTION("Valid URL without port and uppercase protocol test")
	{
		std::string urlStr = "HTTP://lks.volgatech.net/ExamList";
		CHttpUrl url(urlStr);
		CHECK(url.GetURL() == "http://lks.volgatech.net/ExamList");
		CHECK(url.GetProtocol() == "http");
		CHECK(url.GetDomain() == "lks.volgatech.net");
		CHECK(url.GetPort() == HTTP_DEF_PORT);
		CHECK(url.GetDocument() == "/ExamList");
	}

	SECTION("Test uppercase http and 73 port")
	{
		std::string urlStr = "HTTP://lks.volgatech.net:73/ExamList";
		CHttpUrl url(urlStr);
		CHECK(url.GetURL() == "http://lks.volgatech.net:73/ExamList");
		CHECK(url.GetProtocol() == "http");
		CHECK(url.GetDomain() == "lks.volgatech.net");
		CHECK(url.GetPort() == 73);
		CHECK(url.GetDocument() == "/ExamList");
	}

	SECTION("Valide url withiout port test")
	{
		std::string urlStr = "https://www.youtube.com/";
		CheckUrlString(urlStr, "https", "www.youtube.com", HTTPS_DEF_PORT, "/");
	}

	SECTION("Test localhost url")
	{
		std::string urlStr = "http://localhost/doc";
		CheckUrlString(urlStr, "http", "localhost", HTTP_DEF_PORT, "/doc");
	}

	SECTION("Test ip url")
	{
		std::string urlStr = "http://127.0.0.1.xyz.com:424/doc";
		CheckUrlString(urlStr, "http", "127.0.0.1.xyz.com", 424, "/doc");
	}

	SECTION("Test url with .org")
	{
		std::string urlStr = "http://www.something.org.ru/doc";
		CheckUrlString(urlStr, "http", "www.something.org.ru", HTTP_DEF_PORT, "/doc");
	}

	SECTION("Test MIN_NUMBER_PORT")
	{
		std::string urlStr = "https://www.youtube.com:1/doc";
		CheckUrlString(urlStr, "https", "www.youtube.com", 1, "/doc");
	}

	SECTION("Test MAX_NUMBER_PORT")
	{
		std::string urlStr = "https://www.youtube.com:65535/doc";
		CheckUrlString(urlStr, "https", "www.youtube.com", 65535, "/doc");
	}

	SECTION("Validated url test with a different register protocol")
	{
		std::string urlStr = "hTtP://ya.ru/";
		CHttpUrl url(urlStr);
		CHECK(url.GetURL() == "http://ya.ru/");
		CHECK(url.GetProtocol() == "http");
		CHECK(url.GetDomain() == "ya.ru");
		CHECK(url.GetPort() == HTTP_DEF_PORT);
		CHECK(url.GetDocument() == "/");
	}

	SECTION("CUrlParsingError test: url with invalid port = 0")
	{
		std::string urlStr = "https://www.youtube.com:0/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: url with invalid port = 65536")
	{
		std::string urlStr = "https://www.youtube.com:65536/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: empty url")
	{
		std::string urlStr = "";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: invalid URL port")
	{
		std::string urlStr = "https://www.google.com:-1/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: invalid url domain")
	{
		std::string urlStr = "https://www google.com/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: invalid protocol")
	{
		std::string urlStr = "http:/host/doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: url with only protocol")
	{
		std::string urlStr = "http://";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}

	SECTION("CUrlParsingError test: invalid url")
	{
		std::string urlStr = "http:///doc";
		CHECK_THROWS_AS(CHttpUrl(urlStr), CUrlParsingError);
	}
}

TEST_CASE("Check Url Without Port")
{
	SECTION("Test valid url for components without port")
	{
		std::string urlStr = "http://mathhelpplanet.com/static.php?p=onlain-reshit-treugolnik";
		CheckUrlWithoutPort(Protocol::HTTP, "mathhelpplanet.com", "/static.php?p=onlain-reshit-treugolnik");
	}

	SECTION("Test valid url for components without document and without port")
	{
		std::string urlStr = "http://mathhelpplanet.com/";
		CheckUrlWithoutPort(Protocol::HTTP, "mathhelpplanet.com", "/");
	}
}

TEST_CASE("Check Url With Port")
{
	SECTION("Test valid url for components with port")
	{
		std::string urlStr = "http://vk.com:832/audios62352g721709";
		CheckUrlWithPort(Protocol::HTTP, "vk.com", 832, "/audios62352g721709");
	}

	SECTION("Test valid url for components with port without document")
	{
		std::string urlStr = "http://vk.com:214/";
		CheckUrlWithPort(Protocol::HTTP, "vk.com", 214, "/");
	}
}
