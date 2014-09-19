#pragma once

/***
 *	States available for SMStateManager.
 */
typedef enum SMState {
	SMStateUnknown = 0,
	SMStateStarted,
	SMStateRunning,
	SMStateClosing
};

/***
 *	State manager for the application.
 *
 */
class SMStateManager {
private:

	/** Current application state. SMState. */
	SMState _currentState;

public:

	/** Constructor */
	SMStateManager();

	/***
	 *	Sets new state.
	 *	\param New SMState state
	 */
	void setState(SMState newState);

	/***
	 *	Gets current state.
	 *	\return Current SMState state
	 */
	SMState getState() const;
};