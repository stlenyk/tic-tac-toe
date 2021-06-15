#pragma once

#ifndef TIC_TAC_TOE_SFML_STATE_H
#define TIC_TAC_TOE_SFML_STATE_H


class State {
public:
	virtual void Init() = 0;

	virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(float dt) = 0;

	virtual void Pause() {}
	virtual void Resume() {}
};


#endif //TIC_TAC_TOE_SFML_STATE_H
