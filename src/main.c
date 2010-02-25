/* main.c generated by valac, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <gst/gst.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dbus/dbus.h>

#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _dbus_g_connection_unref0(var) ((var == NULL) ? NULL : (var = (dbus_g_connection_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_FACTORY (factory_get_type ())
#define FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FACTORY, Factory))
#define FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FACTORY, FactoryClass))
#define IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FACTORY))
#define IS_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FACTORY))
#define FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FACTORY, FactoryClass))

typedef struct _Factory Factory;
typedef struct _FactoryClass FactoryClass;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _DBusObjectVTable _DBusObjectVTable;

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};


extern GMainLoop* loop;
GMainLoop* loop = NULL;
extern DBusGConnection* conn;
DBusGConnection* conn = NULL;

static guint _dynamic_request_name0 (DBusGProxy* self, const char* param1, guint param2, GError** error);
Factory* factory_new (void);
Factory* factory_construct (GType object_type);
GType factory_get_type (void);
void _main (char** args, int args_length1);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);



static guint _dynamic_request_name0 (DBusGProxy* self, const char* param1, guint param2, GError** error) {
	guint result;
	dbus_g_proxy_call (self, "RequestName", error, G_TYPE_STRING, param1, G_TYPE_UINT, param2, G_TYPE_INVALID, G_TYPE_UINT, &result, G_TYPE_INVALID);
	if (*error) {
		return 0U;
	}
	return result;
}


void _main (char** args, int args_length1) {
	GError * _inner_error_;
	GMainLoop* _tmp0_;
	_inner_error_ = NULL;
	gst_init (&args_length1, &args);
	loop = (_tmp0_ = g_main_loop_new (NULL, FALSE), _g_main_loop_unref0 (loop), _tmp0_);
	{
		DBusGConnection* _tmp1_;
		DBusGConnection* _tmp2_;
		DBusGProxy* bus;
		guint request_name_result;
		_tmp1_ = dbus_g_bus_get (DBUS_BUS_SYSTEM, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
			goto __finally0;
		}
		conn = (_tmp2_ = _tmp1_, _dbus_g_connection_unref0 (conn), _tmp2_);
		bus = dbus_g_proxy_new_for_name (conn, "org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus");
		request_name_result = _dynamic_request_name0 (bus, "com.ridgerun.gstreamer.gstd", (guint) 0, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (bus);
			goto __catch0_g_error;
			goto __finally0;
		}
		if (request_name_result == DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
			Factory* factory;
			factory = factory_new ();
			_vala_dbus_register_object (dbus_g_connection_get_connection (conn), "/com/ridgerun/gstreamer/gstd/factory", (GObject*) factory);
			g_main_loop_run (loop);
			_g_object_unref0 (factory);
		} else {
			fprintf (stderr, "%s", "Gstd: Failed to obtain primary ownership of " "the service\n");
			fprintf (stderr, "%s", "Gstd: This usually means there is another instance of " "gstd already running\n");
		}
		_g_object_unref0 (bus);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			fprintf (stderr, "Gstd: Error: %s\n", e->message);
			_g_error_free0 (e);
		}
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


int main (int argc, char ** argv) {
	g_type_init ();
	_main (argv, argc);
	return 0;
}


static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	const _DBusObjectVTable * vtable;
	vtable = g_type_get_qdata (G_TYPE_FROM_INSTANCE (object), g_quark_from_static_string ("DBusObjectVTable"));
	if (vtable) {
		vtable->register_object (connection, path, object);
	} else {
		g_warning ("Object does not implement any D-Bus interface");
	}
}


static void _vala_dbus_unregister_object (gpointer connection, GObject* object) {
	char* path;
	path = g_object_steal_data ((GObject*) object, "dbus_object_path");
	dbus_connection_unregister_object_path (connection, path);
	g_free (path);
}




