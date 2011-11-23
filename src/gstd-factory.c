/* gstd-factory.c generated by valac 0.14.0, the Vala compiler
 * generated from gstd-factory.vala, do not modify */

/*
 * gstd/src/gstd-factory.vala
 *
 * GStreamer daemon pipeline Factory class - framework for controlling audio and video streaming using D-Bus messages
 *
 * Copyright (c) 2010, RidgeRun
 * All rights reserved.
 *
 * GPL2 license - See http://www.opensource.org/licenses/gpl-2.0.php for complete text.
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <syslog.h>


#define GSTD_TYPE_FACTORY_INTERFACE (gstd_factory_interface_get_type ())
#define GSTD_FACTORY_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSTD_TYPE_FACTORY_INTERFACE, gstdFactoryInterface))
#define GSTD_IS_FACTORY_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSTD_TYPE_FACTORY_INTERFACE))
#define GSTD_FACTORY_INTERFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), GSTD_TYPE_FACTORY_INTERFACE, gstdFactoryInterfaceIface))

typedef struct _gstdFactoryInterface gstdFactoryInterface;
typedef struct _gstdFactoryInterfaceIface gstdFactoryInterfaceIface;

#define GSTD_TYPE_FACTORY_INTERFACE_PROXY (gstd_factory_interface_proxy_get_type ())

#define GSTD_TYPE_FACTORY (gstd_factory_get_type ())
#define GSTD_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSTD_TYPE_FACTORY, gstdFactory))
#define GSTD_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GSTD_TYPE_FACTORY, gstdFactoryClass))
#define GSTD_IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSTD_TYPE_FACTORY))
#define GSTD_IS_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GSTD_TYPE_FACTORY))
#define GSTD_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GSTD_TYPE_FACTORY, gstdFactoryClass))

typedef struct _gstdFactory gstdFactory;
typedef struct _gstdFactoryClass gstdFactoryClass;
typedef struct _gstdFactoryPrivate gstdFactoryPrivate;

#define GSTD_TYPE_PIPELINE_INTERFACE (gstd_pipeline_interface_get_type ())
#define GSTD_PIPELINE_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSTD_TYPE_PIPELINE_INTERFACE, gstdPipelineInterface))
#define GSTD_IS_PIPELINE_INTERFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSTD_TYPE_PIPELINE_INTERFACE))
#define GSTD_PIPELINE_INTERFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), GSTD_TYPE_PIPELINE_INTERFACE, gstdPipelineInterfaceIface))

typedef struct _gstdPipelineInterface gstdPipelineInterface;
typedef struct _gstdPipelineInterfaceIface gstdPipelineInterfaceIface;

#define GSTD_TYPE_PIPELINE_INTERFACE_PROXY (gstd_pipeline_interface_proxy_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define GSTD_TYPE_PIPELINE (gstd_pipeline_get_type ())
#define GSTD_PIPELINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GSTD_TYPE_PIPELINE, gstdPipeline))
#define GSTD_PIPELINE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GSTD_TYPE_PIPELINE, gstdPipelineClass))
#define GSTD_IS_PIPELINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GSTD_TYPE_PIPELINE))
#define GSTD_IS_PIPELINE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GSTD_TYPE_PIPELINE))
#define GSTD_PIPELINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GSTD_TYPE_PIPELINE, gstdPipelineClass))

typedef struct _gstdPipeline gstdPipeline;
typedef struct _gstdPipelineClass gstdPipelineClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _gstdFactoryInterfaceIface {
	GTypeInterface parent_iface;
	gchar* (*create) (gstdFactoryInterface* self, const gchar* description, GError** error);
	gboolean (*destroy) (gstdFactoryInterface* self, const gchar* path, GError** error);
	gboolean (*destroy_all) (gstdFactoryInterface* self, GError** error);
	gchar** (*list) (gstdFactoryInterface* self, int* result_length1, GError** error);
	gboolean (*ping) (gstdFactoryInterface* self, GError** error);
};

struct _gstdFactory {
	GObject parent_instance;
	gstdFactoryPrivate * priv;
};

struct _gstdFactoryClass {
	GObjectClass parent_class;
};

struct _gstdPipelineInterfaceIface {
	GTypeInterface parent_iface;
	void (*pipeline_set_id) (gstdPipelineInterface* self, guint64 id, GError** error);
	guint64 (*pipeline_get_id) (gstdPipelineInterface* self, GError** error);
	gboolean (*pipeline_set_state) (gstdPipelineInterface* self, gint state, GError** error);
	void (*pipeline_async_set_state) (gstdPipelineInterface* self, gint state, GError** error);
	gboolean (*element_set_property_boolean) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gboolean val, GError** error);
	gboolean (*element_set_property_int) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gint val, GError** error);
	gboolean (*element_set_property_int64) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gint64 val, GError** error);
	gboolean (*element_set_property_string) (gstdPipelineInterface* self, const gchar* element, const gchar* property, const gchar* val, GError** error);
	void (*element_get_property_boolean) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gboolean* val, gboolean* success, GError** error);
	void (*element_get_property_int) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gint* val, gboolean* success, GError** error);
	void (*element_get_property_int64) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gint64* val, gboolean* success, GError** error);
	void (*element_get_property_string) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gchar** val, gboolean* success, GError** error);
	void (*element_get_property_buffer) (gstdPipelineInterface* self, const gchar* element, const gchar* property, gchar** caps, guint8** data, int* data_length1, gboolean* success, GError** error);
	gint64 (*pipeline_get_duration) (gstdPipelineInterface* self, GError** error);
	gint64 (*pipeline_get_position) (gstdPipelineInterface* self, GError** error);
	gboolean (*pipeline_speed) (gstdPipelineInterface* self, gdouble newrate, GError** error);
	gboolean (*pipeline_skip) (gstdPipelineInterface* self, gint64 period_ns, GError** error);
	gboolean (*pipeline_seek) (gstdPipelineInterface* self, gint64 ipos_ns, GError** error);
	void (*pipeline_step) (gstdPipelineInterface* self, guint64 frames, GError** error);
	void (*pipeline_async_seek) (gstdPipelineInterface* self, gint64 ipos_ns, GError** error);
	gint (*pipeline_get_state) (gstdPipelineInterface* self, GError** error);
	gint (*element_get_state) (gstdPipelineInterface* self, const gchar* element, GError** error);
	void (*pipeline_send_eos) (gstdPipelineInterface* self, GError** error);
	gboolean (*pipeline_send_custom_event) (gstdPipelineInterface* self, const gchar* type, const gchar* name, GError** error);
	void (*set_window_id) (gstdPipelineInterface* self, guint64 winId, GError** error);
	gboolean (*ping) (gstdPipelineInterface* self, GError** error);
	gboolean (*element_set_state) (gstdPipelineInterface* self, const gchar* element, gint state, GError** error);
	void (*element_async_set_state) (gstdPipelineInterface* self, const gchar* element, gint state, GError** error);
};

struct _gstdFactoryPrivate {
	GDBusConnection* conn;
	gstdPipelineInterface** pipes;
	gint pipes_length1;
	gint _pipes_size_;
};


static gpointer gstd_factory_parent_class = NULL;
static gstdFactoryInterfaceIface* gstd_factory_gstd_factory_interface_parent_iface = NULL;

GType gstd_factory_interface_proxy_get_type (void) G_GNUC_CONST;
guint gstd_factory_interface_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
GType gstd_factory_interface_get_type (void) G_GNUC_CONST;
GType gstd_factory_get_type (void) G_GNUC_CONST;
GType gstd_pipeline_interface_proxy_get_type (void) G_GNUC_CONST;
guint gstd_pipeline_interface_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
GType gstd_pipeline_interface_get_type (void) G_GNUC_CONST;
#define GSTD_FACTORY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GSTD_TYPE_FACTORY, gstdFactoryPrivate))
enum  {
	GSTD_FACTORY_DUMMY_PROPERTY
};
#define GSTD_FACTORY_num_pipes 20
gstdFactory* gstd_factory_new (GDBusConnection* conn);
gstdFactory* gstd_factory_construct (GType object_type, GDBusConnection* conn);
static gchar* gstd_factory_real_create (gstdFactoryInterface* base, const gchar* description, GError** error);
gstdPipeline* gstd_pipeline_new (const gchar* description);
gstdPipeline* gstd_pipeline_construct (GType object_type, const gchar* description);
GType gstd_pipeline_get_type (void) G_GNUC_CONST;
gboolean gstd_pipeline_pipeline_is_initialized (gstdPipeline* self);
gboolean gstd_pipeline_pipeline_set_path (gstdPipeline* self, const gchar* dbuspath);
static gboolean gstd_factory_real_destroy (gstdFactoryInterface* base, const gchar* objectpath, GError** error);
gchar* gstd_pipeline_pipeline_get_path (gstdPipeline* self);
static gboolean gstd_factory_real_destroy_all (gstdFactoryInterface* base, GError** error);
static gchar** gstd_factory_real_list (gstdFactoryInterface* base, int* result_length1, GError** error);
static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value);
static gboolean gstd_factory_real_ping (gstdFactoryInterface* base, GError** error);
static void gstd_factory_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


/**
   Create a new instance of a factory server to process D-Bus
   factory messages
 */
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


