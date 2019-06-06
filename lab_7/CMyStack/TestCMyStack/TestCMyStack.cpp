#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <string>
#include "lab_7\CMyStack\CMyStack\CMyStack.h"

using namespace std;

TEST_CASE("Test with int type parameters")
{
	CMyStack<int> myTestStack;
	CMyStack<int> myTestCopyStack;
	CMyStack<int> myTestMoveStack;

	SECTION("One element in stack")
	{
		myTestStack.Push(1);
		CHECK(myTestStack.GetTopElement() == 1);
		myTestStack.Pop();
		CHECK_THROWS_AS(myTestStack.GetTopElement(), logic_error);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Empty stack")
	{
		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Clear")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);
		myTestStack.Push(192);

		CHECK(myTestStack.IsEmptyStack() == false);

		myTestStack.Clear();
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Three element in stack")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);
		myTestStack.Push(192);

		CHECK(myTestStack.IsEmptyStack() == false);

		myTestStack.Pop();
		CHECK(myTestStack.GetTopElement() == 15);

		myTestStack.Pop();
		CHECK(myTestStack.GetTopElement() == 10);

		myTestStack.Pop();
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Copy stack Constructor")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);

		CMyStack<int> myTestCopyStack(myTestStack);

		CHECK(myTestCopyStack.IsEmptyStack() == false);
		CHECK(myTestStack.GetTopElement() == myTestCopyStack.GetTopElement());
	}

	SECTION("Copy stack Constructor(2)")
	{
		CMyStack<int> myTestCopyStack(myTestStack);

		CHECK(myTestCopyStack.IsEmptyStack() == true);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Copy stack =")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);

		myTestCopyStack = myTestStack;

		CHECK(myTestCopyStack.IsEmptyStack() == false);
		CHECK(myTestStack.GetTopElement() == myTestCopyStack.GetTopElement());
	}

	SECTION("Copy stack =(2)")
	{
		myTestCopyStack = myTestStack;

		CHECK(myTestCopyStack.IsEmptyStack() == true);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("CopyStack operator =(3)")
	{
		myTestCopyStack.Push(10);

		myTestCopyStack = myTestCopyStack;

		CHECK(myTestCopyStack.GetTopElement() == 10);
	}

	SECTION("Move stack Constructor")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);

		CMyStack<int> myTestMoveStack(move(myTestStack));

		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK(myTestMoveStack.GetTopElement() == 15);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack Constructor(2)")
	{
		CMyStack<int> myTestMoveStack(move(myTestStack));

		CHECK(myTestMoveStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestMoveStack.GetTopElement(), std::logic_error);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =")
	{
		myTestStack.Push(10);
		myTestStack.Push(15);

		myTestMoveStack = move(myTestStack);

		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK(myTestMoveStack.GetTopElement() == 15);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =(2)")
	{
		myTestMoveStack = move(myTestStack);

		CHECK(myTestMoveStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestMoveStack.GetTopElement(), std::logic_error);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =(3)")
	{
		myTestMoveStack.Push(10);

		myTestMoveStack = move(myTestMoveStack);

		CHECK(myTestMoveStack.IsEmptyStack() == false);
		CHECK(myTestMoveStack.GetTopElement() == 10);
	}
}

TEST_CASE("Test with string type parameters")
{
	CMyStack<string> myTestStack;
	CMyStack<string> myTestCopyStack;
	CMyStack<string> myTestMoveStack;

	SECTION("One element in stack")
	{
		myTestStack.Push("World");
		CHECK(myTestStack.GetTopElement() == "World");
		myTestStack.Pop();
		CHECK_THROWS_AS(myTestStack.GetTopElement(), logic_error);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Empty stack")
	{
		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Clear")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");

		CHECK(myTestStack.IsEmptyStack() == false);

		myTestStack.Clear();
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Three element in stack")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");
		myTestStack.Push("My");

		CHECK(myTestStack.IsEmptyStack() == false);

		myTestStack.Pop();
		CHECK(myTestStack.GetTopElement() == "Hello");

		myTestStack.Pop();
		CHECK(myTestStack.GetTopElement() == "World");

		myTestStack.Pop();
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Copy stack Constructor")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");

		CMyStack<string> myTestCopyStack(myTestStack);

		CHECK(myTestCopyStack.IsEmptyStack() == false);
		CHECK(myTestStack.GetTopElement() == myTestCopyStack.GetTopElement());
	}

	SECTION("Copy stack Constructor(2)")
	{
		CMyStack<string> myTestCopyStack(myTestStack);

		CHECK(myTestCopyStack.IsEmptyStack() == true);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("Copy stack =")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");

		myTestCopyStack = myTestStack;

		CHECK(myTestCopyStack.IsEmptyStack() == false);
		CHECK(myTestStack.GetTopElement() == myTestCopyStack.GetTopElement());
	}

	SECTION("Copy stack =(2)")
	{
		myTestCopyStack = myTestStack;

		CHECK(myTestCopyStack.IsEmptyStack() == true);
		CHECK(myTestStack.IsEmptyStack() == true);
	}

	SECTION("CopyStack operator =(3)")
	{
		myTestCopyStack.Push("World");

		myTestCopyStack = myTestCopyStack;

		CHECK(myTestCopyStack.GetTopElement() == "World");
	}

	SECTION("Move stack Constructor")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");

		CMyStack<string> myTestMoveStack(move(myTestStack));

		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK(myTestMoveStack.GetTopElement() == "Hello");
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack Constructor(2)")
	{
		CMyStack<string> myTestMoveStack(move(myTestStack));

		CHECK(myTestMoveStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestMoveStack.GetTopElement(), std::logic_error);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =")
	{
		myTestStack.Push("World");
		myTestStack.Push("Hello");

		myTestMoveStack = move(myTestStack);

		CHECK(myTestStack.IsEmptyStack() == true);
		CHECK(myTestMoveStack.GetTopElement() == "Hello");
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =(2)")
	{
		myTestMoveStack = move(myTestStack);

		CHECK(myTestMoveStack.IsEmptyStack() == true);
		CHECK_THROWS_AS(myTestMoveStack.GetTopElement(), std::logic_error);
		CHECK_THROWS_AS(myTestStack.GetTopElement(), std::logic_error);
	}

	SECTION("Move stack =(3)")
	{
		myTestMoveStack.Push("World");

		myTestMoveStack = move(myTestMoveStack);

		CHECK(myTestMoveStack.IsEmptyStack() == false);
		CHECK(myTestMoveStack.GetTopElement() == "World");
	}
}