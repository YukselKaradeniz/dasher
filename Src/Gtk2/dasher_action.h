#ifndef __dasher_action_h__
#define __dasher_action_h__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS
#define TYPE_DASHER_ACTION            (dasher_action_get_type())
#define DASHER_ACTION(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), TYPE_DASHER_ACTION, DasherAction ))
#define DASHER_ACTION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DASHER_ACTION, DasherActionClass ))
#define IS_DASHER_ACTION(obj)	      (G_TYPE_CHECK_INSTANCE_TYPE((obj), TYPE_DASHER_ACTION))
#define IS_DASHER_ACTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DASHER_ACTION))
#define DASHER_ACTION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DASHER_ACTION, DasherActionClass))

typedef struct _DasherAction DasherAction;
typedef struct _DasherActionClass DasherActionClass;

struct _DasherAction {
  GObject parent;
  gpointer private_data;
};

struct _DasherActionClass {
  GObjectClass parent_class;

  gboolean (*execute)(DasherAction *pSelf, const gchar *szData);
};

DasherAction *dasher_action_new();
GType dasher_action_get_type();

gboolean dasher_action_execute(DasherAction *pSelf, const gchar *szData);
G_END_DECLS

#endif