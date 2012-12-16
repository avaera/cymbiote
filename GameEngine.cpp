/**
 * GameEngine.cpp - Code file for the GameEngine class, managing the primary logic of the game world
 *
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. Please see COPYING for more details.
 * 
 **/

#include "GameEngine.h"

namespace Cymbiote {

// Constructor simply sets initial values to member variables
GameEngine::GameEngine() {

	state = EngineState::UNINITIALISED;

}

// Performs any necessary actions to prepare the engine for initialisation
bool GameEngine::init() {
	
	// Here will go much more later on.
	
	state = EngineState::INITIALISED;
	return true;
}

// Iterates through the game loop, returning false if no more loops should
// occur.
bool GameEngine::loop() {

    if (state == EngineState::STOPPING) {
		
		state = EngineState::STOPPED;
		return false;
		
	}
	
    state = EngineState::RUNNING;
    
	// Again, not much to do yet.
	
	return true;
	
}

// Requests that the engine shut down once the current loop is completed,
// returning false on any error.
bool GameEngine::stop() {
	
	state = EngineState::STOPPING;
	
	// Perform necessary safety checks at a later stage.
	
	return true;
}

}
