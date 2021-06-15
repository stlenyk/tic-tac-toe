#ifndef TIC_TAC_TOE_SFML_STATEMACHINE_H
#define TIC_TAC_TOE_SFML_STATEMACHINE_H

#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
	StateMachine() = default;
	~StateMachine() = default;

	void AddState(StateRef newState, bool isReplacing = true);
	void RemoveState();

	void ProcessStateChanges();

	StateRef& GetActiveState();

private:
	std::stack<StateRef> _states;
	StateRef _newState;
	bool _isAdding;
	bool _isRemoving;
	bool _isReplacing;

};


#endif //TIC_TAC_TOE_SFML_STATEMACHINE_H
