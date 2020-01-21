// test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "m6502.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


uint8_t store[0x10000];


inline void read(m6502_device& cpu) {
	cpu.setDATA(store[cpu.getADDR()]);
};

inline void write(m6502_device& cpu) {
	store[cpu.getADDR()] = cpu.getDATA();
}



const long int MAXCYCLES = 1000000000L;


int main()
{

	{
		ifstream ismos;
		ismos.open(
			"d:\\work\\vs2017\\scratch\\mame-cpu-libs\\mame-cpu-lib-6502-test\\testasm\\test-rom0.mos",
			ifstream::in | ifstream::binary
		);

		if (ismos.fail())
		{
			cerr << "Unable to open mos image\n";
			return 1;
		}

		ismos.read(((char *)store) + 0xC000, 0x4000);

		ismos.close();
	}
	
	m6502_device cpu;

	cpu.start();
	cpu.reset();

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	for (long int i = 0; i < MAXCYCLES; i++)
	{
		cpu.tick();
		if (cpu.getRNW()) {
			read(cpu);
		}
		else {
			write(cpu);
		}

		//cout << cpu;
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	duration<double> ts = duration_cast<duration<double>>(t2 - t1);

	cout << MAXCYCLES << " in " << (ts.count() * 1000) << "ms\n";
	cout << "=" << (((double)MAXCYCLES / 1000000.0) / ts.count()) << "MHz\n";
}

