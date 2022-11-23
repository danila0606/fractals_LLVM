#include "driver/driver.hpp"

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "Need input file" << std::endl;
        return 0;
    } 

    try {
        std::ofstream out_file("out.ll");
        if (!out_file.is_open())
        {
            throw std::runtime_error("Can not open out.ll file");
        }

        std::ifstream in(argv[1], std::ifstream::in);
        yy::Driver driver(in, out_file);
        driver.parse();
        driver.dumpIR(out_file);

        out_file.close();
    } catch(std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }    
}