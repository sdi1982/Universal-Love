#pragma once

class LmDanceRoom{
public:
	LmDanceRoom()
	{
		m_rc.top = 0;
		m_rc.bottom = 100;
		m_rc.left = 0;
		m_rc.right= 100;
		m_Pos.x = 0;
		m_Pos.y = 0;
		m_Pos.z = 0;
	}

	~LmDanceRoom()
	{
	}

	bool Release()
	{
		SAFE_RELEASE(m_pTexture);
		return true;
	}

	bool Load(LPDIRECT3DDEVICE9 pd3dDevice)
	{
		if( FAILED(D3DXCreateTextureFromFile(pd3dDevice, L"dance_room.bmp", &m_pTexture)) )
			return false;

		return true;
	}

	bool Render(LPD3DXSPRITE _pSprite)
	{
		_pSprite->Draw(m_pTexture, &m_rc, NULL, &m_Pos, D3DCOLOR_RGBA(255,255,255,255));

		return true;
	}

	RECT GetRect()
	{
		return m_rect;
	}
private:
	RECT m_rect;
	LPDIRECT3DTEXTURE9 m_pTexture;
	RECT m_rc;
	D3DXVECTOR3 m_Pos;
}