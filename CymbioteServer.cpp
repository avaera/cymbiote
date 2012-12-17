/**
 * CymbioteServer.cpp - Initiates the main game engine and controls 
 * program execution.
 *
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 *
 **/

#include "CymbioteServer.hpp"

using namespace std;

int main() {
	
	Cymbiote::GameEngine engine;
	bool engine_result;
	
	// Enter the main game logic loop
	engine_result = engine.run();
	
	cout << "\nCymbiote server shut down " << (engine_result ? "successfully." : "due to error.") << endl;
	return 0;
	
}
