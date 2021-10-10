#include "cli_paser.hpp"

using Dims_t = std::vector<std::vector<int>>;

auto main(int argc,char ** argv) -> int {
    CLI::App app{""};
    std::string model_file;
    std::string weights_file;
    std::string build_config;
    Dims_t input_dims;

    app.add_option("-m,--model", model_file, "caffe proto file ")->check(CLI::ExistingFile);
    app.add_option("-w,--weights", weights_file, "caffemodel file ")->check(CLI::ExistingFile);
    app.add_option("-b,--build_config", build_config, "build config file ")->check(CLI::ExistingFile);
    add_option(app, "-i,--input_dims", input_dims,"input dims, one input: 1,3,224,224 two input: 1,3,224,224 1,3,256,256");
    
    CLI11_PARSE(app,argc,argv);
    for(auto dim: input_dims){
        for(auto d:dim){
            std::cout<<d<<",";
        }
        std::cout<<"\n";
    }
}
