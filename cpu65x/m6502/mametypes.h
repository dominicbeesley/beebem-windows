


// I/O line states
enum line_state
{
	CLEAR_LINE = 0,             // clear (a fired or held) line
	ASSERT_LINE                 // assert an interrupt immediately
};


// I/O line definitions
enum
{
	// input lines
	INPUT_LINE_IRQ0,
	INPUT_LINE_NMI,
	INPUT_LINE_V,

	// special input lines that are implemented in the core
	INPUT_LINE_RESET,
	INPUT_LINE_HALT,
	MAX_INPUT_LINES
};

