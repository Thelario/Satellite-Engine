/*
#pragma once

// For more information on this topic, see section 3.2.3.3 on Game Engine Architecture by Jason Gregory.

#if ASSERTIONS_ENABLED

// define some inline assembly that causes a break into the debugger -- this will be different on each target CPU
#define debugBreak() asm { int 3 }

// check the expression and fail if it is false
#define ASSERT(expr) 
	if (expr) { } 
	else 
	{ 
		reportAssertionFailure(#expr, __FILE__, __LINE__); 
		debugBreak(); 
	}

#else

#define ASSERT(expr) // evaluates to nothing

#endif
*/
/*  Advice On Assertions */
/* 
It’s important to be aware of their performance cost.You may want to consider defining two kinds of assertion macros.The regular
ASSERT() macro can be left active in all builds, so that errors are easily caught even when not running in debug mode.A second assertion
macro, perhaps called SLOW_ASSERT(), could be activated only in debug builds.This macro could then be used in places where the cost of assertion
checking is too high to permit inclusion in release builds.
*/

/* Compile-Time Assertions */
// static_assert(expr, "Wrong Message")
// 
