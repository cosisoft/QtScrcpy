#include <QtGlobal>

#include "mousetap.h"
#ifdef Q_OS_WIN32
#include "winmousetap.h"
#endif
#ifdef Q_OS_OSX
#include "cocoamousetap.h"
#endif

MouseTap *MouseTap::s_instance = Q_NULLPTR;
MouseTap *MouseTap::getInstance()
{
    if (s_instance == Q_NULLPTR) {
#ifdef Q_OS_WIN32
        s_instance = new WinMouseTap();
#endif
#ifdef Q_OS_OSX
        s_instance = new CocoaMouseTap();
#endif
#ifdef Q_OS_LINUX
        Q_ASSERT(false);
#endif
    }
    return s_instance;
}
