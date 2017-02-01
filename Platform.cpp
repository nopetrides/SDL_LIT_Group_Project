#include "Platform.h"


Platform::Platform(int speedChange)
{
	m_ChangeSpeed = speedChange;
}
int Platform::getSpeedMult()
{
	return m_ChangeSpeed;
}
