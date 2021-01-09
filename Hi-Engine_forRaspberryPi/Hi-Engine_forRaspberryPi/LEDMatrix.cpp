#include "LEDMatrix.h"

LEDMatrix::LEDMatrix()
{
	if (wiringPiSetupGpio() < 0) return;

	pinMode(R1, OUTPUT);
	pinMode(R2, OUTPUT);
	pinMode(G1, OUTPUT);
	pinMode(G2, OUTPUT);
	pinMode(B1, OUTPUT);
	pinMode(B2, OUTPUT);

	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);

	pinMode(CLK, OUTPUT);
	pinMode(LATCH, OUTPUT);
	pinMode(OE, OUTPUT);
}

void LEDMatrix::clk()
{
	digitalWrite(CLK, 1);
	delayMicroseconds(10);
	digitalWrite(CLK, 0);
}

void LEDMatrix::latch()
{
	digitalWrite(LATCH, 1);
	delayMicroseconds(10);
	digitalWrite(LATCH, 0);
}

tuple<unsigned char, unsigned char, unsigned char> LEDMatrix::bits_from_int(unsigned char x)
{
	return tuple<unsigned char, unsigned char, unsigned char>(x & 1, x & 2, x & 4);
}

void LEDMatrix::set_row(unsigned char row) const
{
	tuple<unsigned char, unsigned char, unsigned char> result = bits_from_int(row);
	digitalWrite(A, get<0>(result));
	digitalWrite(B, get<1>(result));
	digitalWrite(C, get<2>(result));
}

void LEDMatrix::set_color_top(unsigned char color) const
{
	tuple<unsigned char, unsigned char, unsigned char> result = bits_from_int(color);
	digitalWrite(R1, get<0>(result));
	digitalWrite(G1, get<1>(result));
	digitalWrite(B1, get<2>(result));
}

void LEDMatrix::set_color_bottom(unsigned char color) const
{
	tuple<unsigned char, unsigned char, unsigned char> result = bits_from_int(color);
	digitalWrite(R2, get<0>(result));
	digitalWrite(G2, get<1>(result));
	digitalWrite(B2, get<2>(result));
}

void LEDMatrix::refresh()
{
	for (int row = 0; row < 8; row++)
	{
		digitalWrite(OE, 1);
		set_color_top(0);
		set_row(row);
		for (int col = 0; col < 32; col++)
		{
			set_color_top(screen[row][col]);
			set_color_bottom(screen[row + 8][col]);
			clk();
		}
		latch();
		digitalWrite(OE, 0);
		delay(1);
	}
}

void LEDMatrix::set_pixel(unsigned char x, unsigned char y, unsigned char color)
{
	screen[y][x] = color;
}
