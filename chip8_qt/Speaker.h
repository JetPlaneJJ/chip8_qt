#ifndef Speaker_h
#define Speaker_h

#include <string>
#include <QMediaPlayer>
#include <QAudioOutput>

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
     * @brief Plays a sound at given volume
     *
     * @param volume
     */
    void play(const int volume);

    /**
     * @brief Stops the playing sound.
     *
     */
    void stop();

private:
    int volume_;
    std::string media_file_path_; // local file path to audio to play
    QMediaPlayer* media_player_;
    QAudioOutput* audio_output_;
};

#endif /* Speaker_h */
