/*
  ==============================================================================

    Wavetable.h
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#ifndef WAVETABLE_H_INCLUDED
#define WAVETABLE_H_INCLUDED

class Wavetable
{
public:
    Wavetable ();
    ~Wavetable ();
    
    float get (int index);
    
    static int size;
    
private:
    float* m_table;
};



#endif  // WAVETABLE_H_INCLUDED