gstdFactory* gstd_factory_construct (GType object_type, GDBusConnection* conn) {
	gstdFactory * self = NULL;
	GDBusConnection* _tmp0_;
	GDBusConnection* _tmp1_;
	gstdPipelineInterface** _tmp2_ = NULL;
	g_return_val_if_fail (conn != NULL, NULL);
	self = (gstdFactory*) g_object_new (object_type, NULL);
	_tmp0_ = conn;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->conn);
	self->priv->conn = _tmp1_;
	_tmp2_ = g_new0 (gstdPipelineInterface*, GSTD_FACTORY_num_pipes + 1);
	self->priv->pipes = (_vala_array_free (self->priv->pipes, self->priv->pipes_length1, (GDestroyNotify) g_object_unref), NULL);
	self->priv->pipes = _tmp2_;
	self->priv->pipes_length1 = GSTD_FACTORY_num_pipes;
	self->priv->_pipes_size_ = self->priv->pipes_length1;
	{
		gint ids;
		ids = 0;
		{
			gboolean _tmp3_;
			_tmp3_ = TRUE;
			while (TRUE) {
				gboolean _tmp4_;
				gint _tmp6_;
				gstdPipelineInterface** _tmp7_;
				gint _tmp7__length1;
				gstdPipelineInterface** _tmp8_;
				gint _tmp8__length1;
				gint _tmp9_;
				gstdPipelineInterface* _tmp10_;
				_tmp4_ = _tmp3_;
				if (!_tmp4_) {
					gint _tmp5_;
					_tmp5_ = ids;
					ids = _tmp5_ + 1;
				}
				_tmp3_ = FALSE;
				_tmp6_ = ids;
				_tmp7_ = self->priv->pipes;
				_tmp7__length1 = self->priv->pipes_length1;
				if (!(_tmp6_ < _tmp7__length1)) {
					break;
				}
				_tmp8_ = self->priv->pipes;
				_tmp8__length1 = self->priv->pipes_length1;
				_tmp9_ = ids;
				_g_object_unref0 (_tmp8_[_tmp9_]);
				_tmp8_[_tmp9_] = NULL;
				_tmp10_ = _tmp8_[_tmp9_];
			}
		}
	}
	return self;
}


