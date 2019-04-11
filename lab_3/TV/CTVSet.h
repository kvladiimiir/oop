#pragma once
#include "pch.h"

class CTVSet
{
public:
	CTVSet();
	~CTVSet();

	//�������� ���������, ���� �� ��� ��������
	void TurnOn();
	//��������� ���������, ���� �� ��� �������
	void TurnOff();
	//�������� ��������� ����� ������
	void SelectChannel(const int numberChannel);
	//������ ��� ������ �� ������ ������
	std::string GetChannelName(const int numberChannel);
	//������ ����� ������ �� ��� �����
	int GetChannelByName(std::string &nameChannel);
	//������������ ���������� �� �����, �� ������� ��������� ��������� �����,
	//���� �������� �� ��� �� ������
	void SelectPreviousChannel();
	////����������� ������� ����� ��� ������ � ���������� �������
	void SetChannelName(const int numberChannel, std::string &nameChannel);
	////�������� ��������� ����� �� �����
	void SelectChannel(std::string &nameChannel);
	//�������� ����� ������
	void DeleteChannelName(std::string &nameChannel);
	//���������� � ������
	void GetInfo();

private:
	static const auto MAX_NUM_CHANNEL = 100;
	bool m_turnOn = false;
	int m_currentChanel = 0;
	int m_prevChannel = 0;
	std::map <std::string, int> channelNames;
	std::map <int, std::string> channelNumbersWithNames;
};

