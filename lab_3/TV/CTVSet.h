#pragma once
#include "pch.h"

class CTVSet
{
public:
	CTVSet();
	~CTVSet();

	//Включает телевизор, если он был выключен
	void TurnOn();
	//Выключает телевизор, если он был включен
	void TurnOff();
	//Выбирает указанный номер канала
	void SelectChannel(const int numberChannel);
	//Узнать имя канала по номеру канала
	std::string GetChannelName(const int numberChannel);
	//Узнать номер канала по его имени
	int GetChannelByName(std::string &nameChannel);
	//переключение телевизора на канал, на котором телевизор находился ранее,
	//либо остаться на том же канале
	void SelectPreviousChannel();
	////возможность задания имени для канала с допустимым номером
	void SetChannelName(const int numberChannel, std::string &nameChannel);
	////Выбирает указанный канал по имени
	void SelectChannel(std::string &nameChannel);
	//Удаление имени канала
	void DeleteChannelName(std::string &nameChannel);
	//Информация о канале
	void GetInfo();

private:
	static const auto MAX_NUM_CHANNEL = 100;
	bool m_turnOn = false;
	int m_currentChanel = 0;
	int m_prevChannel = 0;
	std::map <std::string, int> channelNames;
	std::map <int, std::string> channelNumbersWithNames;
};

