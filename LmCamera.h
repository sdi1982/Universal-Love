#pragma once

// ���ΰ���ġ�� �ľ��ؼ� ����� �̵��� ������ ���ΰ��� �̵��� ������ ������ �Ѵ�.
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


		// ȭ���� �����ڸ� ����: ĳ���Ͱ� �̵��Ѵ�.
		if(_globalX<400)// ȭ�� ���� ����
		{
			resultLocalPosition.x = _globalX;
		}

		// ȭ���� �����ڸ� ������: ĳ���Ͱ� �̵��Ѵ�.
		else if(_globalX>(2048-400)) // �ʳ��� - ȭ�� ���� ����
		{
			resultLocalPosition.x = _globalX - (2048-800);
		}
		// �� �ܿ� ĳ���ʹ� ���� �߾ӿ� �����ȴ�.
		else
		{
			resultLocalPosition.x = 400;
		}

		// ȭ���� �����ڸ� ����: ĳ���Ͱ� �̵��Ѵ�.
		if(_globalY<300) // ȭ�� ��������
		{
			resultLocalPosition.y = _globalY;
		}

		// ȭ���� �����ڸ� �Ʒ���: ĳ���Ͱ� �̵��Ѵ�.
		else if(_globalY>(2048-300)) // �ʳ���- ȭ�� ���� ����
		{
			resultLocalPosition.y = _globalY - (2048-600);
		}

		// �� �ܿ� ĳ���ʹ� ���� �߾ӿ� �����ȴ�.
		else
		{
			resultLocalPosition.y = 300;
		}

		return resultLocalPosition;
	}

	RECT TranslateBackgroundRectPosition()
	{
		RECT resultRect;

		
		// ȭ���� �����ڸ� ����: ����
		if(m_globalCharacterX<400)// ȭ�� ���� ����
		{
			resultRect.left = 0;
			resultRect.right = 800;
		}

		// ȭ���� �����ڸ� ������: ĳ���Ͱ� �̵��Ѵ�.
		else if(m_globalCharacterX>(2048-400)) // �ʳ��� - ȭ�� ���� ����
		{
			resultRect.left = 2048 - 800;
			resultRect.right = 2048;
		}
		// �� �ܿ� ĳ���ʹ� ���� �߾ӿ� �����ȴ�.
		else
		{
			resultRect.left = (long)m_globalCharacterX - 400;
			resultRect.right = (long)m_globalCharacterX + 400;
		}

		// ȭ���� �����ڸ� ����: ĳ���Ͱ� �̵��Ѵ�.
		if(m_globalCharacterY<300) // ȭ�� ��������
		{
			resultRect.top = 0;
			resultRect.bottom = 600;
		}

		// ȭ���� �����ڸ� �Ʒ���: ĳ���Ͱ� �̵��Ѵ�.
		else if(m_globalCharacterY>(2048-300)) // �ʳ���- ȭ�� ���� ����
		{
			resultRect.top = 2048 - 600;
			resultRect.bottom = 2048;
		}

		// �� �ܿ� ĳ���ʹ� ���� �߾ӿ� �����ȴ�.
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