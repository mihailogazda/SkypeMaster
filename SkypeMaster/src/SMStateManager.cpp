#include "SMStateManager.h"

SMStateManager::SMStateManager()
{
	setState(SMStateUnknown);
}

void SMStateManager::setState(SMState newState)
{
	_currentState = newState;
}

SMState SMStateManager::getState() const
{
	return _currentState;
}
