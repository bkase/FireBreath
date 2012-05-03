/**********************************************************\

  Auto-generated JoyfullAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/joystick.h>
#include <errno.h>
#include <stropts.h>

#define IS_BUTTON(type) ((type) & 0x1)
#define IS_INIT(type) (((type) >> 0x7) & 0x1)

//The 11 Buttons
#define TRIGGER 0x0
#define DOWN_TOP 0x1
#define UP_TOP 0x2
#define LEFT_TOP 0x3
#define RIGHT_TOP 0x4
#define BOT_LEFTUP 0x5
#define BOT_LEFTDOWN 0x6
#define BOT_CENTERLEFT 0x7
#define BOT_CENTERRIGHT 0x8
#define BOT_RIGHTDOWN 0x9
#define BOT_RIGHTUP 0xA



#include "JoyfullAPI.h"


FB::variant process_event(struct js_event e) {

    /*printf("time: %lu, value: %d, type: 0x%X, number: 0x%X\n",*/
            /*e.time, e.value, e.type, e.number);*/

    std::map<std::string, FB::variant> joyObj;

    if (IS_BUTTON(e.type) & !IS_INIT(e.type)) {
        std::string buf;
        switch(e.number) {
            case TRIGGER: buf = "trigger"; break;
            case DOWN_TOP: buf = "down_top"; break;
            case UP_TOP: buf = "up_top"; break;
            case LEFT_TOP: buf = "left_top"; break;
            case RIGHT_TOP: buf = "right_top"; break;
            case BOT_LEFTUP: buf = "leftup_bot"; break;
            case BOT_LEFTDOWN: buf = "leftdown_bot"; break;
            case BOT_CENTERLEFT: buf = "centerleft_bot"; break;
            case BOT_CENTERRIGHT: buf = "centerright_bot"; break;
            case BOT_RIGHTDOWN: buf = "rightdown_bot"; break;
            case BOT_RIGHTUP: buf = "rightup_bot"; break;
            default: printf("Error!"); break;
        }
        joyObj["button_type"] = buf;
    }
    else if (!IS_BUTTON(e.type) & !IS_INIT(e.type)) {
    
        std::string buf;
        switch(e.number) {
            case 0: buf = "analog_x"; break;
            case 1: buf = "analog_y"; break;
            case 2: buf = "analog_ball"; break;
            default: printf("Error!"); break;
        }
        joyObj["button_type"] = buf;
    }
    joyObj["button_value"] = e.value;

    return joyObj;
}


FB::variant JoyfullAPI::init(const FB::variant& path) {
    
    //printf("Path: %s\n", path.cast<std::string>().c_str());
    fd = open (path.cast<std::string>().c_str(), O_NONBLOCK);
    if (fd == -1)
        return false;
    else
        return true;
}

///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant JoyfullAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
FB::variant JoyfullAPI::poll(const FB::variant& msg)
{
    struct js_event e;

    // process_event(e);

    char buf[200];
    while (read (fd, &e, sizeof(struct js_event)) > 0) {
        sprintf(buf, "e.value:%d e.type:0x%X e.number:0x%X ", e.value, e.type, e.number);
        fire_joystickData(process_event(e));
    };

    /*EAGAIN is returned when the queue is empty*/
    if (errno != EAGAIN) {
        fire_joystickData("Error!");
        return msg;
    }

    // return "foobar";
    return msg;
}

///////////////////////////////////////////////////////////////////////////////
/// @fn JoyfullPtr JoyfullAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
JoyfullPtr JoyfullAPI::getPlugin()
{
    JoyfullPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

// Read/Write property testString
std::string JoyfullAPI::get_testString()
{
    return m_testString;
}

void JoyfullAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string JoyfullAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}

