#ifndef LIBGUILE_HPP
#define LIBGUILE_HPP

#include <libguile.h>
#include <libguile/eval.hpp>

#if USE_GUILE_QT

#include <QString>
#include <QDir>
#include <QDirIterator>

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

#else

inline void scm_use_embedded_ice9() {
    printf("warning: scm_use_embedded_ice9() is not implemented on this build.\n");
}

#endif

#endif