  1. Go to the plugins directory and run `git clone https://github.com/kongr45gpen/killmsg.git`
  2. On the base bzflag source folder, run
```
 ./autogen.sh
 ./configure --disable-client --enable-custom-plugins=killmsg
 make
 sudo make install
```
  3. Add `-loadplugin killmsg,1` to your server configuration file. Change the path so that it matches the path of the plugin .so file.
  4. If your server is up, type `/loadplugin killmsg,1`. Be sure to change the path so that it matches the path of the plugin .so file.

**IMPORTANT**: Don't erase the `,1` option! If your config file however has the `-tk` option and you don't get dead if you teamkill, replace it with `,0`!