gstdFactory* gstd_factory_new (GDBusConnection* conn) {
	return gstd_factory_construct (GSTD_TYPE_FACTORY, conn);
}


/**
   Creates a pipeline from a gst-launch like description using or not
   debug information
   @param description, gst-launch like description of the pipeline
   @param debug, flag to enable debug information
   @return the dbus-path of the pipeline, or null if out of resources
 */
static gchar* gstd_factory_real_create (gstdFactoryInterface* base, const gchar* description, GError** error) {
	gstdFactory * self;
	gchar* result = NULL;
	GError * _inner_error_ = NULL;
	self = (gstdFactory*) base;
	g_return_val_if_fail (description != NULL, NULL);
	{
		gint next_id;
		gstdPipelineInterface** _tmp7_;
		gint _tmp7__length1;
		gint _tmp8_;
		const gchar* _tmp9_;
		gstdPipeline* _tmp10_;
		gstdPipelineInterface* _tmp11_;
		gstdPipelineInterface** _tmp12_;
		gint _tmp12__length1;
		gint _tmp13_;
		gstdPipelineInterface* _tmp14_;
		gboolean _tmp15_ = FALSE;
		gint _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* _tmp22_;
		gchar* _tmp23_;
		gchar* _tmp24_;
		gchar* objectpath;
		GDBusConnection* _tmp25_;
		const gchar* _tmp26_;
		gstdPipelineInterface** _tmp27_;
		gint _tmp27__length1;
		gint _tmp28_;
		gstdPipelineInterface* _tmp29_;
		gstdPipelineInterface** _tmp30_;
		gint _tmp30__length1;
		gint _tmp31_;
		gstdPipelineInterface* _tmp32_;
		const gchar* _tmp33_;
		next_id = 0;
		while (TRUE) {
			gstdPipelineInterface** _tmp0_;
			gint _tmp0__length1;
			gint _tmp1_;
			gstdPipelineInterface* _tmp2_;
			gint _tmp3_;
			gstdPipelineInterface** _tmp4_;
			gint _tmp4__length1;
			gint _tmp5_;
			_tmp0_ = self->priv->pipes;
			_tmp0__length1 = self->priv->pipes_length1;
			_tmp1_ = next_id;
			_tmp2_ = _tmp0_[_tmp1_];
			if (!(_tmp2_ != NULL)) {
				break;
			}
			_tmp3_ = next_id;
			_tmp4_ = self->priv->pipes;
			_tmp4__length1 = self->priv->pipes_length1;
			next_id = (_tmp3_ + 1) % _tmp4__length1;
			_tmp5_ = next_id;
			if (_tmp5_ == 0) {
				gchar* _tmp6_;
				_tmp6_ = g_strdup ("");
				result = _tmp6_;
				return result;
			}
		}
		_tmp7_ = self->priv->pipes;
		_tmp7__length1 = self->priv->pipes_length1;
		_tmp8_ = next_id;
		_tmp9_ = description;
		_tmp10_ = gstd_pipeline_new (_tmp9_);
		_g_object_unref0 (_tmp7_[_tmp8_]);
		_tmp7_[_tmp8_] = (gstdPipelineInterface*) _tmp10_;
		_tmp11_ = _tmp7_[_tmp8_];
		_tmp12_ = self->priv->pipes;
		_tmp12__length1 = self->priv->pipes_length1;
		_tmp13_ = next_id;
		_tmp14_ = _tmp12_[_tmp13_];
		_tmp15_ = gstd_pipeline_pipeline_is_initialized (GSTD_IS_PIPELINE (_tmp14_) ? ((gstdPipeline*) _tmp14_) : NULL);
		if (!_tmp15_) {
			gstdPipelineInterface** _tmp16_;
			gint _tmp16__length1;
			gint _tmp17_;
			gstdPipelineInterface* _tmp18_;
			gchar* _tmp19_;
			_tmp16_ = self->priv->pipes;
			_tmp16__length1 = self->priv->pipes_length1;
			_tmp17_ = next_id;
			_g_object_unref0 (_tmp16_[_tmp17_]);
			_tmp16_[_tmp17_] = NULL;
			_tmp18_ = _tmp16_[_tmp17_];
			_tmp19_ = g_strdup ("");
			result = _tmp19_;
			return result;
		}
		_tmp20_ = next_id;
		_tmp21_ = g_strdup_printf ("%i", _tmp20_);
		_tmp22_ = _tmp21_;
		_tmp23_ = g_strconcat ("/com/ridgerun/gstreamer/gstd/pipe", _tmp22_, NULL);
		_tmp24_ = _tmp23_;
		_g_free0 (_tmp22_);
		objectpath = _tmp24_;
		_tmp25_ = self->priv->conn;
		_tmp26_ = objectpath;
		_tmp27_ = self->priv->pipes;
		_tmp27__length1 = self->priv->pipes_length1;
		_tmp28_ = next_id;
		_tmp29_ = _tmp27_[_tmp28_];
		gstd_pipeline_interface_register_object (_tmp29_, _tmp25_, _tmp26_, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_free0 (objectpath);
			if (_inner_error_->domain == G_IO_ERROR) {
				goto __catch3_g_io_error;
			}
			_g_free0 (objectpath);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp30_ = self->priv->pipes;
		_tmp30__length1 = self->priv->pipes_length1;
		_tmp31_ = next_id;
		_tmp32_ = _tmp30_[_tmp31_];
		_tmp33_ = objectpath;
		gstd_pipeline_pipeline_set_path (GSTD_IS_PIPELINE (_tmp32_) ? ((gstdPipeline*) _tmp32_) : NULL, _tmp33_);
		result = objectpath;
		return result;
	}
	goto __finally3;
	__catch3_g_io_error:
	{
		GError* _error_ = NULL;
		gchar* _tmp34_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		_tmp34_ = g_strdup ("");
		result = _tmp34_;
		_g_error_free0 (_error_);
		return result;
	}
	__finally3:
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
	g_clear_error (&_inner_error_);
	return NULL;
}


/**
   Destroy a pipeline
   @param id, the pipeline id assigned when created
   @return true, if succeded
   @see PipelineId
 */
static gboolean gstd_factory_real_destroy (gstdFactoryInterface* base, const gchar* objectpath, GError** error) {
	gstdFactory * self;
	gboolean result = FALSE;
	self = (gstdFactory*) base;
	g_return_val_if_fail (objectpath != NULL, FALSE);
	{
		gint index;
		index = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				gint _tmp3_;
				gstdPipelineInterface** _tmp4_;
				gint _tmp4__length1;
				gstdPipelineInterface** _tmp5_;
				gint _tmp5__length1;
				gint _tmp6_;
				gstdPipelineInterface* _tmp7_;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = index;
					index = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = index;
				_tmp4_ = self->priv->pipes;
				_tmp4__length1 = self->priv->pipes_length1;
				if (!(_tmp3_ < _tmp4__length1)) {
					break;
				}
				_tmp5_ = self->priv->pipes;
				_tmp5__length1 = self->priv->pipes_length1;
				_tmp6_ = index;
				_tmp7_ = _tmp5_[_tmp6_];
				if (_tmp7_ != NULL) {
					gstdPipelineInterface** _tmp8_;
					gint _tmp8__length1;
					gint _tmp9_;
					gstdPipelineInterface* _tmp10_;
					gchar* _tmp11_ = NULL;
					gchar* _tmp12_;
					const gchar* _tmp13_;
					gboolean _tmp14_;
					_tmp8_ = self->priv->pipes;
					_tmp8__length1 = self->priv->pipes_length1;
					_tmp9_ = index;
					_tmp10_ = _tmp8_[_tmp9_];
					_tmp11_ = gstd_pipeline_pipeline_get_path (GSTD_IS_PIPELINE (_tmp10_) ? ((gstdPipeline*) _tmp10_) : NULL);
					_tmp12_ = _tmp11_;
					_tmp13_ = objectpath;
					_tmp14_ = g_strcmp0 (_tmp12_, _tmp13_) == 0;
					_g_free0 (_tmp12_);
					if (_tmp14_) {
						gstdPipelineInterface** _tmp15_;
						gint _tmp15__length1;
						gint _tmp16_;
						gstdPipelineInterface* _tmp17_;
						_tmp15_ = self->priv->pipes;
						_tmp15__length1 = self->priv->pipes_length1;
						_tmp16_ = index;
						_g_object_unref0 (_tmp15_[_tmp16_]);
						_tmp15_[_tmp16_] = NULL;
						_tmp17_ = _tmp15_[_tmp16_];
						result = TRUE;
						return result;
					}
				}
			}
		}
	}
	syslog (LOG_ERR, "Fail to destroy pipeline", NULL);
	result = FALSE;
	return result;
}


