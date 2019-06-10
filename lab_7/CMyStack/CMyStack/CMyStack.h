#pragma once
#include <iostream>
#include <string>

template <typename T>
class CMyStack
{
public:
	CMyStack() = default;

	CMyStack(CMyStack const& stack)
	{
		if (!stack.IsEmptyStack())
		{
			CopyStack(stack);
		}
	}

	CMyStack(CMyStack&& stack)
	{
		MoveStack(stack);
	}

	CMyStack &operator=(CMyStack const& stack)
	{
		if (this == &stack)
		{
			return *this;
		}

		if (stack.IsEmptyStack())
		{
			Clear();
			return *this;
		}

		CopyStack(stack);
		return *this;
	}

	CMyStack &operator=(CMyStack && stack)
	{
		if (this == &stack)
		{
			return *this;
		}

		MoveStack(stack);
		return *this;
	}

	bool IsEmptyStack() const
	{
		return (m_stackSize == 0);
	}

	void Clear()
	{
		while (!IsEmptyStack())
		{
			Pop();
		}
	}

	T GetTopElement() const
	{
		if (!IsEmptyStack())
		{
			return m_top->data;
		}
		else
		{
			throw std::logic_error("Function 'GetTop' doesn't work, because stack is empty.");
		}
	}

	void Push(T const& newElement)
	{
		auto newNode = std::make_shared<Node>(newElement, m_top);
		m_top = newNode;
		m_stackSize++;
	}

	void Pop()
	{
		if (!IsEmptyStack())
		{
			m_top = m_top->prev;
			m_stackSize--;
		}
	}

	~CMyStack()
	{
		Clear();
	}

private:
	struct Node
	{
		Node(const T& value, const std::shared_ptr<Node>& node)
			: data(value)
			, prev(node)
		{
		}

		T data;
		std::shared_ptr<Node> prev = nullptr;
	};

	typedef std::shared_ptr<Node> NodePtr;
	int m_stackSize = 0;
	std::shared_ptr<Node> m_top = nullptr;

	void CopyStack(CMyStack const& stack)
	{
		std::shared_ptr<Node> copiedStack = stack.m_top;
		m_top = std::make_shared<Node>(*copiedStack);

		auto newStack = m_top;

		while (copiedStack->prev != nullptr)
		{
			m_stackSize++;
			newStack->prev = std::make_shared<Node>(*copiedStack->prev);
			copiedStack = copiedStack->prev;
			newStack = newStack->prev;
		}
	}

	void MoveStack(CMyStack& stack)
	{
		m_stackSize = stack.m_stackSize;
		m_top = stack.m_top;
		stack.m_stackSize = 0;
		stack.m_top = nullptr;
	}
};
