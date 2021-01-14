#include "LEDMatrix.h"
#include <iostream>

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

	pinMode(JOY_UP, INPUT);
	pinMode(JOY_DOWN, INPUT);
	pinMode(JOY_LEFT, INPUT);
	pinMode(JOY_RIGHT, INPUT);

	pullUpDnControl(JOY_UP, PUD_UP);
	pullUpDnControl(JOY_DOWN, PUD_UP);
	pullUpDnControl(JOY_LEFT, PUD_UP);
	pullUpDnControl(JOY_RIGHT, PUD_UP);


	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			set_pixel(x, y, BLACK);
		}
	}
	refresh();
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

unsigned char LEDMatrix::bits_from_int(unsigned char mode, unsigned char x)
{
	if (mode == 0) return x & 1;
	if (mode == 1) return x & 2;
	if (mode == 2) return x & 4;
}

void LEDMatrix::set_row(unsigned char row) const
{
	digitalWrite(A, bits_from_int(0, row));
	digitalWrite(B, bits_from_int(1, row));
	digitalWrite(C, bits_from_int(2, row));
}

void LEDMatrix::set_color_top(unsigned char color) const
{
	digitalWrite(R1, bits_from_int(0, color));
	digitalWrite(G1, bits_from_int(1, color));
	digitalWrite(B1, bits_from_int(2, color));
}

void LEDMatrix::set_color_bottom(unsigned char color) const
{
	digitalWrite(R2, bits_from_int(0, color));
	digitalWrite(G2, bits_from_int(1, color));
	digitalWrite(B2, bits_from_int(2, color));
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

int LEDMatrix::get_joy()
{
	if (!digitalRead(JOY_UP)) return 0;
	if (!digitalRead(JOY_DOWN)) return 1;
	if (!digitalRead(JOY_LEFT)) return 2;
	if (!digitalRead(JOY_RIGHT)) return 3;
	return -1;
}