/**
   Destroy all pipelines
   @return true, if succeded
   @see PipelineId
 */
static gboolean gstd_factory_real_destroy_all (gstdFactoryInterface* base, GError** error) {
	gstdFactory * self;
	gboolean result = FALSE;
	self = (gstdFactory*) base;
	{
		gint index;
		index = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				gint _tmp3_;
				gstdPipelineInterface** _tmp4_;
				gint _tmp4__length1;
				gstdPipelineInterface** _tmp5_;
				gint _tmp5__length1;
				gint _tmp6_;
				gstdPipelineInterface* _tmp7_;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = index;
					index = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = index;
				_tmp4_ = self->priv->pipes;
				_tmp4__length1 = self->priv->pipes_length1;
				if (!(_tmp3_ < _tmp4__length1)) {
					break;
				}
				_tmp5_ = self->priv->pipes;
				_tmp5__length1 = self->priv->pipes_length1;
				_tmp6_ = index;
				_tmp7_ = _tmp5_[_tmp6_];
				if (_tmp7_ != NULL) {
					gstdPipelineInterface** _tmp8_;
					gint _tmp8__length1;
					gint _tmp9_;
					gstdPipelineInterface* _tmp10_;
					_tmp8_ = self->priv->pipes;
					_tmp8__length1 = self->priv->pipes_length1;
					_tmp9_ = index;
					_g_object_unref0 (_tmp8_[_tmp9_]);
					_tmp8_[_tmp9_] = NULL;
					_tmp10_ = _tmp8_[_tmp9_];
				}
			}
		}
	}
	result = TRUE;
	return result;
}


