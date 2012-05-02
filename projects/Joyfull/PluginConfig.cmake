#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Joyfull
#
#\**********************************************************/

set(PLUGIN_NAME "Joyfull")
set(PLUGIN_PREFIX "JOY")
set(COMPANY_NAME "bkase")

# ActiveX constants:
set(FBTYPELIB_NAME JoyfullLib)
set(FBTYPELIB_DESC "Joyfull 1.0 Type Library")
set(IFBControl_DESC "Joyfull Control Interface")
set(FBControl_DESC "Joyfull Control Class")
set(IFBComJavascriptObject_DESC "Joyfull IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "Joyfull ComJavascriptObject Class")
set(IFBComEventSource_DESC "Joyfull IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 6085c610-c73a-5b54-ab64-e412b57fe65a)
set(IFBControl_GUID 8259b995-de6f-5148-9024-1a97c521b669)
set(FBControl_GUID 1b9c7117-405d-55de-b1f2-1836f36be0df)
set(IFBComJavascriptObject_GUID cea37c79-15a3-5f54-86e5-4bc2a447a6a2)
set(FBComJavascriptObject_GUID 046051b1-0c46-5d3e-b573-fc2cec1dbcfb)
set(IFBComEventSource_GUID 0ef6e7f3-4e7b-53ea-9668-692c3e75361e)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "bkase.Joyfull")
set(MOZILLA_PLUGINID "brandonkase.com/Joyfull")

# strings
set(FBSTRING_CompanyName "bkase")
set(FBSTRING_PluginDescription "Use a Joystick in the browser")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 bkase")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Joyfull")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Joyfull")
set(FBSTRING_MIMEType "application/x-joyfull")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
