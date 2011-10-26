lib_LTLIBRARIES = killmsg.la

killmsg_la_SOURCES = killmsg.cpp
killmsg_la_CXXFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
killmsg_la_LDFLAGS = -module -avoid-version -shared
killmsg_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

EXTRA_DIST = \
	README.txt \
	killmsg.def \
	killmsg.sln \
	killmsg.vcproj

MAINTAINERCLEANFILES =	\
	Makefile.in
