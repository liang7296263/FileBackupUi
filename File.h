#pragma once
#include <string>
#include <string.h>
#include <cstdint>
#include <QString>
struct FileInformation
{
    std::uint64_t filesize; // 文件大小
    char filename[256];     // 文件名
};
