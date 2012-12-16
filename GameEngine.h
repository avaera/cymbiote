/**
 * GameEngine.h - Header file for the Game Engine class, managing the primary logic of the game world.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. Please see COPYING for more details.
 * 
 **/
 
#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

namespace Cymbiote {
	
// GameEngine class
class GameEngine {
	public:
	
		// Default constructor
		GameEngine();
		
		// Initialisation function
		bool init();
		
		// Main logic for game loop, returns true as long as the loop
		// should continue
		bool loop();
		
		// Ends the main game loop and shuts down the server
		bool stop();
		
		// Destructor
		~GameEngine() { };
	
	protected:
	
	private:
	
		// Enumerated state information
		struct EngineState {
			enum Setting {
				UNINITIALISED, INITIALISED, RUNNING, STOPPING, STOPPED
			};
		};
		
		// Any interface servers used by the game
		//vector<InterfaceServer> interfaces;
		
		// The current enumerated state of the engine
		EngineState::Setting state;
		
		
};

}


#endif
