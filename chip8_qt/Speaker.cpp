#include "Speaker.h"

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
    // TODO: currently doesn't play anything
    media_player_->setAudioOutput(audio_output_);
    media_player_->setSource(QUrl::fromLocalFile("../audio/hit.wav"));
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
