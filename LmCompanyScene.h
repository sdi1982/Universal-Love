#pragma once

#define IDC_COMPANYBUTTON1	201
#define IDC_COMPANYBUTTON2	202
#define IDC_COMPANYBUTTON3	203

class LmCompanyScene
{
public:
	LmCompanyScene()
	{
		m_sampleUI = NULL;
		m_pTexture = NULL;
	}

	~LmCompanyScene()
	{
		m_sampleUI = NULL;
	}

	bool Load(CDXUTDialog* _sampleUI,LPDIRECT3DDEVICE9 pd3dDevice)
	{
		m_sampleUI = _sampleUI;

		if( FAILED(D3DXCreateTextureFromFile(pd3dDevice, L"company.bmp", &m_pTexture)) )
			return false;

		return true;
	}

	bool Release()
	{
		SAFE_RELEASE(m_pTexture);

		return true;
	}

	bool Create()
	{
		m_sampleUI->AddButton(IDC_COMPANYBUTTON1, L"타이거",50,330,150,50);
		m_sampleUI->AddButton(IDC_COMPANYBUTTON2, L"라이온",350,330,150,50);
		m_sampleUI->AddButton(IDC_COMPANYBUTTON3, L"와이번",600,330,150,50);

		return true;
	}

	bool Destroy()
	{
		m_sampleUI->RemoveAllControls();
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
	CDXUTDialog* m_sampleUI;
	LPDIRECT3DTEXTURE9 m_pTexture;

};