/**
   List the existing pipelines
   @return pipe_list with the corresponding paths
 */
static void _vala_array_add1 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static gchar** gstd_factory_real_list (gstdFactoryInterface* base, int* result_length1, GError** error) {
	gstdFactory * self;
	gchar** result = NULL;
	gchar** _tmp0_ = NULL;
	gchar** paths;
	gint paths_length1;
	gint _paths_size_;
	gchar** _tmp14_;
	gint _tmp14__length1;
	self = (gstdFactory*) base;
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	paths = _tmp0_;
	paths_length1 = 0;
	_paths_size_ = paths_length1;
	{
		gint index;
		index = 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				gboolean _tmp2_;
				gint _tmp4_;
				gstdPipelineInterface** _tmp5_;
				gint _tmp5__length1;
				gstdPipelineInterface** _tmp6_;
				gint _tmp6__length1;
				gint _tmp7_;
				gstdPipelineInterface* _tmp8_;
				_tmp2_ = _tmp1_;
				if (!_tmp2_) {
					gint _tmp3_;
					_tmp3_ = index;
					index = _tmp3_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp4_ = index;
				_tmp5_ = self->priv->pipes;
				_tmp5__length1 = self->priv->pipes_length1;
				if (!(_tmp4_ < _tmp5__length1)) {
					break;
				}
				_tmp6_ = self->priv->pipes;
				_tmp6__length1 = self->priv->pipes_length1;
				_tmp7_ = index;
				_tmp8_ = _tmp6_[_tmp7_];
				if (_tmp8_ != NULL) {
					gchar** _tmp9_;
					gint _tmp9__length1;
					gstdPipelineInterface** _tmp10_;
					gint _tmp10__length1;
					gint _tmp11_;
					gstdPipelineInterface* _tmp12_;
					gchar* _tmp13_ = NULL;
					_tmp9_ = paths;
					_tmp9__length1 = paths_length1;
					_tmp10_ = self->priv->pipes;
					_tmp10__length1 = self->priv->pipes_length1;
					_tmp11_ = index;
					_tmp12_ = _tmp10_[_tmp11_];
					_tmp13_ = gstd_pipeline_pipeline_get_path (GSTD_IS_PIPELINE (_tmp12_) ? ((gstdPipeline*) _tmp12_) : NULL);
					_vala_array_add1 (&paths, &paths_length1, &_paths_size_, _tmp13_);
				}
			}
		}
	}
	_tmp14_ = paths;
	_tmp14__length1 = paths_length1;
	if (result_length1) {
		*result_length1 = _tmp14__length1;
	}
	result = _tmp14_;
	return result;
}


