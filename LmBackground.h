#pragma once

#include "LmCamera.h"

class LmBackground
{
public:
	LmBackground()
	{
		m_rc.left = 0;
		m_rc.right = 800;
		m_rc.top = 0;
		m_rc.bottom = 600;

		m_pTextureBG = NULL;
	}
	
	bool Load(LPDIRECT3DDEVICE9 _pd3dDevice)
	{
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"back.png", &m_pTextureBG)) )
			return false;

		return true;
	}

	bool Update()
	{
		return true;
	}

	bool Render(LPD3DXSPRITE _pSprite)
	{
		D3DXVECTOR3 Pos(0,0,0);
		m_rc = LmCamera::CreateInstance()->TranslateBackgroundRectPosition();
		_pSprite->Draw(m_pTextureBG, &m_rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));

		return true;
	}

	bool Release()
	{
		SAFE_RELEASE(m_pTextureBG);

		return true;
	}

private:
	LPDIRECT3DTEXTURE9 m_pTextureBG;
	RECT m_rc;
};