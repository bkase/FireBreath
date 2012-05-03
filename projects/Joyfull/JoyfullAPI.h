/**********************************************************\

  Auto-generated JoyfullAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "Joyfull.h"

#ifndef H_JoyfullAPI
#define H_JoyfullAPI

class JoyfullAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn JoyfullAPI::JoyfullAPI(const JoyfullPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    JoyfullAPI(const JoyfullPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {

        registerMethod("poll",      make_method(this, &JoyfullAPI::poll));

        // Initialization method (takes path as argument)
        registerMethod("init", make_method(this, &JoyfullAPI::init));

        // Read-only property
        registerProperty("version",
                         make_property(this,
                                       &JoyfullAPI::get_version));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn JoyfullAPI::~JoyfullAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~JoyfullAPI() {};

    JoyfullPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    FB::variant poll(const FB::variant& msg);
    FB::variant init(const FB::variant& path);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Event helpers
    FB_JSAPI_EVENT(joystickData, 1, (const FB::variant&));

private:
    JoyfullWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;

    int fd;
};

#endif // H_JoyfullAPI

