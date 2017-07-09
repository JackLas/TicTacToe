#include "RAWdata.hpp"

RAWdata::RAWdata(std::string fn, size_t fs, char *d)
{
	fileName = fn;
	fileSize = fs;
	data = d;
}

RAWdata::RAWdata()
{
	data = nullptr;
}

RAWdata::~RAWdata()
{
	delete[] data;
}

std::string RAWdata::getFileName()
{
	return fileName;
}

size_t RAWdata::getFileSize()
{
	return fileSize;
}

char* RAWdata::getData()
{
	return data;
}

void RAWdata::setFileName(std::string fn)
{
	fileName = fn;
}

void RAWdata::setFileSize(size_t fs)
{
	fileSize = fs;
}

void RAWdata::setData(char *d, size_t size)
{
	delete[] data;
	data = new char[size];
	data = d;
}