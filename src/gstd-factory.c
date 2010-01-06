/* gstd-factory.c generated by valac, the Vala compiler
 * generated from gstd-factory.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <stdio.h>
#include <dbus/dbus.h>


#define TYPE_FACTORY (factory_get_type ())
#define FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FACTORY, Factory))
#define FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FACTORY, FactoryClass))
#define IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FACTORY))
#define IS_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FACTORY))
#define FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FACTORY, FactoryClass))

typedef struct _Factory Factory;
typedef struct _FactoryClass FactoryClass;
typedef struct _FactoryPrivate FactoryPrivate;

#define TYPE_PIPELINE (pipeline_get_type ())
#define PIPELINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PIPELINE, Pipeline))
#define PIPELINE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PIPELINE, PipelineClass))
#define IS_PIPELINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PIPELINE))
#define IS_PIPELINE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PIPELINE))
#define PIPELINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PIPELINE, PipelineClass))

typedef struct _Pipeline Pipeline;
typedef struct _PipelineClass PipelineClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DBusObjectVTable _DBusObjectVTable;

struct _Factory {
	GObject parent_instance;
	FactoryPrivate * priv;
};

struct _FactoryClass {
	GObjectClass parent_class;
};

struct _FactoryPrivate {
	gint next_id;
	Pipeline** pipes;
	gint pipes_length1;
	gint pipes_size;
};

struct _DBusObjectVTable {
	void (*register_object) (DBusConnection*, const char*, void*);
};


extern DBusGConnection* conn;
static gpointer factory_parent_class = NULL;

GType factory_get_type (void);
GType pipeline_get_type (void);
#define FACTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_FACTORY, FactoryPrivate))
enum  {
	FACTORY_DUMMY_PROPERTY
};
Factory* factory_new (void);
Factory* factory_construct (GType object_type);
Pipeline* pipeline_new (const char* description);
Pipeline* pipeline_construct (GType object_type, const char* description);
char* factory_Create (Factory* self, const char* description);
gboolean factory_Destroy (Factory* self, const char* objectpath);
void factory_dbus_register_object (DBusConnection* connection, const char* path, void* object);
void _factory_dbus_unregister (DBusConnection* connection, void* _user_data_);
DBusHandlerResult factory_dbus_message (DBusConnection* connection, DBusMessage* message, void* object);
static DBusHandlerResult _dbus_factory_introspect (Factory* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_factory_property_get_all (Factory* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_factory_Create (Factory* self, DBusConnection* connection, DBusMessage* message);
static DBusHandlerResult _dbus_factory_Destroy (Factory* self, DBusConnection* connection, DBusMessage* message);
static void factory_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_dbus_register_object (DBusConnection* connection, const char* path, void* object);
static void _vala_dbus_unregister_object (gpointer connection, GObject* object);

static const DBusObjectPathVTable _factory_dbus_path_vtable = {_factory_dbus_unregister, factory_dbus_message};
static const _DBusObjectVTable _factory_dbus_vtable = {factory_dbus_register_object};


Factory* factory_construct (GType object_type) {
	Factory * self;
	Pipeline** _tmp0_;
	self = (Factory*) g_object_new (object_type, NULL);
	self->priv->next_id = 0;
	self->priv->pipes = (_tmp0_ = g_new0 (Pipeline*, 20 + 1), self->priv->pipes = (_vala_array_free (self->priv->pipes, self->priv->pipes_length1, (GDestroyNotify) g_object_unref), NULL), self->priv->pipes_length1 = 20, self->priv->pipes_size = self->priv->pipes_length1, _tmp0_);
	{
		gint ids;
		ids = 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				Pipeline* _tmp2_;
				if (!_tmp1_) {
					ids++;
				}
				_tmp1_ = FALSE;
				if (!(ids < 20)) {
					break;
				}
				self->priv->pipes[ids] = (_tmp2_ = NULL, _g_object_unref0 (self->priv->pipes[ids]), _tmp2_);
			}
		}
	}
	return self;
}


Factory* factory_new (void) {
	return factory_construct (TYPE_FACTORY);
}


char* factory_Create (Factory* self, const char* description) {
	char* result;
	Pipeline* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (description != NULL, NULL);
	while (TRUE) {
		if (!(self->priv->pipes[self->priv->next_id] != NULL)) {
			break;
		}
		self->priv->next_id = (self->priv->next_id++) % 20;
	}
	self->priv->pipes[self->priv->next_id] = (_tmp0_ = pipeline_new (description), _g_object_unref0 (self->priv->pipes[self->priv->next_id]), _tmp0_);
	if (IS_PIPELINE (self->priv->pipes[self->priv->next_id])) {
		char* _tmp1_;
		char* _tmp2_;
		char* objectpath;
		objectpath = (_tmp2_ = g_strconcat ("/com/ridgerun/gstreamer/gstd/pipe", _tmp1_ = g_strdup_printf ("%i", self->priv->next_id), NULL), _g_free0 (_tmp1_), _tmp2_);
		_vala_dbus_register_object (dbus_g_connection_get_connection (conn), objectpath, (GObject*) self->priv->pipes[self->priv->next_id]);
		self->priv->next_id++;
		result = objectpath;
		return result;
	}
	result = g_strdup ("");
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gboolean factory_Destroy (Factory* self, const char* objectpath) {
	gboolean result;
	GObject* pipeline;
	gint id;
	GObject* _tmp0_;
	Pipeline* _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (objectpath != NULL, FALSE);
	pipeline = NULL;
	id = 0;
	pipeline = (_tmp0_ = _g_object_ref0 (dbus_g_connection_lookup_g_object (conn, objectpath)), _g_object_unref0 (pipeline), _tmp0_);
	while (TRUE) {
		if (!(G_OBJECT (self->priv->pipes[id]) != pipeline)) {
			break;
		}
		id = (id++) % 20;
		fprintf (stdout, "Searching pipe %d\n", id);
	}
	self->priv->pipes[id] = (_tmp1_ = NULL, _g_object_unref0 (self->priv->pipes[id]), _tmp1_);
	result = TRUE;
	_g_object_unref0 (pipeline);
	return result;
}


void _factory_dbus_unregister (DBusConnection* connection, void* _user_data_) {
}


static DBusHandlerResult _dbus_factory_introspect (Factory* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter;
	GString* xml_data;
	char** children;
	int i;
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	xml_data = g_string_new ("<!DOCTYPE node PUBLIC \"-//freedesktop//DTD D-BUS Object Introspection 1.0//EN\" \"http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd\">\n");
	g_string_append (xml_data, "<node>\n<interface name=\"org.freedesktop.DBus.Introspectable\">\n  <method name=\"Introspect\">\n    <arg name=\"data\" direction=\"out\" type=\"s\"/>\n  </method>\n</interface>\n<interface name=\"org.freedesktop.DBus.Properties\">\n  <method name=\"Get\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"out\" type=\"v\"/>\n  </method>\n  <method name=\"Set\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"propname\" direction=\"in\" type=\"s\"/>\n    <arg name=\"value\" direction=\"in\" type=\"v\"/>\n  </method>\n  <method name=\"GetAll\">\n    <arg name=\"interface\" direction=\"in\" type=\"s\"/>\n    <arg name=\"props\" direction=\"out\" type=\"a{sv}\"/>\n  </method>\n</interface>\n<interface name=\"com.ridgerun.gstreamer.gstd.FactoryInterface\">\n  <method name=\"Create\">\n    <arg name=\"description\" type=\"s\" direction=\"in\"/>\n    <arg name=\"result\" type=\"s\" direction=\"out\"/>\n  </method>\n  <method name=\"Destroy\">\n    <arg name=\"objectpath\" type=\"s\" direction=\"in\"/>\n    <arg name=\"result\" type=\"b\" direction=\"out\"/>\n  </method>\n</interface>\n");
	dbus_connection_list_registered (connection, g_object_get_data ((GObject *) self, "dbus_object_path"), &children);
	for (i = 0; children[i]; i++) {
		g_string_append_printf (xml_data, "<node name=\"%s\"/>\n", children[i]);
	}
	dbus_free_string_array (children);
	g_string_append (xml_data, "</node>\n");
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &xml_data->str);
	g_string_free (xml_data, TRUE);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_factory_property_get_all (Factory* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessage* reply;
	DBusMessageIter iter, reply_iter, subiter;
	char* interface_name;
	const char* _tmp0_;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &reply_iter);
	dbus_message_iter_get_basic (&iter, &_tmp0_);
	dbus_message_iter_next (&iter);
	interface_name = g_strdup (_tmp0_);
	if (strcmp (interface_name, "com.ridgerun.gstreamer.gstd.FactoryInterface") == 0) {
		dbus_message_iter_open_container (&reply_iter, DBUS_TYPE_ARRAY, "{sv}", &subiter);
		dbus_message_iter_close_container (&reply_iter, &subiter);
	} else {
		dbus_message_unref (reply);
		reply = NULL;
	}
	g_free (interface_name);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_factory_Create (Factory* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	char* description;
	const char* _tmp1_;
	char* result;
	DBusMessage* reply;
	const char* _tmp2_;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	description = NULL;
	dbus_message_iter_get_basic (&iter, &_tmp1_);
	dbus_message_iter_next (&iter);
	description = g_strdup (_tmp1_);
	result = factory_Create (self, description);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_g_free0 (description);
	_tmp2_ = result;
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_STRING, &_tmp2_);
	_g_free0 (result);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


static DBusHandlerResult _dbus_factory_Destroy (Factory* self, DBusConnection* connection, DBusMessage* message) {
	DBusMessageIter iter;
	GError* error;
	char* objectpath;
	const char* _tmp3_;
	gboolean result;
	DBusMessage* reply;
	dbus_bool_t _tmp4_;
	error = NULL;
	if (strcmp (dbus_message_get_signature (message), "s")) {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
	dbus_message_iter_init (message, &iter);
	objectpath = NULL;
	dbus_message_iter_get_basic (&iter, &_tmp3_);
	dbus_message_iter_next (&iter);
	objectpath = g_strdup (_tmp3_);
	result = factory_Destroy (self, objectpath);
	reply = dbus_message_new_method_return (message);
	dbus_message_iter_init_append (reply, &iter);
	_g_free0 (objectpath);
	_tmp4_ = result;
	dbus_message_iter_append_basic (&iter, DBUS_TYPE_BOOLEAN, &_tmp4_);
	if (reply) {
		dbus_connection_send (connection, reply, NULL);
		dbus_message_unref (reply);
		return DBUS_HANDLER_RESULT_HANDLED;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


DBusHandlerResult factory_dbus_message (DBusConnection* connection, DBusMessage* message, void* object) {
	DBusHandlerResult result;
	result = DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Introspectable", "Introspect")) {
		result = _dbus_factory_introspect (object, connection, message);
	} else if (dbus_message_is_method_call (message, "org.freedesktop.DBus.Properties", "GetAll")) {
		result = _dbus_factory_property_get_all (object, connection, message);
	} else if (dbus_message_is_method_call (message, "com.ridgerun.gstreamer.gstd.FactoryInterface", "Create")) {
		result = _dbus_factory_Create (object, connection, message);
	} else if (dbus_message_is_method_call (message, "com.ridgerun.gstreamer.gstd.FactoryInterface", "Destroy")) {
		result = _dbus_factory_Destroy (object, connection, message);
	}
	if (result == DBUS_HANDLER_RESULT_HANDLED) {
		return result;
	} else {
		return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
	}
}


void factory_dbus_register_object (DBusConnection* connection, const char* path, void* object) {
	if (!g_object_get_data (object, "dbus_object_path")) {
		g_object_set_data (object, "dbus_object_path", g_strdup (path));
		dbus_connection_register_object_path (connection, path, &_factory_dbus_path_vtable, object);
		g_object_weak_ref (object, _vala_dbus_unregister_object, connection);
	}
}


static void factory_class_init (FactoryClass * klass) {
	factory_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FactoryPrivate));
	G_OBJECT_CLASS (klass)->finalize = factory_finalize;
	g_type_set_qdata (TYPE_FACTORY, g_quark_from_static_string ("DBusObjectVTable"), (void*) (&_factory_dbus_vtable));
}


static void factory_instance_init (Factory * self) {
	self->priv = FACTORY_GET_PRIVATE (self);
}


static void factory_finalize (GObject* obj) {
	Factory * self;
	self = FACTORY (obj);
	self->priv->pipes = (_vala_array_free (self->priv->pipes, self->priv->pipes_length1, (GDestroyNotify) g_object_unref), NULL);
	G_OBJECT_CLASS (factory_parent_class)->finalize (obj);
}


GType factory_get_type (void) {
	static GType factory_type_id = 0;
	if (factory_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (FactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Factory), 0, (GInstanceInitFunc) factory_instance_init, NULL };
		factory_type_id = g_type_register_static (G_TYPE_OBJECT, "Factory", &g_define_type_info, 0);
	}
	return factory_type_id;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
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




