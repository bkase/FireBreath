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


void process_event(struct js_event e) {

    /*printf("time: %lu, value: %d, type: 0x%X, number: 0x%X\n",*/
            /*e.time, e.value, e.type, e.number);*/

    if (IS_BUTTON(e.type) & !IS_INIT(e.type)) {
        printf("Pressed ");
        switch(e.number) {
            case TRIGGER: printf(" TRIGGER %d", e.value); break;
            case DOWN_TOP: printf(" DOWN_TOP %d", e.value); break;
            case UP_TOP: printf(" UP_TOP %d", e.value); break;
            case LEFT_TOP: printf(" LEFT_TOP %d", e.value); break;
            case RIGHT_TOP: printf(" RIGHT_TOP %d", e.value); break;
            case BOT_LEFTUP: printf(" BOT_LEFTUP %d", e.value); break;
            case BOT_LEFTDOWN: printf(" BOT_LEFTDOWN %d", e.value); break;
            case BOT_CENTERLEFT: printf(" BOT_CENTERLEFT %d", e.value); break;
            case BOT_CENTERRIGHT: printf(" BOT_CENTERRIGHT %d", e.value); break;
            case BOT_RIGHTDOWN: printf(" BOT_RIGHTDOWN %d", e.value); break;
            case BOT_RIGHTUP: printf(" BOT_RIGHTUP %d", e.value); break;
            default: printf("Error!"); break;
        }
        printf("\n");
    }
    else if (!IS_BUTTON(e.type) & !IS_INIT(e.type)) {
    
        printf("Analog stick: ");
        switch(e.number) {
            case 0: printf(" X: %d", e.value); break;
            case 1: printf(" Y: %d", e.value); break;
            case 2: printf(" BALL: %d", e.value); break;
            default: printf("Error!"); break;
        }
        printf("\n");
    }

}



///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant JoyfullAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
FB::variant JoyfullAPI::echo(const FB::variant& msg)
{
    static int n(0);
    struct js_event e;
    static int fd(-1);

           // process_event(e);


    
    if (n == 0) {
        fd = open ("/dev/input/js0", O_NONBLOCK);
        n++;
    }
    else {
        char buf[200];
        while (read (fd, &e, sizeof(struct js_event)) > 0) {
            sprintf(buf, "e.value:%d e.type:0x%X e.number:0x%X", e.value, e.type, e.number);
            fire_echo(buf, -2);
        };

        /*EAGAIN is returned when the queue is empty*/
        if (errno != EAGAIN) {
            fire_echo("So far, you clicked this many times(error): ", errno);
            return msg;
        }

        return msg;
    }
    fire_echo("So far, you clicked this many times: ", -1);

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

void JoyfullAPI::testEvent()
{
    fire_test();
}
