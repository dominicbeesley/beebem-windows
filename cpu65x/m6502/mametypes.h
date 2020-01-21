

typedef uint32_t u32;
typedef uint16_t u16;

typedef uint32_t offs_t;


// I/O line states
enum line_state
{
	CLEAR_LINE = 0,             // clear (a fired or held) line
	ASSERT_LINE,                // assert an interrupt immediately
	HOLD_LINE                   // hold interrupt line until acknowledged
};


// I/O line definitions
enum
{
	// input lines
	MAX_INPUT_LINES = 64 + 3,
	INPUT_LINE_IRQ0 = 0,
	INPUT_LINE_IRQ1 = 1,
	INPUT_LINE_IRQ2 = 2,
	INPUT_LINE_IRQ3 = 3,
	INPUT_LINE_IRQ4 = 4,
	INPUT_LINE_IRQ5 = 5,
	INPUT_LINE_IRQ6 = 6,
	INPUT_LINE_IRQ7 = 7,
	INPUT_LINE_IRQ8 = 8,
	INPUT_LINE_IRQ9 = 9,
	INPUT_LINE_NMI = MAX_INPUT_LINES - 3,

	// special input lines that are implemented in the core
	INPUT_LINE_RESET = MAX_INPUT_LINES - 2,
	INPUT_LINE_HALT = MAX_INPUT_LINES - 1
};

