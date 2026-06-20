#include "sed.hpp"


int is_valid_file(std::string file)
{
	std::ifstream input;

	input.open (file.c_str());
	if(input.is_open() == false)
		return(0);
	return(1);
}


std::string make_outputfile(std::string srcfile)
{
	std::string destfile;

	destfile = srcfile + ".replace";
	return(destfile);
}

int is_process_success(std::string srcfile, std::string s1, std::string s2, std::string destfile)
{
	std::ifstream input(srcfile.c_str());
	std::ofstream output(destfile.c_str());

	if(output.is_open() == false)
		return(0);

	std::string content;
	std::stringstream buf;
	std::string::size_type detect_pos;
	std::string::size_type aft_start;

	aft_start = 0;
	buf << input.rdbuf();
	content = buf.str();
	while(1)
	{
		detect_pos = content.find(s1, aft_start);
		if(detect_pos == std::string::npos)
		{
			output << content.substr(aft_start);
			break;
		}
		output << content.substr(aft_start, (detect_pos - aft_start));
		output << s2;
		aft_start = detect_pos + s1.length();
	}
	return(1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid arguments." << std::endl;
		return(1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string destfile;

	if (s1.empty() == true)
	{
		std::cerr << "Error: invalid arguments." << std::endl;
		return(1);
	}
	if (is_valid_file(filename) == 0)
	{
		std::cerr << "Error: can't open designated file." << std::endl;
		return(1);
	}

	destfile = make_outputfile(filename);

	if(is_process_success(filename, s1, s2, destfile) == 0)
	{
		std::cerr << "Error: can't process til the end." << std::endl;
		return(1);
	}
	return(0);
}
