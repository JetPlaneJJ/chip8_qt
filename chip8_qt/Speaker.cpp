#include "Speaker.h"
#include <QCoreApplication>

Speaker::Speaker()
{
    media_player_ = new QMediaPlayer;
    audio_output_ = new QAudioOutput;
}

Speaker::~Speaker()
{
    delete media_player_;
    delete audio_output_;
}

/**
* @brief Plays a sound at given volume
*
* @param volume
*/
void Speaker::play(const int volume)
{
    media_player_->setAudioOutput(audio_output_);

    // TODO: change this to relative file path
    media_player_->setSource(QUrl::fromLocalFile("/Users/jlin/Downloads/Projects/chip8_qt/chip8_qt/audio/hit.mp3"));
    audio_output_->setVolume(volume);
    media_player_->play();
}

/**
 * @brief Stops the playing sound.
 *
 */
void Speaker::stop()
{
    media_player_->stop();
}
