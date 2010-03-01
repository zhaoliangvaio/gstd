/*
 * gstd/src/main.vala
 *
 * Main function for GStreamer daemon - framework for controlling audio and video streaming using D-Bus messages
 *
 * Copyright (c) 2010, RidgeRun
 * All rights reserved.
 *
 * GPL2 license - See http://www.opensource.org/licenses/gpl-2.0.php for complete text.
*/
using Gst;

/*Global Variable*/
public MainLoop loop;
public DBus.Connection conn;

public void
main (string[]args)
{

  /* Initializing GStreamer */
  Gst.init (ref args);

  /* Creating a GLib main loop with a default context */
  loop = new MainLoop (null, false);

  try {
    conn = DBus.Bus.get (DBus.BusType.SYSTEM);

    dynamic DBus.Object bus = conn.get_object ("org.freedesktop.DBus",
        "/org/freedesktop/DBus",
        "org.freedesktop.DBus");

    /* Try to register service in session bus */
    uint request_name_result =
        bus.request_name ("com.ridgerun.gstreamer.gstd", (uint) 0);

    if (request_name_result == DBus.RequestNameReply.PRIMARY_OWNER) {

      /* Create our factory */
      var factory = new Factory ();

      conn.register_object ("/com/ridgerun/gstreamer/gstd/factory", factory);

      loop.run ();
    } else {
      stderr.printf ("Gstd: Failed to obtain primary ownership of " +
          "the service\n");
      stderr.printf ("Gstd: This usually means there is another instance of " +
          "gstd already running\n");
    }
  }
  catch (Error e) {
    stderr.printf ("Gstd: Error: %s\n", e.message);
  }
}
