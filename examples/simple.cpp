#include <iostream>
#include <string>

#include "../src/curlpp.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <url>\n";
        return 1;
    }

    curlpp::init();

    try
    {
        std::string buffer;

        curlpp::Easy easy;

        easy.setOpt(CURLOPT_URL, argv[1]);
        easy.setOpt(CURLOPT_WRITEDATA, &buffer);
        easy.setOpt(CURLOPT_WRITEFUNCTION, curlpp::write::toString);

        easy.perform();

        std::cout << "Success: " << buffer << std::endl;
    }
    catch (const curlpp::Exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    curlpp::cleanup();
}