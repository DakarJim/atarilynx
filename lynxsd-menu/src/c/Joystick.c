#include <joystick.h>
#include "Joystick.h"
#include "Preferences.h"

/*
 ******************************************************************************
 Functions for joystick state processing
 ******************************************************************************
 */


static unsigned char joyState = 0;


unsigned char __fastcall__ Joy_IsOn(unsigned char mask) {
	if ((joyState & mask) == 0) { // if button is not pressed, do nothing
		return 0;
	}
	joyState ^= mask; // reset buffered button state

	// delay processing if the previous action countdown hasn't expired
	// this works more or less like a key debouncer
	if (joystickActionDelay == 0) {
		joystickActionDelay = (preferences[PREF_FAST_SCROLL] ? ACTION_DELAY_FRAMES_FAST : ACTION_DELAY_FRAMES_SLOW);
		return 1;
	}
	return 0;
}


void Joy_Buffer() {
  joyState |= joy_read(JOY_1);
}