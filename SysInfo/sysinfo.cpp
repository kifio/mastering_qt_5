#include "sysinfo.h"
#include <QtGlobal>

#ifdef Q_OS_MAC
    #include "sysinfomacimpl.h"
#else
    #error "Only Mac OS are supported"
#endif

SysInfo& SysInfo::instance()
{
    #ifdef Q_OS_MAC
        static SysInfoMacImpl singleton;
    #else
        #error "Only Mac OS are supported"
    #endif

    return singleton;
}

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}
