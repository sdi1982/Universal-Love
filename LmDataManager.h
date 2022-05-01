#pragma once

#define DIFFICULTY_EASY			1
#define DIFFICULTY_NORMAL	2
#define DIFFICULTY_HARD			3

#define COMPANY_TIGERS		1
#define COMPANY_LIONS		2
#define COMPANY_WYVERNS	3

class LmDataManager
{
public:
	bool SetDifficulty(int _iDiffculty)
	{
		m_iDifficulty = _iDiffculty;

		return true;
	}

	bool SetCompany(int _iCompany)
	{
		m_iCompany = _iCompany;

		return true;
	}

	bool SetMoney(int _iMoney)
	{
		m_iMoney = _iMoney;

		return true;
	}

	int GetDiffculty()
	{
		return m_iDifficulty;
	}

	int GetCompany()
	{
		return m_iCompany;
	}

	int GetMoney()
	{
		return m_iMoney;
	}

private:
	int m_iCompany;
	int m_iDifficulty;
	int m_iMoney;
};