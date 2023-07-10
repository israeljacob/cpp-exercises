#pragma once
struct  Message{
	std::thread::id thread;
	double num;
	bool flag;
};