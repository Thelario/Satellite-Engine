#pragma once

#include <string>

namespace Satellite
{
	namespace Utils
	{
		class FileUtils
		{
		public:
			// Everything that is not part of a class, will have the following naming convention: type name_name
			// This was previously not part of a class, but I haven't changed the name
			static std::string read_file(const char* filepath)
			{
				FILE* file = fopen(filepath, "rt"); // fopen opens the filename fpointed to by filepath, using the give mode (rt)
				
				fseek(file, 0, SEEK_END); // fseek sets the file position of the stream to the given offset. The third parameter is the position from where the offset is added.
				
				// We get the length of the file by getting the position of the file being this in the end of the file
				unsigned long length = ftell(file); // ftell returns the current file position of the specified stream with respect to the starting of the file.
				unsigned long auxLen = length + 1;
				char* data = new char[auxLen];

				memset(data, 0, auxLen); // If we don't initialize the data with 0, there will be weird characters at the end of the file we are reading
				
				fseek(file, 0, SEEK_SET); // It moves the file pointer position to the beginning of the file
				fread(data, 1, length, file); // We read the file and set all its contents into the data array
				fclose(file);

				std::string result(data);
				delete[] data;
				return result;
			}
		};
	}
}