#include <iostream>
#include <string>

#include "../src/curlpp.hpp"

int main()
{
    curlpp::init();

    try
    {
        std::string buffer;

        curlpp::List header{"Accept-Language: de"};

        curlpp::Easy easy;

        easy.setOpt(CURLOPT_HTTPHEADER, header.getHandle());
        easy.setOpt(CURLOPT_URL, "http://example.com");
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