#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Complex/CComplex.h"

TEST_CASE("CComplex functions")
{
	{
		double real = 1.0;
		double image = 0.1;
		CComplex complex(real, image);
		CHECK(complex.Re() == real);
	}

	{
		double real = 2.0;
		double image = 0.3;
		CComplex complex(real, image);
		CHECK(complex.Im() == image);
	}

	{
		double real = 4.0;
		double image = 3.0;
		CComplex complex(real, image);
		CHECK(complex.GetMagnitude() == 5.0);
	}

	{
		double real = 4.0;
		double image = 3.0;
		CComplex complex(real, image);
		double answer = atan2(image, real);
		CHECK(complex.GetArgument() == answer);
	}

	{
		double real = 2.0;
		double image = -1.0;
		CComplex complex(real, image);
		double answer = atan2(image, real);
		CHECK(complex.GetArgument() == answer);
	}

	{
		double real = -2.0;
		double image = -1.0;
		CComplex complex(real, image);
		double answer = atan2(image, real);
		CHECK(complex.GetArgument() == answer);
	}

	{
		double real = 0.0;
		double image = 0.0;
		CComplex complex(real, image);
		CHECK(complex.GetArgument() == 0.0);
	}
}

TEST_CASE("Operators")
{
	{
		CComplex complex(1.0, 2.5);

		CComplex answer = +complex;
		CHECK(answer.Re() == 1.0);
		CHECK(answer.Im() == 2.5);

		CComplex complex2 = +1.0;
		CHECK(complex2.Re() == 1.0);
		CHECK(complex2.Im() == 0.0);
	}

	{
		CComplex complex(1.0, 2.5);

		CComplex answer = -complex;
		CHECK(answer.Re() == -1.0);
		CHECK(answer.Im() == -2.5);

		CComplex complex2 = -1.0;
		CHECK(complex2.Re() == -1.0);
		CHECK(complex2.Im() == 0.0);
	}

	{
		CComplex complex(1.0, 2.5);
		CComplex complex2(3.9, 1.2);
		complex += complex2;
		CHECK(complex.Re() == 4.9);
		CHECK(complex.Im() == 3.7);

		CComplex complex3(5.0, 9.8);
		complex3 += -1.0;
		CHECK(complex3.Re() == 4.0);
		CHECK(complex3.Im() == 9.8);
	}

	{
		CComplex complex(1.0, 2.5);
		CComplex complex2(3.9, 1.2);
		complex -= complex2;
		CHECK(complex.Re() == -2.9);
		CHECK(complex.Im() == 1.3);

		CComplex complex3(5.0, 9.8);
		complex3 -= 1.0;
		CHECK(complex3.Re() == 4.0);
		CHECK(complex3.Im() == 9.8);
	}

	{
		CComplex complex(1.0, 2.0);
		CComplex complex2(2.0, 1.0);
		complex *= complex2;
		CHECK(complex.Re() == 0.0);
		CHECK(complex.Im() == 5.0);

		CComplex complex3(5.0, 9.0);
		complex3 *= 2.0;
		CHECK(complex3.Re() == 10.0);
		CHECK(complex3.Im() == 18.0);
	}

	{
		CComplex complex(1.0, 2.0);
		CComplex complex2(2.0, 4.0);
		complex /= complex2;
		CHECK(complex.Re() == 0.5);
		CHECK(complex.Im() == 0.0);

		CComplex complex3(3.0, 4.0);
		complex3 /= 2.0;
		CHECK(complex3.Re() == 1.5);
		CHECK(complex3.Im() == 2.0);
	}

	{
		CComplex complex1(1.0, 2.5);
		CComplex complex2(3.9, 1.2);
		CComplex answerFirst = complex1 + complex2;
		CHECK(answerFirst.Re() == 4.9);
		CHECK(answerFirst.Im() == 3.7);

		CComplex complex3(5.0, 9.8);
		CComplex answerSecond = complex3 + 6.6;
		CHECK(answerSecond.Re() == 11.6);
		CHECK(answerSecond.Im() == 9.8);
	}

	{
		CComplex complex1(1.0, 2.5);
		CComplex complex2(3.9, 1.2);
		CComplex answerFirst = complex1 - complex2;
		CHECK(answerFirst.Re() == -2.9);
		CHECK(answerFirst.Im() == 1.3);

		CComplex complex3(5.0, 9.8);
		CComplex answerSecond = complex3 - 5.0;
		CHECK(answerSecond.Re() == 0.0);
		CHECK(answerSecond.Im() == 9.8);
	}

	{
		CComplex complex1(3.0, 2.2);
		CComplex complex2(2.0, 1.0);
		CComplex answerFirst = complex1 * complex2;
		CHECK(answerFirst.Re() == 3.8);
		CHECK(answerFirst.Im() == 7.4);

		CComplex complex3(5.0, 9.0);
		CComplex answerSecond = complex3 * 6.0;
		CHECK(answerSecond.Re() == 30.0);
		CHECK(answerSecond.Im() == 54.0);
	}

	{
		CComplex complex1(3.0, 2.0);
		CComplex complex2(2.0, 1.0);
		CComplex answerFirst = complex1 / complex2;
		CHECK(answerFirst.Re() == 1.6);
		CHECK(answerFirst.Im() == 0.2);

		CComplex complex3(12.0, 18.0);
		CComplex answerSecond = complex3 / 6.0;
		CHECK(answerSecond.Re() == 2.0);
		CHECK(answerSecond.Im() == 3.0);
	}

	{
		CComplex first(1.0, 2.0);
		CComplex second(1.0, 2.0);
		bool answer1 = (first == second);
		CHECK(answer1 == true);

		CComplex first1(1.0, 2.0);
		CComplex second1(1.2, 2.0);
		bool answer2 = (first1 == second1);
		CHECK(answer2 == false);
	}

	{
		CComplex first(1.0, 2.0);
		CComplex second(1.0, 2.0);
		bool answer1 = (first != second);
		CHECK(answer1 == false);

		CComplex first1(1.0, 2.0);
		CComplex second1(1.2, 2.0);
		bool answer2 = (first1 != second1);
		CHECK(answer2 == true);
	}
}
