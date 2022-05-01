#pragma once

#include "LmCamera.h"

#define WALK_UP	1
#define WALK_DOWN	2
#define WALK_LEFT	3
#define WALK_RIGHT	4

class LmCharacter
{
public:
	LmCharacter()
	{
		//m_rect = _rect;
		m_direction = WALK_UP;
		m_downCount = 0;
		m_frontCount = 0;
		m_leftCount = 0;
		m_rightCount = 0;
		m_localX = 0;
		m_localY = 0;
		m_globalX = 100;
		m_globalY = 100;

		m_stepSize = 32;
	}

	~LmCharacter()
	{
	}

	bool Release()
	{
		SAFE_RELEASE(m_pTextureUp1);
		SAFE_RELEASE(m_pTextureUp2);
		SAFE_RELEASE(m_pTextureUp3);
		SAFE_RELEASE(m_pTextureDown1);
		SAFE_RELEASE(m_pTextureDown2);
		SAFE_RELEASE(m_pTextureDown3);
		SAFE_RELEASE(m_pTextureLeft1);
		SAFE_RELEASE(m_pTextureLeft2);
		SAFE_RELEASE(m_pTextureLeft3);
		SAFE_RELEASE(m_pTextureRight1);
		SAFE_RELEASE(m_pTextureRight2);
		SAFE_RELEASE(m_pTextureRight3);

		return true;
	}

	bool Load(LPDIRECT3DDEVICE9 _pd3dDevice)
	{
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_up1.png", &m_pTextureUp1)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_up2.png", &m_pTextureUp2)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_up3.png", &m_pTextureUp3)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_down1.png", &m_pTextureDown1)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_down2.png", &m_pTextureDown2)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_down3.png", &m_pTextureDown3)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_left1.png", &m_pTextureLeft1)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_left2.png", &m_pTextureLeft2)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_left3.png", &m_pTextureLeft3)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_right1.png", &m_pTextureRight1)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_right2.png", &m_pTextureRight2)) )
			return false;
		if( FAILED(D3DXCreateTextureFromFile(_pd3dDevice, L"girl2_right3.png", &m_pTextureRight3)) )
			return false;

		return true;
	}

	bool Render(LPD3DXSPRITE _pSprite)
	{
		RECT rc = {0, 0, 40, 40};


		D3DXVECTOR3 Pos = LmCamera::CreateInstance()->TranslateCharacterPositionGlobalToLocal(m_globalX,m_globalY);

		//D3DXVECTOR3 Pos(m_localX,m_localY,0);

		switch(m_direction)
		{
		case WALK_UP:
			if(m_downCount%3== 0)
			{			
				_pSprite->Draw(m_pTextureUp1, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
				m_downCount = 0;
			}
			else if(m_downCount%3 == 1)
				_pSprite->Draw(m_pTextureUp2, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			else if(m_downCount%3 == 2)
			{
				_pSprite->Draw(m_pTextureUp3, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			}

			break;
		case WALK_DOWN:
			if(m_frontCount%3== 0)
			{
				_pSprite->Draw(m_pTextureDown1, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
				m_frontCount = 0;
			}
			else if(m_frontCount%3== 1)
				_pSprite->Draw(m_pTextureDown2, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			else if(m_frontCount%3== 2)
			{
				_pSprite->Draw(m_pTextureDown3, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			}
			break;
		case WALK_LEFT:
			if(m_leftCount%3 == 0)
			{
				_pSprite->Draw(m_pTextureLeft1, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
				m_leftCount = 0;
			}
			else if(m_leftCount%3== 1)
				_pSprite->Draw(m_pTextureLeft2, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			else if(m_leftCount%3== 2)
			{
				_pSprite->Draw(m_pTextureLeft3, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			}
			break;

		case WALK_RIGHT:
			if(m_rightCount%3== 0)
			{
				_pSprite->Draw(m_pTextureRight1, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
				m_rightCount = 0;
			}
			else if(m_rightCount%3== 1)
				_pSprite->Draw(m_pTextureRight2, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			else if(m_rightCount%3== 2)
			{
				_pSprite->Draw(m_pTextureRight3, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));
			}
			break;

		}

		return true;
	}

	bool WalkLeft()
	{
		m_direction = WALK_LEFT;
		m_leftCount++;

		if(m_globalX <= 0)
			return false;
		else
			m_globalX = m_globalX-m_stepSize;

		return true;
	}

	bool WalkRight()
	{
		m_direction = WALK_RIGHT;
		m_rightCount++;

		if(m_globalX > 2048-40)
			return false;
		else
			m_globalX = m_globalX+m_stepSize;

		return true;
	}

	bool WalkDown()
	{
		m_direction = WALK_DOWN;
		m_frontCount++;

		if(m_globalY > 2048-40)
			return false;
		else
			m_globalY = m_globalY+m_stepSize;

		return true;
	}

	bool WalkUp()
	{
		m_direction = WALK_UP;
		m_downCount++;

		if(m_globalY <= 0)
			return false;
		else
			m_globalY = m_globalY-m_stepSize;

		return true;
	}

	RECT GetRect()
	{
		return m_rect;
	}
	
	FLOAT GetLocalX()
	{
		return m_localX;
	}

	FLOAT GetLocalY()
	{
		return m_localY;
	}

	FLOAT GetGlobalX()
	{
		return m_localX;
	}

	FLOAT GetGlobalY()
	{
		return m_localY;
	}

private:
	LPDIRECT3DTEXTURE9 m_pTextureUp1;
	LPDIRECT3DTEXTURE9 m_pTextureUp2;
	LPDIRECT3DTEXTURE9 m_pTextureUp3;
	LPDIRECT3DTEXTURE9 m_pTextureDown1;
	LPDIRECT3DTEXTURE9 m_pTextureDown2;
	LPDIRECT3DTEXTURE9 m_pTextureDown3;
	LPDIRECT3DTEXTURE9 m_pTextureLeft1;
	LPDIRECT3DTEXTURE9 m_pTextureLeft2;
	LPDIRECT3DTEXTURE9 m_pTextureLeft3;
	LPDIRECT3DTEXTURE9 m_pTextureRight1;
	LPDIRECT3DTEXTURE9 m_pTextureRight2;
	LPDIRECT3DTEXTURE9 m_pTextureRight3;

	RECT m_rect;
	CDXUTDialog* m_sampleUI;

	UINT m_direction;
	UINT m_downCount;
	UINT m_frontCount;
	UINT m_leftCount;
	UINT m_rightCount;

	FLOAT m_localX;
	FLOAT m_localY;

	FLOAT m_globalX;
	FLOAT m_globalY;

	UINT m_stepSize;
};
