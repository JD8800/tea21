#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include "CLI/CLI.hpp"
#include "config.h"
#include <random>
 
auto main(int argc, char **argv) -> int
{
    auto count = 20;
   
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c, --count",
            count,
            fmt::format("Create a vector with the given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
 
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("\nHello JD8800, {}!\n", app.get_name());
 
    /* INSERT YOUR CODE HERE */
     std::vector<int> data(count);
    fmt::print("\nCreated a vector with {} elements \n", count);
 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> distrib(1,100);
 
    for(auto& i :data) {
        i = distrib(gen);
    }
 
    fmt::print("\nThe vector:\n[{}]\n", fmt::join(data, ", "));
 
    auto start = std::chrono::system_clock::now();
 
    std::sort(data.begin(), data.end());
 
    fmt::print("\nSorted vector:\n[{}]\n", fmt::join(data, ", "));
 
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
 
    fmt::print("\nTime to sort the vector:\n[{}]\n", elapsed);
 
    return 0; /* exit gracefully*/
}