#pragma once
#include <SDL.h>

/// <summary>
/// Class that represents a timer
/// This timer can be used to time certain actions inside the game
/// </summary>
class Timer
{
public:
    //Initializes variables
    Timer();

    //The various clock functions
    
    /// <summary>
    /// Starts the timer and keeps on counting until it's paused or stopped
    /// </summary>
    void start();

    /// <summary>
    /// Stops the timer and restarts it's values
    /// </summary>
    void stop();

    /// <summary>
    /// Pauses the timer, and the time stops counting
    /// </summary>
    void pause();

    /// <summary>
    /// Unpauses the timer, and the timer resumes
    /// </summary>
    void unpause();

    //Gets the timer's time
    Uint32 getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

private:
    //The clock time when the timer started
    Uint32 mStartTicks;

    //The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
};

