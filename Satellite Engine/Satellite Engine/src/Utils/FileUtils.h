#pragma once

#include <string>

namespace Satellite
{
	namespace Utils
	{
		// Everything that is not part of a class, will have the following naming convention: type name_name
		std::string read_file(const char* filepath)
		{
			FILE* file = fopen(filepath, "rt"); // fopen opens the filename fpointed to by filepath, using the give mode (rt)
			fseek(file, 0, SEEK_END); // fseek sets the file position of the stream to the given offset. The third parameter is the position from where the offset is added.
			unsigned long length = ftell(file); // ftell returns the current file position of the specified stream with respect to the starting of the file.
			unsigned long auxLen = length + 1;
			char* data = new char[auxLen];
			memset(data, 0, auxLen); // If we don't initialize the data with 0, there will be weird characters at the end of the file we are reading
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}
	}
}