/**
   Ping Gstd daemon.
   Some GStreamer elements use exit(), thus killing the daemon.
   @return true if alive
 */
static gboolean gstd_factory_real_ping (gstdFactoryInterface* base, GError** error) {
	gstdFactory * self;
	gboolean result = FALSE;
	self = (gstdFactory*) base;
	result = TRUE;
	return result;
}


static void gstd_factory_class_init (gstdFactoryClass * klass) {
	gstd_factory_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (gstdFactoryPrivate));
	G_OBJECT_CLASS (klass)->finalize = gstd_factory_finalize;
}


static void gstd_factory_gstd_factory_interface_interface_init (gstdFactoryInterfaceIface * iface) {
	gstd_factory_gstd_factory_interface_parent_iface = g_type_interface_peek_parent (iface);
	iface->create = (gchar* (*)(gstdFactoryInterface*, const gchar*, GError**)) gstd_factory_real_create;
	iface->destroy = (gboolean (*)(gstdFactoryInterface*, const gchar*, GError**)) gstd_factory_real_destroy;
	iface->destroy_all = (gboolean (*)(gstdFactoryInterface*, GError**)) gstd_factory_real_destroy_all;
	iface->list = (gchar** (*)(gstdFactoryInterface*, int*, GError**)) gstd_factory_real_list;
	iface->ping = (gboolean (*)(gstdFactoryInterface*, GError**)) gstd_factory_real_ping;
}


