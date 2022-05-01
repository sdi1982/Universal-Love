#pragma once

#include "LmStartScene.h"
#include "LmCompanyScene.h"
#include "LmRecruitScene.h"
#include "LmHelpScene.h"
#include "LmFieldScene.h"

#define NONE_STATE			0
#define START_STATE			1
#define COMPANY_STATE		2
#define RECRUITE_STATE		3
#define HELP_STATE			4
#define FIELD_STATE			5

class LmSceneManager
{
public:
	LmSceneManager()
	{
		m_gameState = NONE_STATE; // 
	}

	~LmSceneManager()
	{

	}

	bool Load(CDXUTDialog* _pSampleUI,LPDIRECT3DDEVICE9 _pd3dDevice)
	{
		m_startScene.Load(_pSampleUI,_pd3dDevice);
		m_companyScene.Load(_pSampleUI,_pd3dDevice);
		m_recruitScene.Load(_pSampleUI,_pd3dDevice);
		m_helpScene.Load(_pSampleUI,_pd3dDevice);
		m_fieldScene.Load(_pSampleUI,_pd3dDevice);

		return true;
	}

	bool ReleaseAll()
	{
		m_startScene.Release();
		m_companyScene.Release();
		m_recruitScene.Release();
		m_helpScene.Release();
		m_fieldScene.Release();

		return true;
	}

	bool SetGameState(int _gameState)
	{
		// 이전 스테이트 컨트롤 파괴
		switch(m_gameState)
		{
		case NONE_STATE:
			break;
		case START_STATE:
			m_startScene.Destroy();
			break;
		case COMPANY_STATE:
			m_companyScene.Destroy();
			break;
		case RECRUITE_STATE:
			m_recruitScene.Destroy();
			break;
		case HELP_STATE:
			m_helpScene.Destroy();
			break;
		case FIELD_STATE:
			m_fieldScene.Destroy();
			break;
		default:
			return false;
		}

		// 전환할 스테이트 컨트롤 생성
		switch(_gameState)
		{
		case START_STATE:
			m_startScene.Create();
			break;
		case COMPANY_STATE:
			m_companyScene.Create();
			break;
		case RECRUITE_STATE:
			m_recruitScene.Create();
			break;
		case HELP_STATE:
			m_helpScene.Create();
			break;
		case FIELD_STATE:
			m_fieldScene.Create();
			break;
		default:
			return false;
		}

		m_gameState = _gameState;

		return true;
	}

	bool DestroyAll()
	{
		m_startScene.Destroy();
		m_companyScene.Destroy();
		m_recruitScene.Destroy();
		m_helpScene.Destroy();
		m_fieldScene.Destroy();

		return true;
	}

	bool StateRender(LPD3DXSPRITE _pSprite) 
	{
		switch(m_gameState)
		{
		case START_STATE:
			m_startScene.Render(_pSprite);
			break;
		case COMPANY_STATE:
			m_companyScene.Render(_pSprite);
			break;
		case RECRUITE_STATE:
			m_recruitScene.Render(_pSprite);
			break;
		case HELP_STATE:
			m_helpScene.Render(_pSprite);
			break;
		case FIELD_STATE:
			m_fieldScene.Render(_pSprite);
			break;

		default:
			return false;
		}

		return true;
	}

	void TextRender() 
	{
		switch(m_gameState)
		{
			//case START_STATE:
			//	g_startScene.Render(g_pSprite);
			//	break;
			//case COMPANY_STATE:
			//	g_companyScene.Render(g_pSprite);
			//	break;
			//case RECRUITE_STATE:
			//	g_recruitScene.Render(g_pSprite);
			//	break;
		case HELP_STATE:
			m_helpScene.RenderText();
			break;
		}
	}

	bool GUIEvent(int nControlID)
	{
		// 상태변환에 사용되는 컨트롤 메세지
		switch(nControlID)
		{
		case IDC_STARTBUTTON:
			SetGameState(COMPANY_STATE);
			break;

		case IDC_COMPANYBUTTON1:
			//g_company = 1;
			//g_difficulty = 1;
			//g_money = 10000;
			SetGameState(RECRUITE_STATE);
			break;

		case IDC_COMPANYBUTTON2:
			//g_company = 2;
			//g_difficulty = 2;
			//g_money = 100000;
			SetGameState(RECRUITE_STATE);
			break;

		case IDC_COMPANYBUTTON3:
			//g_company = 3;
			//g_difficulty = 3;
			//g_money = 30000;
			SetGameState(RECRUITE_STATE);
			break;

		case IDC_CHRACTERBUTTON1:
			//g_characterType = 1;
			SetGameState(HELP_STATE);
			break;

		case IDC_CHRACTERBUTTON2:
			//g_characterType = 2;
			SetGameState(HELP_STATE);
			break;
		case IDC_HELPFINISHBUTTON:
			SetGameState(FIELD_STATE);
			break;

		}

		// 상태별로 처리되어야할 컨트롤 메세지
		switch(m_gameState)
		{
		case NONE_STATE:
			break;
		case START_STATE:
			m_startScene.GUIEvent(nControlID);
			break;
		case COMPANY_STATE:
			m_companyScene.GUIEvent(nControlID);
			break;
		case RECRUITE_STATE:
			m_recruitScene.GUIEvent(nControlID);
			break;
		case HELP_STATE:
			m_helpScene.GUIEvent(nControlID);
			break;
		case FIELD_STATE:
			m_fieldScene.GUIEvent(nControlID);
			break;
		default:
			return false;
		}
		return true;
	}
private:
	int m_gameState;

	LmStartScene m_startScene;
	LmCompanyScene m_companyScene;
	LmRecruitScene m_recruitScene;
	LmHelpScene m_helpScene;
	LmFieldScene m_fieldScene;

	CDXUTDialog* m_pSampleUI;
};