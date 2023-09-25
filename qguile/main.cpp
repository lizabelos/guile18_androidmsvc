#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>
#include <QDirIterator>
#include <QString>

#include "MainWindow.h"

inline void scm_use_embedded_ice9() {
    QString destination = QDir::currentPath() + QDir::separator() + "guile";

    // Test if the resources are already extracted
    if (QFile(destination + "/.resources_extracted").exists()) {
        return;
    }
    QDir().mkpath(destination);

    // Count the number of files to extract
    int count = 0;
    for (QDirIterator it(":/ice-9/", QDirIterator::Subdirectories); it.hasNext(); it.next()) {
        count++;
    }

    // Extract the files
    int i = 0;
    for (QDirIterator it(":/ice-9/", QDirIterator::Subdirectories); it.hasNext(); ) {
        QString source_filename = it.next();
        QString destination_filename = source_filename;
        destination_filename.replace(":", destination);
        if (it.fileInfo().isDir()) {
            QDir().mkpath(destination_filename);
        } else {
            QDir().mkpath(QFileInfo(destination_filename).dir().absolutePath());
            if (!QFile::copy(source_filename, destination_filename)) {
                //throw std::runtime_error("Could not copy " + source_filename.toStdString() + " to " + destination_filename.toStdString());
            }
        }
        i++;
    }

    // Create a dummy file to indicate that the resources have been extracted
    QFile f(destination + "/.resources_extracted");
    f.open(QIODevice::WriteOnly);
    f.close();

}

void guile_error() {

    // get the active window
    SchemeConsole *scheme_console = dynamic_cast<SchemeConsole*>(QApplication::activeWindow());

    // the active window should be a SchemeConsole. I prefer to check it, but it is not necessary
    if (scheme_console != nullptr) {
        // append the error in red color using html
        scheme_console->mTextBrowser.append("<font color=\"red\">Error</font>");
    }

    // throw an exception, that will be catched inside the evaluate slots of the SchemeConsole
    throw std::runtime_error("Error");
}

void guile_log_function(const char *cmsg, int len) {

    // Convert the c string to a QString. The c string is not null terminated, so we need to specify the length.
    QString msg = QString::fromStdString(std::string(cmsg, len));

    // Print the message in the console
    qDebug() << msg;
    
    // get the active window
    SchemeConsole *scheme_console = dynamic_cast<SchemeConsole*>(QApplication::activeWindow());

    // the active window should be a SchemeConsole. I prefer to check it, but it is not necessary
    if (scheme_console != nullptr) {

        // Replace the new line character by a html break
        msg.replace("\n", "<br>");

        // append the log in blue color using html
        scheme_console->mTextBrowser.textCursor().insertHtml(QString("<font color=\"blue\">%1</font>").arg(QString::fromStdString(std::string(cmsg, len))));
    }
}

void setup_guile_load_path() {
    // set the environment variable GUILE_LOAD_PATH to the current directory on which we extracted the ice9 files
    qputenv("GUILE_LOAD_PATH", QDir::currentPath().toUtf8());
}

int main(int argc, char **argv) {
    /*** Initialize the Qt application ***/
    QApplication a(argc, argv);

    /*** Initialize the Scheme interpreter ***/
    // scm_use_embedded_ice9 extracts the ice9 scheme code from the executable
    scm_use_embedded_ice9();

    // setup the guile load path
    setup_guile_load_path();

    // in my implementation of guile, the printf have been replaced by a callback, which can be set with scm_set_log_function
    scm_set_log_function(guile_log_function);

    // in my implementation of guile, the error have been replaced by a callback, which can be set with scm_set_error_callback
    // set_error_callback(guile_error);

    /*** Initialize the Main Window ***/

    // create the window
    SchemeConsole w;

    // show the window
    w.show();

    // let the control flow to the Qt event loop
    return a.exec();
}


