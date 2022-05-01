#pragma once

#define IDC_CHRACTERBUTTON1			300
#define IDC_CHRACTERBUTTON2			301

class LmRecruitScene
{
public:
	LmRecruitScene()
	{
		m_pSampleUI = NULL;
		m_pTexture = NULL;
	}

	~LmRecruitScene()
	{
		m_pSampleUI = NULL;
	}

	bool Release()
	{
		SAFE_RELEASE(m_pTexture);

		return true;
	}

	bool Load(CDXUTDialog* _sampleUI,LPDIRECT3DDEVICE9 pd3dDevice)
	{
		m_pSampleUI = _sampleUI;

		if( FAILED(D3DXCreateTextureFromFile(pd3dDevice, L"recruit.bmp", &m_pTexture)) )
			return false;

		return true;
	}

	bool Create()
	{
		m_pSampleUI->AddButton(IDC_CHRACTERBUTTON1, L"아이유",150,100,150,150);
		m_pSampleUI->AddButton(IDC_CHRACTERBUTTON2, L"신세경",600,100,150,150);

		return true;
	}

	bool Destroy()
	{
		m_pSampleUI->RemoveAllControls();
		return true;
	}

	bool Render(LPD3DXSPRITE _pSprite)
	{
		RECT rc = {0, 0, 800, 600};
		D3DXVECTOR3 Pos(0,0,0);
		_pSprite->Draw(m_pTexture, &rc, NULL, &Pos, D3DCOLOR_RGBA(255,255,255,255));

		return true;
	}

	void GUIEvent(int nControlID)
	{
		//switch( nControlID )
		//{
		//}
	}

private:
	CDXUTDialog* m_pSampleUI;
	LPDIRECT3DTEXTURE9 m_pTexture;
};