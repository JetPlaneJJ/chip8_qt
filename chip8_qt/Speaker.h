#ifndef Speaker_h
#define Speaker_h

#include <string>

/**
 * @file Speaker.h
 * @author Jay Lin
 * @brief Controls playing audio
 * @version 0.1
 * @date 2023-08-09
 *
 * @copyright Copyright (c) 2023
 *
 */

// TODO:
/**
 * @brief Speaker handles audio control
 */
class Speaker
{
public:
    Speaker(/* args */);
    ~Speaker();

    /**
     * @brief Plays a sound at given frequency
     *
     * @param frequency
     */
    void play(const int frequency);

    /**
     * @brief Stops the playing sound.
     *
     */
    void stop();

private:
    int volume_;
    std::string media_file_path_; // local file path to audio to play
};

#endif /* Speaker_h */
