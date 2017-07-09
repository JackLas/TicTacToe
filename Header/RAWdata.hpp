#ifndef RAWDATA_H
#define RAWDATA_H

#include <string>

class RAWdata
{
private:
	std::string fileName;
	size_t fileSize;
	char *data;
public:
	RAWdata(std::string fn, size_t fs, char *d);
	RAWdata();
	~RAWdata();

	std::string getFileName();
	size_t getFileSize();
	char* getData();

	void setFileName(std::string fn);
	void setFileSize(size_t fs);
	void setData(char *d, size_t size);
};

#endif //RAWDATA_H