#pragma once

// 주인공위치를 파악해서 배경을 이동할 것인지 주인공을 이동할 것인지 결정을 한다.
class LmCamera
{
public:
	static LmCamera* CreateInstance()
	{

		if(m_instance == NULL)
			m_instance = new LmCamera;

		return m_instance;
	}

	D3DXVECTOR3 TranslateCharacterPositionGlobalToLocal(FLOAT _globalX, FLOAT _globalY)
	{
		m_globalCharacterX = _globalX;
		m_globalCharacterY = _globalY;

		D3DXVECTOR3 resultLocalPosition;

		//resultLocalPosition.x = ?
		//resultLocalPosition.y = ?
		resultLocalPosition.z = 0;


		// 화면의 가장자리 왼쪽: 캐릭터가 이동한다.
		if(_globalX<400)// 화면 넓이 절반
		{
			resultLocalPosition.x = _globalX;
		}

		// 화면의 가장자리 오른쪽: 캐릭터가 이동한다.
		else if(_globalX>(2048-400)) // 맵넓이 - 화면 넓이 절반
		{
			resultLocalPosition.x = _globalX - (2048-800);
		}
		// 그 외에 캐릭터는 넓이 중앙에 고정된다.
		else
		{
			resultLocalPosition.x = 400;
		}

		// 화면의 가장자리 위쪽: 캐릭터가 이동한다.
		if(_globalY<300) // 화면 높이절반
		{
			resultLocalPosition.y = _globalY;
		}

		// 화면의 가장자리 아래쪽: 캐릭터가 이동한다.
		else if(_globalY>(2048-300)) // 맵높이- 화면 높이 절반
		{
			resultLocalPosition.y = _globalY - (2048-600);
		}

		// 그 외에 캐릭터는 높이 중앙에 고정된다.
		else
		{
			resultLocalPosition.y = 300;
		}

		return resultLocalPosition;
	}

	RECT TranslateBackgroundRectPosition()
	{
		RECT resultRect;

		
		// 화면의 가장자리 왼쪽: 고정
		if(m_globalCharacterX<400)// 화면 넓이 절반
		{
			resultRect.left = 0;
			resultRect.right = 800;
		}

		// 화면의 가장자리 오른쪽: 캐릭터가 이동한다.
		else if(m_globalCharacterX>(2048-400)) // 맵넓이 - 화면 넓이 절반
		{
			resultRect.left = 2048 - 800;
			resultRect.right = 2048;
		}
		// 그 외에 캐릭터는 넓이 중앙에 고정된다.
		else
		{
			resultRect.left = (long)m_globalCharacterX - 400;
			resultRect.right = (long)m_globalCharacterX + 400;
		}

		// 화면의 가장자리 위쪽: 캐릭터가 이동한다.
		if(m_globalCharacterY<300) // 화면 높이절반
		{
			resultRect.top = 0;
			resultRect.bottom = 600;
		}

		// 화면의 가장자리 아래쪽: 캐릭터가 이동한다.
		else if(m_globalCharacterY>(2048-300)) // 맵높이- 화면 높이 절반
		{
			resultRect.top = 2048 - 600;
			resultRect.bottom = 2048;
		}

		// 그 외에 캐릭터는 높이 중앙에 고정된다.
		else
		{
			resultRect.top = (long)m_globalCharacterY - 300;
			resultRect.bottom = (long)m_globalCharacterY + 300;
		}

		return resultRect;
	}

private:
	LmCamera()
	{
		m_globalCharacterX = -1;
		m_globalCharacterY = -1;
	}

	FLOAT m_globalCharacterX;
	FLOAT m_globalCharacterY;

	static LmCamera* m_instance;
};

LmCamera* LmCamera::m_instance = 0; 