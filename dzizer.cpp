#include <vips/vips8>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
//input — image to convert to dzi
//output — name(without path) of output file. DZI extension is xml dzi file and folder with tiles,
//the will have this name
//saveDir — directory to save the dzi to. not necessary to exist
//containerDir — directory with all files. If "" files will be saved in saveDir
bool build(std::string input, std::string output, std::string saveDir, std::string containerDir){
    //Making all paths
    std::string savePath = saveDir;
    if (savePath[savePath.length() - 1] != '/') savePath += "/";
    if (containerDir != "" ) savePath += containerDir + "/";
    fs::create_directories(savePath);

    std::string dzFile = savePath + output;
    //Cleaning <output>_files folder because it must contain only tiles
    fs::remove_all(dzFile + "_files");
    //std::string thumbnail = savePath + output + ".jpg";

    try{
        vips::VImage image = vips::VImage::new_from_file(input.c_str());
        //Possible definitions for "depth" option: https://www.libvips.org/API/8.6/VipsForeignSave.html#VipsForeignDzDepth
        image.dzsave(dzFile.c_str(), vips::VImage::option()->set("depth", VIPS_FOREIGN_DZ_DEPTH_ONEPIXEL));
        /*Thumbnail if needed
        int maxLength = std::max(image.width(), image.height());
        image.resize(180.0/maxLength).jpegsave(thumbnail.c_str());*/
        return true;
    }catch(const vips::VError& e){
        std::cerr << e.what();
    }
    return false;
}

bool build(std::string input, std::string output, std::string saveDir){
    return build(input, output, saveDir, "");
}

int main(int argc, char **argv) {
    if (VIPS_INIT(argv[0])) vips_error_exit(nullptr);
    if (argc < 4) {
        std::cout << "Not enough arguements" << std::endl;
        return 1;
    }
    if (argc == 4) return (build(argv[1], argv[2], argv[3]) ? 0 : 1);
    else return (build(argv[1], argv[2], argv[3], argv[4]) ? 0 : 1);
}