static void gstd_factory_instance_init (gstdFactory * self) {
	self->priv = GSTD_FACTORY_GET_PRIVATE (self);
}


static void gstd_factory_finalize (GObject* obj) {
	gstdFactory * self;
	self = GSTD_FACTORY (obj);
	_g_object_unref0 (self->priv->conn);
	self->priv->pipes = (_vala_array_free (self->priv->pipes, self->priv->pipes_length1, (GDestroyNotify) g_object_unref), NULL);
	G_OBJECT_CLASS (gstd_factory_parent_class)->finalize (obj);
}


GType gstd_factory_get_type (void) {
	static volatile gsize gstd_factory_type_id__volatile = 0;
	if (g_once_init_enter (&gstd_factory_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (gstdFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gstd_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (gstdFactory), 0, (GInstanceInitFunc) gstd_factory_instance_init, NULL };
		static const GInterfaceInfo gstd_factory_interface_info = { (GInterfaceInitFunc) gstd_factory_gstd_factory_interface_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType gstd_factory_type_id;
		gstd_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "gstdFactory", &g_define_type_info, 0);
		g_type_add_interface_static (gstd_factory_type_id, GSTD_TYPE_FACTORY_INTERFACE, &gstd_factory_interface_info);
		g_once_init_leave (&gstd_factory_type_id__volatile, gstd_factory_type_id);
	}
	return gstd_factory_type_id__volatile;
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



