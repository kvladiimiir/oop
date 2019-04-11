#include "pch.h"
#include "CTVSet.h"


CTVSet::CTVSet()
{
}


CTVSet::~CTVSet()
{
}

void CTVSet::TurnOn()
{
	if (m_turnOn)
	{
		throw std::logic_error("TV was ON!\n");
	}
	m_turnOn = true;

	m_currentChanel = m_prevChannel;
}

void CTVSet::TurnOff()
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV was OFF!\n");
	}
	m_turnOn = false;

	m_prevChannel = m_currentChanel;
	m_currentChanel = 0;
}

void CTVSet::SelectChannel(const int numberChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (numberChannel < 0 || numberChannel > MAX_NUM_CHANNEL)
	{
		throw std::logic_error("Your channel is out of range!\n");
	}

	m_prevChannel = m_currentChanel;
	m_currentChanel = numberChannel;
}

void CTVSet::SelectChannel(std::string &nameChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (nameChannel.empty())
	{
		throw std::logic_error("Name channel is empty!\n");
	}

	if (channelNames.find(nameChannel) == channelNames.end())
	{
		throw std::logic_error("No name!\n");
	}

	int numberChannel = channelNames.find(nameChannel)->second;

	m_prevChannel = m_currentChanel;
	m_currentChanel = numberChannel;
}

void CTVSet::SelectPreviousChannel()
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	std::swap(m_prevChannel, m_currentChanel);
}

void CTVSet::SetChannelName(const int numberChannel, std::string &nameChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (numberChannel < 0 || numberChannel > MAX_NUM_CHANNEL)
	{
		throw std::logic_error("Your channel is out of range!\n");
	}

	if (nameChannel.empty())
	{
		throw std::logic_error("Name channel is empty!\n");
	}

	if (channelNumbersWithNames.find(numberChannel) != channelNumbersWithNames.end())
	{
		throw std::logic_error("This channel has a name!\n");
	}

	if (channelNames.find(nameChannel) != channelNames.end())
	{
		throw std::logic_error("This channel already exists!\n");
	}

	channelNames.insert(std::make_pair(nameChannel, numberChannel));
	channelNumbersWithNames.insert(std::make_pair(numberChannel, nameChannel));
}

std::string CTVSet::GetChannelName(const int numberChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (numberChannel < 0 || numberChannel > MAX_NUM_CHANNEL)
	{
		throw std::logic_error("Your channel is out of range!\n");
	}

	if (channelNumbersWithNames.find(numberChannel) == channelNumbersWithNames.end())
	{
		throw std::logic_error("No name!\n");
	}

	std::string result = channelNumbersWithNames.find(numberChannel)->second;
	return result;
}

int CTVSet::GetChannelByName(std::string &nameChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (nameChannel.empty())
	{
		throw std::logic_error("Name channel is empty!\n");
	}

	if (channelNames.find(nameChannel) == channelNames.end())
	{
		throw std::logic_error("No name!\n");
	}

	int result = channelNames.find(nameChannel)->second;
	return result;
}

void CTVSet::DeleteChannelName(std::string &nameChannel)
{
	if (!m_turnOn)
	{
		throw std::logic_error("TV is off!\n");
	}

	if (nameChannel.empty())
	{
		throw std::logic_error("Name channel is empty!\n");
	}

	if (channelNames.find(nameChannel) == channelNames.end())
	{
		throw std::logic_error("No name!\n");
	}

	int channelNumberIntoName = channelNames.find(nameChannel)->second;
	channelNames.erase(nameChannel);
	channelNumbersWithNames.erase(channelNumberIntoName);
}

void CTVSet::GetInfo()
{
	if (!m_turnOn)
	{
		std::cout << "TV is off.\n";
		throw std::logic_error("TV is off!\n");
	}

	std::cout << "TV is on.\n";

	std::cout << "Current channel is " << m_currentChanel << '\n';

	for (auto it = channelNumbersWithNames.begin(); it != channelNumbersWithNames.end(); it++)
	{
		std::cout << it->first << " - " << it->second << '\n';
	}
}
