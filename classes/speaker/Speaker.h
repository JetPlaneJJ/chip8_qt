#ifndef Speaker_h
#define Speaker_h
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

class Speaker
{
private:
    /* data */
public:
    Speaker(/* args */);
    ~Speaker();
    
    /**
     * @brief 
     * 
     * @param frequency 
     */
    void play(const int frequency);

    /**
     * @brief 
     * 
     */
    void stop();
};

#endif /* Speaker_h */