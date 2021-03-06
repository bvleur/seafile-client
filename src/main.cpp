#include <QApplication>
#include <QMessageBox>

#include <glib-object.h>

#include "utils/process.h"
#include "seafile-applet.h"
#include "QtAwesome.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (count_process("seafile-applet") > 1) {
        QMessageBox::warning(NULL, "Seafile",
                             QObject::tr("Seafile is already running"),
                             QMessageBox::Ok);
        return -1;
    }

#if !GLIB_CHECK_VERSION(2, 35, 0)
    g_type_init();
#endif
#if !GLIB_CHECK_VERSION(2, 31, 0)
    g_thread_init(NULL);
#endif

    awesome = new QtAwesome(qApp);
    awesome->initFontAwesome();

    seafApplet = new SeafileApplet;
    seafApplet->start();

    return app.exec();
}
