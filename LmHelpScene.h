#pragma once

#define IDC_HELPFINISHBUTTON			400

class LmHelpScene
{
public:
	LmHelpScene()
	{
		m_pSampleUI = NULL;
		m_pTexture = NULL;
		m_pFont = NULL;         // Font for drawing text
		m_pTextSprite = NULL;   // Sprite for batching draw text calls
		m_characterType = 0;
	}

	~LmHelpScene()
	{
		m_pSampleUI = NULL;

		m_characterType = 0;
	}

	void SetCharacterType(UINT _character)
	{
		m_characterType = _character;
	}

	bool Load(CDXUTDialog* _sampleUI,LPDIRECT3DDEVICE9 pd3dDevice)
	{
		m_pSampleUI = _sampleUI;

		// 폰트 스프라이트 생성
		if( D3DXCreateSprite( pd3dDevice, &m_pTextSprite ) != S_OK)
			return false;

		if( D3DXCreateFont( pd3dDevice, 15, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, 
			OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
			L"Arial", &m_pFont ) != S_OK)
			return false;

		// 텍스쳐 로드
		if( FAILED(D3DXCreateTextureFromFile(pd3dDevice, L"back.png", &m_pTexture)) )
			return false;

		return true;
	}
	
	bool Release()
	{
		SAFE_RELEASE(m_pFont);
		SAFE_RELEASE(m_pTexture);
		SAFE_RELEASE(m_pTextSprite);

		return true;
	}

	bool Create()
	{
		m_pSampleUI->AddButton(IDC_HELPFINISHBUTTON, L"Start",325,300,150,150);

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

		//RenderText();

		return true;
	}

	void RenderText()
	{

		CDXUTTextHelper txtHelper( m_pFont, m_pTextSprite, 15 );

		// Output statistics
		txtHelper.Begin();
		txtHelper.SetInsertionPos( 300, 300 );
		txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 0.0f, 1.0f ) );
//		txtHelper.DrawTextLine( DXUTGetFrameStats( DXUTIsVsyncEnabled() ) );
//		txtHelper.DrawTextLine( DXUTGetDeviceStats() );

		txtHelper.DrawTextLine( L"경대 월드에 오신 것을 환영합니다." );

//		txtHelper.DrawTextLine( L"Press ESC to quit" );
//		txtHelper.DrawTextLine( L"Press ESC to quit" );
//		txtHelper.DrawTextLine( L"Press ESC to quit" );


		txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0f ) );
		txtHelper.SetForegroundColor( D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0f ) );
		txtHelper.DrawTextLine( L"Press ESC to quit" );
		txtHelper.End();
	}

	void GUIEvent(int nControlID)
	{
		//switch( nControlID )
		//{
		//}
	}

private:
	ID3DXFont* m_pFont;         // Font for drawing text
	ID3DXSprite* m_pTextSprite;   // Sprite for batching draw text calls

	CDXUTDialog* m_pSampleUI;
	LPDIRECT3DTEXTURE9 m_pTexture;

	UINT m_characterType;
};