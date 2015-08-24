To install the plugin you should:
  1. Download the binaries for your operating system at http://code.google.com/p/killmsg/downloads/list
  1. Unpack them in a folder, all together.
  1. Add -loadplugin /path/to/plugin.so,1 on **nix(-like) operating systems or -loadplugin C:/path/to/plugin.dll,1 on Windows to your configuration file. Change the path so that it matches the path of the plugin .so or .dll file.
  1. If your server is up, type /loadplugin /path/to/plugin.so,1 . Be sure to change the path so that it matches the path of the plugin .so or .dll file.**

**IMPORTANT**: Don't erase the ",1" option! If your config file however has the "-tk" option and you don't get dead if you teamkill, replace it with ",0"!