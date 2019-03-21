#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lab_2\WorkVector\HTMLEncode\Encode_HTML_String.h"

TEST_CASE("Check HtmlEncode()")
{
	{
		std::string htmlPart = "<div>PutIn</div>";
		std::string encodeHtmlString = "&lt;div&gt;PutIn&lt;/div&gt;";
		REQUIRE(HtmlEncode(htmlPart) == encodeHtmlString);
	}

	{
		std::string htmlPart = "<p\"> asd;&sdjfn </p>";
		std::string encodeHtmlString = "&lt;p&quot;&gt; asd;&amp;sdjfn &lt;/p&gt;";
		REQUIRE(HtmlEncode(htmlPart) == encodeHtmlString);
	}
};