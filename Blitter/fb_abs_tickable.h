#ifndef _FB_TICKABLE_H
#define _FB_TICKABLE_H

#pragma once
class fb_abs_tickable
{
public:
	//called at the end of each cycle, sys indicates this is aligned with 2/1 MHz BBC cycle
	virtual void tick(bool sys) = 0;
	//called at the start of each cycle
	virtual void tock() = 0;
	virtual void reset() = 0;
};


#endif //_FB_TICKABLE_H

