  1. Go to the plugins directory and run ` svn checkout http://killmsg.googlecode.com/svn/trunk/ killmsg `
  1. Edit the Makefile.am and add a line for the killmsg folder, do the same to ../configure.ac
  1. On the base bzflag source folder, run
```
 ./autogen.sh
 ./configure --enable-shared --disable-client
 make
 sudo make install
```
  1. Add `-loadplugin /path/to/plugin.so,1` to your server configuration file. Change the path so that it matches the path of the plugin .so file.
  1. If your server is up, type `/loadplugin /path/to/plugin.so,1`. Be sure to change the path so that it matches the path of the plugin .so file.

**IMPORTANT**: Don't erase the `,1` option! If your config file however has the `-tk` option and you don't get dead if you teamkill, replace it with `,0`!