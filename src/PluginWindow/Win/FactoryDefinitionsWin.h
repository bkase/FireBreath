/**********************************************************\
Original Author: Richard Bateman (taxilian)

Created:    Oct 19, 2009
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2009 Richard Bateman, Firebreath development team
\**********************************************************/

#ifndef H_FactoryDefinitionsWin
#define H_FactoryDefinitionsWin

#include "Win/win_common.h"

namespace FB {
    class JSAPI;
    class PluginCore;
    class PluginWindowWin;
    namespace Npapi {
        class NpapiPlugin;
        class NpapiBrowserHost;
    };
}

// These global functions *must* be defined in your main plugin project -- that's the one that
// actually builds into a DLL that everything links to.  These are used to determine what
// JSAPI object is used as the root JSAPI, what type of Plugin object to use, etc, as well
// as providing a way for the plugin to find out such information as MIME type, plugin name, etc

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @fn FB::PluginWindowWin *_createPluginWindow(HWND hWnd)
///
/// @brief  Creates a PluginWindowWin derived object and returns it
///
/// @param  hWnd    Handle of the window. 
///
/// @return A ptr to your window 
////////////////////////////////////////////////////////////////////////////////////////////////////
FB::PluginWindowWin *_createPluginWindow(HWND hWnd);

#endif
