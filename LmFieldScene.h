#pragma once

#include "LmCharacter.h"
#include "LmHome.h"
#include "LmBackground.h"

//버튼 ID
#define IDC_UPBUTTON	500
#define IDC_DOWNBUTTON	501
#define IDC_LEFTBUTTON	502
#define IDC_RIGHTBUTTON	503
#define IDC_ENTERBUTTON 504

//캐릭터 방향 
#define CHARACTER_DIRECTION_UP		1
#define CHARACTER_DIRECTION_DOWN	2
#define CHARACTER_DIRECTION_LEFT	3
#define CHARACTER_DIRECTION_RIGHT	4

class LmFieldScene
{
public:
	LmFieldScene()
	{
		m_pSampleUI = NULL;
		m_pFont = NULL;         // Font for drawing text
		m_pTextSprite = NULL;   // Sprite for batching draw text calls
	}

	~LmFieldScene()
	{
		m_pSampleUI = NULL;
	}

	bool Load(CDXUTDialog* _sampleUI,LPDIRECT3DDEVICE9 _pd3dDevice)
	{
		m_pSampleUI = _sampleUI;

		if( D3DXCreateFont( _pd3dDevice, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, 
			OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
			L"Arial", &m_pFont ) != S_OK)
			return false;

		m_bg.Load(_pd3dDevice);
		m_home.Load(_pd3dDevice);
		m_character.Load(_pd3dDevice);

		return true;
	}

	bool Release()
	{
		SAFE_RELEASE(m_pFont);
		SAFE_RELEASE(m_pTextSprite);

		m_bg.Release();
		m_home.Release();
		m_character.Release();
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Create()
	{
		m_pSampleUI->AddButton(IDC_UPBUTTON, L"UP",325,300,50,50);
		m_pSampleUI->AddButton(IDC_DOWNBUTTON, L"DOWN",325,350,50,50);
		m_pSampleUI->AddButton(IDC_LEFTBUTTON, L"LEFT",275,350,50,50);
		m_pSampleUI->AddButton(IDC_RIGHTBUTTON, L"RIGHT",375,350,50,50);

		m_pSampleUI->AddButton(IDC_ENTERBUTTON, L"ENTER",375,300,50,50);

		return true;
	}

	void GUIEvent(int nControlID)
	{
		switch( nControlID )
		{
		case IDC_UPBUTTON:
			m_character.WalkUp();
			break;

		case IDC_DOWNBUTTON:
			m_character.WalkDown();
			break;

		case IDC_LEFTBUTTON:
			m_character.WalkLeft();
			break;

		case IDC_RIGHTBUTTON:
			m_character.WalkRight();
			break;
		}
	}

	bool CharacterWalk(int _iDirection)
	{
		switch( _iDirection )
		{
		case CHARACTER_DIRECTION_UP:
			m_character.WalkUp();
			return true;

		case CHARACTER_DIRECTION_DOWN:
			m_character.WalkDown();
			return true;

		case CHARACTER_DIRECTION_LEFT:
			m_character.WalkLeft();
			return true;

		case CHARACTER_DIRECTION_RIGHT:
			m_character.WalkRight();
			return true;
		}

		return false;
	}


	bool Destroy()
	{
		m_pSampleUI->RemoveAllControls();

		return true;
	}
	//////////////////////////////////////////////////////////////////////////

	bool Render(LPD3DXSPRITE _pSprite)
	{
		m_bg.Render(_pSprite);
		m_home.Render(_pSprite);
		m_character.Render(_pSprite);

		return true;
	}

	void RenderText()
	{

		//CDXUTTextHelper txtHelper( m_pFont, m_pTextSprite, 15 );

		//// Output statistics
		//txtHelper.Begin();
		//txtHelper.SetInsertionPos( 5, 5 );
		//txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 0.0f, 1.0f ) );
		//txtHelper.DrawTextLine( DXUTGetFrameStats( DXUTIsVsyncEnabled() ) );
		//txtHelper.DrawTextLine( DXUTGetDeviceStats() );
		//txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0f ) );
		//txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0f ) );
		//txtHelper.DrawTextLine( L"Press ESC to quit" );
		//txtHelper.End();
	}

private:
	ID3DXFont* m_pFont;         // Font for drawing text
	ID3DXSprite* m_pTextSprite;   // Sprite for batching draw text calls

	CDXUTDialog* m_pSampleUI;

	LmCharacter m_character;
	LmHome m_home;
	LmBackground m_bg;
	//CollisionChecker m_collisionChecker;
};